#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "Graphics.h"

#include "Button.h"
#include "Scene.h"

class Menu : public Scene {
private:
	Button login;

public: 
	Menu();
	Scene* process();
	void render();
};

#endif