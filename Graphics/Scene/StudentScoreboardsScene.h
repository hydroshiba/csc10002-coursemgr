#ifndef STUDENTSCOREBOARDSSCENE_H
#define STUDENTSCOREBOARDSSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"
#include "Objects/Button.h"

#include "Components.h"
#include "Student.h"
class StudentScoreBoardsScene : public Scene {
private:
	TextBox sceneName;
	Button back;
public:
	StudentScoreBoardsScene();
	void render();
	Scene* process();
};

#endif