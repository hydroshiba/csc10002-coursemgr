#ifndef SCHOOLYEARSCENE_H
#define SCHOOLYEARSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects\TextBox.h"

class SchoolYearScene : public Scene {
private:
    TextBox content;
public:
    SchoolYearScene();
    void render();
    Scene* process();
};

#endif //SCHOOLYEARSCENE_H