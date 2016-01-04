#pragma once
#include "Component.h"
#include "VectorMath.h"
#include <queue>
#include <iostream>

class PhysicsController : public Component
{
public:
	PhysicsController();
	~PhysicsController();

	bool update(const float dt, const bool VERLET_STATE) override;
	bool draw(sf::RenderWindow *window) override;		
	
	void applyForce(sf::Vector2f force);

	//these methods are used in the Verlet velocity algorithm
	sf::Vector2f calculatePositionChange(const float dt);
	sf::Vector2f calculateVelocityChange(const float dt);

	//getters & setters
	sf::Vector2f getPositionChange();
	sf::Vector2f getPosition();

private:
	sf::Vector2f calculateAcceleration();

	sf::Vector2f position;
	sf::Vector2f positionChange;
	sf::Vector2f velocity;
	sf::Vector2f velocityChange;
	sf::Vector2f appliedForce;
	sf::Vector2f acceleration;

	float mass;
	float density;		
};

