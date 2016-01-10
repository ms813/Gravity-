#include "EventListener.h"
#include "ComponentEvent.h"
#include "PhysicsComponent.h"

template <class EventType>
EventListener<EventType>::EventListener()
{
}

template <class EventType>
EventListener<EventType>::~EventListener()
{
}

template class EventListener<ComponentEvent<PhysicsComponent>>;