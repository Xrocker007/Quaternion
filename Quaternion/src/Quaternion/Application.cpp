#include "pch.h"
#include "Application.h"

#include "raylib.h"

namespace QUA {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Input = std::unique_ptr<Input>(Input::Create());
		m_Renderer = std::unique_ptr<Draw>(Draw::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		while (m_Window->IsWindowRunning())
		{
			m_Window->BeginFrame();

			//m_Renderer->drawText("colour:" , 190, 200, 20, {1, 0, 0, 1});

			m_Renderer->drawCircle(200, 200, 50, { 0, 0, 1, 1 });
			m_Renderer->drawRect(200, 225, 50, 50, { 1, 0, 0, 0.5 });
			m_Renderer->drawLine(100, 100, 300, 400, 10, { 0, 1, 0, 0.7 });

			if (m_Input->MouseButtonDown(MouseButton::Left))
			{
				m_Window->SetBackgroundColour({ 0, 0, 0, 1 });
			}

			if (m_Input->MouseButtonReleased(MouseButton::Left))
			{
				m_Window->SetBackgroundColour({ 0.9, 0.9, 0.9, 1 });
			}

			m_Window->EndFrame();

		}

	}

}