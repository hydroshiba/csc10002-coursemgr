#ifndef MENU_H
#define MENU_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"
#include "Objects/DropBox.h"

class Menu : public Scene {
private:
	Button login;
	Button quit;

	TextBox title, invalid;
	InputBox username, password;

	DropBox test;

public: 
	Menu();
	Scene* process();
	void render();
};

#endif