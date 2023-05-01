#ifndef LOGIN_H
#define LOGIN_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"
#include "Objects/DropBox.h"

#include "../Components/Components.h"
#include "../Components/SearchFunction.h"

class Login : public Scene {
private:
	Button login;
	Button quit;

	TextBox title, invalid;
	InputBox username, password;

public: 
	Login();
	Scene* process();
	void render();
};

#endif