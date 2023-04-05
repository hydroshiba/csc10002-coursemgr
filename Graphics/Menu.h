#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "raylib.h"

#include "Constants.h"
#include "Graphics.h"
#include "Scene.h"

#include "Button.h"
#include "TextBox.h"
#include "InputBox.h"

class Menu : public Scene {
private:
	Button login;
	Button quit;

	TextBox title;
	InputBox username, password;

public: 
	Menu();
	Scene* process();
	void render();
};

#endif