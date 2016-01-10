#include "ComponentEvent.h"
#include "PhysicsComponent.h"

template <class ComponentType>
ComponentEvent<ComponentType>::ComponentEvent(std::shared_ptr<ComponentType> component, ComponentEventAction action):
_component(component),
_action(action)
{
}

template <class ComponentType>
ComponentEvent<ComponentType>::~ComponentEvent()
{
}

template class ComponentEvent<PhysicsComponent>;