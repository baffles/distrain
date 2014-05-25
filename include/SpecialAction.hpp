#ifndef __SPECIALACTION_HPP
#define __SPECIALACTION_HPP

#include <allegro5/allegro.h>
#include "Scene.hpp"

class Game;
class SpecialActionDelegate;

class SpecialAction : public Scene
{
private:
	SpecialActionDelegate *delegate;

protected:
	SpecialAction(SpecialActionDelegate *delegate);
	~SpecialAction();

	void dismiss();

public:
	virtual void render();
};

class SpecialActionDelegate
{
private:
	Game *game;
	Scene *parentScene;
	SpecialAction *active;

	void dismissAction(SpecialAction *action);
	void prerender();

	friend SpecialAction;

protected:
	SpecialActionDelegate(Game *game, Scene *parentScene);
	~SpecialActionDelegate();

	void activateAction(SpecialAction *action);
};

#endif