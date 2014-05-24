#include <allegro5/allegro.h>
#include "Scene.hpp"

HasScene::HasScene() : currentScene(NULL)
{
}

HasScene::~HasScene()
{
	currentScene = NULL;
}

void HasScene::setScene(Scene *scene)
{
	currentScene = scene;
}