#include "Component.hpp"

#include <stdexcept>

Component::Component(
    Entity::ID parent
) :
    entityId(parent)
{
    // TODO: Validate parent exists
}

Component::Component(
    const Component& copy
) :
    entityId(0)
{

}

void
Component::SetParent(
    Entity::ID parent
) {
    Entity::GetEntity(parent).AddComponent(*this);
    Entity::GetEntity(entityId).RemoveComponent(*this);
}
