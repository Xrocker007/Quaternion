#pragma once

#include "Core.h"
#include "Window.h"
#include "Input.h"
#include "Draw.h"
#include "Physics.h"
#include "TextureManager.h"
#include "CameraManager.h"
#include "Scene.h"
#include "EntityComponentSystem.h"

namespace QUA {

	class QUA_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		void addScene(Scene* scene)
		{
			Scenes.push_back(scene);
		}

		void setCurrentScene(int sceneIndex)
		{
			currentScene = sceneIndex;
		}

	protected:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<Input> m_Input;
		std::unique_ptr<Draw> m_Renderer;
		std::unique_ptr<Physics> m_Physics;
		std::unique_ptr<TextureManager> m_TextureManager;
		std::unique_ptr<CameraManager> m_CameraManager;

		int currentScene = 0;
		std::vector<Scene*> Scenes;

		bool m_Running = true;
	};

	//To be defined by CLIENT
	Application* CreateApplication();
}


