#include "Entity.h"

Entity::Entity()
{
	shape.setRadius(10.0f);
	shape.setFillColor(sf::Color::Green);
}


Entity::~Entity()
{
}

bool Entity::init()
{
	shape.setPosition(physicsController->getPosition());
	return true;
}


bool Entity::draw(sf::RenderWindow &window)
{
	window.draw(shape);

	for (auto &component : components)
	{
		component->draw(window);
	}

	return true;
}

bool Entity::update(const float dt, const bool VERLET_STATE)
{		
	sf::Vector2f offset = physicsController->getPositionChange();	
	shape.move(offset);

	for (auto &component : components)
	{
		component->update(dt, VERLET_STATE);
	}

	return true;
}


bool Entity::addComponent(Component* component)
{	
	bool found = std::find(components.begin(), components.end(), component) != components.end();
	
	if (!found)
	{
		components.push_back(component);		
		std::cout << "[Entity.addComponent()] Component added " << component << std::endl;

		//cache the physics controller
		if (dynamic_cast<PhysicsController*>(component) != NULL)
		{
			physicsController = dynamic_cast<PhysicsController*>(component);
			std::cout << "Cached the physics controller" << std::endl;
		}
	}
	else
	{
		std::cout << "[Entity.addComponent()] Error, trying to add component that is already on this entity" << std::endl;
	}
	
	return true;
}
