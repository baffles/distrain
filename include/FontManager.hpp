#ifndef __FONTMANAGER_HPP
#define __FONTMANAGER_HPP

#include <allegro5/allegro_font.h>

class FontManager
{
private:
	ALLEGRO_FONT *builtin;

public:
	FontManager();
	~FontManager();

	ALLEGRO_FONT *getBuiltinFont();
};

#endif