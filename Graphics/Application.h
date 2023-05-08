#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "raylib.h"

#include "Scene/Scene.h"
#include "Scene/Registry.h"

#include "Scene/Login.h"
#include "Scene/StudentScene.h"
#include "Scene/StaffScene.h"
#include "Scene/StaffScene2.h"
#include "Scene/CourseScene.h"
#include "Scene/SchoolYearScene.h"
#include "Scene/ListSchoolYearScene.h"
#include "Scene/StudentScoreboardsScene.h"
#include "Scene/ListAcademicYearScene.h"
#include "Scene/AcademicYearScene.h"
#include "Scene/SemesterScene.h"
#include "Scene/ClassScene.h"
#include "Scene/EditScoreboardScene.h"
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