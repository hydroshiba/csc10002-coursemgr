#include "SemesterScene.h"

bool isAddCourse = false;

const float buttonWidth = 150;
const float buttonHeight = 50;
const float inputWidth = 250;
const float inputHeight = 50;

const Vector2 buttonSize = { buttonWidth, buttonHeight };
const Vector2 inputSize = { inputWidth, inputHeight };

const float xDis = 180;
const float yDis = 50;
const float textSize = 30;

const float xPos1 = 50;
const float xPos2 = xPos1 + xDis;
const float xPos3 = xPos2 + inputSize.x;
const float xPos4 = 750;
const float xPos5 = xPos4 + inputSize.x;

const float yPos1 = 150;
const float yPos2 = yPos1 + inputSize.y + yDis;
const float yPos3 = yPos2 + inputSize.y + yDis;
const float yPos4 = yPos3 + inputSize.y + yDis;
const float yPos5 = yPos4 + inputSize.y + yDis;

const float yMid = -40;

SemesterScene::SemesterScene() {
    sceneTitle = "Semester";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(50);
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textAddCourse = "Add course";
    textAddCourse.setSize(textSize);
    textAddCourse.setPos({ xPos1, yPos1 });

    inputAddCourse.defaultText = "Enter CourseID";
    inputAddCourse.setPos({ xPos2, yPos1 });
    inputAddCourse.setSize(inputSize);

    buttonAddCourse.label = "Add";
    buttonAddCourse.setPos({ xPos3, yPos1 });
    buttonAddCourse.setSize(buttonSize);
    buttonAddCourse.setInsertColor();

    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textRemoveCourse = "Remove course";
    textRemoveCourse.setSize(textSize);
    textRemoveCourse.setPos({ xPos1, yPos2 });

    inputRemoveCourse.defaultText = "Enter CourseID";
    inputRemoveCourse.setPos({ xPos2, yPos2 });
    inputRemoveCourse.setSize(inputSize);

    buttonRemoveCourse.label = "Remove";
    buttonRemoveCourse.setPos({ xPos3, yPos2 });
    buttonRemoveCourse.setSize(buttonSize);
    buttonRemoveCourse.setRemoveColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textSemesterID = "SemesterID";
    textSemesterID.setSize(textSize);
    textSemesterID.setPos({ xPos1, yPos3 });

    inputSemesterID.defaultText = "New SemesterID";
    inputSemesterID.setPos({ xPos2, yPos3 });
    inputSemesterID.setSize(inputSize);

    buttonSemesterID.label = "Change";
    buttonSemesterID.setPos({ xPos3, yPos3 });
    buttonSemesterID.setSize(buttonSize);
    buttonSemesterID.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textStartDate = "Change start date:";
    textStartDate.setSize(textSize);
    textStartDate.setPos({ xPos4, yPos1 + yMid });

    inputStartDate.defaultText = "dd/mm/yyyy";
    inputStartDate.setPos({ xPos4, yPos1 });
    inputStartDate.setSize(inputSize);

    buttonStartDate.label = "Change";
    buttonStartDate.setPos({ xPos5, yPos1 });
    buttonStartDate.setSize(buttonSize);
    buttonStartDate.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    
    textEndDate = "Change end date:";
    textEndDate.setSize(textSize);
    textEndDate.setPos({ xPos4, yPos2 + yMid });

    inputEndDate.defaultText = "dd/mm/yyyy";
    inputEndDate.setPos({ xPos4, yPos2 });
    inputEndDate.setSize(inputSize);

    buttonEndDate.label = "Change";
    buttonEndDate.setPos({ xPos5, yPos2 });
    buttonEndDate.setSize(buttonSize);
    buttonEndDate.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textView = "List course";
    textView.setSize(textSize);
    textView.setPos({ xPos1, yPos4 });

    listCourse.setLabel("Choose course:");
    listCourse.setSize(inputSize);
    listCourse.setPos({ xPos2, yPos4 });
    
    view.label = "View";
    view.setSize(buttonSize);
    view.setPos({ xPos3, yPos4 });
    view.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textExport = "Export list of courses to file:";
    textExport.setSize(textSize);
    textExport.setPos({ xPos4, yPos3 + yMid });

    inputExport.defaultText = "Enter filename...";
    inputExport.setPos({ xPos4, yPos3 });
    inputExport.setSize(inputSize);

    buttonExport.label = "Export";
    buttonExport.setSize(buttonSize);
    buttonExport.setPos({ xPos5, yPos3 });
    buttonExport.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    ms = "";
    ms.setColor(RED);
    ms.setY(680);
    ms.setSize(textSize);
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    back.label = "Back";
    back.setPos({ 1050, 600 });
    back.setSize({ 150, 50 });
    back.setRemoveColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
}

