#include <cstdlib>
#include <exception>
#include <iostream>
#include "Game.hpp"
#include "CharacterCustomizer.hpp"

//temp
#include "Character.hpp"
#include "ResourceManager.hpp"
#include "Tilemap.hpp"
#include "TestScene.hpp"

using namespace std;

int main(int argc, char **argv[])
{
	srand(time(NULL));

	Game *game;

	try
	{
		game = new Game();
	}
	catch (exception& e)
	{
		cerr << "Error initializing game: " << e.what() << endl;
		return -1;
	}

	//game->setScene(new CharacterCustomizer(game));

	game->getCharacter()->randomize();
	game->setScene(new TestScene(game->getCharacter(), new TileEngine(new TileSet(game->getResourceManager()->getImageManager()->getImage("data/open_tileset.png")))));

	game->run();

	return 0;
}