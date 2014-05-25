#include <map>
#include "World.hpp"
#include "Constants.hpp"
#include "Character.hpp"
#include "Tilemap.hpp"

using namespace std;
using Constants::Direction;

World::World(TileEngine *engine, CharacterActor *player) : engine(engine), player(player), currentMap(NULL), currentMapId(-1)
{
	maps[0] = new TileMap("data/maps/house.map");
	maps[1] = new TileMap("data/maps/yard.map");

	// start in the yard real quick, just so we can push a state for when we exit the house
	player->setDirection(Direction::Down);
	warpTo(1);
	player->setDirection(Direction::Up);
	pushState();

	player->setDirection(Direction::Down);
	warpTo(0);
}

World::~World()
{
	currentMap = NULL;
	for (auto it = maps.begin(); it != maps.end(); it++)
		delete it->second;
	maps.clear();
}

int World::getCurrentMapId() const
{
	return currentMapId;
}

TileMap *World::getCurrentMap() const
{
	return currentMap;
}

TileMap *World::getMap(int id) const
{
	auto mapIt = maps.find(id);
	if (mapIt == maps.end()) return NULL;
	return mapIt->second;
}

void World::tick()
{
	if (!currentMap) return;

	int x = floor(player->getX()), y = floor(player->getY());
	auto cell = currentMap->cells[y][x];

	switch (cell.flag)
	{
	case TileCellFlag::PushAutoWarp:
		pushState();
	case TileCellFlag::AutoWarp:
		warpTo(cell.flagArg);
		break;

	case TileCellFlag::PopAutoWarp:
		popState();
		break;
	}
}

void World::playerUse()
{
	if (!currentMap) return;

	// the player 'used' the current cell (so take the one they're looking at)
	int x = floor(player->getX()), y = floor(player->getY());

	switch (player->getDirection())
	{
	case Direction::Up:
		y--;
		break;
	case Direction::Down:
		y++;
		break;
	case Direction::Left:
		x--;
		break;
	case Direction::Right:
		x++;
		break;
	}

	auto cell = currentMap->cells[y][x];

	switch (cell.flag)
	{
	case TileCellFlag::PushWarp:
		pushState();
	case TileCellFlag::Warp:
		warpTo(cell.flagArg);
		break;

	case TileCellFlag::PopWarp:
		popState();
		break;

	case TileCellFlag::SpecialUse:
		//TODO
		break;
	}
}

WorldState World::getCurrentState() const
{
	return WorldState(currentMapId, player->getDirection(), player->getX(), player->getY());
}

void World::pushState()
{
	states.push(getCurrentState());
}

void World::popState()
{
	returnToState(states.top());
	states.pop();
}

void World::warpTo(int id)
{
	currentMapId = id;
	currentMap = getMap(id);
	engine->setMap(currentMap);

	auto startPos = currentMap->startPositions[player->getDirection()];
	player->setPosition(startPos.x + 0.5f, startPos.y + 0.5f);
}

void World::returnToState(WorldState state)
{
	currentMapId = state.mapId;
	currentMap = getMap(state.mapId);
	engine->setMap(currentMap);

	// turn player around when returning to an old state
	auto heading = static_cast<Direction>((state.heading + 2) % 4);
	player->setDirection(heading);

	auto x = state.x, y = state.y;

	// move player 1 block away (in their new direction)
	switch (heading)
	{
	case Direction::Up:
		y -= 1;
		break;

	case Direction::Down:
		y += 1;
		break;

	case Direction::Left:
		x -= 1;
		break;

	case Direction::Right:
		x += 1;
		break;
	}

	player->setPosition(x, y);
}



WorldState::WorldState(int mapId, Direction heading, float x, float y) : mapId(mapId), heading(heading), x(x), y(y)
{
}