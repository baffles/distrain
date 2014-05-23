#include <stdexcept>
#include <allegro5/allegro.h>
#include "HasEvents.hpp"
#include "GameLoop.hpp"

using namespace std;

HasEvents::HasEvents(): loop(NULL), eventSource(NULL)
{
}

HasEvents::~HasEvents()
{
	if (loop)
		loop->unregisterHandler(this);
}

void HasEvents::registerWith(GameLoop *loop)
{
	if (this->loop)
		throw runtime_error("attempted to register event source multiple times");

	this->loop = loop;
	loop->registerHandler(this);
}

ALLEGRO_EVENT_SOURCE *HasEvents::getEventSource()
{
	if (!eventSource)
		eventSource = createEventSource();

	return eventSource;
}