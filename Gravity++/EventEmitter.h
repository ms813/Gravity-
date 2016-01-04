#pragma once

#include "Event.h"
class EventHandler;

class EventEmitter
{
public:
	EventEmitter();
	virtual ~EventEmitter();
	virtual bool handleEvent(Event event);
	bool emitEvent(Event event);
	bool setEventHandler(EventHandler* handler);

private:
	EventHandler* _eventHandler;
};