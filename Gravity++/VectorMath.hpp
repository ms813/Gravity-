#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <sstream>

class VectorMath
{
public:
	VectorMath();
	~VectorMath();
	static sf::Vector2f normalize(const sf::Vector2f vector);
	static float magnitude(const sf::Vector2f vector);
	static float sumSquare(const sf::Vector2f vector);	

	//return a neat string to print using std::cout
	static std::string str(const sf::Vector2f vector);
};

