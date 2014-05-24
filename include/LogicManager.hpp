#ifndef __LOGICMANAGER_HPP
#define __LOGICMANAGER_HPP

#include <vector>

class Scene;

class LogicManager
{
private:
	Scene *currentScene;
	double lastTick;

public:
	LogicManager();
	~LogicManager();

	void setScene(Scene *scene);

	void tick();
};

class HasLogic
{
public:
	virtual void tick(double delta) = 0;
};

#endif