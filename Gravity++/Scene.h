#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.h"
#include "PhysicsController.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();
	bool draw(sf::RenderWindow *window);
	bool update(const float dt);
	bool handleInput(sf::RenderWindow *window);

private:
	std::vector<Entity*> entities;
	bool VERLET_STATE;
};

