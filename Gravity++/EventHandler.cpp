#include "EventHandler.h"


EventHandler::EventHandler()
{
}


EventHandler::~EventHandler()
{
}


bool EventHandler::registerEmitter(EventEmitter* emitter)
{	
	// Does emitter already exist in emitter list?
	bool found = std::find(_eventEmitters.begin(), _eventEmitters.end(), emitter) != _eventEmitters.end();

	if (!found)
	{
		_eventEmitters.push_back(emitter);
	}

	return !found;
}


bool EventHandler::deregisterEmitter(EventEmitter* emitter)
{
	auto it = std::find(_eventEmitters.begin(), _eventEmitters.end(), emitter);
	if (it != _eventEmitters.end())
	{
		_eventEmitters.erase(it);
		return true;
	}
	return false;
}

bool EventHandler::receiveEvent(Event event)
{
	_events.push(event);
	return true;
}

bool EventHandler::handleEvents()
{
	Event event = _events.front();
	_events.pop();
	return false;
}
