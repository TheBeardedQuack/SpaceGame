#pragma once

#include "Component.hpp"

class Transform :
    public Component<Transform>
{
private:
    Transform();

    Transform(
        const Transform& copy
    );

    Transform(
        Transform&& move
    );

    virtual
    ~Transform();

public:
    float x, y, r;
};
