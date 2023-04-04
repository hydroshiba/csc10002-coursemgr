#include <cassert>
#include <iostream>

#include "raylib.h"

#include "Application.h"
#include "Text.h"

#include "TextBox.h"
#include "InputBox.h"

#include "Menu.h"

bool Application::appShouldClose() const {
	return WindowShouldClose();
}

void Application::tick() {
    BeginDrawing();

    mousePoint = GetMousePosition();

    update();
    render();
    
    EndDrawing();
}

void Application::render() {
    ClearBackground(RAYWHITE);
    
    boxx = "Course Management System";
    boxx.setSize(75);
    boxx.setPos({300, 300});

    boxx.centerX();
    boxx.setY(boxx.getPos().y / 2);
    boxx.render();

    butt.setSize({150, 75});
    butt.setPos({300, 300});
    butt.label = "click me!";
    butt.centerX();
    butt.setY((butt.getPos().y * 3) / 2);

    butt.render(mousePoint);

    if(butt.clicked(mousePoint)) {
        std::cout <<  "CLICKED!" << std::endl;
        std::cout << mousePoint.x << ' ' << mousePoint.y << std::endl;
    }
    
    //InputBox example({400, 200}, 55);
    //example.draw();
}

void Application::update() {

}