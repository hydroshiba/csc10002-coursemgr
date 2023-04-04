#include <cassert>
#include <iostream>

#include "raylib.h"

#include "Application.h"
#include "Text.h"

#include "TextBox.h"
#include "InputBox.h"

#include "Menu.h"

Application::Application() {
    menu.app = this;
    scene = &menu;
}

Application::~Application() {
    if(GetWindowHandle() == nullptr) return;
    CloseWindow();
}

bool Application::appShouldClose() const {
	return (GetWindowHandle() == nullptr || WindowShouldClose());
}

void Application::tick() {
    BeginDrawing();
    process();

    if(GetWindowHandle() == nullptr) return;

    render();
    EndDrawing();
}

void Application::render() {
    ClearBackground(RAYWHITE);
    scene->render();
}

void Application::process() {
    mousePoint = GetMousePosition();

    if(scene) scene = scene->process();
    else CloseWindow();
}