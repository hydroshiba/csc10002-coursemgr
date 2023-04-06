#include "Application.h"

Application::Application() {
    registry.menu = &menu;
    registry.blank = &blank;

    scene = registry.menu;
}

Application::~Application() {
    if(GetWindowHandle() == nullptr) return;
    CloseWindow();
}

bool Application::appShouldClose() const {
	return (scene == nullptr || WindowShouldClose());
}

void Application::tick() {
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