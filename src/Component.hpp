#pragma once

#include <mutex>
#include <deque>
#include <memory>
#include <functional>

template<class T>
class Component
{
private:
    std::recursive_mutex mutex;
    std::deque<std::weak_ptr<T>> instances;

public:
    template<class... TArgs>
    std::shared_ptr<T>
    Spawn(TArgs... args)
    {
        std::scoped_lock lock{mutex};

        auto sp = std::shared_ptr<T>(new T(std::forward(args)...));
        instances.push_back(sp);
        return sp;
    }

    std::shared_ptr<T>
    Clone() const
    {
        return Spawn(*this);
    }

    void
    ForEach(
        std::function<void(std::shared_ptr<T>& spComponent)> callback
    ) {
        if(!callback)
            return;
        
        std::scoped_lock lock{mutex};

        for(auto it = instances.begin(); it != instances.end();)
        {
            auto sp = it->lock();

            if(sp)
            {
                callback(sp);
                ++it;
            }
            else
                it = instances.erase(it);
        }
    }
};
