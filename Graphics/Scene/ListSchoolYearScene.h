#ifndef LISTSCHOOLYEARSCENE_H
#define LISTSCHOOLYEARSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Button.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"

#include "Components.h"
#include "InsertFunction.h"
#include "DisplayFunction.h"
#include "RemoveFunction.h"
#include "SearchFunction.h"
#include "SchoolYear.h"
#include <iostream>

class ListSchoolYearScene : public Scene {
private:
    TextBox sceneTitle;
    
    TextBox viewYear;
    DropBox chooseSchoolYear;
    Button view;

    TextBox addYear;
    InputBox inputSchoolYearAdded;
    Button add;

    TextBox removeYear;
    InputBox inputSchoolYearRemoved;
    Button remove;

    TextBox ms;

    Button back;
public:
    ListSchoolYearScene();
    void render();
    Scene* process();
};

#endif //LISTSCHOOLYEARSCENE_H