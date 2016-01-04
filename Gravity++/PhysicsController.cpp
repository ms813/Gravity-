#include "PhysicsController.h"

PhysicsController::PhysicsController():
position(100.0f, 0),
appliedForce(0,0),
velocity(10.0f,0)
{
}


PhysicsController::~PhysicsController()
{
}

bool PhysicsController::draw(sf::RenderWindow &window)
{
	return true;
}

bool PhysicsController::update(const float dt, const bool VERLET_STATE)
{	
	//Verlet method requires updating position and velocity in separate steps
	//see http://gamedev.stackexchange.com/questions/15708/how-can-i-implement-gravity

	if (VERLET_STATE)
	{
		positionChange = calculatePositionChange(dt);			
		position += positionChange;
	}
	else
	{
		velocityChange = calculateVelocityChange(dt);
		velocity += velocityChange;
	}

	return true;
}

sf::Vector2f PhysicsController::calculatePositionChange(const float dt)
{
	acceleration = calculateAcceleration();

	//position += timestep * (velocity + timestep * acceleration /2)
	sf::Vector2f change = dt * (velocity + (dt * acceleration / 2.0f));
	
	return change;
}

sf::Vector2f PhysicsController::calculateVelocityChange(const float dt)
{
	sf::Vector2f newAcceleration = calculateAcceleration();

	//velocity += timestep * (acceleration + newAcceleration) / 2;
	return dt * (acceleration + newAcceleration) / 2.0f;
}

sf::Vector2f PhysicsController::calculateAcceleration()
{
	sf::Vector2f dir = VectorMath::normalize(appliedForce);	

	float F = VectorMath::magnitude(appliedForce);

	//F = ma, so a = F/m
	return dir * (F / mass);
}

void PhysicsController::applyForce(sf::Vector2f force)
{
	appliedForce += force;
}

sf::Vector2f PhysicsController::getPositionChange()
{		
	return positionChange;
}

sf::Vector2f PhysicsController::getPosition()
{
	return position;
}
