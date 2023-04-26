#ifndef REGISTRY_H
#define REGISTRY_H

#include "Scene.h"

class Registry {
public:
	Scene* blank;
	Scene* login;
	Scene* courseScene;
	Scene* editScene;
	Scene* editSchoolYearScene;
	Scene* studentScene;
	Registry(): 
	blank(nullptr), 
	login(nullptr), 
	studentScene(nullptr),
	courseScene(nullptr), 
	editScene(nullptr), 
	editSchoolYearScene(nullptr) {}
};

extern Registry registry;

#endif