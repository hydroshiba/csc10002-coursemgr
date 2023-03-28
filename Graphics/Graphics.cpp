#include <cassert>
#include <raylib.h>

#include "Graphics.h"

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

    update();
    display();
    
    EndDrawing();
}

void Application::display() {
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, RED);
}

void Application::update() {

}