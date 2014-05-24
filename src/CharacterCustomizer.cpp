#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "CharacterCustomizer.hpp"
#include "ResourceManager.hpp"
#include "Character.hpp"

CharacterCustomizer::CharacterCustomizer(ResourceManager *resourceManager, Character *character) : character(character), currentPart(BodyPart::Body)
{
	character->setDirection(Direction::Down);
	character->startWalk();

	font = resourceManager->getFontManager()->getBuiltinFont();
}

CharacterCustomizer::~CharacterCustomizer()
{
}

void CharacterCustomizer::tick(double delta)
{
	character->tick(delta);
}

void CharacterCustomizer::render()
{
	float baseX = 50, baseY = 50;

	character->preview(Direction::Down, false, baseX, baseY, 4.0f);

	baseX += 5 * Character::CharacterWidth;
	
	character->preview(Direction::Up, true, baseX, baseY, 1.0f);
	character->preview(Direction::Up, false, baseX + Character::CharacterWidth, baseY, 1.0f);

	baseY += Character::CharacterHeight;

	character->preview(Direction::Left, true, baseX, baseY, 1.0f);
	character->preview(Direction::Left, false, baseX + Character::CharacterWidth, baseY, 1.0f);

	baseY += Character::CharacterHeight;

	character->preview(Direction::Right, true, baseX, baseY, 1.0f);
	character->preview(Direction::Right, false, baseX + Character::CharacterWidth, baseY, 1.0f);

	baseY += Character::CharacterHeight;

	character->preview(Direction::Down, true, baseX, baseY, 1.0f);
	character->preview(Direction::Down, false, baseX + Character::CharacterWidth, baseY, 1.0f);

	baseX += 4 * Character::CharacterWidth;
	baseY -= 3 * Character::CharacterHeight;

	static auto fontH = al_get_font_line_height(font);
	auto unsel = al_map_rgb(255, 255, 255);
	auto sel = al_map_rgb(255, 83, 13);

	al_draw_text(font, currentPart == BodyPart::Body ? sel : unsel, baseX, baseY, 0, "Body");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::Top ? sel : unsel, baseX, baseY, 0, "Top");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::Bottom ? sel : unsel, baseX, baseY, 0, "Bottom");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::Eyes ? sel : unsel, baseX, baseY, 0, "Eyes");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::Hair ? sel : unsel, baseX, baseY, 0, "Hair");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::FacialHair ? sel : unsel, baseX, baseY, 0, "Facial Hair");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::Hat ? sel : unsel, baseX, baseY, 0, "Hat");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::Head ? sel : unsel, baseX, baseY, 0, "Head");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::Extra ? sel : unsel, baseX, baseY, 0, "Accessory");
	baseY += fontH;
	al_draw_text(font, currentPart == BodyPart::Shoes ? sel : unsel, baseX, baseY, 0, "Shoes");
}

void CharacterCustomizer::cyclePart(bool reverse)
{
	switch (currentPart)
	{
	case BodyPart::Body:
		character->cycleBody(reverse);
		break;

	case BodyPart::Top:
		character->cycleTop(reverse);
		break;

	case BodyPart::Bottom:
		character->cycleBottom(reverse);
		break;

	case BodyPart::Eyes:
		character->cycleEyes(reverse);
		break;

	case BodyPart::Hair:
		character->cycleHair(reverse);
		break;

	case BodyPart::FacialHair:
		character->cycleFacialHair(reverse);
		break;

	case BodyPart::Hat:
		character->cycleHat(reverse);
		break;

	case BodyPart::Head:
		character->cycleHead(reverse);
		break;

	case BodyPart::Extra:
		character->cycleExtra(reverse);
		break;

	case BodyPart::Shoes:
		character->cycleShoes(reverse);
		break;
	}
}

void CharacterCustomizer::handleInputEvent(const ALLEGRO_EVENT &event)
{
	if (event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			currentPart = (BodyPart)(currentPart - 1);
			if (currentPart < 0) currentPart = (BodyPart)(currentPart + BodyPart::BodyPartCount);
			break;

		case ALLEGRO_KEY_DOWN:
			currentPart = (BodyPart)((currentPart + 1) % BodyPart::BodyPartCount);
			break;

		case ALLEGRO_KEY_LEFT:
			cyclePart(true);
			break;

		case ALLEGRO_KEY_RIGHT:
			cyclePart(false);
			break;
		}
	}
}