#include "PhysicsSystem.h"


PhysicsSystem::PhysicsSystem() :
_gravityGrid(50)
{
}


PhysicsSystem::~PhysicsSystem()
{
}


bool PhysicsSystem::update(const float dt, const bool VERLET_STATE)
{
	_gravityGrid.clear();
	for (auto &comp : _physicsComponents)
	{
		_gravityGrid.insert(comp);
	}
	
	std::cout << "Something fishy! PhysicsSystem._physicsComponents.size() = " <<_physicsComponents.size() << std::endl;
	return true;
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