#ifndef __ANIMATION_HPP
#define __ANIMATION_HPP

class Animation
{
private:
	bool active;
	double frame;
	float frameRate;
	int numFrames;

protected:
	Animation(float frameRate, int numFrames);
	~Animation();

	bool isActive() const;
	void startAnimation();
	void stopAnimation();

	void setFrameRate(float frameRate);
	void setNumFrames(int numFrames);

	int getCurrentAnimationFrame() const;

public:
	void tick(double delta);
};

#endif