#pragma once

#include "Core.h"
#include "Window.h"
#include "Input.h"

namespace QUA {

	class QUA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<Input> m_Input;
	};

	//To be defined by CLIENT
	Application* CreateApplication();
}


