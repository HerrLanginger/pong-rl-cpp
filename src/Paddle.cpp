#include "Paddle.h"
#include "Constants.h"

void Paddle::Update(float deltaTime)
{
}
void Paddle::Draw()
{
    DrawRectangleRec(GetRect(), Config::PaddleColor);
}

const void Paddle::GetRect()
{
}