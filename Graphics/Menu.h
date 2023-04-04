#ifndef MENU_H
#define MENU_H

#include "raylib.h"

#include "Button.h"
#include "Text.h"
#include "TextBox.h"

#include "Scene.h"

class Menu : public Scene {
	Button login;

	Menu();
	
};

#endif