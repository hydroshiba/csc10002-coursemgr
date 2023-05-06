#include "ClassScene.h"

ClassScene::ClassScene() {
    sceneTitle = "Class";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(100);
    //-----------------------------------------------------------
    addStudentLabel = "Add student";
    addStudentLabel.setSize(30);
    addStudentLabel.setPos({50, 200});

    addStudentInput.defaultText = "Student ID";
    addStudentInput.setPos({275, 200});
    addStudentInput.setSize({225, 50});

    addStudentButton.label = "Add";
    addStudentButton.setPos({525, 200});
    addStudentButton.setSize({150, 50});
    addStudentButton.setInsertColor();

    //-----------------------------------------------------------
    removeStudentLabel = "Remove student:";
    removeStudentLabel.setSize(30);
    removeStudentLabel.setPos({50, 375});

    removeStudentInput.defaultText = "Student ID";
    removeStudentInput.setPos({275, 375});
    removeStudentInput.setSize({225, 50});
    
    removeStudentButton.label = "Remove";
    removeStudentButton.setPos({525, 375});
    removeStudentButton.setSize({150, 50});
    removeStudentButton.setRemoveColor();
    //-----------------------------------------------------------
    changeClassnameLabel = "Change Class name";
    changeClassnameLabel.setSize(30);
    changeClassnameLabel.setPos({50, 500});

    changeClassnameInput.defaultText = "New classname";
    changeClassnameInput.setPos({275, 500});
    changeClassnameInput.setSize({225, 50});

    changeClassnameButton.label = "Change";
    changeClassnameButton.setPos({525, 500});
    changeClassnameButton.setSize({150, 50});
    changeClassnameButton.setViewColor();
    //-----------------------------------------------------------
    viewStudentListLabel = "Export student list to a location:";
    viewStudentListLabel.setSize(30);
    viewStudentListLabel.setPos({750, 200});

    pathExportStudentList.defaultText = "Location";
    pathExportStudentList.setPos({750, 250});
    pathExportStudentList.setSize({300, 50});

    viewStudentListButton.label = "Export";
    viewStudentListButton.setPos({1075, 250});
    viewStudentListButton.setSize({150, 50});
    viewStudentListButton.setViewColor();
    //-----------------------------------------------------------
    viewScoreboardLabel = "Export scoreboard to a location:";
    viewScoreboardLabel.setSize(30);
    viewScoreboardLabel.setPos({750, 375});

    pathExportScoreboard.defaultText = "Location";
    pathExportScoreboard.setPos({750, 425});
    pathExportScoreboard.setSize({300, 50});

    viewScoreboardButton.label = "Export";
    viewScoreboardButton.setPos({1075, 425});
    viewScoreboardButton.setSize({150, 50});
    viewScoreboardButton.setViewColor();
    //-----------------------------------------------------------
    back.label = "Back";
    back.setPos({1050, 600});
    back.setSize({150, 50});
    back.setRemoveColor();
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

    back.render(mousePoint);
}

Scene* ClassScene::process() {
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

    if (back.clicked(mousePoint)) return registry.schoolYearScene;
    return this;
}