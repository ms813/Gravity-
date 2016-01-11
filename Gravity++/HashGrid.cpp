#include "HashGrid.h"
#include "GridCell.h"
#include "GravityGridCell.h"
#include "PhysicsComponent.h"

#include <math.h>

template <class CellType>
HashGrid<CellType>::HashGrid(float cellSize) : 
_cellSize(cellSize)
{
}

template <class CellType>
HashGrid<CellType>::~HashGrid()
{
}

//this gets indices for gravity grid (i.e. each component should be in only 1 cell at a time)
std::vector<sf::Vector2i> HashGrid<GravityGridCell>::_getComponentIndices(std::shared_ptr<PhysicsComponent> component)
{
	int col = (int) floor((component->getPosition().x + component->getSize().x / 2) / _cellSize);
	int row = (int) floor((component->getPosition().y + component->getSize().y / 2) / _cellSize);

	std::vector<sf::Vector2i> indices;
	indices.push_back(sf::Vector2i(row, col));
	return indices;
}

//this gets indices for the collision grid (i.e. components can be in multiple cells at a time)
std::vector<sf::Vector2i> HashGrid<GridCell>::_getComponentIndices(std::shared_ptr<PhysicsComponent> component)
{
	std::vector<sf::Vector2i> indices;
	return indices;
}

template <class CellType>
bool HashGrid<CellType>::insert(std::shared_ptr<PhysicsComponent> component)
{
	std::vector<sf::Vector2i> cellIndices = _getComponentIndices(component);

	bool cellExists = false;;
	for (auto &index : cellIndices)
	{
		for (CellType &cell : _cells)
		{
			if (cell.getIndex() == index)
			{
				cell.insert(component);
				cellExists = true;
			}
		}		

		if (!cellExists)
		{
			_cells.push_back(CellType(_cellSize, index));
		}
	}

	return true;
}

template <class CellType>
void HashGrid<CellType>::draw(sf::RenderWindow& window)
{
	for (CellType &cell : _cells)
	{
		cell.draw(window);		
	}
}

template <class CellType>
void HashGrid<CellType>::clear()
{
	_cells.clear();
}

template class HashGrid<GridCell>;
template class HashGrid<GravityGridCell>;
