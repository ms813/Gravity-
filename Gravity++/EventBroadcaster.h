#pragma once
#include "EventListener.h"
#include <memory>
#include <vector>

template <class EventType>
class EventBroadcaster
{
public:
	typedef std::shared_ptr<EventListener<EventType>> ListenerPtr;
	EventBroadcaster();
	virtual ~EventBroadcaster();
	bool deregisterListener(ListenerPtr listener);
	bool registerListener(ListenerPtr listener);
	bool broadcastEvent(EventType event);

private:	
	std::vector<ListenerPtr> _listeners;
};

