#ifndef __HASEVENTS_HPP
#define __HASEVENTS_HPP

#include <allegro5/allegro.h>

class GameLoop;

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