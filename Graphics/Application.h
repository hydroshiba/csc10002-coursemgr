#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "raylib.h"

#include "Constants.h"
#include "Graphics.h"

#include "Button.h"
#include "Menu.h"

class Application {
public:
	Application(int width = app_const::width, int height = app_const::height, int fps = app_const::fps, std::string title = app_const::title);
	~Application() noexcept;

	Application(const Application &other) = delete;
	Application& operator=(const Application &other) = delete;

	bool appShouldClose() const;
	void tick();

private:
	Vector2 mousePoint = { 0.0f, 0.0f };

	void render();
	void update();
};

#endif