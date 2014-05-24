#ifndef __KEYBOARDMANAGER_HPP
#define __KEYBOARDMANAGER_HPP

#include "GameLoop.hpp"
#include "Scene.hpp"

class KeyboardManager : public HasEvents, public HasScene
{
protected:
	ALLEGRO_EVENT_SOURCE *createEventSource();

public:
	KeyboardManager();
	~KeyboardManager();

	void handleEvent(GameLoop *loop, const ALLEGRO_EVENT &event);
};

#endif