#ifndef SCHOOLYEARSCENE_H
#define SCHOOLYEARSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"

#include "Scene/Blank.h"
#include "Components.h"
#include "SchoolYear.h"
#include "Class.h"

#include <iostream>
class SchoolYearScene : public Scene {
private:
    TextBox sceneTitle;

    TextBox viewClass;
    DropBox listClass;
    Button view;
    TextBox warningViewClass;
    bool isAnyClassChosen;
    int frameCounterViewClass;

    TextBox addClass;
    InputBox inputClassAdded;
    Button add;
    TextBox warningClassAdded;
    bool isClassAddedEmpty;
    bool isAddClicked;
    int frameCounterAddWarning;

    TextBox removeClass;
    InputBox inputClassRemoved;
    Button remove;
    TextBox warningClassRemoved;
    bool isClassRemovedEmpty;
    bool isRemoveClicked;
    int frameCounterRemoveWarning;

    TextBox editYear;
    InputBox inputStartYear;
    Button change;
    TextBox warningStartYear;
    bool isStartYearEmpty;
    bool isChangeClicked;
    int frameCounterChangeWarning;

    Button back;

public:
    SchoolYearScene();
    void render();
    Scene* process();
};

#endif //SCHOOLYEARSCENE_H