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
	void buildEntity(std::string entityType, std::shared_ptr<Entity> entity);
};

