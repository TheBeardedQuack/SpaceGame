#pragma once

#include <memory>
#include <typeindex>

class Component;

#include "Entity.hpp"
#include "MapView.hpp"

class ComponentFactory
{
    virtual
    Component&
    operator ()(
        void
    ) const = 0;

    virtual
    Component&
    operator ()(
        const Component& copy
    ) const = 0;

    virtual
    Component&
    operator ()(
        Component&& move
    ) const = 0;
};

class Component
{
friend class Entity;

protected:
    class TypeRegistration
    {
        friend class Entity;

    public:
        const std::string type;
        const ComponentFactory& factory;

    private:
        MapView<Entity::ID, Component>& components;

    public:
        TypeRegistration(
            const std::string& typeToRegister,
            const ComponentFactory& factory,
            MapView<Entity::ID, Component>& components
        ) : 
            type(typeToRegister),
            factory(factory),
            components(components)
        {
            s_types.insert({type, *this});
        }

        ~TypeRegistration()
        {
            s_types.erase(type);
        }

        const MapView<Entity::ID, Component>
        GetComponents();
    };

private:
    static std::map<std::string, TypeRegistration> s_types;
    Entity::ID entityId  = 0;

protected:
    Component() = default;

    Component(
        Entity::ID parent
    );

    static
    TypeRegistration&
    GetTypeRegistration(
        const std::string& type
    ) {
        return s_types.at(type);
    }

public:
    Component(
        const Component& copy
    );

    Component(
        Component&& move
    ) = delete;

    inline
    Entity::ID
    GetParentId()
    const {
        return entityId;
    }

    void
    SetParent(
        Entity::ID parent
    );

    std::string
    GetTypeInfo(
        void
    ) {
        return typeid(*this).name();
    };
};
