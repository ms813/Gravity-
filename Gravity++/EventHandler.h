#pragma once

#include <vector>
#include <queue>

#include "Event.h"
#include "EventEmitter.h"

class EventHandler
{
public:
	EventHandler();
	virtual ~EventHandler();
	bool registerEmitter(EventEmitter* emitter);
	bool deregisterEmitter(EventEmitter* emitter);
	bool receiveEvent(Event event);	
	void update(const float dt);

private:
	std::vector <EventEmitter*> _eventEmitters;
	std::queue <Event> _events;
};

