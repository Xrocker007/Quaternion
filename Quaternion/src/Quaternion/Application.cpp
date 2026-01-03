#include "pch.h"
#include "Application.h"

#include "raylib.h"



namespace QUA {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		const int screenWidth = 800;
		const int screenHeight = 450;

		InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

		SetTargetFPS(60);

		while (!WindowShouldClose())
		{
			BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

			EndDrawing();

		}

		CloseWindow();

	}

}