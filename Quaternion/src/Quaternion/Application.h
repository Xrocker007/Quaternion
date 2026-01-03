#pragma once

#include "Core.h"
#include "Window.h"

namespace QUA {

	class QUA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
	};

	//To be defined by CLIENT
	Application* CreateApplication();
}


