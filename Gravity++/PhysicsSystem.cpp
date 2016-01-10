#include "PhysicsSystem.h"


PhysicsSystem::PhysicsSystem()
{
}


PhysicsSystem::~PhysicsSystem()
{
}


bool PhysicsSystem::update(const float dt, const bool VERLET_STATE)
{
	return false;
}


bool PhysicsSystem::_deregisterComponent(std::shared_ptr<PhysicsComponent> component)
{
	return true;
}


bool PhysicsSystem::_registerComponent(std::shared_ptr<PhysicsComponent> component)
{
	_physicsComponents.push_back(component);
	return true;
}

void PhysicsSystem::handleEvent(ComponentEvent<PhysicsComponent> event)
{
	if (event._action == ComponentEventAction::CREATED)
	{
		std::cout << "Adding physics component to physics system list" << std::endl;
		_registerComponent(event._component);
	}
}