#ifndef EDIT_COURSE_H
#define EDIT_COURSE_H

#include "raylib.h"

#include "Registry.h"
#include "Scene.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"


class EditCourse : public Scene{
private: 
    TextBox title, courseID, classID, name, teacher, weekday, session;
    InputBox courseBox, classBox, nameBox, teacherBox, dayBox, sessionBox;
    Button change, back;
public:
    EditCourse();
    Scene *process();
    void render();
};

#endif