#include <stdexcept>
#include <map>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "ResourceManager.hpp"

using namespace std;

ResourceManager::ResourceManager() : fontManager(new FontManager()), imageManager(new ImageManager())
{
}

ResourceManager::~ResourceManager()
{
	delete fontManager;
	delete imageManager;
}

FontManager *ResourceManager::getFontManager()
{
	return fontManager;
}

ImageManager *ResourceManager::getImageManager()
{
	return imageManager;
}



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



ImageManager::ImageManager()
{
	if (!al_init_image_addon())
		throw runtime_error("failed to initialize image addon");
}

ImageManager::~ImageManager()
{
	for (auto it = images.begin(); it != images.end(); it++)
		al_destroy_bitmap(it->second);

	images.clear();

	al_shutdown_image_addon();
}

ALLEGRO_BITMAP *ImageManager::getImage(string path)
{
	auto imageIt = images.find(path);
	if (imageIt != images.end())
		return imageIt->second;

	ALLEGRO_BITMAP *image = al_load_bitmap(path.c_str());
	if (!image)
		throw runtime_error("failed to load image: " + path);

	images[path] = image;
	return image;
}