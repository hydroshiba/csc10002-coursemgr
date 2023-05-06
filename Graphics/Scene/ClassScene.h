#ifndef ClassSCENE_H
#define ClassSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"
#include "Objects/Button.h"

class ClassScene : public Scene {
private:
    TextBox sceneTitle;

    TextBox addStudentLabel;
    InputBox addStudentInput;
    Button addStudentButton;
    Button addStudentByFileButton;

    TextBox removeStudentLabel;
    InputBox removeStudentInput;
    Button removeStudentButton;

    TextBox changeClassnameLabel;
    InputBox changeClassnameInput;
    Button changeClassnameButton;

    TextBox viewStudentListLabel;
    InputBox pathExportStudentList;
    Button viewStudentListButton;

    TextBox viewScoreboardLabel;
    InputBox pathExportScoreboard;
    Button viewScoreboardButton;

    Button back;

public:
    ClassScene();
    void render();
    Scene* process();
};

#endif