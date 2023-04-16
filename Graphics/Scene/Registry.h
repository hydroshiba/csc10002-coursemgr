#ifndef REGISTRY_H
#define REGISTRY_H

#include "Scene.h"

class Registry {
public:
	Scene* blank;
	Scene* login;

	Registry() : blank(nullptr), login(nullptr) {}
};

extern Registry registry;

#endif