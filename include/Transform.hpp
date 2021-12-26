#pragma once

#include "ComponentBase.hpp"

class Transform :
    public ComponentBase<Transform>
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
