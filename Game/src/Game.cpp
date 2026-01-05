#include "Quaternion.h"

class ExampleScene : public QUA::Scene
{
public:
	ExampleScene()
		: Scene("Example")
	{

	}

	void OnUpdate() override
	{
		
	}

private:


};

class Game : public QUA::Application
{
public:
	Game()
	{
		addScene(new ExampleScene());
	}

	~Game()
	{

	}

};

QUA::Application* QUA::CreateApplication()
{
	return new Game();
}
