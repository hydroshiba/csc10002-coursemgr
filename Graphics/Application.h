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
public:
	Application() {}
	Application(const Application &other) = delete;
	Application& operator=(const Application &other) = delete;

	bool appShouldClose() const;
	void tick();

private:
	Vector2 mousePoint = { 0.0f, 0.0f };
	Menu menu;
	Button butt;
	TextBox boxx;

	void render();
	void update();
};

#endif