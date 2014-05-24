#ifndef __GAMELOOP_HPP
#define __GAMELOOP_HPP

#include <allegro5/allegro.h>
#include <map>

class RenderController;
class HasEvents;

class GameLoop
{
private:
	RenderController *renderer;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	bool alive;

	std::map<ALLEGRO_EVENT_SOURCE*, HasEvents*> eventHandlers;

	HasEvents *findHandler(ALLEGRO_EVENT_SOURCE *src);

public:
	GameLoop(RenderController *garendererme);
	~GameLoop();

	void registerHandler(HasEvents *handler);
	void unregisterHandler(HasEvents *handler);

	bool isIdle();
	void run();
	void kill();
};

class HasEvents
{
private:
	GameLoop *loop;
	ALLEGRO_EVENT_SOURCE *eventSource;

protected:
	HasEvents();
	~HasEvents();

	virtual ALLEGRO_EVENT_SOURCE *createEventSource() = 0;

public:
	void registerWith(GameLoop *loop);
	ALLEGRO_EVENT_SOURCE *getEventSource();
	virtual void handleEvent(GameLoop *loop, const ALLEGRO_EVENT &event) = 0;
};

#endif