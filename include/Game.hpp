#ifndef __GAME_HPP
#define __GAME_HPP

class ResourceManager;
class Display;
class LogicManager;
class RenderController;
class KeyboardManager;
class GameLoop;
class GameTimer;

class Character;
class Scene;

class Game
{
private:
	ResourceManager *resourceManager;
	Display *display;
	LogicManager *logicManager;
	RenderController *renderer;
	KeyboardManager *keyboardManager;
	GameLoop *loop;
	GameTimer *timer;

	Character *character;
	Scene *currentScene;
	
public:
	Game();
	~Game();

	void run();

	void setScene(Scene *scene);

	ResourceManager *getResourceManager();
	Display *getDisplay();
	RenderController *getRenderer();
	KeyboardManager *getKeyboardManager();
	GameLoop *getLoop();

	Character *getCharacter();
};

#endif