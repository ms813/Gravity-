#include "EventEmitter.h"
#include "EventHandler.h"

template <class EventType>
EventEmitter::EventEmitter()
{
}

template <class EventType>
EventEmitter::~EventEmitter()
{
}

template <class EventType>
bool EventEmitter::handleEvent(std::shared_ptr<EventType> event)
{
	return false;
}

template <class EventType>
bool EventEmitter::emitEvent(EventType event)
{		
	return _eventHandler->receiveEvent(event);
}

template <class EventType>
bool EventEmitter::setEventHandler(EventHandler* handler)
{
	return _eventHandler = handler;
}
