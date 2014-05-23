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

#endif