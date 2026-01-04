#include "Quaternion.h"
#include "Quaternion/Input.h"

class Game : public QUA::Application
{
public:
	Game()
	{
		
	}

	~Game()
	{

	}

	/*void Game::Run()
	{
		
	}*/

};

QUA::Application* QUA::CreateApplication()
{
	return new Game();
}
