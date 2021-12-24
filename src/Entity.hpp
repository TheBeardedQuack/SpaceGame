#pragma once

#include "Component.hpp"

using EntityCollection = std::set<Entity::ID>;

class Entity
{
private:
    std::deque<std::shared_ptr<Component>> components;


public:
    Entity();

    Entity(
        const Entity& copy
    );

    virtual
    ~Entity();

    template<class T> operator T&(
        const Entity& entity
    ) {
        for(auto c : components)
        {
            try {
                return std::dynamic_pointer_cast<T>(c);
            }
            catch(const std::bad_cast&)
            {
                continue;
            }
        }

        throw std::bad_cast{};
    }
};
