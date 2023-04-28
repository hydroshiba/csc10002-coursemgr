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
    TextBox title, courseID, classID, name, teacher, credit, maxEnroll, weekday, session;
    InputBox courseBox, classBox, nameBox, teacherBox, creditBox, enrollBox, dayBox, sessionBox;
    Button change, back;

    TextBox result;
public:
    EditCourse();
    Scene *process();
    void render();
};

#endif