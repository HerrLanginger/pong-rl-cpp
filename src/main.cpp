/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <memory>

class Player
{
public:
	Player(KeyboardKey keyUp, KeyboardKey keyDown, Vector2 position) : keyUp(keyUp), keyDown(keyDown), position(position) {}
	~Player() {}

	int score = 0;

	Rectangle GetRect() const 
	{ 
		return Rectangle{ position.x, position.y, 20.0f, 100.0f }; 
	}

	void Move()
	{
		if (IsKeyDown(keyUp))
		{
			position.y -= speed;
		}
		if (IsKeyDown(keyDown))
		{
			position.y += speed;
		}
	}

	void Draw()
	{
		// draw player (placeholder)
		DrawRectangleRec(GetRect(), RAYWHITE);
	}

	std::string GetScoreString() const
	{
		return std::to_string(score);
	}

private:
	
	std::string name;
	Vector2 position;
	Vector2 velocity;
	float speed = 8.0f;

	KeyboardKey keyUp;
	KeyboardKey keyDown;

	//Rectangle rectangle;

};

class Ball
{
public:
	Ball() {
		position = Vector2{ 640.0f, 400.0f };
		velocity = Vector2{ speed, 2.0f };
	}
	~Ball() {}

	Rectangle GetRect() const 
	{ 
		return Rectangle{ position.x, position.y, 20.0f, 20.0f }; 
	}

	void Reset()
	{
		position = Vector2{ 640.0f, 400.0f };
		velocity = Vector2{ speed, 2.0f };
	}

	void Move(std::unique_ptr<Player>& p1, std::unique_ptr<Player>& p2)
	{
		if (CheckCollisionRecs(GetRect(), p1->GetRect()))
		{
			velocity.x *= -1 * speedMultiplier;
			
		} else if (CheckCollisionRecs(GetRect(), p2->GetRect()))
		{
			velocity.x *= -1 * speedMultiplier;
		} else if (CheckCollisionRecs(GetRect(), Rectangle{0.0f, 0.0f, 1280.0f, 0.0f}))
		{
			velocity.y *= -1;
		} else if (CheckCollisionRecs(GetRect(), Rectangle{0.0f, 800.0f, 1280.0f, 0.0f}))
		{
			velocity.y *= -1;
		}
		
		position.x += velocity.x;
		position.y += velocity.y;
	}

	void Draw()
	{
		DrawRectangleRec(GetRect(), RAYWHITE);
	}


private:
	float speed = 3.0f;
	float speedMultiplier = 1.5f;
	Vector2 position;
	Vector2 velocity;

	//Rectangle rectangle;
};

int main ()
{
	// Enable verbose logging to confirm if GLFW initializes Wayland or X11
	SetTraceLogLevel(LOG_ALL);

	// Tell the window to use vsync, work on high DPI displays, and be resizable (better for Wayland tiling)
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);

	// Create the window and OpenGL context
	InitWindow(1280, 800, "Hello Raylib");
	
	if (!IsWindowReady())
	{
		return 1;
	}

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");

	std::unique_ptr<Player> playerLeft = std::make_unique<Player>(KEY_W, KEY_S, Vector2{ 50.0f, 300.0f });
	std::unique_ptr<Player> playerRight = std::make_unique<Player>(KEY_UP, KEY_DOWN, Vector2{ 1180.0f, 300.0f });
	std::unique_ptr<Ball> ball = std::make_unique<Ball>();

	
	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);

		DrawText("Press ESC to quit", 200, 240, 20, WHITE);
		DrawText("Press SPACE to get FREE MONEY", 200, 240, 20, RAYWHITE);

		if (IsKeyDown(KEY_SPACE))
		{
			DrawText("GET A FUCKING JOB YOU FOOL", 200, 280, 20, GOLD);
		}
		
		
		DrawText(playerLeft->GetScoreString().c_str(), 600, 10, 40, WHITE);
		DrawText(playerRight->GetScoreString().c_str(), 680, 10, 40, WHITE);

		// draw our texture to the screen
		DrawTexture(wabbit, 400, 200, WHITE);

		playerLeft->Move();
		playerRight->Move();
		ball->Move(playerLeft, playerRight);

		if (IsKeyDown(KEY_ESCAPE))
		{
			break;
		}

		if (ball->GetRect().x < 0)
		{
			ball->Reset();
			playerRight->score++;
		} else if (ball->GetRect().x > 1280)
		{
			ball->Reset();
			playerLeft->score++;
		}

		playerLeft->Draw();
		playerRight->Draw();
		ball->Draw();

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
