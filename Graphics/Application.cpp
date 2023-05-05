#include "Application.h"

Application::Application() {
    SetTargetFPS(app_const::fps);
    InitWindow(app_const::width, app_const::height, app_const::title.c_str());

    registry.login = new Login();
    registry.studentScene = new StudentScene();
    registry.staffScene = new StaffScene();
    registry.staffScene2 = new StaffScene2();
    registry.studentScoreboardsScene = new StudentScoreBoardsScene();
    registry.blank = new Blank();
    registry.courseScene = new CourseScene();
    registry.editScene = new EditCourse();
    registry.schoolYearScene = new SchoolYearScene();
    registry.listSchoolYearScene = new ListSchoolYearScene();
    registry.listSchoolYearScene = new ListSchoolYearScene();
    registry.academicYearScene = new AcademicYearScene();
    scene = registry.login;
}

Application::~Application() {
    if(GetWindowHandle() == nullptr) return;
    CloseWindow();

    delete registry.login;
    delete registry.studentScene;
    delete registry.staffScene;
    delete registry.staffScene2;
    delete registry.studentScoreboardsScene;
    delete registry.blank;
    delete registry.courseScene;
    delete registry.editScene;
    delete registry.schoolYearScene;
    delete registry.listSchoolYearScene;
}

bool Application::shouldClose() const {
	return (scene == nullptr || WindowShouldClose());
}

void Application::run() {
    BeginDrawing();
    render();
    process();
    EndDrawing();
}

void Application::render() {
    ClearBackground(RAYWHITE);
    scene->render();
}

void Application::process() {
    mousePoint = GetMousePosition();
    if(scene) scene = scene->process();
}