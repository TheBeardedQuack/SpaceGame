#include "Entity.hpp"


Entity::s_nextId = 1;

Entity::Entity()
{
    do
    {
        if(s_nextId == NullId)
            ++s_nextId;
    }while(!s_instances::try_emplace(s_nextId++, Impl{}));

    id = s_nextId - 1;
}

Entity::Entity(
    const Entity& copy
) :
    Entity()
{
    for(auto type : components)
        AddComponent(copy.GetComponent(type));
}

Entity::Entity(
    Entity&& move
) :
    id(move.id)
    components(std::move(move.components))
{
    move.id = 0;
}

Entity::~Entity()
{
    for(auto type : components)
        RemoveComponent(type);
}

Component&
Entity::AddComponent(
    const Component& clone
) {
    auto& reg = Component::GetTypeRegistration(clone.GetTypeInfo());
    reg.s_view.insert(id, reg.factory(clone));
    reg.s_view.at(id).entityId = id;
    components.push_back(reg.type);
}

Component&
Entity::AddComponent(
    const std::string& component
) {
    auto& reg = Component::GetTypeRegistration(component);
    reg.s_view.insert(id, reg.factory());
    reg.s_view.at(id).entityId = id;
    components.push_back(component);
}

const Component&
Entity::GetComponent(
    const std::string& component
) const {
    auto& reg = Component::GetTypeRegistration(component);
    return reg.s_view.at(id);
}

Component&
Entity::GetComponent(
    const std::string& component
) {
    auto& reg = Component::GetTypeRegistration(component);
    return reg.s_view.at(id);
}

void
Entity::RemoveComponent(
    const std::string& component
) {
    auto& reg = Component::GetTypeRegistration(component);
    reg.s_view.erase(id);
    components.erase(reg.type);
}
