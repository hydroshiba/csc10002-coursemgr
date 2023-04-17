#ifndef REGISTRY_H
#define REGISTRY_H

#include "Scene.h"

class Registry {
public:
	Scene* blank;
	Scene* login;
	Scene* courseScene;

	Registry() : blank(nullptr), login(nullptr), courseScene(nullptr) {}
};

extern Registry registry;

#endif