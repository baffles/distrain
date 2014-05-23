#ifndef __FONT_HPP
#define __FONT_HPP

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