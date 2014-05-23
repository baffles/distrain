#include "ResourceManager.hpp"
#include "FontManager.hpp"
#include "ImageManager.hpp"

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