#ifndef COURSESCENE_H
#define COURSESCENE_H

#include "raylib.h"
#include <string>
 
#include "Registry.h"
#include "Scene.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"

#include "Components.h"
#include "../Components/ConvertType.h"
#include "../Components/Course.h"

#include "InsertFunction.h"
#include "RemoveFunction.h"
class CourseScene : public Scene {
private:
    TextBox title, courseID, classID, name, teacher, credit, maxEnroll, weekday, session, invalid;

    InputBox addBox, removeBox, fileBox;

    Button viewStudent, add, remove, fileButton, viewScore, updateBox, back;
public:
    CourseScene();
    Scene* process();
    void render();
};

#endif