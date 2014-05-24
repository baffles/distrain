#ifndef __DISPLAY_HPP
#define __DISPLAY_HPP

#include <string>
#include <allegro5/allegro.h>
#include "GameLoop.hpp"

class Display : public HasEvents
{
private:
	int w, h;
	ALLEGRO_DISPLAY *display;

protected:
	ALLEGRO_EVENT_SOURCE *createEventSource();

public:
	Display(int w, int h, std::string title);
	~Display();

	ALLEGRO_DISPLAY *getAllegroDisplay();
	void handleEvent(GameLoop *loop, const ALLEGRO_EVENT &event);

	int getW() const;
	int getH() const;

	void setTarget();
	void flip();
};

#endif