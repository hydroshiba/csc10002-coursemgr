#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

const int defWidth = 800;
const int defHeight = 450;
const int defFPS = 60;

const std::string defTitle = "Course Management System";

class Application {
public:
	Application(int width = defWidth, int height = defHeight, int fps = defFPS, std::string title = defTitle);
	~Application() noexcept;

	Application(const Application &other) = delete;
	Application& operator=(const Application &other) = delete;

	bool AppShouldClose() const;
	void Tick();

private:
	void Display();
	void Update();
};

#endif