#include <allegro5/allegro.h>
#include "SpecialAction.hpp"
#include "Game.hpp"
#include "Scene.hpp"

SpecialAction::SpecialAction(SpecialActionDelegate *delegate) : delegate(delegate)
{
}

SpecialAction::~SpecialAction()
{
}

void SpecialAction::dismiss()
{
	delegate->dismissAction(this);
}

void SpecialAction::render()
{
	delegate->prerender();
}



SpecialActionDelegate::SpecialActionDelegate(Game *game, Scene *parentScene) : game(game), parentScene(parentScene), active(NULL)
{
}

SpecialActionDelegate::~SpecialActionDelegate()
{
}

void SpecialActionDelegate::activateAction(SpecialAction *action)
{
	if (active)
		dismissAction(active);

	active = action;
	game->setScene(action);
}

void SpecialActionDelegate::dismissAction(SpecialAction *action)
{
	if (action != active) return;

	active = NULL;
	game->setScene(parentScene);
}

void SpecialActionDelegate::prerender()
{
	if (active)
	{
		active->render();
		// fade out current display?
	}
}