#ifndef COURSESCENE_H
#define COURSESCENE_H

#include "raylib.h"
 
#include "Registry.h"
#include "Scene.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"

#include "../Components/ConvertType.h"
#include "../Components/Course.h"

class CourseScene : public Scene {
private:
    TextBox title, courseID, classID, name, teacher, weekday, session, invalid;

    InputBox addBox, removeBox;

    Button viewStudent, add, remove, viewScore, updateBox, back;
public:
    CourseScene();
    CourseScene(const Course& course);
    Scene* process();
    void render();
};

#endif