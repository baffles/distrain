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

class CharacterCustomizer;
class GameScene;

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

	CharacterCustomizer *characterCustomizer;
	GameScene *gameScene;

	Character *character;
	Scene *currentScene;
	
public:
	Game();
	~Game();

	void run();
	void quit();

	void setScene(Scene *scene);

	ResourceManager *getResourceManager() const;
	Display *getDisplay() const;
	RenderController *getRenderer() const;
	KeyboardManager *getKeyboardManager() const;
	GameLoop *getLoop() const;

	Character *getCharacter() const;

	CharacterCustomizer *getCharacterCustomizer() const;
	GameScene *getGameScene() const;
};

#endif