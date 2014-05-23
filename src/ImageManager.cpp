#include <stdexcept>
#include <map>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "ImageManager.hpp"

using namespace std;

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