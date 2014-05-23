#include <stdexcept>
#include <allegro5/allegro.h>
#include "Game.hpp"
#include "ResourceManager.hpp"
#include "FontManager.hpp"
#include "GameLoop.hpp"
#include "GameTimer.hpp"
#include "Display.hpp"
#include "RenderController.hpp"

using namespace std;

Game::Game()
{
	if (!al_init())
		throw runtime_error("failed to initialize allegro");

	resourceManager = new ResourceManager();

	display = new Display(640, 480, "Distrain - BAF's SpeedHack 2014 Entry");
	
	renderer = new RenderController(display, true, resourceManager->getFontManager()->getBuiltinFont());
	loop = new GameLoop(renderer);

	timer = new GameTimer(renderer, 30);

	display->registerWith(loop);
	timer->registerWith(loop);
}

Game::~Game()
{
	delete resourceManager;
	delete renderer;
	delete display;
	delete timer;
	delete loop;
}

void Game::run()
{
	timer->start();
	loop->run();
	timer->stop();
}

ResourceManager *Game::getResourceManager()
{
	return resourceManager;
}

Display *Game::getDisplay()
{
	return display;
}

RenderController *Game::getRenderer()
{
	return renderer;
}

GameLoop *Game::getLoop()
{
	return loop;
}