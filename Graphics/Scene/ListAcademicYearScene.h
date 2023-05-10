#ifndef LISTACADEMICYEAR_SCENE_H
#define LISTACADEMICYEAR_SCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"
#include "Objects/Button.h"

#include "Components.h"
#include "InsertFunction.h"
#include "DisplayFunction.h"
#include "RemoveFunction.h"
#include "SearchFunction.h"
#include "AcademicYear.h"

class ListAcademicYearScene : public Scene {
private:
    TextBox sceneTitle;

    TextBox viewYear;
   
    Button view;

    TextBox addYear;
    InputBox inputAcademicYearAdded;
    Button add;

    TextBox removeYear;
    InputBox inputAcademicYearRemoved;
    Button remove;

    TextBox ms;

    Button back;
public:
    DropBox chooseAcademicYear;
    ListAcademicYearScene();
    void render();
    Scene* process();
};

#endif