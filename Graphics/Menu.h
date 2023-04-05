#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "raylib.h"

#include "Scene.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"

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