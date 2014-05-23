#ifndef __RENDERCONTROLLER_HPP
#define __RENDERCONTROLLER_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Display;
class Scene;

class RenderController
{
private:
	Display *display;
	Scene *currentScene;

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

	void setScene(Scene *scene);

	void requestFrame();
	void doRender();

	float getFps();
};

#endif