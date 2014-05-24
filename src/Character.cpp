#include <cstdlib>
#include <vector>
#include <allegro5/allegro.h>
#include "Character.hpp"
#include "Constants.hpp"
#include "ResourceManager.hpp"

using namespace std;
using Constants::Direction;

CharacterResources::CharacterResources(ImageManager *imageManager)
{
	// filename typos care of https://github.com/silveira/openpixels
	bodies.push_back(imageManager->getImage("data/character/body_black.png"));
	bodies.push_back(imageManager->getImage("data/character/body_caucassian.png"));
	bodies.push_back(imageManager->getImage("data/character/body_dark.png"));
	bodies.push_back(imageManager->getImage("data/character/body_ghost.png"));
	bodies.push_back(imageManager->getImage("data/character/body_green.png"));
	bodies.push_back(imageManager->getImage("data/character/body_olive.png"));
	bodies.push_back(imageManager->getImage("data/character/body_skeleton.png"));
	bodies.push_back(imageManager->getImage("data/character/body_stormtrooper.png"));

	tops.push_back(imageManager->getImage("data/character/cloths_armor.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_blackdress.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_blacksuit.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_blacksuit_groom.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_blousewithtie.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_blueshirtstripes.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_bluestripesshirt.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_greendress.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_hazmat.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_king.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_labcoat.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_redstripesshirt.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_redtshirt.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_santa.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_tshirt.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_wedding_dress.png"));
	tops.push_back(imageManager->getImage("data/character/cloths_yellowCBFtshirt.png"));

	bottoms.push_back(imageManager->getImage("data/character/cloths_blueshorts.png"));
	bottoms.push_back(imageManager->getImage("data/character/cloths_femenineunderpants.png"));
	bottoms.push_back(imageManager->getImage("data/character/cloths_jeans.png"));
	bottoms.push_back(imageManager->getImage("data/character/cloths_masculineunderpants.png"));
	bottoms.push_back(imageManager->getImage("data/character/cloths_pantsleather.png"));

	eyes.push_back(imageManager->getImage("data/character/eyes_black.png"));
	eyes.push_back(imageManager->getImage("data/character/eyes_blue.png"));
	eyes.push_back(imageManager->getImage("data/character/eyes_brown.png"));
	eyes.push_back(imageManager->getImage("data/character/eyes_default.png"));
	eyes.push_back(imageManager->getImage("data/character/eyes_green.png"));
	eyes.push_back(imageManager->getImage("data/character/eyes_loves.png"));
	eyes.push_back(imageManager->getImage("data/character/eyes_red.png"));
	eyes.push_back(imageManager->getImage("data/character/eyes_surprise.png"));

	hair.push_back(imageManager->getImage("data/character/hair_afro.png"));
	hair.push_back(imageManager->getImage("data/character/hair_bun.png"));
	hair.push_back(imageManager->getImage("data/character/hair_cuttedblack.png"));
	hair.push_back(imageManager->getImage("data/character/hair_cuttedbrown.png"));
	hair.push_back(imageManager->getImage("data/character/hair_fringebrown.png"));
	hair.push_back(imageManager->getImage("data/character/hair_long_blue.png"));
	hair.push_back(imageManager->getImage("data/character/hair_longbrown.png"));
	hair.push_back(imageManager->getImage("data/character/hair_midblack.png"));
	hair.push_back(imageManager->getImage("data/character/hair_redbun.png"));
	hair.push_back(imageManager->getImage("data/character/hair_semibald.png"));
	hair.push_back(imageManager->getImage("data/character/hair_shortblack.png"));
	hair.push_back(imageManager->getImage("data/character/hair_squared.png"));
	hair.push_back(imageManager->getImage("data/character/hair_white.png"));

	facialHair.push_back(imageManager->getImage("data/character/hair_beard.png"));
	facialHair.push_back(imageManager->getImage("data/character/hair_beard_2.png"));
	facialHair.push_back(imageManager->getImage("data/character/hair_longwhitebeard.png"));
	facialHair.push_back(imageManager->getImage("data/character/hair_mustache.png"));
	facialHair.push_back(imageManager->getImage("data/character/hair_whitebeard.png"));

	hats.push_back(imageManager->getImage("data/character/hat_mafia.png"));
	hats.push_back(imageManager->getImage("data/character/hat_santa.png"));
	hats.push_back(imageManager->getImage("data/character/hat_turban.png"));
	hats.push_back(imageManager->getImage("data/character/hat_witch.png"));

	heads.push_back(imageManager->getImage("data/character/head_crown.png"));
	heads.push_back(imageManager->getImage("data/character/head_hazmat.png"));
	heads.push_back(imageManager->getImage("data/character/head_helmet.png"));
	heads.push_back(imageManager->getImage("data/character/head_skeleton.png"));
	heads.push_back(imageManager->getImage("data/character/head_stormstrooper.png"));
	heads.push_back(imageManager->getImage("data/character/head_tiara.png"));

	extras.push_back(imageManager->getImage("data/character/misc_backpack.png"));
	extras.push_back(imageManager->getImage("data/character/misc_blackgloves.png"));
	extras.push_back(imageManager->getImage("data/character/misc_cape.png"));
	extras.push_back(imageManager->getImage("data/character/misc_epaulettes.png"));
	extras.push_back(imageManager->getImage("data/character/misc_mask.png"));
	extras.push_back(imageManager->getImage("data/character/misc_mask_medic.png"));
	extras.push_back(imageManager->getImage("data/character/misc_redboxgloves.png"));
	extras.push_back(imageManager->getImage("data/character/misc_roundglasses.png"));
	extras.push_back(imageManager->getImage("data/character/misc_sunglasses.png"));
	extras.push_back(imageManager->getImage("data/character/misc_tank.png"));
	extras.push_back(imageManager->getImage("data/character/misc_vendetamask.png"));

	shoes = imageManager->getImage("data/character/misc_shoes.png");
}

