#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "FontManager.hpp"

FontManager::FontManager() : builtin(NULL)
{
	al_init_font_addon();
}

FontManager::~FontManager()
{
	if (builtin)
		al_destroy_font(builtin);

	al_shutdown_font_addon();
}

ALLEGRO_FONT *FontManager::getBuiltinFont()
{
	if (!builtin)
		builtin = al_create_builtin_font();

	return builtin;
}