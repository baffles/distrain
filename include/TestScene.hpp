#ifndef __TESTSCENE_HPP
#define __TESTSCENE_HPP

#include <allegro5/allegro.h>
#include "Scene.hpp"

class Character;
class CharacterActor;
class TileEngine;
class World;

class TestScene : public Scene
{
private:
	CharacterActor *actor;
	TileEngine *engine;
	World *world;

	int moveKey;

public:
	TestScene(Character *character, TileEngine *engine);
	~TestScene();

	void tick(double delta);
	void render();
	void handleInputEvent(const ALLEGRO_EVENT &event);
};

#endif