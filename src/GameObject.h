#pragma once
#include "raylib.h"

class GameObject
{
public:
    virtual ~GameObject() = default;

    virtual void Update(float deltaTime) = 0; // pure virtual, children must implement
    virtual void Draw() = 0;

    virtual Rectangle GetRect() const = 0;

protected:
    Vector2 position;
    Vector2 velocity;
}