#pragma once
#include "ComponentEventAction.h"
#include <memory>

template <class ComponentType>
struct ComponentEvent
{
	ComponentEvent(std::shared_ptr<ComponentType> component, ComponentEventAction action);
	~ComponentEvent();
	
	std::shared_ptr<ComponentType> _component;
	ComponentEventAction _action;
};

