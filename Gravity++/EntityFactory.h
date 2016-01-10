#pragma once
#include "Entity.h"
#include "EventBroadcaster.h"
#include "ComponentEvent.h"

template class ComponentEvent<PhysicsComponent>;

class EntityFactory : public EventBroadcaster<ComponentEvent<PhysicsComponent>>
{
public:
	EntityFactory();
	~EntityFactory();
	std::shared_ptr<Entity> createEntity(std::string entityType);
};

