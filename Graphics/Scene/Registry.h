#ifndef REGISTRY_H
#define REGISTRY_H

#include "Scene.h"

class Registry {
public:
	Scene* blank;
	Scene* menu;

	Registry() : blank(nullptr), menu(nullptr) {}
};

extern Registry registry;

#endif