#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "PhysicsComponent.h"

class GridCell
{
public:
	GridCell(float cellSize, sf::Vector2i index);
	virtual ~GridCell();
	sf::Vector2i getIndex();
	bool insert(std::shared_ptr<PhysicsComponent> component);
	void draw(sf::RenderWindow& window);

protected:
	float _cellSize;
	sf::Vector2i _index;
	std::vector<std::shared_ptr<PhysicsComponent>> _components;
	sf::RectangleShape _outline;
};

