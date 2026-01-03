#include "Quaternion.h"

class Game : public QUA::Application
{
public:
	Game()
	{
		
	}

	~Game()
	{

	}

};

QUA::Application* QUA::CreateApplication()
{
	return new Game();
}
