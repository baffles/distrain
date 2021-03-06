#include <cmath>
#include "Actor.hpp"
#include "Constants.hpp"
#include "Tilemap.hpp"

using namespace std;
using Constants::Direction;

Actor::Actor(TileEngine *engine) : engine(engine), moving(false), x(0), y(0), direction(Direction::Down), velocity(0)
{
}

Actor::~Actor()
{
}

void Actor::startMoving()
{
	moving = true;
}

void Actor::stopMoving()
{
	moving = false;
}

bool Actor::isMoving() const
{
	return moving;
}

void Actor::setX(float x)
{
	this->x = x;
}

float Actor::getX() const
{
	return x;
}

void Actor::setY(float y)
{
	this->y = y;
}

float Actor::getY() const
{
	return y;
}

void Actor::setDirection(Direction direction)
{
	this->direction = direction;
}

Direction Actor::getDirection() const
{
	return direction;
}

void Actor::setVelocity(float velocity)
{
	this->velocity = velocity;
}

float Actor::getVelocity() const
{
	return velocity;
}

bool Actor::checkCollision(int proposedX, int proposedY) const
{
	// this is very naive... it works as long as deltas are small. if logic hiccups
	// then the player may be able to pass beyond an obstacle (if x/y jumps)
	return engine->isBlocking(proposedX, proposedY);
}

void Actor::tick(double delta)
{
	if (moving)
	{
		float dist = delta * velocity;

		int rx = floor(x), ry = floor(y);

		switch (direction)
		{
		case Direction::Left:
			if (!checkCollision(floor(x - 0.5f - dist), ry))
				x -= dist;
			else
				stopMoving();
			break;

		case Direction::Right:
			if (!checkCollision(floor(x + 0.5f + dist), ry))
				x += dist;
			else
				stopMoving();
			break;

		case Direction::Up:
			if (!checkCollision(rx, floor(y - 0.5f - dist)))
				y -= dist;
			else
				stopMoving();
			break;

		case Direction::Down:
			if (!checkCollision(rx, floor(y + dist)))
				y += dist;
			else
				stopMoving();
			break;
		}
	}
}

void Actor::render() const
{
	renderAt(x * Constants::TileWidth, y * Constants::TileHeight);
}