#ifndef SEMESTERSCENE_H
#define SEMESTERSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"
#include "Objects/Button.h"

#include "InsertFunction.h"
#include "RemoveFunction.h"
#include "SearchFunction.h"
#include "ImportAndExportFunction.h"

class SemesterScene : public Scene {
private:
    TextBox sceneTitle;

    TextBox addStudentLabel;
    InputBox addStudentInput;
    Button addStudentButton;

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

    TextBox textSemesterID;
    InputBox inputSemesterID;

    TextBox textImport;
    InputBox inputImport;
    Button importBut;

    Button back;

public:
    SemesterScene();
    void render();
    Scene* process();
};

#endif