void SemesterScene::render() {
    sceneTitle.render();

    textAddCourse.render();
    inputAddCourse.render(mousePoint);
    buttonAddCourse.render(mousePoint);

    textRemoveCourse.render();
    inputRemoveCourse.render(mousePoint);
    buttonRemoveCourse.render(mousePoint);

    textSemesterID.render();
    inputSemesterID.render(mousePoint);
    buttonSemesterID.render(mousePoint);

    textStartDate.render();
    inputStartDate.render(mousePoint);
    buttonStartDate.render(mousePoint);

    textEndDate.render();
    inputEndDate.render(mousePoint);
    buttonEndDate.render(mousePoint);

    textView.render();
    listCourse.render(mousePoint);
    view.render(mousePoint);

    textExport.render();
    inputExport.render(mousePoint);
    buttonExport.render(mousePoint);

    ms.render();

    back.render(mousePoint);
}

Scene* SemesterScene::process() {
    mousePoint = GetMousePosition();
    inputAddCourse.process(mousePoint);
    inputRemoveCourse.process(mousePoint);
    inputSemesterID.process(mousePoint);
    inputStartDate.process(mousePoint);
    inputEndDate.process(mousePoint);
    inputExport.process(mousePoint);
    listCourse.process(mousePoint);

    if (ptrSemester_Global != nullptr) {
        sceneTitle = "Semester " + ptrSemester_Global->semesterID;
        inputSemesterID.defaultText = ptrSemester_Global->semesterID;
        inputStartDate.defaultText = ptrSemester_Global->startDate.get();
        inputEndDate.defaultText = ptrSemester_Global->endDate.get();
        if (isAddCourse == false) {
            listCourse.add(getListCourse(*ptrSemester_Global));
            isAddCourse = true;
        }
    }

    string outStr;

    if (buttonAddCourse.clicked(mousePoint)) {
        string courseID = inputAddCourse.getContent();
        if (addCourse(*ptrSemester_Global, courseID, outStr)) {
            listCourse.add(courseID);
            listCourse.process(mousePoint);
        }
        ms = outStr;
        ms.centerX();
        inputAddCourse.clearContent();
        return this;
    }


    else if (buttonRemoveCourse.clicked(mousePoint)) {
        string courseID = inputRemoveCourse.getContent();
        if (removeCourse(*ptrSemester_Global, courseID, outStr)) {
            listCourse.remove(courseID);
            listCourse.process(mousePoint);
        }
        ms = outStr;
        ms.centerX();
        inputRemoveCourse.clearContent();
        return this;
    }

    else if (buttonSemesterID.clicked(mousePoint) || buttonStartDate.clicked(mousePoint) || buttonEndDate.clicked(mousePoint)) {
        string semesterID = inputSemesterID.getContent();
        string startDate = inputStartDate.getContent();
        string endDate = inputEndDate.getContent();
        updateSemester(*ptrSemester_Global, semesterID, startDate, endDate, outStr);
        ms = outStr;
        ms.centerX();
        inputSemesterID.clearContent();
        inputStartDate.clearContent();
        inputEndDate.clearContent();
        return this;
    }
    else if (buttonExport.clicked(mousePoint)) {
        string filename = inputExport.getContent();
        exportListCourseInSemester(filename, *ptrSemester_Global, outStr);
        ms = outStr;
        ms.centerX();
        inputExport.clearContent();
        return this;
    }
    else if (view.clicked(mousePoint)) {
        ptrCourse_Global = getCourse(*ptrSemester_Global, listCourse.getCurLabel());
        inputAddCourse.clearContent();
        inputRemoveCourse.clearContent();
        inputSemesterID.clearContent();
        inputStartDate.clearContent();
        inputEndDate.clearContent();
        inputExport.clearContent();
        listCourse.clear();
        isAddCourse = false;
        return registry.courseScene;
    }
    else if (back.clicked(mousePoint)) {
        ptrSemester_Global = nullptr;
        inputAddCourse.clearContent();
        inputRemoveCourse.clearContent();
        inputSemesterID.clearContent();
        inputStartDate.clearContent();
        inputEndDate.clearContent();
        inputExport.clearContent();
        listCourse.clear();
        isAddCourse = false;
        return registry.academicYearScene;
    }
    return this;
}