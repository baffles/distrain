#ifndef __ACTOR_HPP
#define __ACTOR_HPP

#include "Constants.hpp"

class TileEngine;

class Actor
{
private:
	TileEngine *engine;

	bool moving;
	float x, y;
	Constants::Direction direction;
	float velocity;

	bool checkCollision(int proposedX, int proposedY) const;

protected:
	Actor(TileEngine *engine);
	~Actor();

	void setX(float x);
	void setY(float y);
	void setDirection(Constants::Direction direction);
	void setVelocity(float velocity);

	virtual void startMoving();
	virtual void stopMoving();

	virtual void renderAt(float x, float y) const = 0;

public:
	bool isMoving() const;
	float getX() const;
	float getY() const;
	Constants::Direction getDirection() const;
	float getVelocity() const;

	virtual void tick(double delta);
	void render() const;
};

#endif