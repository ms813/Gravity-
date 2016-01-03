#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	~Entity();
	int draw(sf::RenderWindow *window);
	int update(float dt);

private:
	sf::CircleShape shape;
};

