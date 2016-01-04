#include "EventEmitter.h"
#include "EventHandler.h"

EventEmitter::EventEmitter()
{
}


EventEmitter::~EventEmitter()
{
}

bool EventEmitter::handleEvent(Event event)
{
	return false;
}

bool EventEmitter::emitEvent(Event event)
{		
	return _eventHandler->receiveEvent(event);
}


bool EventEmitter::setEventHandler(EventHandler* handler)
{
	return _eventHandler = handler;
}
