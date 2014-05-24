#include <vector>
#include <allegro5/allegro.h>
#include "Character.hpp"
#include "ResourceManager.hpp"

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

int CharacterResources::getBodyCount()
{
	return bodies.size();
}

ALLEGRO_BITMAP *CharacterResources::getBody(int id)
{
	return bodies[id];
}

int CharacterResources::getTopsCount()
{
	return tops.size();
}

ALLEGRO_BITMAP *CharacterResources::getTop(int id)
{
	return tops[id];
}

int CharacterResources::getBottomsCount()
{
	return bottoms.size();
}

ALLEGRO_BITMAP *CharacterResources::getBottom(int id)
{
	return bottoms[id];
}

int CharacterResources::getEyesCount()
{
	return eyes.size();
}

ALLEGRO_BITMAP *CharacterResources::getEyes(int id)
{
	return eyes[id];
}

int CharacterResources::getHairCount()
{
	return hair.size();
}

ALLEGRO_BITMAP *CharacterResources::getHair(int id)
{
	return hair[id];
}

int CharacterResources::getFacialHairCount()
{
	return facialHair.size();
}

ALLEGRO_BITMAP *CharacterResources::getFacialHair(int id)
{
	return facialHair[id];
}

int CharacterResources::getHatCount()
{
	return hats.size();
}

ALLEGRO_BITMAP *CharacterResources::getHat(int id)
{
	return hats[id];
}

int CharacterResources::getHeadCount()
{
	return heads.size();
}

ALLEGRO_BITMAP *CharacterResources::getHead(int id)
{
	return heads[id];
}

int CharacterResources::getExtrasCount()
{
	return extras.size();
}

ALLEGRO_BITMAP *CharacterResources::getExtra(int id)
{
	return extras[id];
}

ALLEGRO_BITMAP *CharacterResources::getShoes()
{
	return shoes;
}


// body + eyes mandatory, rest optional
// draw body, then head, then eyes, then facial hair, then hair, then hat, then bottom, then top, then shoes, then misc

Character::Character(CharacterResources *res) : res(res), bodyId(1), topId(0), bottomId(2), eyesId(1), hairId(2), facialHairId(0), hatId(-1), headId(-1), extraId(-1), hasShoes(true)
	//: res(res), bodyId(0), topId(-1), bottomId(-1), eyesId(0), hairId(-1), facialHairId(-1), hatId(-1), headId(-1), extraId(-1), hasShoes(false)
{
}

Character::~Character()
{
}

void Character::drawChunk(ALLEGRO_BITMAP *chunk, Direction direction, int frame, int x, int y)
{
	al_draw_bitmap_region(chunk, frame * CharacterWidth, direction * CharacterHeight, CharacterWidth, CharacterHeight, x, y, 0);
}

void Character::render(Direction direction, int frame, int x, int y)
{
	drawChunk(res->getBody(bodyId), direction, frame, x, y);
	if (headId >= 0) drawChunk(res->getHead(headId), direction, frame, x, y);
	drawChunk(res->getEyes(eyesId), direction, frame, x, y);
	if (facialHairId >= 0) drawChunk(res->getFacialHair(facialHairId), direction, frame, x, y);
	if (hairId >= 0) drawChunk(res->getHair(hairId), direction, frame, x, y);
	if (hatId >= 0) drawChunk(res->getHat(hatId), direction, frame, x, y);
	if (bottomId >= 0) drawChunk(res->getBottom(bottomId), direction, frame, x, y);
	if (topId >= 0) drawChunk(res->getTop(topId), direction, frame, x, y);
	if (hasShoes) drawChunk(res->getShoes(), direction, frame, x, y);
	if (extraId >= 0) drawChunk(res->getExtra(extraId), direction, frame, x, y);
}

void Character::testRender(Direction direction, int x, int y)
{
	render(direction, 0, x, y);
}