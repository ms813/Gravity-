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
		PhysicsControllerInitialiser physParameters;
		physParameters.density = 5;
		physParameters.mass = 10000;
		physParameters.position = sf::Vector2f(200, 200);
		physParameters.velocity = sf::Vector2f(50, 0);		

		auto physControl = std::make_shared<PhysicsController>();		
		physControl->init(physParameters);

		entity->addComponent(physControl);		
	}

	entity->init();
	return entity;
}
