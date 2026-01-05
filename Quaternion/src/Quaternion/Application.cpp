#include "pch.h"
#include "Application.h"

namespace QUA {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Input = std::unique_ptr<Input>(Input::Create());
		m_Renderer = std::unique_ptr<Draw>(Draw::Create());
		m_Physics = std::unique_ptr<Physics>(Physics::Create());
		m_TextureManager = std::unique_ptr<TextureManager>(TextureManager::Create());
		m_CameraManager = std::unique_ptr<CameraManager>(CameraManager::Create());
		
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		//while (m_Window->IsWindowRunning())
		//{
		//	//Scenes[currentScene]->OnUpdate();

		//	m_Window->BeginFrame();

		//	m_CameraManager->startCamera(camera);

		//	m_CameraManager->endCamera();

		//	m_Window->EndFrame();

		//}
	}
}