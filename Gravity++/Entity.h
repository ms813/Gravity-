#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Component.h"
#include "PhysicsController.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
	bool draw(sf::RenderWindow &window);
	bool update(const float dt, const bool VERLET_STATE);
	bool init();
	bool addComponent(Component *component);	

private:
	sf::CircleShape shape;
	std::vector<Component*> components;

	PhysicsController* physicsController;
};

