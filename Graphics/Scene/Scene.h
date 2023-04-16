#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"

class Scene {
protected:
	Vector2 mousePoint = { 0.0f, 0.0f };

public:
	virtual void render() {}
	virtual Scene* process() { return nullptr; }
};

#endif