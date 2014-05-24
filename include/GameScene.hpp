#ifndef __GAMESCENE_HPP
#define __GAMESCENE_HPP

#include <allegro5/allegro.h>
#include "Scene.hpp"

class Game;
class Character;
class CharacterActor;
class TileEngine;
class World;

class GameScene : public Scene
{
private:
	Game *game;
	CharacterActor *player;
	TileEngine *engine;
	World *world;

	int moveKey;

public:
	GameScene(Game *game);
	~GameScene();

	void tick(double delta);
	void render();
	void handleInputEvent(const ALLEGRO_EVENT &event);
};

#endif