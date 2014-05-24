#ifndef __TESTSCENE_HPP
#define __TESTSCENE_HPP

#include <allegro5/allegro.h>
#include "Scene.hpp"

class TileEngine;

class TestScene : public Scene
{
private:
	TileEngine *engine;

public:
	TestScene(TileEngine *engine);
	~TestScene();

	void tick(double delta);
	void render();
	void handleInputEvent(const ALLEGRO_EVENT &event);
};

#endif