#ifndef SCHOOLYEARSCENE_H
#define SCHOOLYEARSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"

class SchoolYearScene : public Scene {
private:
    TextBox nameScene;

    TextBox viewClass;
    DropBox listClass;

    TextBox addClass;
    InputBox inputClassNameAdded;

    TextBox removeClass;
    InputBox inputClassNameRemoved;

    TextBox editYear;
    InputBox inputYearEditted;
public:
    SchoolYearScene();
    void render();
    Scene* process();
};

#endif //SCHOOLYEARSCENE_H