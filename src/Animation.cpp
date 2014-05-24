#include "Animation.hpp"

Animation::Animation(float frameRate, int numFrames) : active(false), frame(0)
{
	setFrameRate(frameRate);
	setNumFrames(numFrames);
}

Animation::~Animation()
{
}

bool Animation::isActive()
{
	return active;
}

void Animation::startAnimation()
{
	active = true;
}

void Animation::stopAnimation()
{
	active = false;
}

void Animation::setFrameRate(float frameRate)
{
	this->frameRate = frameRate;
}

void Animation::setNumFrames(int numFrames)
{
	this->numFrames = numFrames;
}

int Animation::getCurrentAnimationFrame()
{
	return (int)frame;
}

void Animation::tick(double delta)
{
	if (active)
	{
		frame += frameRate * delta;
		while (frame >= numFrames)
			frame -= numFrames;
	}
}