#include "Application.h"

Application::Application() {
    SetTargetFPS(app_const::fps);
    InitWindow(app_const::width, app_const::height, app_const::title.c_str());

    registry.login = new Login();
    registry.studentScene = new StudentScene();
    registry.staffScene = new StaffScene();
    registry.addStudentScene = new AddStudentScene();
    registry.blank = new Blank();
    registry.courseScene = new CourseScene();
    registry.editScene = new EditCourse();
    registry.editSchoolYearScene = new SchoolYearScene();
    registry.editListSchoolYearScene = new ListSchoolYearScene();

    scene = registry.login;
}

Application::~Application() {
    if(GetWindowHandle() == nullptr) return;
    CloseWindow();
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