#ifndef __CHARACTER_HPP
#define __CHARACTER_HPP

#include <vector>
#include <allegro5/allegro.h>

class ImageManager;

class CharacterResources
{
private:
	std::vector<ALLEGRO_BITMAP*> bodies;
	std::vector<ALLEGRO_BITMAP*> tops;
	std::vector<ALLEGRO_BITMAP*> bottoms;
	std::vector<ALLEGRO_BITMAP*> eyes;
	std::vector<ALLEGRO_BITMAP*> hair;
	std::vector<ALLEGRO_BITMAP*> facialHair;
	std::vector<ALLEGRO_BITMAP*> hats;
	std::vector<ALLEGRO_BITMAP*> heads;
	std::vector<ALLEGRO_BITMAP*> extras;
	ALLEGRO_BITMAP *shoes;

public:
	CharacterResources(ImageManager *imageManager);
	~CharacterResources();

	int getBodyCount();
	ALLEGRO_BITMAP *getBody(int id);

	int getTopsCount();
	ALLEGRO_BITMAP *getTop(int id);

	int getBottomsCount();
	ALLEGRO_BITMAP *getBottom(int id);

	int getEyesCount();
	ALLEGRO_BITMAP *getEyes(int id);

	int getHairCount();
	ALLEGRO_BITMAP *getHair(int id);

	int getFacialHairCount();
	ALLEGRO_BITMAP *getFacialHair(int id);

	int getHatCount();
	ALLEGRO_BITMAP *getHat(int id);

	int getHeadCount();
	ALLEGRO_BITMAP *getHead(int id);

	int getExtrasCount();
	ALLEGRO_BITMAP *getExtra(int id);

	ALLEGRO_BITMAP *getShoes();
};

enum Direction {
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3
};

class Character
{
private:
	static const int CharacterWidth = 35;
	static const int CharacterHeight = 52;

	CharacterResources *res;

	int bodyId, topId, bottomId, eyesId, hairId, facialHairId, hatId, headId, extraId;
	bool hasShoes;

	void drawChunk(ALLEGRO_BITMAP *chunk, Direction direction, int frame, int x, int y);
	void render(Direction direction, int frame, int x, int y);

public:
	Character(CharacterResources *res);
	~Character();

	void testRender(Direction direction, int x, int y);
};

#endif