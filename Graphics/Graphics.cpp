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

bool Application::AppShouldClose() const {
	return WindowShouldClose();
}

void Application::Tick() {
    BeginDrawing();

    Update();
    Display();
    
    EndDrawing();
}

void Application::Display() {
    ClearBackground(RAYWHITE);
}

void Application::Update() {

}