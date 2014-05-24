#include <allegro5/allegro.h>
#include "TestScene.hpp"
#include "Scene.hpp"
#include "Tilemap.hpp"

TestScene::TestScene(TileEngine *tileEngine) : engine(tileEngine)
{
	auto map = new TileMap("data/maps/test.map");
	engine->setMap(map);
}

TestScene::~TestScene()
{
}

void TestScene::tick(double delta)
{
}

void TestScene::render()
{
	engine->render();
}

void TestScene::handleInputEvent(const ALLEGRO_EVENT &event)
{
}