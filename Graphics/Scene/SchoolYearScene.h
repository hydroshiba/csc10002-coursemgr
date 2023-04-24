#ifndef SCHOOLYEARSCENE_H
#define SCHOOLYEARSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects\TextBox.h"
#include "Objects\Dropbox.h"

class SchoolYearScene : public Scene {
private:
    TextBox nameScene;

    TextBox viewClass;
    TextBox addClass;
    TextBox removeClass;
    TextBox editYear;
public:
    SchoolYearScene();
    void render();
    Scene* process();
};

#endif //SCHOOLYEARSCENE_H