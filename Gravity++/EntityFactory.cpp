#include "EntityFactory.h"


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
		sf::Vector2f pos(200, 200);
		sf::Vector2f vel(50, 0);

		auto physControl = std::make_shared<PhysicsComponent>(entity, pos, vel, mass, density);
		Event evt;
		emitEvent(evt);

		entity->addComponent(physControl);		
	}

	entity->init();
	return entity;
}