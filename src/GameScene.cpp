#include <allegro5/allegro.h>
#include "TestScene.hpp"
#include "Constants.hpp"
#include "Scene.hpp"
#include "Character.hpp"
#include "Tilemap.hpp"
#include "World.hpp"

using Constants::Direction;

TestScene::TestScene(Character *character, TileEngine *tileEngine) : engine(tileEngine), actor(new CharacterActor(character, tileEngine)), world(new World(engine, actor)), moveKey(0)
{
	//auto map = new TileMap("data/maps/test.map");
	//engine->setMap(map);

	//actor->setPosition(map->startPositions[Direction::Right].x, map->startPositions[Direction::Right].y);
}

TestScene::~TestScene()
{
}

void TestScene::tick(double delta)
{
	actor->tick(delta);
	world->tick();
}

void TestScene::render()
{
	engine->renderBase();
	actor->render();
	engine->renderOverlay();
}

void TestScene::handleInputEvent(const ALLEGRO_EVENT &event)
{
	//TODO: stack or something of key presses (so if I'm holding down, tap right and let go, I go back to moving down)
	if (event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
		case ALLEGRO_KEY_W:
			actor->walk(Direction::Up);
			moveKey = event.keyboard.keycode;
			break;

		case ALLEGRO_KEY_DOWN:
		case ALLEGRO_KEY_S:
			actor->walk(Direction::Down);
			moveKey = event.keyboard.keycode;
			break;

		case ALLEGRO_KEY_LEFT:
		case ALLEGRO_KEY_A:
			actor->walk(Direction::Left);
			moveKey = event.keyboard.keycode;
			break;

		case ALLEGRO_KEY_RIGHT:
		case ALLEGRO_KEY_D:
			actor->walk(Direction::Right);
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
			actor->stop();
	}
}