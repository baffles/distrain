#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <string>
#include <allegro5/allegro.h>
#include "Tilemap.hpp"

using namespace std;

TileSet::TileSet(ALLEGRO_BITMAP *tileset) : tileset(tileset)
{
	perRow = al_get_bitmap_width(tileset) / TileWidth;
}

TileSet::~TileSet()
{
}

void TileSet::draw(int tile, float x, float y) const
{
	int sx = (tile % perRow) * TileWidth;
	int sy = (tile / perRow) * TileHeight;
	al_draw_bitmap_region(tileset, sx, sy, TileWidth, TileHeight, x, y, 0);
}



TileMap::TileMap(string filename)
{
	load(filename);
}

TileMap::~TileMap()
{
}

// poor (read: almost zero) error handling here. it is speedhack, after all
void TileMap::load(string filename)
{
	ifstream file(filename);
	if (!file.is_open()) throw runtime_error("failed to open map " + filename);

	map<int, int> frontMatter;

	while (true)
	{
		// read front-matter
		string kvp;
		file >> kvp;

		if (kvp == "----")
			break;

		auto splitPos = kvp.find(':');
		string key = kvp.substr(0, splitPos);
		string val = kvp.substr(splitPos + 1, kvp.length() - splitPos - 1);

		frontMatter[stoi(key)] = stoi(val);
	}

	for (int y = 0; y < ScreenHeight; ++y)
		for (int x = 0; x < ScreenWidth; ++x)
		{
			string cell;
			file >> cell;

			auto splitPos = cell.find(',');
			string idS = cell.substr(0, splitPos);
			string flagS = cell.substr(splitPos + 1, cell.length() - splitPos - 1);

			cells[y][x].tile = stoi(idS);

			int flag = stoi(flagS);

			switch (flag / 10)
			{
			case 4:
			case 5:
			case 6:
				cells[y][x].flag = TileCellFlag::Overlay;
				cells[y][x].flagArg = frontMatter[flag];
				break;

			case 7:
				cells[y][x].flag = TileCellFlag::SpecialUse;
				cells[y][x].flagArg = frontMatter[flag];
				break;

			case 8:
				cells[y][x].flag = TileCellFlag::AutoWarp;
				cells[y][x].flagArg = frontMatter[flag];
				break;

			case 9:
				cells[y][x].flag = TileCellFlag::Warp;
				cells[y][x].flagArg = frontMatter[flag];
				break;

			case 0:
			default:
				cells[y][x].flag = TileCellFlag::None;
				cells[y][x].flagArg = 0;
				break;
			}
		}

	file.close();
}



TileEngine::TileEngine(TileSet *tileSet) : tileSet(tileSet)
{
}

TileEngine::~TileEngine()
{
}

void TileEngine::setMap(TileMap *map)
{
	currentMap = map;
}

void TileEngine::render() const
{
	if (!currentMap) return;

	for (int y = 0; y < TileMap::ScreenHeight; ++y)
		for (int x = 0; x < TileMap::ScreenWidth; ++x)
		{
			auto cell = currentMap->cells[y][x];
			auto dx = x * TileSet::TileWidth, dy = y * TileSet::TileHeight;

			tileSet->draw(cell.tile, dx, dy);

			if (cell.flag == TileCellFlag::Overlay)
				tileSet->draw(cell.flagArg, dx, dy);
		}
}