#include "pch.h"
#include "Application.h"

#include "raylib.h"



namespace QUA {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		while (m_Window->IsWindowRunning())
		{
			m_Window->BeginFrame();

			DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

			m_Window->EndFrame();

		}

	}

}