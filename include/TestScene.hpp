#ifndef __TESTSCENE_HPP
#define __TESTSCENE_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "Scene.hpp"

class ResourceManager;
class Character;

enum BodyPart
{
	Body = 0,
	Top,
	Bottom,
	Eyes,
	Hair,
	FacialHair,
	Hat,
	Head,
	Extra,
	Shoes,
	BodyPartCount
};

class TestScene: public Scene
{
private:
	ALLEGRO_FONT *font;
	Character *character;

	BodyPart currentPart;

	void cyclePart(bool reverse);

public:
	TestScene(ResourceManager *resourceManager, Character *character);
	~TestScene();

	void tick(double delta);
	void render();
	void handleInputEvent(const ALLEGRO_EVENT &event);
};

#endif