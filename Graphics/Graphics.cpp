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

Font lmao;

void Application::display() {
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, RED);

    Button butt({300, 300}, {100, 50}, "click me!");
    butt.centerX();
    //butt.centerY();

    std::cout << butt.label.size().x << ' ' << butt.label.size().y << std::endl;

    butt.display(mousePoint);

    if(butt.clicked(mousePoint)) {
        std::cout <<  "CLICKED!" << std::endl;
        std::cout << mousePoint.x << ' ' << mousePoint.y << std::endl;
    }

    DrawFPS(0, 0);
}

void Application::update() {

}