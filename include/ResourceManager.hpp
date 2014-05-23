#ifndef __RESOURCEMANAGER_HPP
#define __RESOURCEMANAGER_HPP

class FontManager;

class ResourceManager
{
private:
	FontManager *fontManager;

public:
	ResourceManager();
	~ResourceManager();

	FontManager *getFontManager();
};

#endif