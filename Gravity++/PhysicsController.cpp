#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(std::shared_ptr<Entity> owner, sf::Vector2f position, sf::Vector2f velocity, float mass, float density) :
Component(owner),
position(position),
velocity(velocity),
mass(mass),
density(density),
appliedForce(0,0)
{
}


PhysicsComponent::~PhysicsComponent()
{
}

bool PhysicsComponent::draw(sf::RenderWindow &window)
{
	return true;
}

bool PhysicsComponent::update(const float dt, const bool VERLET_STATE)
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

sf::Vector2f PhysicsComponent::calculatePositionChange(const float dt)
{
	acceleration = calculateAcceleration();

	//position += timestep * (velocity + timestep * acceleration /2)
	sf::Vector2f change = dt * (velocity + (dt * acceleration / 2.0f));
	
	return change;
}

sf::Vector2f PhysicsComponent::calculateVelocityChange(const float dt)
{
	sf::Vector2f newAcceleration = calculateAcceleration();

	//velocity += timestep * (acceleration + newAcceleration) / 2;
	return dt * (acceleration + newAcceleration) / 2.0f;
}

sf::Vector2f PhysicsComponent::calculateAcceleration()
{
	sf::Vector2f dir = VectorMath::normalize(appliedForce);	

	float F = VectorMath::magnitude(appliedForce);

	//F = ma, so a = F/m
	return dir * (F / mass);
}

void PhysicsComponent::applyForce(sf::Vector2f force)
{
	appliedForce += force;
}

sf::Vector2f PhysicsComponent::getPositionChange()
{		
	return positionChange;
}

sf::Vector2f PhysicsComponent::getPosition()
{
	return position;
}
