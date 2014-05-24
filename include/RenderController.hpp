#ifndef __RENDERCONTROLLER_HPP
#define __RENDERCONTROLLER_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "Scene.hpp"

class Display;

class RenderController : public HasScene
{
private:
	Display *display;

	ALLEGRO_FONT *font;
	bool displayStats;

	bool frameRequested;
	
	float lastFps;
	int frameCounter;
	double frameCounterReset;
	double lastFrameDuration;

	void calculateFps();

public:
	RenderController(Display *display, bool displayStats, ALLEGRO_FONT *font = NULL);
	~RenderController();

	void requestFrame();
	void doRender();

	float getFps();
};

#endif