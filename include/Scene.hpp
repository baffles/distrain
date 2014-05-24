#ifndef __SCENE_HPP
#define __SCENE_HPP

class Scene
{
public:
	virtual void tick(double delta) = 0;
	virtual void render() = 0;
};

#endif