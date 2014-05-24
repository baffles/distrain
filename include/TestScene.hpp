#ifndef __TESTSCENE_HPP
#define __TESTSCENE_HPP

#include "Scene.hpp"

class Character;

class TestScene: public Scene
{
private:
	Character *character;

public:
	TestScene(Character *character);
	~TestScene();

	void tick(double delta);
	void render();
};

#endif