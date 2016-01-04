#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

#include "Component.h"
#include "PhysicsController.h"

class Entity
{
public:
	Entity();
	~Entity();
	bool draw(sf::RenderWindow &window);
	bool update(const float dt, const bool VERLET_STATE);
	bool init();
	bool addComponent(std::shared_ptr<Component> component);	

private:
	sf::CircleShape shape;
	std::vector<std::shared_ptr<Component>> components;

	PhysicsController* physicsController;
};

