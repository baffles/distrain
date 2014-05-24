#ifndef __CHARACTER_HPP
#define __CHARACTER_HPP

#include <vector>
#include <allegro5/allegro.h>
#include "LogicManager.hpp"
#include "Constants.hpp"
#include "Actor.hpp"
#include "Animation.hpp"

class ImageManager;
class TileEngine;

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

	int getBodyCount() const;
	ALLEGRO_BITMAP *getBody(int id) const;

	int getTopsCount() const;
	ALLEGRO_BITMAP *getTop(int id) const;

	int getBottomsCount() const;
	ALLEGRO_BITMAP *getBottom(int id) const;

	int getEyesCount() const;
	ALLEGRO_BITMAP *getEyes(int id) const;

	int getHairCount() const;
	ALLEGRO_BITMAP *getHair(int id) const;

	int getFacialHairCount() const;
	ALLEGRO_BITMAP *getFacialHair(int id) const;

	int getHatCount() const;
	ALLEGRO_BITMAP *getHat(int id) const;

	int getHeadCount() const;
	ALLEGRO_BITMAP *getHead(int id) const;

	int getExtrasCount() const;
	ALLEGRO_BITMAP *getExtra(int id) const;

	ALLEGRO_BITMAP *getShoes() const;
};

class Character : public HasLogic, private Animation
{
private:
	CharacterResources *res;

	int bodyId, topId, bottomId, eyesId, hairId, facialHairId, hatId, headId, extraId;
	bool hasShoes;

	void drawChunk(ALLEGRO_BITMAP *chunk, Constants::Direction direction, int frame, float x, float y, float scale) const;
	int getAnimationFrame(Constants::Direction direction) const;
	void render(Constants::Direction direction, int frame, float x, float y, float scale) const;

public:
	Character(CharacterResources *res);
	~Character();

	void startAnimation();
	void stopAnimation();

	void tick(double delta);

	void render(Constants::Direction direction, float x, float y, bool animated = true, float scale = 1.0f) const;

	// customization
	void randomize();
	void cycleBody(bool reverse);
	void cycleTop(bool reverse);
	void cycleBottom(bool reverse);
	void cycleEyes(bool reverse);
	void cycleHair(bool reverse);
	void cycleFacialHair(bool reverse);
	void cycleHat(bool reverse);
	void cycleHead(bool reverse);
	void cycleExtra(bool reverse);
	void cycleShoes(bool reverse);
};

class CharacterActor : public Actor
{
private:
	Character *character;

protected:
	void renderAt(float x, float y) const;

	void startMoving();
	void stopMoving();

public:
	CharacterActor(Character *character, TileEngine *engine);
	~CharacterActor();

	void setPosition(float x, float y);

	void walk(Constants::Direction direction);
	void run(Constants::Direction direction);
	void stop();

	void tick(double delta);
};

#endif