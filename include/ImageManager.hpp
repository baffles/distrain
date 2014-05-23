#ifndef __IMAGEMANAGER_HPP
#define __IMAGEMANAGER_HPP

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