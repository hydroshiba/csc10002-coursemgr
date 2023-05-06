#ifndef LOGIN_H
#define LOGIN_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/Button.h"
#include "Objects/Dropbox.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"
#include "Objects/Table.h"

#include "Components.h"
#include "SearchFunction.h"

class Login : public Scene {
private:
	Button login;
	Button quit;

	TextBox title, invalid;
	InputBox username, password;

	Table table;

public: 
	Login();
	Scene* process();
	void render();
};

#endif