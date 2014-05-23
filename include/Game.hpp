#ifndef __GAME_HPP
#define __GAME_HPP

class ResourceManager;
class Display;
class RenderController;
class GameLoop;
class GameTimer;

class TestScene;

class Game
{
private:
	ResourceManager *resourceManager;
	Display *display;
	RenderController *renderer;
	GameLoop *loop;
	GameTimer *timer;

	//temp
	TestScene *scene;
	
public:
	Game();
	~Game();

	void run();

	ResourceManager *getResourceManager();
	Display *getDisplay();
	RenderController *getRenderer();
	GameLoop *getLoop();
};

#endif