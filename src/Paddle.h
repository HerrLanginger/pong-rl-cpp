#pragma once
#include "GameObject.h"

class Paddle : public GameObject
{
public:
    Paddle(float startX, float startY);

    void Update(float deltaTime) override;
    void Draw() override;
    Rectangle GetRect() const override;

    void MoveUp(float deltaTime);
    void MoveDown(float deltaTime);

private:
    float width;
    float height;
    float speed;
};