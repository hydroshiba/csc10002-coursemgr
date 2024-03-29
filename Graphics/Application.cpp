#include "Application.h"

Application::Application() {
    SetTargetFPS(app_const::fps);
    InitWindow(app_const::width, app_const::height, app_const::title.c_str());

    registry.login = new Login();

    registry.studentScene = new StudentScene();
    registry.staffScene = new StaffScene();
    registry.staffScene2 = new StaffScene2();

    registry.schoolYearScene = new SchoolYearScene();
    registry.listSchoolYearScene = new ListSchoolYearScene();
    registry.classScene = new ClassScene();

    registry.listAcademicYearScene = new ListAcademicYearScene();
    registry.academicYearScene = new AcademicYearScene();
    registry.semesterScene = new SemesterScene();

    registry.courseScene = new CourseScene();
    registry.editScoreboardCourse = new EditScoreboardScene();

    scene = registry.login;
}

Application::~Application() {
    if(GetWindowHandle() == nullptr) return;
    CloseWindow();

    delete registry.login;
    delete registry.studentScene;
    delete registry.staffScene;
    delete registry.staffScene2;
    delete registry.blank;
    delete registry.courseScene;
    delete registry.schoolYearScene;
    delete registry.listSchoolYearScene;
    delete registry.classScene;
    delete registry.semesterScene;
    delete registry.academicYearScene;
    delete registry.listAcademicYearScene;
    delete registry.editScoreboardCourse;
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