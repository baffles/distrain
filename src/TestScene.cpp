#include <allegro5/allegro.h>
#include "TestScene.hpp"
#include "Character.hpp"

TestScene::TestScene(Character *character) : character(character)
{
	character->setDirection(Direction::Down);
	character->startWalk();
}

TestScene::~TestScene()
{
}

void TestScene::tick(double delta)
{
	character->tick(delta);
}

void TestScene::render()
{
	character->render(15, 15);
}