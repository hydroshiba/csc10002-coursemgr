#ifndef ACADEMICYEAR_SCENE_H
#define ACADEMICYEAR_SCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"
#include "Objects/Button.h"

#include "InsertFunction.h"
#include "RemoveFunction.h"
#include "DisplayFunction.h"
#include "ImportAndExportFunction.h"
#include "UpdateFunction.h"
#include "SearchFunction.h"

#include "AcademicYear.h"
class AcademicYearScene : public Scene {
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
    AcademicYearScene();
    void render();
    Scene* process();
};

#endif