CharacterResources::~CharacterResources()
{
	// ImageManager will clean up the loaded bitmap for us
	bodies.clear();
	tops.clear();
	bottoms.clear();
	eyes.clear();
	hair.clear();
	facialHair.clear();
	hats.clear();
	heads.clear();
	extras.clear();
	shoes = NULL;
}

int CharacterResources::getBodyCount() const
{
	return bodies.size();
}

ALLEGRO_BITMAP *CharacterResources::getBody(int id) const
{
	return bodies[id];
}

int CharacterResources::getTopsCount() const
{
	return tops.size();
}

ALLEGRO_BITMAP *CharacterResources::getTop(int id) const
{
	return tops[id];
}

int CharacterResources::getBottomsCount() const
{
	return bottoms.size();
}

ALLEGRO_BITMAP *CharacterResources::getBottom(int id) const
{
	return bottoms[id];
}

int CharacterResources::getEyesCount() const
{
	return eyes.size();
}

ALLEGRO_BITMAP *CharacterResources::getEyes(int id) const
{
	return eyes[id];
}

int CharacterResources::getHairCount() const
{
	return hair.size();
}

ALLEGRO_BITMAP *CharacterResources::getHair(int id) const
{
	return hair[id];
}

int CharacterResources::getFacialHairCount() const
{
	return facialHair.size();
}

ALLEGRO_BITMAP *CharacterResources::getFacialHair(int id) const
{
	return facialHair[id];
}

int CharacterResources::getHatCount() const
{
	return hats.size();
}

ALLEGRO_BITMAP *CharacterResources::getHat(int id) const
{
	return hats[id];
}

int CharacterResources::getHeadCount() const
{
	return heads.size();
}

ALLEGRO_BITMAP *CharacterResources::getHead(int id) const
{
	return heads[id];
}

int CharacterResources::getExtrasCount() const
{
	return extras.size();
}

