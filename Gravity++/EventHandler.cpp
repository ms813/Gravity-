#include "EventHandler.h"
#include <iostream>
#include <assert.h>

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
		emitter->setEventHandler(this);
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
	std::cout << "EventHandler received an event" << std::endl;
	_events.push(event);
	return true;
}


void EventHandler::update(const float dt)
{	
	
	while (!_events.empty())
	{
		
		Event e = _events.front();
		
		std::cout << &e << std::endl;
		
		for (int i = 0; i < _eventEmitters.size(); i++)
		{
			std::cout << "Processing event " << i+1 << " in queue" << std::endl;
			assert(_eventEmitters[i]);
			_eventEmitters[i]->handleEvent(e);
		}

		_events.pop();
	}
}

