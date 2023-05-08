#ifndef SEMESTERSCENE_H
#define SEMESTERSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"
#include "Objects/Button.h"

#include "InsertFunction.h"
#include "RemoveFunction.h"
#include "SearchFunction.h"
#include "ImportAndExportFunction.h"
#include "DisplayFunction.h"
#include "UpdateFunction.h"
#include "Semester.h"
#include "AcademicYear.h"
class SemesterScene : public Scene {
private:
    TextBox sceneTitle;

    TextBox textAddCourse;
    InputBox inputAddCourse;
    Button buttonAddCourse;

    TextBox textRemoveCourse;
    InputBox inputRemoveCourse;
    Button buttonRemoveCourse;

    TextBox textSemesterID;
    InputBox inputSemesterID;
    Button buttonSemesterID;

    TextBox textStartDate;
    InputBox inputStartDate;
    Button buttonStartDate;

    TextBox textEndDate;
    InputBox inputEndDate;
    Button buttonEndDate;

    TextBox textExport;
    InputBox inputExport;
    Button buttonExport;

    TextBox textView;
    DropBox listCourse;
    Button view;

    TextBox ms;

    Button back;

public:
    SemesterScene();
    void render();
    Scene* process();
};

#endif