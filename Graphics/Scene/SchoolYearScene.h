#ifndef SCHOOLYEARSCENE_H
#define SCHOOLYEARSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"

#include <iostream>
class SchoolYearScene : public Scene {
private:
    TextBox nameScene;

    TextBox viewClass;
    DropBox listClass;
    Button view;
    TextBox warningViewClass;
    bool isAnyClassChosen;

    TextBox addClass;
    InputBox inputClassNameAdded;
    Button add;

    TextBox removeClass;
    InputBox inputClassNameRemoved;
    Button remove;

    TextBox editYear;
    InputBox inputYearEditted;
    Button change;

    Button back;
public:
    SchoolYearScene();
    void render();
    Scene* process();
};

#endif //SCHOOLYEARSCENE_H