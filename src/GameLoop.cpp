#include <stdexcept>
#include <iostream>
#include <allegro5/allegro.h>
#include "GameLoop.hpp"
#include "LogicManager.hpp"
#include "RenderController.hpp"

using namespace std;

GameLoop::GameLoop(LogicManager *logicManager, RenderController *renderer) : logicManager(logicManager), renderer(renderer), alive(false)
{
	eventQueue = al_create_event_queue();
	if (!eventQueue)
		throw runtime_error("failed to create event queue");
}

GameLoop::~GameLoop()
{
	al_destroy_event_queue(eventQueue);
}

void GameLoop::registerHandler(HasEvents *handler)
{
	ALLEGRO_EVENT_SOURCE *src = handler->getEventSource();

	if (findHandler(src) != NULL)
		throw runtime_error("duplicate event source");

	eventHandlers[src] = handler;
	al_register_event_source(eventQueue, src);
}

void GameLoop::unregisterHandler(HasEvents *handler)
{
	ALLEGRO_EVENT_SOURCE *src = handler->getEventSource();
	al_unregister_event_source(eventQueue, src);
	eventHandlers.erase(src);
}

HasEvents *GameLoop::findHandler(ALLEGRO_EVENT_SOURCE *src)
{
	auto entry = eventHandlers.find(src);

	if (entry == eventHandlers.end())
		return NULL;

	return entry->second;
}

bool GameLoop::isIdle()
{
	return al_is_event_queue_empty(eventQueue);
}

void GameLoop::run()
{
	alive = true;

	ALLEGRO_EVENT event;

	while (alive)
	{
		al_wait_for_event(eventQueue, &event);

		auto handler = findHandler(event.any.source);

		if (handler != NULL)
			handler->handleEvent(this, event);
		else
			cerr << "unknown event " << event.type << endl;

		logicManager->tick();

		if (isIdle())
			renderer->doRender();
	}
}

void GameLoop::kill()
{
	alive = false;
}



HasEvents::HasEvents() : loop(NULL), eventSource(NULL)
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