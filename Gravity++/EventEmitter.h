#pragma once

#include "Event.h"
class EventHandler;

class EventEmitter
{
public:
	EventEmitter(const EventHandler& eventHandler);
	virtual ~EventEmitter();
	bool handleEvent(const Event& event);
	bool emitEvent(const Event& event);
private:
	const EventHandler& _eventHandler;
};