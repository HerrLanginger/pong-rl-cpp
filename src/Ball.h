#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
    Ball(float startX, float startY);

    void Update(float deltaTime) override;
    void Draw() override;
    Rectangle GetRect() const override;

    void Reset();

    // bounce
    void InvertX();
    void InvertY();

private:
    float radius;
    bool active;
}