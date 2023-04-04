#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "raylib.h"

#include "Constants.h"
#include "Graphics.h"

#include "Button.h"
#include "TextBox.h"
#include "Menu.h"

class Application {
private:
	Vector2 mousePoint = { 0.0f, 0.0f };
	Menu menu;
	Scene* scene;

	void render();
	void process();

public:
	Application();
	~Application();
	Application(const Application &other) = delete;
	Application& operator=(const Application &other) = delete;

	bool appShouldClose() const;
	void tick();
};

#endif