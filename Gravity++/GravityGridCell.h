#pragma once
#include "GridCell.h"

class GravityGridCell :
	public GridCell
{
public:
	GravityGridCell(float cellSize, sf::Vector2i index);
	~GravityGridCell();
};

