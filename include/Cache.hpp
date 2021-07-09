#pragma once

#include <map>
#include <string>

template<class T>
class Cache
{
    sp::shared_ptr<T>
    operator[](
        const std::string& key
    ) {
        std::shared_ptr<T> result;

        // Check if key exists in cache
        auto it = cache.find(key);
        if(it != cache.end())
        {
            // Is the resource for this key still valid
            result = it->second.lock();
            if(result)
                return result;
        }

        // If no key, or not valid, store new instance
        result = std::make_shared<T>(key);
        cache[key] = result;
        return result;
    }

    //! Empty internal container of any dangling pointers
    RecycleUnused();

private:
    std::map<std::string, std::weak_ptr<T>> cache;
};
