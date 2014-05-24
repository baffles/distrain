#ifndef __RESOURCEMANAGER_HPP
#define __RESOURCEMANAGER_HPP

class FontManager;
class ImageManager;

class ResourceManager
{
private:
	FontManager *fontManager;
	ImageManager *imageManager;

public:
	ResourceManager();
	~ResourceManager();

	FontManager *getFontManager();
	ImageManager *getImageManager();
};

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

#include <map>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class ImageManager
{
private:
	std::map<std::string, ALLEGRO_BITMAP*> images;

public:
	ImageManager();
	~ImageManager();

	ALLEGRO_BITMAP *getImage(std::string path);
};

#endif