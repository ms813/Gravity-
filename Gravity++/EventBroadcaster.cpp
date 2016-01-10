#include "EventBroadcaster.h"
#include "ComponentEvent.h"
#include "PhysicsComponent.h"

template <class EventType>
EventBroadcaster<EventType>::EventBroadcaster()
{
}

template <class EventType>
EventBroadcaster<EventType>::~EventBroadcaster()
{
}

template <class EventType>
bool EventBroadcaster<EventType>::deregisterListener(std::shared_ptr<EventListener<EventType>>listener)
{
	return false;
}

template <class EventType>
bool EventBroadcaster<EventType>::registerListener(std::shared_ptr<EventListener<EventType>> listener)
{
	_listeners.push_back(listener);
	return false;
}

template <class EventType>
bool EventBroadcaster<EventType>::broadcastEvent(EventType event)
{
	for (auto &listener : _listeners)
	{
		listener->handleEvent(event);
	}

	return true;
}

template class EventBroadcaster<ComponentEvent<PhysicsComponent>>;