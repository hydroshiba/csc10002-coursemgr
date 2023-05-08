#include "ClassScene.h"

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

ClassScene::ClassScene() {
    sceneTitle = "Class";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(50);
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    addStudentLabel = "Add student";
    addStudentLabel.setSize(textSize);
    addStudentLabel.setPos({xPos1, yPos1});

    addStudentInput.defaultText = "Student ID";
    addStudentInput.setPos({xPos2, yPos1});
    addStudentInput.setSize(inputSize);

    addStudentButton.label = "Add";
    addStudentButton.setPos({xPos3, yPos1});
    addStudentButton.setSize(buttonSize);
    addStudentButton.setInsertColor();

    //-----------------------------------------------------------
    //-----------------------------------------------------------
    removeStudentLabel = "Remove student";
    removeStudentLabel.setSize(textSize);
    removeStudentLabel.setPos({xPos1, yPos2});

    removeStudentInput.defaultText = "Student ID";
    removeStudentInput.setPos({xPos2, yPos2});
    removeStudentInput.setSize(inputSize);
    
    removeStudentButton.label = "Remove";
    removeStudentButton.setPos({xPos3, yPos2});
    removeStudentButton.setSize(buttonSize);
    removeStudentButton.setRemoveColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    changeClassnameLabel = "Class name";
    changeClassnameLabel.setSize(textSize); 
    changeClassnameLabel.setPos({xPos1, yPos3});

    changeClassnameInput.defaultText = "New classname";
    changeClassnameInput.setPos({xPos2, yPos3});
    changeClassnameInput.setSize(inputSize);

    changeClassnameButton.label = "Change";
    changeClassnameButton.setPos({xPos3, yPos3});
    changeClassnameButton.setSize(buttonSize);
    changeClassnameButton.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    viewStudentListLabel = "Export student list to a location:";
    viewStudentListLabel.setSize(textSize);
    viewStudentListLabel.setPos({xPos4, yPos1 + yMid});

    pathExportStudentList.defaultText = "Location";
    pathExportStudentList.setPos({xPos4, yPos1});
    pathExportStudentList.setSize(inputSize);

    viewStudentListButton.label = "Export";
    viewStudentListButton.setPos({xPos5, yPos1});
    viewStudentListButton.setSize(buttonSize);
    viewStudentListButton.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    viewScoreboardLabel = "Export scoreboard to a location:";
    viewScoreboardLabel.setSize(textSize);
    viewScoreboardLabel.setPos({xPos4, yPos2 + yMid});

    pathExportScoreboard.defaultText = "Location";
    pathExportScoreboard.setPos({xPos4, yPos2});
    pathExportScoreboard.setSize(inputSize);

    viewScoreboardButton.label = "Export";
    viewScoreboardButton.setPos({xPos5, yPos2});
    viewScoreboardButton.setSize(buttonSize);
    viewScoreboardButton.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textSemesterID = "Input semesterID:";
    textSemesterID.setSize(textSize);
    textSemesterID.setPos({ xPos4, yPos3 + yMid });

    inputSemesterID.defaultText = "All semester";
    inputSemesterID.setSize(inputSize);
    inputSemesterID.setPos({ xPos4, yPos3 });
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textImport = "Import list of students from file:";
    textImport.setSize(textSize);
    textImport.setPos({ xPos4, yPos4 + yMid });
    
    inputImport.defaultText = "Enter filename...";
    inputImport.setPos({ xPos4, yPos4 });
    inputImport.setSize(inputSize);

    importBut.label = "Import";
    importBut.setSize(buttonSize);
    importBut.setPos({ xPos5, yPos4 });
    importBut.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    back.label = "Back";
    back.setPos({1050, 600});
    back.setSize({150, 50});
    back.setRemoveColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    ms = "";
    ms.setColor(RED);
    ms.setY(680);
    ms.setSize(textSize);
    textNumStudents = "Number of students: 0";
    textNumStudents.setSize(textSize);
    textNumStudents.setPos({ xPos1, yPos4 });
}

