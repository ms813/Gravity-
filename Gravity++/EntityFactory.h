#pragma once
#include "Entity.h"

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();
	std::shared_ptr<Entity> createEntity(std::string entityType);
};

