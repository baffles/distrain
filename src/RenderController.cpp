#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "RenderController.hpp"
#include "Display.hpp"
#include "Scene.hpp"

RenderController::RenderController(Display *display, bool displayStats, ALLEGRO_FONT *font) : display(display), currentScene(NULL), font(font), displayStats(displayStats), frameRequested(false), lastFps(0), frameCounter(0), frameCounterReset(al_get_time())
{
}

RenderController::~RenderController()
{
}

void RenderController::setScene(Scene *scene)
{
	currentScene = scene;
}

void RenderController::calculateFps()
{
	// update FPS every 500ms or so
	auto now = al_get_time();
	auto interval = now - frameCounterReset;
	if (interval >= 0.5)
	{
		lastFps = frameCounter / interval;

		frameCounter = 0;
		frameCounterReset = now;
	}
}

void RenderController::requestFrame()
{
	frameRequested = true;
}

void RenderController::doRender()
{
	if (frameRequested)
	{
		auto renderStart = al_get_time();

		display->setTarget();

		// RENDER

		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (currentScene != NULL)
			currentScene->render();

		if (displayStats && font != NULL)
		{
			static auto fontH = al_get_font_line_height(font);
			auto white = al_map_rgb(255, 255, 255);

			al_draw_textf(font, white, display->getW() - 5, 5, ALLEGRO_ALIGN_RIGHT, "FPS: %f", getFps());
			al_draw_textf(font, white, display->getW() - 5, fontH + 10, ALLEGRO_ALIGN_RIGHT, "Frame: %f ms", lastFrameDuration * 1000);
		}

		display->flip();

		lastFrameDuration = al_get_time() - renderStart;
		frameRequested = false;

		frameCounter++;
		calculateFps();
	}
}

float RenderController::getFps()
{
	return lastFps;
}