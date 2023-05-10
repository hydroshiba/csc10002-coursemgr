#ifndef REGISTRY_H
#define REGISTRY_H

#include "Scene.h"

class Registry {
public:
	Scene* blank;
	Scene* login;
	Scene* courseScene;
	Scene* listSchoolYearScene;
	Scene* schoolYearScene;
	Scene* studentScene;
	Scene* staffScene;
	Scene* staffScene2;
	Scene* listAcademicYearScene;
	Scene* academicYearScene;
	Scene* semesterScene;
	Scene* classScene;
	Scene* editScoreboardCourse;
	Registry(): 
	blank(nullptr), 
	login(nullptr), 
	studentScene(nullptr),
	staffScene(nullptr),
	staffScene2(nullptr),
	courseScene(nullptr), 
	schoolYearScene(nullptr),
	listSchoolYearScene(nullptr),
	listAcademicYearScene(nullptr),
	academicYearScene(nullptr),
	semesterScene(nullptr),
	classScene(nullptr),
	editScoreboardCourse(nullptr){}
};

extern Registry registry;

#endif