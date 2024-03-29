#ifndef SCHOOLYEARSCENE_H
#define SCHOOLYEARSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"

#include "Components.h"
#include "SchoolYear.h"
#include "Class.h"
#include "ListSchoolYearScene.h"
#include "InsertFunction.h"
#include "RemoveFunction.h"
#include "DisplayFunction.h"
#include "ImportAndExportFunction.h"
#include "UpdateFunction.h"
#include "SearchFunction.h"
#include <iostream>

class SchoolYearScene : public Scene {
private:
    TextBox sceneTitle;

    TextBox viewClass;
    DropBox listClass;
    Button view;

    TextBox textAddClass;
    InputBox inputClassAdded;
    Button add;

    TextBox textRemoveClass;
    InputBox inputClassRemoved;
    Button remove;

    TextBox editYear;
    InputBox inputStartYear;
    Button change;

    TextBox exportOption;
    Button Export;
    InputBox exportPath;
    Button back;

    TextBox ms;

public:
    SchoolYearScene();
    void render();
    Scene* process();
};


#endif //SCHOOLYEARSCENE_H