ALLEGRO_BITMAP *CharacterResources::getExtra(int id) const
{
	return extras[id];
}

ALLEGRO_BITMAP *CharacterResources::getShoes() const
{
	return shoes;
}



Character::Character(CharacterResources *res) : res(res), bodyId(0), topId(-1), bottomId(-1), eyesId(0), hairId(-1), facialHairId(-1), hatId(-1), headId(-1), extraId(-1), hasShoes(true), Animation(5.0f, 3 /*6*/)
	// bodyId(1), topId(0), bottomId(2), eyesId(1), hairId(2), facialHairId(0), hatId(-1), headId(-1), extraId(-1)
{
}

Character::~Character()
{
}

void Character::startAnimation()
{
	Animation::startAnimation();
}

void Character::stopAnimation()
{
	Animation::stopAnimation();
}

void Character::tick(double delta)
{
	Animation::tick(delta);
}

int Character::getAnimationFrame(Direction direction) const
{
	return Animation::isActive() ? Animation::getCurrentAnimationFrame() : 1;

	// animation frame will be 0-5. during animation, when moving up or down, alternate between frames 0 and 2. when moving left or right, use frames 0, 1, and 2.
	// when not moving, lock at frame 1
	/*return Animation::isActive() ?
		(direction == Direction::Up || direction == Direction::Down ?
			(Animation::getCurrentAnimationFrame() % 2) * 2 :
			(Animation::getCurrentAnimationFrame() % 3)
		) : 1;*/
}

void Character::drawChunk(ALLEGRO_BITMAP *chunk, Direction direction, int frame, float x, float y, float scale) const
{
	// weird coords.... https://github.com/silveira/openpixels/blob/master/lib/chars.json
	float cx, cy;
	switch (frame)
	{
	case 0:
		cx = 0;
		break;
	case 1:
		cx = 36;
		break;
	case 2:
		cx = 73;
		break;
	}
	switch (direction)
	{
	case Direction::Up:
		cy = 7;
		break;
	case Direction::Right:
		cy = 55;
		break;
	case Direction::Down:
		cy = 103;
		break;
	case Direction::Left:
		cy = 151;
		break;
	}

	if (scale == 1.0f)
		al_draw_bitmap_region(chunk, cx, cy, Constants::CharacterWidth, Constants::CharacterHeight, x, y, 0);
	else
		al_draw_scaled_bitmap(chunk, cx, cy, Constants::CharacterWidth, Constants::CharacterHeight, x, y, Constants::CharacterWidth * scale, Constants::CharacterHeight * scale, 0);
}

void Character::render(Direction direction, int frame, float x, float y, float scale) const
{
	// draw body, then head, then eyes, then facial hair, then shoes, then bottom, then top, then misc, then hair, then hat,
	drawChunk(res->getBody(bodyId), direction, frame, x, y, scale);
	if (headId >= 0) drawChunk(res->getHead(headId), direction, frame, x, y, scale);
	drawChunk(res->getEyes(eyesId), direction, frame, x, y, scale);
	if (facialHairId >= 0) drawChunk(res->getFacialHair(facialHairId), direction, frame, x, y, scale);
	if (hasShoes) drawChunk(res->getShoes(), direction, frame, x, y, scale);
	if (bottomId >= 0) drawChunk(res->getBottom(bottomId), direction, frame, x, y, scale);
	if (topId >= 0) drawChunk(res->getTop(topId), direction, frame, x, y, scale);
	if (extraId >= 0) drawChunk(res->getExtra(extraId), direction, frame, x, y, scale);
	if (hairId >= 0) drawChunk(res->getHair(hairId), direction, frame, x, y, scale);
	if (hatId >= 0) drawChunk(res->getHat(hatId), direction, frame, x, y, scale);
}

void Character::render(Direction direction, float x, float y, bool animated, float scale) const
{
	render(direction, animated ? getAnimationFrame(direction) : 1, x, y, scale);
}

