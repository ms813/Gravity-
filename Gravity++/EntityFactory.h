#pragma once
#include "Entity.h"
#include "EventEmitter.h"

class EntityFactory : public EventEmitter
{
public:
	EntityFactory();
	~EntityFactory();
	std::shared_ptr<Entity> createEntity(std::string entityType);
};

