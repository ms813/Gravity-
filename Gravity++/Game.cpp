#include "Game.h"
#include <Windows.h>

Game::Game(){}

Game::~Game(){}

// starts the game loop running
int Game::run()
{
	//get the size of the primary monitor
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	sf::RenderWindow window(sf::VideoMode(screenWidth / 2, screenHeight / 2), "Gravity++");
	window.setFramerateLimit(60);

	sf::Clock clock;

	Scene scene;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		scene.handleInput(window);

		scene.update(dt);

		window.clear();
		scene.draw(window);
		window.display();
	}
	return 0;
}
