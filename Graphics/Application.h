#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "raylib.h"

#include "Scene/Scene.h"
#include "Scene/Registry.h"

#include "Scene/Blank.h"
#include "Scene/Login.h"
#include "Scene/StudentScene.h"
#include "Scene/StaffScene.h"
#include "Scene/AddStudentScene.h"
#include "Scene/CourseScene.h"
#include "Scene/EditCourse.h"
#include "Scene/SchoolYearScene.h"
#include "Scene/ListSchoolYearScene.h"
#include "Scene/StudentScoreboardsScene.h"

class Application {
private:
	Vector2 mousePoint = { 0.0f, 0.0f };
	Scene* scene;

	void render();
	void process();

public:
	Application();
	~Application();
	Application(const Application &other) = delete;
	Application& operator=(const Application &other) = delete;

	bool shouldClose() const;
	void run();
};

#endif