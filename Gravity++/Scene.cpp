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
