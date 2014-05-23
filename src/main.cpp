#include <exception>
#include <iostream>
#include "Game.hpp"

using namespace std;

int main(int argc, char **argv[])
{
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

	game->run();

	return 0;
}