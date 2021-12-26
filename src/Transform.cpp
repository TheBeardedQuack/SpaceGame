#include "Transform.hpp"

Transform::Transform(
    void
) :
    x(0.0f),
    y(0.0f),
    r(0.0f)
{
}

Transform::Transform(
    const Transform& copy
) :
    ComponentBase(*this),
    x(copy.x),
    y(copy.y),
    r(copy.r)
{
}

Transform::Transform(
    Transform&& move
) :
    ComponentBase(*this),
    x(move.x),
    y(move.y),
    r(move.r)
{
}

Transform::~Transform()
{
}
