#ifndef EDIT_COURSE_H
#define EDIT_COURSE_H

#include "raylib.h"

#include "Registry.h"
#include "Scene.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"

#include "Components.h"
#include "Course.h"
#include "ConvertType.h"
#include "UpdateFunction.h"

class EditCourse : public Scene{
private: 
    TextBox title, courseID, classID, name, teacher, credit, weekday, session;
    InputBox courseBox, classBox, nameBox, teacherBox, creditBox, dayBox, sessionBox;
    Button change, back;

    TextBox invalid;
public:
    EditCourse();
    Scene *process();
    void render();
};

#endif