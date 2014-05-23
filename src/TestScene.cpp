#include <allegro5/allegro.h>
#include "TestScene.hpp"
#include "Character.hpp"

TestScene::TestScene(Character *character) : character(character)
{
}

TestScene::~TestScene()
{
}

void TestScene::render()
{
	character->testRender(Direction::Down, 15, 15);
}