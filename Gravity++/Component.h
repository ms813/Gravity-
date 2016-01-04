#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Entity;

class Component
{
public:
	Component();
	virtual ~Component();
	virtual bool draw(sf::RenderWindow &window) = 0;
	virtual bool update(const float dt, const bool VERLET_STATE) = 0;	

protected:
	Component(std::shared_ptr<Entity> owner);
	std::shared_ptr<Entity> owner;
};

