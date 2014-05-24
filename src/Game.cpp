#include <stdexcept>
#include <allegro5/allegro.h>
#include "Game.hpp"
#include "ResourceManager.hpp"
#include "GameLoop.hpp"
#include "GameTimer.hpp"
#include "Display.hpp"
#include "LogicManager.hpp"
#include "RenderController.hpp"

#include "Character.hpp"
#include "TestScene.hpp"

using namespace std;

Game::Game()
{
	if (!al_init())
		throw runtime_error("failed to initialize allegro");

	resourceManager = new ResourceManager();

	display = new Display(640, 480, "Distrain - BAF's SpeedHack 2014 Entry");

	logicManager = new LogicManager();
	renderer = new RenderController(display, true, resourceManager->getFontManager()->getBuiltinFont());
	loop = new GameLoop(logicManager, renderer);

	timer = new GameTimer(renderer, 30);

	display->registerWith(loop);
	timer->registerWith(loop);

	Character *ch = new Character(new CharacterResources(resourceManager->getImageManager()));
	scene = new TestScene(ch);
	logicManager->setScene(scene);
	renderer->setScene(scene);
}

Game::~Game()
{
	delete resourceManager;
	delete logicManager;
	delete renderer;
	delete display;
	delete timer;
	delete loop;

	delete scene;
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