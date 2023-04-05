#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"
#include "Graphics.h"

class Scene {
protected:
	Vector2 mousePoint = { 0.0f, 0.0f };

public:
	Application* app;

	virtual void render() {}
	virtual Scene* process() { return nullptr; }
};

#endif