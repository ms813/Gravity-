#pragma once

template <class EventType>
class EventListener
{
public:
	EventListener();
	virtual ~EventListener();
	virtual void handleEvent(EventType event) = 0;
};

