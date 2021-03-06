#include <cstdlib>
#include <exception>
#include <iostream>
#include "Game.hpp"
#include "CharacterCustomizer.hpp"

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

	game->setScene(game->getCharacterCustomizer());
	game->run();

	return 0;
}