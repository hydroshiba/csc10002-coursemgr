#include <cassert>
#include <iostream>

#include "raylib.h"
#include "Graphics.h"
#include "Text.h"
#include "TextBox.h"

Application::Application(int width, int height, int fps, std::string title) {
    assert(GetWindowHandle() == nullptr);
    
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
}

Application::~Application() noexcept {
    assert(GetWindowHandle() != nullptr);
    CloseWindow();
}

bool Application::appShouldClose() const {
	return WindowShouldClose();
}

void Application::tick() {
    BeginDrawing();

    mousePoint = GetMousePosition();

    update();
    display();
    
    EndDrawing();
}

void Application::display() {
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, RED);
    Text content("fuck raylib imma jump from the roof", 21);
    TextBox newBox(Vector2{100, 300}, content);
    newBox.display();
}

void Application::update() {

}