#include "Entity.h"


Entity::Entity()
{
	shape.setRadius(10.0f);
	shape.setFillColor(sf::Color::Green);
}


Entity::~Entity()
{
}


int Entity::draw(sf::RenderWindow *window)
{
	window->draw(shape);
	return 0;
}


int Entity::update(float dt)
{
	return 0;
}
