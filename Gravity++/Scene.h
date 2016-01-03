#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"

class Scene
{
public:
	Scene();
	~Scene();
	int draw(sf::RenderWindow *window);
	int update(float dt);
private:
	std::vector<Entity> entities;
};

