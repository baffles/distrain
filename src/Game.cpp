#include <stdexcept>
#include <allegro5/allegro.h>
#include "Game.hpp"
#include "ResourceManager.hpp"
#include "GameLoop.hpp"
#include "GameTimer.hpp"
#include "Display.hpp"
#include "LogicManager.hpp"
#include "RenderController.hpp"
#include "KeyboardManager.hpp"
#include "Scene.hpp"
#include "Character.hpp"

using namespace std;

Game::Game() : currentScene(NULL)
{
	if (!al_init())
		throw runtime_error("failed to initialize allegro");

	resourceManager = new ResourceManager();

	display = new Display(640, 480, "Distrain - BAF's SpeedHack 2014 Entry");

	logicManager = new LogicManager();
	renderer = new RenderController(display, true, resourceManager->getFontManager()->getBuiltinFont());
	keyboardManager = new KeyboardManager();
	loop = new GameLoop(logicManager, renderer);

	timer = new GameTimer(renderer, 30);

	keyboardManager->registerWith(loop);
	display->registerWith(loop);
	timer->registerWith(loop);

	character = new Character(new CharacterResources(resourceManager->getImageManager()));
}

Game::~Game()
{
	delete resourceManager;
	delete logicManager;
	delete renderer;
	delete keyboardManager;
	delete display;
	delete timer;
	delete loop;

	currentScene = NULL;
}

void Game::run()
{
	timer->start();
	loop->run();
	timer->stop();
}

void Game::quit()
{
	loop->kill();
}

void Game::setScene(Scene *scene)
{
	currentScene = scene;

	logicManager->setScene(scene);
	renderer->setScene(scene);
	keyboardManager->setScene(scene);
}

ResourceManager *Game::getResourceManager() const
{
	return resourceManager;
}

Display *Game::getDisplay() const
{
	return display;
}

RenderController *Game::getRenderer() const
{
	return renderer;
}

KeyboardManager *Game::getKeyboardManager() const
{
	return keyboardManager;
}

GameLoop *Game::getLoop() const
{
	return loop;
}

Character *Game::getCharacter() const
{
	return character;
}