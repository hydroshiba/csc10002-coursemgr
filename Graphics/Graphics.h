#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include "raylib.h"

#include "Button.h"

const int defWidth = 1280;
const int defHeight = 720;
const int defFPS = 60;

const std::string defTitle = "Course Management System";

class Application {
public:
	Application(int width = defWidth, int height = defHeight, int fps = defFPS, std::string title = defTitle);
	~Application() noexcept;

	Application(const Application &other) = delete;
	Application& operator=(const Application &other) = delete;

	bool appShouldClose() const;
	void tick();

private:
	Vector2 mousePoint = { 0.0f, 0.0f };

	void display();
	void update();
};

#endif