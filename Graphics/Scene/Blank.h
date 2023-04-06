#ifndef BLANK_H
#define BLANK_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"

class Blank : public Scene {
private:
	Button back;
	TextBox notice;

public: 
	Blank();
	Scene* process();
	void render();
};

#endif