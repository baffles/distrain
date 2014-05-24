#include <stdexcept>
#include <allegro5/allegro.h>
#include "KeyboardManager.hpp"
#include "Scene.hpp"

using namespace std;

KeyboardManager::KeyboardManager()
{
	if (!al_install_keyboard())
		throw runtime_error("failed to install keyboard driver");
}

KeyboardManager::~KeyboardManager()
{
	al_uninstall_keyboard();
}

ALLEGRO_EVENT_SOURCE *KeyboardManager::createEventSource()
{
	return al_get_keyboard_event_source();
}

void KeyboardManager::handleEvent(GameLoop *loop, const ALLEGRO_EVENT &event)
{
	if (currentScene)
		currentScene->handleInputEvent(event);
}