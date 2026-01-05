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

struct Transform { Vec2 pos{}; };

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

	void Game::Run()
	{
		QUA::Registry reg;

		QUA::Entity player = reg.create();
		reg.emplace<Transform>(player, Vec2{ 200, 500 });

		QUA::Camera2D camera;

		auto testImage = m_TextureManager->load("resources/testImage.png");

		auto world = m_Physics->createWorld({ 0.0f, -10.f });


		Vec2 groundBodyPos = { 400, 400 };
		Vec2 groundBodySize = { 500, 20 };

		QUA::BodyDef ground{};
		ground.type = QUA::BodyType::Static;
		ground.position = groundBodyPos;

		auto groundBody = m_Physics->createBody(world, ground);
		m_Physics->setAsBox(groundBody, groundBodySize, QUA::ShapeProps{ 0.5f, 0.0f, 0.0f }, false);



		//Vec2 bodyPos = { 500, 600 };
		Vec2 bodySize = { 50, 50 };

		QUA::BodyDef box{};
		box.type = QUA::BodyType::Dynamic;
		box.position = reg.get<Transform>(player).pos;

		auto body = m_Physics->createBody(world, box);
		m_Physics->setAsBox(body, bodySize, QUA::ShapeProps{ 0.3f, 0.4f, 1.f }, false);


		Vec2 myForce = { 0, 20000 };
		Vec2 left = { -20, 0 };
		Vec2 right = { 20, 0 };
		Vec2 Up = { 0, 20 };


		while (m_Window->IsWindowRunning())
		{
			//Scenes[currentScene]->OnUpdate();

			m_Physics->step(world, 1.0f / 60.0f, 8, 3);

			if (m_Input->KeyDown(QUA::Key::Up))
			{
				m_Physics->setLinearVelocity(body, Up);
			}
			if (m_Input->KeyDown(QUA::Key::Left))
			{
				m_Physics->setLinearVelocity(body, left);
			}
			if (m_Input->KeyDown(QUA::Key::Right))
			{
				m_Physics->setLinearVelocity(body, right);
			}

			if (m_Input->KeyDown(QUA::Key::W))
			{
				camera.setPos(Vec2{ camera.getPos().x + 1, camera.getPos().y });
			}
			if (m_Input->KeyDown(QUA::Key::A))
			{
				camera.setPos(Vec2{ camera.getPos().x, camera.getPos().y - 1 });
			}
			if (m_Input->KeyDown(QUA::Key::D))
			{
				camera.setPos(Vec2{ camera.getPos().x, camera.getPos().y + 1 });
			}
			if (m_Input->KeyDown(QUA::Key::S))
			{
				camera.setPos(Vec2{ camera.getPos().x - 1, camera.getPos().y });
			}


			if (m_Input->MouseButtonPressed(QUA::MouseButton::Left))
			{
				m_Window->SetBackgroundColour({ 0.9, 1, 0.9, 1 });
				m_Physics->applyLinearImpulseToCenter(body, myForce, true);
			}

			if (m_Input->MouseButtonReleased(QUA::MouseButton::Left))
			{
				m_Window->SetBackgroundColour({ 0.9, 0.9, 0.9, 1 });
			}

			m_Window->BeginFrame();

			m_CameraManager->startCamera(camera);

			m_Renderer->drawRect(Vec2{ groundBodyPos.x, groundBodyPos.y }, Vec2{ groundBodySize.x, groundBodySize.y }, { 0.1, 0.1, 0.1, 1 });

			m_TextureManager->drawTexture(testImage, Vec2{ m_Physics->getPosition(body).x, m_Physics->getPosition(body).y }, Vec2{ bodySize.x, bodySize.y },
				Vec2{ 0 , 0 }, Vec2{ 1 , 1 }, Vec2{ 0 , 0 }, m_Physics->getAngle(body), { 1, 1, 1, 1 });

			m_CameraManager->endCamera();

			m_Window->EndFrame();

		}
	}

};

QUA::Application* QUA::CreateApplication()
{
	return new Game();
}