void ClassScene::render() {
    sceneTitle.render();

    addStudentLabel.render();
    addStudentInput.render(mousePoint);
    addStudentButton.render(mousePoint);

    removeStudentLabel.render();
    removeStudentInput.render(mousePoint);
    removeStudentButton.render(mousePoint);

    changeClassnameLabel.render();
    changeClassnameInput.render(mousePoint);
    changeClassnameButton.render(mousePoint);

    viewStudentListLabel.render();
    pathExportStudentList.render(mousePoint);
    viewStudentListButton.render(mousePoint);

    viewScoreboardLabel.render();
    pathExportScoreboard.render(mousePoint);
    viewScoreboardButton.render(mousePoint);

    textSemesterID.render();
    inputSemesterID.render(mousePoint);

    textImport.render();
    inputImport.render(mousePoint);
    importBut.render(mousePoint);

    back.render(mousePoint);
    ms.render();
    textNumStudents.render();
}

Scene* ClassScene::process() {
    string outStr;
    mousePoint = GetMousePosition();
    addStudentInput.process(mousePoint);
    removeStudentInput.process(mousePoint);
    changeClassnameInput.process(mousePoint);
    pathExportStudentList.process(mousePoint);
    pathExportScoreboard.process(mousePoint);
    inputSemesterID.process(mousePoint);
    inputImport.process(mousePoint);

    if (ptrClass_Global != nullptr) {
        sceneTitle = "Class " + ptrClass_Global->name;
        if (ptrClass_Global->ptrSchoolYear != nullptr) {
            sceneTitle = "Class " + ptrClass_Global->name + "(" + ptrClass_Global->ptrSchoolYear->getPeriod() + ")";
        }
        changeClassnameInput.defaultText = ptrClass_Global->name;
        textNumStudents = "Number of students: " + to_string(ptrClass_Global->students.size());
        sceneTitle.centerX();
    }

    if (addStudentButton.clicked(mousePoint)) {
        string studentID = addStudentInput.getContent();
        addStudentToClass(*ptrClass_Global, studentID, outStr);
        ms = outStr;
        ms.centerX();
        addStudentInput.clearContent();
        return this;
    }
    else if (removeStudentButton.clicked(mousePoint)) {
        string studentID = removeStudentInput.getContent();
        removeStudentFromClass(*ptrClass_Global, studentID, outStr);
        ms = outStr;
        ms.centerX();
        removeStudentInput.clearContent();
        return this;
    }
    else if (changeClassnameButton.clicked(mousePoint)) {
        string classname = changeClassnameInput.getContent();
        updateClass(*ptrClass_Global, classname, outStr);
        ms = outStr;
        ms.centerX();
        changeClassnameInput.clearContent();
        return this;
    }
    else if (viewStudentListButton.clicked(mousePoint)) {
        string filename = pathExportStudentList.getContent();
        exportListStudentInClass(filename, *ptrClass_Global, outStr);
        ms = outStr;
        ms.centerX();
        pathExportStudentList.clearContent();
        return this;
    }
    else if (viewScoreboardButton.clicked(mousePoint)) {
        string filename = pathExportScoreboard.getContent();
        string semesterID = inputSemesterID.getContent();
        if (semesterID.empty()) {
            exportListScoreboardOfClass(filename, *ptrClass_Global, outStr);
        }
        else {
            Semester* ptrSemester = getSemester(semesterID);
            if (ptrSemester == nullptr) {
                outStr = "Semester " + semesterID + " is not existed!";
            }
            else {
                exportListScoreboardInSemesterOfClass(filename, *ptrClass_Global, *ptrSemester, outStr);
            }
        }
        ms = outStr;
        ms.centerX();
        pathExportScoreboard.clearContent();
        inputSemesterID.clearContent();
        return this;
    }
    else if (importBut.clicked(mousePoint)) {
        string filename = inputImport.getContent();
        importStudentListOfClassFromFile(filename, *ptrClass_Global, outStr);
        ms = outStr;
        ms.centerX();
        inputImport.clearContent();
        return this;
    }
    else if (back.clicked(mousePoint)) {
        addStudentInput.clearContent();
        removeStudentInput.clearContent();
        changeClassnameInput.clearContent();
        pathExportStudentList.clearContent();
        pathExportScoreboard.clearContent();
        inputSemesterID.clearContent();
        inputImport.clearContent();
        ptrClass_Global = nullptr;
        ms.clear();
        ptrClass_Global = nullptr;
        return registry.schoolYearScene;
    }
    return this;
}