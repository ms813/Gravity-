#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

#include "Component.h"
#include "PhysicsComponent.h"

class Entity
{
public:
	Entity();
	~Entity();
	bool draw(sf::RenderWindow &window);
	bool update(const float dt, const bool VERLET_STATE);
	bool init();
	bool addComponent(std::shared_ptr<Component> component);	
	void move(sf::Vector2f offset);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f vector);

private:
	sf::CircleShape shape;
	std::vector<std::shared_ptr<Component>> components;
};