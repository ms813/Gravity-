#include "EntityFactory.h"
#include "ComponentEvent.h"
#include "ComponentEventAction.h"
#include "PhysicsComponent.h"

EntityFactory::EntityFactory()
{
}


EntityFactory::~EntityFactory()
{
}


std::shared_ptr<Entity> EntityFactory::createEntity(std::string entityType)
{
	auto entity = std::make_shared<Entity>();	
	if (entityType == "asteroid")
	{
	
		float density = 5;
		float mass = 10000;		
		sf::Vector2<float> pos(200, 200);
		sf::Vector2f vel(50, 0);

		std::shared_ptr<PhysicsComponent> physicsComponent = std::make_shared<PhysicsComponent>(entity, pos, vel, mass, density);					
		ComponentEvent<PhysicsComponent> evt(physicsComponent, ComponentEventAction::CREATED);
		broadcastEvent(evt);
		entity->addComponent(physicsComponent);
	}	

	entity->init();
	return entity;
}