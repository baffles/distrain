#ifndef __TILEMAP_HPP
#define __TILEMAP_HPP

#include <string>
#include <allegro5/allegro.h>
#include "Constants.hpp"

class TileSet
{
private:
	ALLEGRO_BITMAP *tileset;
	int perRow;

public:
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
	PushAutoWarp,
	PushWarp,
	PopAutoWarp,
	PopWarp,
	SpecialUse
};

class TileMap
{
public:
	static const int ScreenWidth = 640 / Constants::TileWidth;
	static const int ScreenHeight = 480 / Constants::TileHeight;

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

	struct StartPosition
	{
		int x, y;
	} startPositions[4];
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