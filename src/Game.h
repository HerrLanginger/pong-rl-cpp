#pragma once
#include "Ball.h"
#include "Paddle.h"
#include <string>

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:
    // internal helper funcs
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    void ResetRound();

    // member variables, no pointers cause RAII
    Paddle playerLeft;
    Paddle playerRight;
    Ball ball;

    int scoreLeft;
    int scoreRight;
    bool isPaused;

    void CheckCollisions();
};