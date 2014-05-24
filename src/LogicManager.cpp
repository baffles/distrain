#include <allegro5/allegro.h>
#include "LogicManager.hpp"
#include "Scene.hpp"

using namespace std;

LogicManager::LogicManager() : lastTick(al_get_time())
{
}

LogicManager::~LogicManager()
{
}

void LogicManager::tick()
{
	double now = al_get_time(), delta = now - lastTick;
	if (currentScene) currentScene->tick(delta);
	lastTick = now;
}