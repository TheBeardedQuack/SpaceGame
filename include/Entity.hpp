#pragma once

#include "InstanceId.hpp"
#include "Component.hpp"

#include <map>
#include <set>
#include <typeinfo>
#include <string>

class Entity
{
public:
    using ID = size_t;
    const ID NullId = 0;

private:
    static ID s_nextId;
    
    InstanceId id;
    std::set<std::string> components;
    
public:
    Entity();

    Entity(
        const Entity& copy
    );

    Entity(
        const Entity&& move
    );

    virtual
    ~Entity();

    Component&
    AddComponent(
        const Component& clone
    );

    Component&
    AddComponent(
        const std::string& component
    );

    [[nodiscard]]
    const Component&
    GetComponent(
        const std::string& component
    ) const;

    [[nodiscard]]
    Component&
    GetComponent(
        const std::string& component
    );

    [[nodiscard]]
    std::set<std::string>
    GetComponents(
        void
    ) const;

    void
    RemoveComponent(
        const std::string& component
    );
};
