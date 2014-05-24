#ifndef __TILEMAP_HPP
#define __TILEMAP_HPP

#include <string>
#include <allegro5/allegro.h>

class TileSet
{
private:
	ALLEGRO_BITMAP *tileset;
	int perRow;

public:
	static const int TileWidth = 32;
	static const int TileHeight = 32;

	TileSet(ALLEGRO_BITMAP *tileset);
	~TileSet();

	void draw(int tile, float x, float y) const;
};

enum TileCellFlag
{
	None,
	Overlay,
	AutoWarp,
	Warp,
	SpecialUse
};

class TileMap
{
public:
	static const int ScreenWidth = 640 / TileSet::TileWidth;
	static const int ScreenHeight = 480 / TileSet::TileHeight;

private:
	void load(std::string filename);

public:
	TileMap(std::string filename);
	~TileMap();

	struct TileCell
	{
		int tile;
		bool blocking;
		TileCellFlag flag;
		int flagArg;
	} cells[ScreenHeight][ScreenWidth];
};

class TileEngine
{
private:
	TileSet *tileSet;
	TileMap *currentMap;

public:
	TileEngine(TileSet *tileSet);
	~TileEngine();

	void setMap(TileMap *map);

	bool isBlocking(int x, int y) const;
	void renderBase() const;
	void renderOverlay() const;
};

#endif