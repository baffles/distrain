#ifndef __GAMETIMER_HPP
#define __GAMETIMER_HPP

#include <allegro5/allegro.h>
#include "GameLoop.hpp"

class RenderController;

class GameTimer : public HasEvents
{
private:
	RenderController *renderer;
	ALLEGRO_TIMER *timer;

protected:
	ALLEGRO_EVENT_SOURCE *createEventSource();

public:
	GameTimer(RenderController *renderer, int fpsTarget);
	~GameTimer();

	void start();
	void stop();

	void handleEvent(GameLoop *loop, const ALLEGRO_EVENT &event);
};

#endif