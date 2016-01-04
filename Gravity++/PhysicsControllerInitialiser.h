#pragma once
#include <SFML/Graphics.hpp>

struct PhysicsControllerInitialiser{
	sf::Vector2f velocity,	position;
	float mass, density;
};