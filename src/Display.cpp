#include <stdexcept>
#include <allegro5/allegro.h>
#include "Display.hpp"
#include "GameLoop.hpp"

using namespace std;

Display::Display(int w, int h, string title) : w(w), h(h)
{
	display = al_create_display(w, h);
	if (!display)
		throw runtime_error("failed to create display");

	al_set_window_title(display, title.c_str());
}

Display::~Display()
{
	al_destroy_display(display);
}

ALLEGRO_DISPLAY *Display::getAllegroDisplay()
{
	return display;
}

ALLEGRO_EVENT_SOURCE *Display::createEventSource()
{
	return al_get_display_event_source(display);
}

void Display::handleEvent(GameLoop *loop, const ALLEGRO_EVENT &event)
{
	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		loop->kill();
}

int Display::getW()
{
	return w;
}

int Display::getH()
{
	return h;
}

void Display::setTarget()
{
	al_set_target_backbuffer(display);
}

void Display::flip()
{
	al_flip_display();
}