#ifndef REGISTRY_H
#define REGISTRY_H

#include "Scene.h"

class Registry {
public:
	Scene* blank;
	Scene* login;
	Scene* courseScene;
	Scene* editScene;
	Scene* listSchoolYearScene;
	Scene* schoolYearScene;
	Scene* studentScene;
	Scene* staffScene;
	Scene* staffScene2;
	Scene* studentScoreboardsScene;
	Scene* listAcademicYearScene;
	Registry(): 
	blank(nullptr), 
	login(nullptr), 
	studentScene(nullptr),
	staffScene(nullptr),
	staffScene2(nullptr),
	studentScoreboardsScene(nullptr),
	courseScene(nullptr), 
	editScene(nullptr), 
	schoolYearScene(nullptr),
	listSchoolYearScene(nullptr),
	listAcademicYearScene(nullptr) {}
};

extern Registry registry;

#endif