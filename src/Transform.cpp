#include "Transform.hpp"

Transform::Transform() :
    x(0.0f),
    y(0.0f),
    r(0.0f)
{
}

Transform::Transform(
    const Transform& copy
) :
    x(copy.x),
    y(copy.y),
    r(copy.r)
{
}

Transform::Transform(
    Transform&& move
) :
    x(move.x),
    y(move.y),
    r(move.r)
{
}

Transform::~Transform()
{
}
