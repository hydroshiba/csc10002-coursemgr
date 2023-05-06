#include "ClassScene.h"

ClassScene::ClassScene() {
    sceneTitle = "Class";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(100);
    //-----------------------------------------------------------
    addStudentLabel = "Add student:";
    addStudentLabel.setSize(30);
    addStudentLabel.setPos({50, 200});

    addStudentInput.defaultText = "Student ID";
    addStudentInput.setPos({275, 200});
    addStudentInput.setSize({225, 50});

    addStudentButton.label = "Add";
    addStudentButton.setPos({525, 200});
    addStudentButton.setSize({150, 50});

    addStudentByFileButton.label = "Add by file";
    addStudentByFileButton.setPos({275, 275});
    addStudentByFileButton.setSize({150, 50});
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
    //-----------------------------------------------------------
    changeClassnameLabel = "Change Class name: ";
    changeClassnameLabel.setSize(30);
    changeClassnameLabel.setPos({50, 500});

    changeClassnameInput.defaultText = "New Class name";
    changeClassnameInput.setPos({275, 500});
    changeClassnameInput.setSize({225, 50});

    changeClassnameButton.label = "Change";
    changeClassnameButton.setPos({525, 500});
    changeClassnameButton.setSize({150, 50});
    //-----------------------------------------------------------
    back.label = "Back";
    back.setPos({1050, 600});
    back.setSize({150, 50});
}

void ClassScene::render() {
    sceneTitle.render();

    addStudentLabel.render();
    addStudentInput.render(mousePoint);
    addStudentButton.render(mousePoint);
    addStudentByFileButton.render(mousePoint);

    removeStudentLabel.render();
    removeStudentInput.render(mousePoint);
    removeStudentButton.render(mousePoint);

    changeClassnameLabel.render();
    changeClassnameInput.render(mousePoint);
    changeClassnameButton.render(mousePoint);

    back.render(mousePoint);
}

Scene* ClassScene::process() {
    mousePoint = GetMousePosition();

    addStudentInput.process(mousePoint);
    if (addStudentButton.clicked(mousePoint)) {
        //add student to class
    }
    if (addStudentByFileButton.clicked(mousePoint)) {
        //add student to class by file
    }
    
    removeStudentInput.process(mousePoint);
    if (removeStudentButton.clicked(mousePoint)) {
        //remove student from class
    }
    
    changeClassnameInput.process(mousePoint);
    if (changeClassnameButton.clicked(mousePoint)) {
        //change class name
    }
    
    if (back.clicked(mousePoint)) return registry.schoolYearScene;
    return this;
}