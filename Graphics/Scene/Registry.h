#ifndef REGISTRY_H
#define REGISTRY_H

#include "Scene.h"

class Registry {
public:
	Scene* blank;
	Scene* login;
	Scene* courseScene;
	Scene* editScene;
	Scene* editListSchoolYearScene;
	Scene* editSchoolYearScene;
	Scene* studentScene;
	Scene* staffScene;
	Scene* staffScene2;
	Scene* studentScoreboardsScene;
	Registry(): 
	blank(nullptr), 
	login(nullptr), 
	studentScene(nullptr),
	staffScene(nullptr),
	staffScene2(nullptr),
	studentScoreboardsScene(nullptr),
	courseScene(nullptr), 
	editScene(nullptr), 
	editSchoolYearScene(nullptr),
	editListSchoolYearScene(nullptr) {}
};

extern Registry registry;

#endif