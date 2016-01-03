#include "Scene.h"

Scene::Scene()
{
	Entity* entity = new Entity();		
	entity->addComponent(new PhysicsController());
	entities.push_back(entity);	
}


Scene::~Scene()
{
}


bool Scene::draw(sf::RenderWindow *window)
{		
	for (auto &entity : entities)
	{
		entity->draw(window);
	}

	return true;
}


bool Scene::update(const float dt, const bool VERLET_STATE)
{
	for (auto &entity : entities){
		entity->update(dt, VERLET_STATE);
	}
	return true;
}

bool Scene::handleInput(sf::RenderWindow *window)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}

	return true;
}
