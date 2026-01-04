#pragma once

#include "Core.h"
#include "Window.h"
#include "Input.h"
#include "Draw.h"

namespace QUA {

	class QUA_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();


	private:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<Input> m_Input;
		std::unique_ptr<Draw> m_Renderer;

	};

	//To be defined by CLIENT
	Application* CreateApplication();
}


