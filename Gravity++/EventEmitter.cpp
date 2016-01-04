#include "EventEmitter.h"

EventEmitter::EventEmitter(const EventHandler& eventHandler) :
_eventHandler(eventHandler)
{
}


EventEmitter::~EventEmitter()
{
}


bool EventEmitter::handleEvent(const Event& event)
{
	return false;
}
