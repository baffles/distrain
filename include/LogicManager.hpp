#ifndef __LOGICMANAGER_HPP
#define __LOGICMANAGER_HPP

#include <vector>
#include "Scene.hpp"

class LogicManager : public HasScene
{
private:
	double lastTick;

public:
	LogicManager();
	~LogicManager();

	void tick();
};

class HasLogic
{
public:
	virtual void tick(double delta) = 0;
};

#endif