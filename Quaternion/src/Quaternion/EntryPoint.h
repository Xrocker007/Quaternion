#pragma once

#ifdef QUA_PLATFORM_WINDOWS

extern QUA::Application* QUA::CreateApplication();

	int main(int argc, char** argv)
	{
		QUA::Log::Init();
		QUA_CORE_WARN("Initialized");

		auto app = QUA::CreateApplication();
		app->Run();
		delete app;
	}

#endif