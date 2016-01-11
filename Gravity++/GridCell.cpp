#include "GridCell.h"

GridCell::GridCell(float cellSize, sf::Vector2i index) : 
_cellSize(cellSize),
_index(index)
{
	_outline.setPosition(sf::Vector2f(_index) * _cellSize);
	_outline.setFillColor(sf::Color::Transparent);
	_outline.setOutlineColor(sf::Color::Green);
	_outline.setOutlineThickness(-1.0f);
	_outline.setSize(sf::Vector2f(_cellSize, _cellSize));
}


GridCell::~GridCell()
{
}


sf::Vector2i GridCell::getIndex()
{
	return _index;
}


bool GridCell::insert(std::shared_ptr<PhysicsComponent> component)
{
	_components.push_back(component);
	return true;
}


void GridCell::draw(sf::RenderWindow& window)
{
	window.draw(_outline);
}
