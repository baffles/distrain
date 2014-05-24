#include <allegro5/allegro.h>
#include "GameScene.hpp"
#include "Constants.hpp"
#include "Game.hpp"
#include "Scene.hpp"
#include "Character.hpp"
#include "ResourceManager.hpp"
#include "Tilemap.hpp"
#include "World.hpp"

using Constants::Direction;

GameScene::GameScene(Game *game) : game(game), moveKey(0)
{
	engine = new TileEngine(new TileSet(game->getResourceManager()->getImageManager()->getImage("data/open_tileset.png")));
	player = new CharacterActor(game->getCharacter(), engine);

	world = new World(engine, player);
}

GameScene::~GameScene()
{
	delete world;
	delete player;
	delete engine;
}

void GameScene::tick(double delta)
{
	player->tick(delta);
	world->tick();
}

void GameScene::render()
{
	engine->renderBase();
	player->render();
	engine->renderOverlay();
}

void GameScene::handleInputEvent(const ALLEGRO_EVENT &event)
{
	//TODO: stack or something of key presses (so if I'm holding down, tap right and let go, I go back to moving down)
	if (event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
		case ALLEGRO_KEY_W:
			player->walk(Direction::Up);
			moveKey = event.keyboard.keycode;
			break;

		case ALLEGRO_KEY_DOWN:
		case ALLEGRO_KEY_S:
			player->walk(Direction::Down);
			moveKey = event.keyboard.keycode;
			break;

		case ALLEGRO_KEY_LEFT:
		case ALLEGRO_KEY_A:
			player->walk(Direction::Left);
			moveKey = event.keyboard.keycode;
			break;

		case ALLEGRO_KEY_RIGHT:
		case ALLEGRO_KEY_D:
			player->walk(Direction::Right);
			moveKey = event.keyboard.keycode;
			break;

		case ALLEGRO_KEY_SPACE:
			world->playerUse();
			break;
		}
	}
	else if (event.type == ALLEGRO_EVENT_KEY_UP)
	{
		if (moveKey == event.keyboard.keycode)
			player->stop();
	}
}