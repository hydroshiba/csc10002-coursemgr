#include <cassert>
#include <iostream>

#include "raylib.h"

#include "Graphics.h"
#include "Text.h"
#include "TextBox.h"

#include "Menu.h"

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

    TextBox boxx({200, 300}, Text("lorem ipsum dolores met", 55), RAYWHITE);
    boxx.display();

    Button butt({300, 300}, {125, 50}, "click me!");
    butt.centerX();
    butt.setY((butt.getPos().y * 3) / 2);

    butt.display(mousePoint);

    if(butt.clicked(mousePoint)) {
        std::cout <<  "CLICKED!" << std::endl;
        std::cout << mousePoint.x << ' ' << mousePoint.y << std::endl;
    }
}

void Application::update() {

}