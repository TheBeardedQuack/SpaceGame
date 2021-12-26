#pragma once

#include "Component.hpp"

#include <type_traits>

template< class TComponent >
class DefaultComponentFactory
    : public ComponentFactory
{
    virtual
    Component&
    operator ()(
        void
    ) {
        return TComponent{};
    }

    Component&
    operator ()(
        const TComponent& copy
    ) {
        return TComponent{copy};
    }

    Component&
    operator ()(
        TComponent&& move
    ) {
        return TComponent{move};
    }
};

template< class TComponent, class TFactory = DefaultComponentFactory<TComponent> >
class ComponentBase :
    public Component
{
    friend class Entity;

private:
    static std::map<Entity::ID, TComponent> s_instances;
    static MapViewImpl<Entity::ID, Component, TComponent> s_view;
    static TFactory s_factory;
    static Component::TypeRegistration s_type;

protected:
    ComponentBase(
        void
    ) :
        Component()
    {
        // Nothing to do
    }

    ComponentBase(
        Entity::ID parent
    ) :
        Component(parent)
    {
        // Nothing to do
    }

    ComponentBase(
        const ComponentBase& copy
    ) :
        Component(copy)
    {
        // Nothing to do
    }
};

template<class TComponent, class TFactory>
std::map<Entity::ID, TComponent>
ComponentBase<TComponent, TFactory>::s_instances{};

template<class TComponent, class TFactory>
MapViewImpl<Entity::ID, Component, TComponent>
ComponentBase<TComponent, TFactory>::s_view{s_instances};

template<class TComponent, class TFactory>
TFactory
ComponentBase<TComponent, TFactory>::s_factory{};

template<class TComponent, class TFactory>
Component::TypeRegistration
ComponentBase<TComponent, TFactory>::s_type{
    typeid(TComponent).name(),
    s_view,
    s_factory
};
