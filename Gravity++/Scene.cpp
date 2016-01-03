#include "Scene.h"

Scene::Scene()
{
	entities.push_back(Entity());
}


Scene::~Scene()
{
}


int Scene::draw(sf::RenderWindow *window)
{	
	for (auto &entity : entities)
	{
		entity.draw(window);
	}
	return 0;
}


int Scene::update(float dt)
{
	return 0;
}

int Scene::handleInput(sf::RenderWindow *window)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}

	return 0;
}
