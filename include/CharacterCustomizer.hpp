#ifndef __CHARACTERCUSTOMIZER_HPP
#define __CHARACTERCUSTOMIZER_HPP

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

class CharacterCustomizer : public Scene
{
private:
	ALLEGRO_FONT *font;
	Character *character;

	BodyPart currentPart;

	void cyclePart(bool reverse);

public:
	CharacterCustomizer(ResourceManager *resourceManager, Character *character);
	~CharacterCustomizer();

	void tick(double delta);
	void render();
	void handleInputEvent(const ALLEGRO_EVENT &event);
};

#endif