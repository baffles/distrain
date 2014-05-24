#ifndef __WORLD_HPP
#define __WORLD_HPP

#include <map>
#include <stack>
#include "Constants.hpp"

class CharacterActor;
class TileEngine;
class TileMap;

struct WorldState
{
	int mapId;
	Constants::Direction heading;
	float x, y;

	WorldState(int mapId, Constants::Direction heading, float x, float y);
};

class World
{
private:
	TileEngine *engine;
	CharacterActor *player;

	std::map<int, TileMap*> maps;
	int currentMapId;
	TileMap *currentMap;

	std::stack<WorldState> states;
	WorldState getCurrentState() const;

	void warpTo(int id);
	void returnToState(WorldState state);

public:
	World(TileEngine *engine, CharacterActor *player);
	~World();

	int getCurrentMapId() const;
	TileMap *getCurrentMap() const;
	TileMap *getMap(int id) const;

	void tick();
	void playerUse();
};

#endif