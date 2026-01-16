#include "Game.h"
#include "Constants.h"

void Game::UpdateGame()
{
    if (isPaused)
        return;

    float deltaTime = GetFrameTime();

    playerLeft.Update(deltaTime);
    playerRight.Update(deltaTime);
    ball.Update(deltaTime);

    Rectangle ballRect = ball.GetRect();

    if (ballRect.y <= 0)
    {
        ball.InvertY(); // might need SetY helper in Ball class
    }
    else if (ballRect.y + ballRect.height >= Config::ScreenHeight)
    {
        ball.InvertY();
    }

    if (CheckCollisionRecs(ballRect, playerLeft.GetRect()))
    {
        ball.InvertX();
        // add later: speed up game
    }

    if (CheckCollisionRecs(ballRect, playerRight.GetRect()))
    {
        ball.InvertX();
    }

    if (ballRect.x <= 0)
    {
        scoreRight++;
        ResetRound();
    }
    else if (ballRect.x >= Config::ScreenWidth)
    {
        scoreLeft++;
        ResetRound();
    }
}