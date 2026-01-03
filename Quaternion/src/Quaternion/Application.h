#pragma once

#include "Core.h"

namespace QUA {

	class QUA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:

		
	};

	//To be defined by CLIENT
	Application* CreateApplication();
}


