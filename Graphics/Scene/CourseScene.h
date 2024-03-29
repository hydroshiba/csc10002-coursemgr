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
#include "Semester.h"
#include "ConvertType.h"
#include "UpdateFunction.h"
#include "InsertFunction.h"
#include "RemoveFunction.h"
#include "ImportAndExportFunction.h"

class CourseScene : public Scene{
private: 
    TextBox title, courseID, classID, name, teacher, credit, maxEnroll, weekday, session;
    InputBox courseBox, classBox, nameBox, teacherBox, creditBox, enrollBox, dayBox, sessionBox;
    Button viewStudent, add, remove, fileButton, viewScore, change, expButton, impScoreButton, back;

    InputBox addBox, removeBox, fileBox, impBox, impScoreBox, expBox;
    TextBox addText, removeText, fileText, impText, impScoreText, expText;

    TextBox result;
    TextBox test;
public:
    CourseScene();
    Scene *process();
    void render();
};

#endif