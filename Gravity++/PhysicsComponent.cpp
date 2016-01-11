#include "PhysicsComponent.h"
#include "Entity.h"
#define _USE_MATH_DEFINES
#include <math.h>


PhysicsComponent::PhysicsComponent(std::shared_ptr<Entity> owner, sf::Vector2f position, sf::Vector2f velocity, float mass, float density) :
Component(owner),
_position(position),
_velocity(velocity),
_mass(mass),
_density(density),
_appliedForce(0,0)
{

	//mass of a sphere = 4/3 * pi * r^3 * density
	// r = ((3 * mass) / (4 * pi * density))^(1/3)
	float r = cbrt((3 * _mass) / (4 * M_PI * _density));
	owner->setPosition(_position);

	_size = sf::Vector2f(2 * r, 2 * r);
	owner->setSize(_size);

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
		_positionChange = _calculatePositionChange(dt);	
		owner->move(_positionChange);
	}
	else
	{
		_velocityChange = _calculateVelocityChange(dt);
		_velocity += _velocityChange;
	}

	return true;
}

sf::Vector2f PhysicsComponent::_calculatePositionChange(const float dt)
{
	_acceleration = _calculateAcceleration();

	//position += timestep * (velocity + timestep * acceleration /2)
	sf::Vector2f change = dt * (_velocity + (dt * _acceleration / 2.0f));
	
	return change;
}

sf::Vector2f PhysicsComponent::_calculateVelocityChange(const float dt)
{
	sf::Vector2f newAcceleration = _calculateAcceleration();

	//velocity += timestep * (acceleration + newAcceleration) / 2;
	return dt * (_acceleration + newAcceleration) / 2.0f;
}

sf::Vector2f PhysicsComponent::_calculateAcceleration()
{
	sf::Vector2f dir = VectorMath::normalize(_appliedForce);	

	float F = VectorMath::magnitude(_appliedForce);

	//F = ma, so a = F/m
	return dir * (F / _mass);
}

void PhysicsComponent::applyForce(sf::Vector2f force)
{
	_appliedForce += force;
}

sf::Vector2f PhysicsComponent::getPositionChange()
{		
	return _positionChange;
}

sf::Vector2f PhysicsComponent::getPosition()
{
	return getPosition();
}

sf::Vector2f PhysicsComponent::getSize()
{
	return _size;
}