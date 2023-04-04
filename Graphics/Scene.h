#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"
#include "Graphics.h"

class Scene {
protected:
	Application* app;
	Vector2 mousePoint = { 0.0f, 0.0f };

	virtual void render() {}
	virtual Scene* process() {}
};

#endif