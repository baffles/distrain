#ifndef __CHARACTERCUSTOMIZER_HPP
#define __CHARACTERCUSTOMIZER_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "Scene.hpp"

class Game;
class ResourceManager;
class Character;

enum MenuOption
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
	Randomizer,
	Play,
	Quit,
	MenuOptionCount
};

class CharacterCustomizer : public Scene
{
private:
	Game *game;

	ALLEGRO_FONT *font;
	Character *character;

	MenuOption currentPart;

	void cyclePart(bool reverse);

public:
	CharacterCustomizer(Game *game);
	~CharacterCustomizer();

	void tick(double delta);
	void render();
	void handleInputEvent(const ALLEGRO_EVENT &event);
};

#endif