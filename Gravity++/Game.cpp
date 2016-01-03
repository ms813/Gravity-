#include "Game.h"




// starts the game loop running
int Game::run()
{

	sf::RenderWindow window(sf::VideoMode(200, 200), "Gravity++");
	sf::CircleShape shape(100.0f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
