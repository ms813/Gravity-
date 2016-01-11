#pragma once
#include "Component.h"
#include "VectorMath.h"
#include <queue>
#include <iostream>
#include <memory>

class PhysicsComponent : public Component
{

public:
	PhysicsComponent(
		std::shared_ptr<Entity> owner,
		sf::Vector2f position,
		sf::Vector2f velocity,
		float mass,
		float density
		);
	~PhysicsComponent();

	bool update(const float dt, const bool VERLET_STATE) override;
	bool draw(sf::RenderWindow &window) override;
	
	void applyForce(sf::Vector2f force);

	//these methods are used in the Verlet velocity algorithm
	

	//getters & setters
	sf::Vector2f getPositionChange();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();

private:
	sf::Vector2f _calculateAcceleration();
	sf::Vector2f _calculatePositionChange(const float dt);
	sf::Vector2f _calculateVelocityChange(const float dt);

	sf::Vector2f _position;
	sf::Vector2f _size;
	sf::Vector2f _positionChange;
	sf::Vector2f _velocity;
	sf::Vector2f _velocityChange;
	sf::Vector2f _appliedForce;
	sf::Vector2f _acceleration;

	float _mass;
	float _density;		
};

