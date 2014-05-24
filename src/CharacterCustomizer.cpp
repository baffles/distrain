#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "CharacterCustomizer.hpp"
#include "Game.hpp"
#include "ResourceManager.hpp"
#include "Character.hpp"

CharacterCustomizer::CharacterCustomizer(Game *game) : game(game), character(game->getCharacter()), currentPart(MenuOption::Body)
{
	character->startAnimation();

	font = game->getResourceManager()->getFontManager()->getBuiltinFont();
}

CharacterCustomizer::~CharacterCustomizer()
{
	character->stopAnimation();
}

void CharacterCustomizer::tick(double delta)
{
	character->tick(delta);
}

void CharacterCustomizer::render()
{
	// the customizer is roughly 420x240, so center that (assuming 640x480); bumped down towards the bottom slightly (title area)
	float baseX = 110, baseY = 170;

	character->render(Direction::Down, baseX, baseY, false, 4.0f);

	baseX += 5 * Character::CharacterWidth;
	
	character->render(Direction::Up, baseX, baseY);
	character->render(Direction::Up, baseX + Character::CharacterWidth, baseY, false);

	baseY += Character::CharacterHeight;

	character->render(Direction::Left, baseX, baseY);
	character->render(Direction::Left, baseX + Character::CharacterWidth, baseY, false);

	baseY += Character::CharacterHeight;

	character->render(Direction::Right, baseX, baseY);
	character->render(Direction::Right, baseX + Character::CharacterWidth, baseY, false);

	baseY += Character::CharacterHeight;

	character->render(Direction::Down, baseX, baseY);
	character->render(Direction::Down, baseX + Character::CharacterWidth, baseY, false);

	baseX += 4 * Character::CharacterWidth;
	baseY -= 3 * Character::CharacterHeight;

	static auto fontH = al_get_font_line_height(font);
	auto unsel = al_map_rgb(255, 255, 255);
	auto sel = al_map_rgb(255, 83, 13);

	al_draw_text(font, currentPart == MenuOption::Body ? sel : unsel, baseX, baseY, 0, "Body");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Top ? sel : unsel, baseX, baseY, 0, "Top");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Bottom ? sel : unsel, baseX, baseY, 0, "Bottom");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Eyes ? sel : unsel, baseX, baseY, 0, "Eyes");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Hair ? sel : unsel, baseX, baseY, 0, "Hair");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::FacialHair ? sel : unsel, baseX, baseY, 0, "Facial Hair");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Hat ? sel : unsel, baseX, baseY, 0, "Hat");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Head ? sel : unsel, baseX, baseY, 0, "Head");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Extra ? sel : unsel, baseX, baseY, 0, "Accessory");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Shoes ? sel : unsel, baseX, baseY, 0, "Shoes");

	baseY += 2.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Randomizer ? sel : unsel, baseX, baseY, 0, "Randomize");

	baseY += 4.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Play ? sel : unsel, baseX, baseY, 0, "Play");
	baseY += 1.5 * fontH;
	al_draw_text(font, currentPart == MenuOption::Quit ? sel : unsel, baseX, baseY, 0, "Quit");
}

void CharacterCustomizer::cyclePart(bool reverse)
{
	switch (currentPart)
	{
	case MenuOption::Body:
		character->cycleBody(reverse);
		break;

	case MenuOption::Top:
		character->cycleTop(reverse);
		break;

	case MenuOption::Bottom:
		character->cycleBottom(reverse);
		break;

	case MenuOption::Eyes:
		character->cycleEyes(reverse);
		break;

	case MenuOption::Hair:
		character->cycleHair(reverse);
		break;

	case MenuOption::FacialHair:
		character->cycleFacialHair(reverse);
		break;

	case MenuOption::Hat:
		character->cycleHat(reverse);
		break;

	case MenuOption::Head:
		character->cycleHead(reverse);
		break;

	case MenuOption::Extra:
		character->cycleExtra(reverse);
		break;

	case MenuOption::Shoes:
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
			currentPart = static_cast<MenuOption>(currentPart - 1);
			if (currentPart < 0) currentPart = static_cast<MenuOption>(currentPart + MenuOption::MenuOptionCount);
			break;

		case ALLEGRO_KEY_DOWN:
			currentPart = static_cast<MenuOption>((currentPart + 1) % MenuOption::MenuOptionCount);
			break;

		case ALLEGRO_KEY_LEFT:
			cyclePart(true);
			break;

		case ALLEGRO_KEY_RIGHT:
			cyclePart(false);
			break;

		case ALLEGRO_KEY_ENTER:
		case ALLEGRO_KEY_PAD_ENTER:
			switch (currentPart)
			{
			case MenuOption::Randomizer:
				character->randomize();
				break;

			case MenuOption::Play:
				// TODO
				break;

			case MenuOption::Quit:
				game->quit();
				break;

			default:
				cyclePart(false);
				break;
			}
			break;
		}
	}
}