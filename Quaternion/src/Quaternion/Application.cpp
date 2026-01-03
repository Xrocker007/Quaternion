#include "pch.h"
#include "Application.h"
#include "Platform/Raylib/RaylibInput.h"

#include "raylib.h"



namespace QUA {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Input = std::unique_ptr<Input>(Input::Create());
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

			if (m_Input->MouseButtonDown(MouseButton::Left))
			{
				m_Window->SetBackgroundColour(0x0);
			}

			if (m_Input->MouseButtonReleased(MouseButton::Left))
			{
				m_Window->SetBackgroundColour(0xF5F5F5F5);
			}

			m_Window->EndFrame();

		}

	}

}