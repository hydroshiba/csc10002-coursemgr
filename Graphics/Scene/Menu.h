#ifndef MENU_H
#define MENU_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"
#include "Objects/Dropbox.h"

class Menu : public Scene {
private:
	Button login;
	Button quit;

	TextBox title;
	InputBox username, password;

	Dropbox drop;

public: 
	Menu();
	Scene* process();
	void render();
};

#endif