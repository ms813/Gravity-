#pragma once
#include "Entity.h"
#include "PhysicsControllerInitialiser.h"

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();
	std::shared_ptr<Entity> createEntity(std::string entityType);
};

