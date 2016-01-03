#pragma once
#include "Component.h"

class PhysicsController : public Component
{
public:
	PhysicsController();
	~PhysicsController();

	bool update(const float dt, const bool VERLET_STATE) override;
	bool draw(sf::RenderWindow *window) override;		
};

