#ifndef REGISTRY_H
#define REGISTRY_H

#include "Scene.h"

class Registry {
public:
	Scene* blank;
	Scene* login;
	Scene* courseScene;
	Scene* courseScene2;
	Scene* listSchoolYearScene;
	Scene* schoolYearScene;
	Scene* studentScene;
	Scene* staffScene;
	Scene* staffScene2;
	Scene* studentScoreboardsScene;
	Scene* listAcademicYearScene;
	Scene* academicYearScene;
	Scene* semesterScene;
	Scene* classScene;
	Registry(): 
	blank(nullptr), 
	login(nullptr), 
	studentScene(nullptr),
	staffScene(nullptr),
	staffScene2(nullptr),
	studentScoreboardsScene(nullptr),
	courseScene(nullptr), 
	courseScene2(nullptr), 
	schoolYearScene(nullptr),
	listSchoolYearScene(nullptr),
	listAcademicYearScene(nullptr),
	academicYearScene(nullptr),
	semesterScene(nullptr),
	classScene(nullptr) {}
};

extern Registry registry;

#endif