void Character::randomize()
{
	bodyId = rand() % res->getBodyCount();
	eyesId = rand() % res->getEyesCount();

	headId = rand() % (res->getHeadCount() + 1) - 1;
	facialHairId = rand() % (res->getFacialHairCount() + 1) - 1;
	bottomId = rand() % (res->getBottomsCount() + 1) - 1;
	topId = rand() % (res->getTopsCount() + 1) - 1;
	extraId = rand() % (res->getExtrasCount() + 1) - 1;
	hairId = rand() % (res->getHairCount() + 1) - 1;
	hatId = rand() % (res->getHatCount() + 1) - 1;

	hasShoes = rand() % 2;
}

// body + eyes mandatory, rest optional
void Character::cycleBody(bool reverse)
{
	bodyId += reverse ? -1 : 1;
	if (bodyId < 0) bodyId += res->getBodyCount();
	else bodyId %= res->getBodyCount();
}

void Character::cycleTop(bool reverse)
{
	topId += reverse ? -1 : 1;
	if (topId < -1) topId += res->getTopsCount();
	else if (topId >= res->getTopsCount()) topId = -1;
}

void Character::cycleBottom(bool reverse)
{
	bottomId += reverse ? -1 : 1;
	if (bottomId < -1) bottomId = res->getBottomsCount() - 1;
	else if (bottomId >= res->getBottomsCount()) bottomId = -1;
}

void Character::cycleEyes(bool reverse)
{
	eyesId += reverse ? -1 : 1;
	if (eyesId < 0) eyesId += res->getEyesCount();
	else eyesId %= res->getEyesCount();
}

void Character::cycleHair(bool reverse)
{
	hairId += reverse ? -1 : 1;
	if (hairId < -1) hairId = res->getHairCount() - 1;
	else if (hairId >= res->getHairCount()) hairId = -1;
}

void Character::cycleFacialHair(bool reverse)
{
	facialHairId += reverse ? -1 : 1;
	if (facialHairId < -1) facialHairId = res->getFacialHairCount() - 1;
	else if (facialHairId >= res->getFacialHairCount()) facialHairId = -1;
}

void Character::cycleHat(bool reverse)
{
	hatId += reverse ? -1 : 1;
	if (hatId < -1) hatId = res->getHatCount() - 1;
	else if (hatId >= res->getHatCount()) hatId = -1;
}

void Character::cycleHead(bool reverse)
{
	headId += reverse ? -1 : 1;
	if (headId < -1) headId = res->getHeadCount() - 1;
	else if (headId >= res->getHeadCount()) headId = -1;
}

void Character::cycleExtra(bool reverse)
{
	extraId += reverse ? -1 : 1;
	if (extraId < -1) extraId = res->getExtrasCount() - 1;
	else if (extraId >= res->getExtrasCount()) extraId = -1;
}

void Character::cycleShoes(bool reverse)
{
	hasShoes = !hasShoes;
}



CharacterActor::CharacterActor(Character *character, TileEngine *engine) : character(character), Actor(engine)
{
}

CharacterActor::~CharacterActor()
{
	character->stopAnimation();
}

void CharacterActor::setPosition(float x, float y)
{
	setX(x);
	setY(y);
}

void CharacterActor::startMoving()
{
	Actor::startMoving();
	character->startAnimation();
}

void CharacterActor::stopMoving()
{
	Actor::stopMoving();
	character->stopAnimation();
	//setDirection(Direction::Down);
}

void CharacterActor::walk(Direction direction)
{
	setDirection(direction);
	setVelocity(Constants::WalkVelocity);
	startMoving();
}

void CharacterActor::run(Direction direction)
{
	setDirection(direction);
	setVelocity(Constants::RunVelocity);
	startMoving();
}

void CharacterActor::stop()
{
	stopMoving();
}

void CharacterActor::renderAt(float x, float y) const
{
	character->render(getDirection(), x, y);
}

void CharacterActor::tick(double delta)
{
	Actor::tick(delta);
	character->tick(delta);
}