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
#include "Game.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir
#include <memory>

int main()
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

	Game pong;

	pong.Run();

	return 0;

	// game loop
	/*
	while (!WindowShouldClose()) // run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
	*/
}
