#include "SemesterScene.h"

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
    addStudentLabel = "Add course";
    addStudentLabel.setSize(textSize);
    addStudentLabel.setPos({ xPos1, yPos1 });

    addStudentInput.defaultText = "Enter CourseID";
    addStudentInput.setPos({ xPos2, yPos1 });
    addStudentInput.setSize(inputSize);

    addStudentButton.label = "Add";
    addStudentButton.setPos({ xPos3, yPos1 });
    addStudentButton.setSize(buttonSize);
    addStudentButton.setInsertColor();

    //-----------------------------------------------------------
    //-----------------------------------------------------------
    removeStudentLabel = "Remove course";
    removeStudentLabel.setSize(textSize);
    removeStudentLabel.setPos({ xPos1, yPos2 });

    removeStudentInput.defaultText = "Enter CourseID";
    removeStudentInput.setPos({ xPos2, yPos2 });
    removeStudentInput.setSize(inputSize);

    removeStudentButton.label = "Remove";
    removeStudentButton.setPos({ xPos3, yPos2 });
    removeStudentButton.setSize(buttonSize);
    removeStudentButton.setRemoveColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    changeClassnameLabel = "SemesterID";
    changeClassnameLabel.setSize(textSize);
    changeClassnameLabel.setPos({ xPos1, yPos3 });

    changeClassnameInput.defaultText = "New SemesterID";
    changeClassnameInput.setPos({ xPos2, yPos3 });
    changeClassnameInput.setSize(inputSize);

    changeClassnameButton.label = "Change";
    changeClassnameButton.setPos({ xPos3, yPos3 });
    changeClassnameButton.setSize(buttonSize);
    changeClassnameButton.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    viewStudentListLabel = "Change start date:";
    viewStudentListLabel.setSize(textSize);
    viewStudentListLabel.setPos({ xPos4, yPos1 + yMid });

    pathExportStudentList.defaultText = "dd/mm/yyyy";
    pathExportStudentList.setPos({ xPos4, yPos1 });
    pathExportStudentList.setSize(inputSize);

    viewStudentListButton.label = "Change";
    viewStudentListButton.setPos({ xPos5, yPos1 });
    viewStudentListButton.setSize(buttonSize);
    viewStudentListButton.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    viewScoreboardLabel = "Change end date:";
    viewScoreboardLabel.setSize(textSize);
    viewScoreboardLabel.setPos({ xPos4, yPos2 + yMid });

    pathExportScoreboard.defaultText = "dd/mm/yyyy";
    pathExportScoreboard.setPos({ xPos4, yPos2 });
    pathExportScoreboard.setSize(inputSize);

    viewScoreboardButton.label = "Change";
    viewScoreboardButton.setPos({ xPos5, yPos2 });
    viewScoreboardButton.setSize(buttonSize);
    viewScoreboardButton.setViewColor();
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    /*textSemesterID = "Input semesterID:";
    textSemesterID.setSize(textSize);
    textSemesterID.setPos({ xPos4, yPos3 + yMid });

    inputSemesterID.defaultText = "All semester";
    inputSemesterID.setSize(inputSize);
    inputSemesterID.setPos({ xPos4, yPos3 });*/
    //-----------------------------------------------------------
    //-----------------------------------------------------------
    textImport = "Export list of courses to file:";
    textImport.setSize(textSize);
    textImport.setPos({ xPos4, yPos4 + yMid });

    inputImport.defaultText = "Enter filename...";
    inputImport.setPos({ xPos4, yPos4 });
    inputImport.setSize(inputSize);

    importBut.label = "Export";
    importBut.setSize(buttonSize);
    importBut.setPos({ xPos5, yPos4 });
    importBut.setViewColor();
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

    /*textSemesterID.render();
    inputSemesterID.render(mousePoint);*/

    textImport.render();
    inputImport.render(mousePoint);
    importBut.render(mousePoint);

    back.render(mousePoint);
}

Scene* SemesterScene::process() {
    mousePoint = GetMousePosition();

    addStudentInput.process(mousePoint);
    if (addStudentButton.clicked(mousePoint)) {
        string studentID = addStudentInput.getContent();
    }


    removeStudentInput.process(mousePoint);
    if (removeStudentButton.clicked(mousePoint)) {
        //remove student from class
    }

    changeClassnameInput.process(mousePoint);
    if (changeClassnameButton.clicked(mousePoint)) {
        //change class name
    }

    pathExportStudentList.process(mousePoint);
    if (viewStudentListButton.clicked(mousePoint)) {
        //export student list
    }

    pathExportScoreboard.process(mousePoint);
    if (viewScoreboardButton.clicked(mousePoint)) {
        //export scoreboard
    }

    if (back.clicked(mousePoint)) return registry.academicYearScene;
    return this;
}