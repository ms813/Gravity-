#pragma once
#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>

class PhysicsComponent;

template <class CellType>
class HashGrid
{
public:
	HashGrid(float cellSize);
	~HashGrid();	
	bool insert(std::shared_ptr<PhysicsComponent> component);
	void draw(sf::RenderWindow& window);
	void clear();

private:
	std::vector<sf::Vector2i> _getComponentIndices(std::shared_ptr<PhysicsComponent> component);
	std::vector<CellType> _cells;
	float _cellSize;
};

