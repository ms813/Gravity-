#include "VectorMath.h"

VectorMath::VectorMath()
{
}


VectorMath::~VectorMath()
{
}


sf::Vector2f VectorMath::normalize(const sf::Vector2f vector)
{		
	if (magnitude(vector) <= 0)
	{
		return sf::Vector2f(0, 0);
	}
	else
	{
		return vector / magnitude(vector);
	}
}

float VectorMath::magnitude(const sf::Vector2f vector)
{	
	return std::sqrt(sumSquare(vector));
}

float VectorMath::sumSquare(const sf::Vector2f vector)
{	
	float pow = std::pow(vector.x, 2) + std::pow(vector.y, 2);
	return pow;
}

std::string VectorMath::str(const sf::Vector2f vector)
{
	std::stringstream ss;
	ss << "(" << vector.x << ", " << vector.y << ")";
	return ss.str();
}
