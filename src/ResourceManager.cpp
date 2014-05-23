#include "ResourceManager.hpp"
#include "FontManager.hpp"

ResourceManager::ResourceManager() : fontManager(new FontManager())
{
}

ResourceManager::~ResourceManager()
{
	delete fontManager;
}

FontManager *ResourceManager::getFontManager()
{
	return fontManager;
}