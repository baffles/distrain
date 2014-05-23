#include <stdexcept>
#include <allegro5/allegro.h>
#include "GameTimer.hpp"
#include "RenderController.hpp"

using namespace std;

GameTimer::GameTimer(RenderController *renderController, int fpsTarget) : renderer(renderController)
{
	timer = al_create_timer(1.0 / fpsTarget);
	if (!timer)
		throw runtime_error("failed to create timer");
}

GameTimer::~GameTimer()
{
	al_destroy_timer(timer);
}

void GameTimer::start()
{
	al_start_timer(timer);
}

void GameTimer::stop()
{
	al_stop_timer(timer);
}

ALLEGRO_EVENT_SOURCE *GameTimer::createEventSource()
{
	return al_get_timer_event_source(timer);
}

void GameTimer::handleEvent(GameLoop *loop, const ALLEGRO_EVENT &event)
{
	if (event.type == ALLEGRO_EVENT_TIMER)
		renderer->requestFrame();
}