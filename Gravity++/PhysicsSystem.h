#pragma once
#include <vector>
#include <memory>

#include "EventListener.h"
#include "PhysicsComponent.h"
#include "ComponentEvent.h"

class PhysicsSystem : public EventListener<ComponentEvent<PhysicsComponent>>
{
public:
	PhysicsSystem();
	~PhysicsSystem();
	bool update(const float dt, const bool VERLET_STATE);
	void handleEvent(ComponentEvent<PhysicsComponent> event) override;

private:
	bool _registerComponent(std::shared_ptr<PhysicsComponent> component);
	bool _deregisterComponent(std::shared_ptr<PhysicsComponent> component);
	std::vector<std::shared_ptr<PhysicsComponent>> _physicsComponents;
};

