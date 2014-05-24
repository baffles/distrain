#ifndef __SCENE_HPP
#define __SCENE_HPP

#include <allegro5/allegro.h>

class Scene
{
public:
	virtual void tick(double delta) = 0;
	virtual void render() = 0;
	virtual void handleInputEvent(const ALLEGRO_EVENT &event) = 0;
};

class HasScene
{
protected:
	HasScene();
	~HasScene();

	Scene *currentScene;

public:
	void setScene(Scene *scene);
};

#endif