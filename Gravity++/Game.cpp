#include "Game.h"

Game::Game(){}

Game::~Game(){}

// starts the game loop running
int Game::run()
{

	sf::RenderWindow window(sf::VideoMode(200, 200), "Gravity++");
	window.setFramerateLimit(60);
	sf::CircleShape shape(100.0f);

	sf::Clock clock;

	Scene scene;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		scene.handleInput(&window);

		scene.update(dt, true);

		window.clear();
		scene.draw(&window);
		window.display();
	}
	return 0;
}
