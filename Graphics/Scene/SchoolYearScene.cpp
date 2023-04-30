#include "SchoolYearScene.h"

SchoolYearScene::SchoolYearScene() {
    sceneTitle = "School Year";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(100);
    //--------------------------------------
    viewClass = "View Classes";
    viewClass.setSize(30);
    viewClass.setPos({100, 250});

    listClass.setLabel("List of Classes:");
    listClass.setPos({400, 240});
    listClass.setSize({300, 50});

    view.label = "View";
    view.setPos({800, 240});
    view.setSize({150, 50});
    
    warningViewClass = "A class must be selected";
    warningViewClass.setColor(RED); 
    warningViewClass.setSize(30);
    warningViewClass.setPos({400, 290});

    isAnyClassChosen = true;
    frameCounterViewClass = 0;
    //--------------------------------------
    addClass = "Add Class";
    addClass.setSize(30);
    addClass.setPos({100, 350});

    inputClassAdded.defaultText = "Enter Class Name";
    inputClassAdded.setPos({400, 340});
    inputClassAdded.setSize({300, 50});

    add.label = "Add";
    add.setPos({800, 340});
    add.setSize({150, 50});

    warningClassAdded.setSize(30);
    warningClassAdded.setPos({400, 390});

    isClassAddedEmpty = false;
    isAddClicked = false;
    frameCounterAddWarning = 0;
    //--------------------------------------
    removeClass = "Remove Class";
    removeClass.setSize(30);
    removeClass.setPos({100, 450});

    inputClassRemoved.defaultText = "Enter Class Name";
    inputClassRemoved.setPos({400, 440});
    inputClassRemoved.setSize({300, 50});

    remove.label = "Remove";
    remove.setPos({800, 440});
    remove.setSize({150, 50});

    warningClassRemoved.setSize(30);
    warningClassRemoved.setPos({400, 490});

    isClassRemovedEmpty = false;
    isRemoveClicked = false;
    frameCounterRemoveWarning = 0;
    //--------------------------------------
    editYear = "Edit Year";
    editYear.setSize(30);
    editYear.setPos({100, 550});

    inputStartYear.defaultText = "Enter Year";
    inputStartYear.setPos({400, 540});
    inputStartYear.setSize({300, 50});

    change.label = "Change";
    change.setPos({800, 540});
    change.setSize({150, 50});

    warningStartYear.setSize(30);
    warningStartYear.setPos({400, 590});

    isStartYearEmpty = false;
    isChangeClicked = false;
    frameCounterChangeWarning = 0;
    //--------------------------------------
    back.label = "Back";
    back.setPos({1000, 600});
    back.setSize({200, 50});
}

void SchoolYearScene::render() {
    sceneTitle.render();
    //--------------------------------------
    viewClass.render();
    listClass.render(mousePoint);
    view.render(mousePoint);
    if (!isAnyClassChosen) {
        frameCounterViewClass++;
        warningViewClass.render();
        if (frameCounterViewClass == 600) {
            isAnyClassChosen = true;
            frameCounterViewClass = 0;
        }
    }
    //--------------------------------------
    addClass.render();
    inputClassAdded.render(mousePoint);
    add.render(mousePoint);
    if (isAddClicked) {
        if (isClassAddedEmpty) {
            warningClassAdded = "Class name must not be empty";
            warningClassAdded.setColor(RED);
        }
        else {
            warningClassAdded = "Class added";
            warningClassAdded.setColor(BLUE);
        }
        warningClassAdded.render();
        frameCounterAddWarning++;
        if (frameCounterAddWarning == 600) {
            frameCounterAddWarning = 0;
            isAddClicked = false;
        }
    }
    //--------------------------------------
    removeClass.render();
    inputClassRemoved.render(mousePoint);
    remove.render(mousePoint);
    if (isRemoveClicked) {
        if (isClassRemovedEmpty) {
            warningClassRemoved = "Class name must not be empty";
            warningClassRemoved.setColor(RED);
        }
        else {
            warningClassRemoved = "Class removed";
            warningClassRemoved.setColor(BLUE);
        }
        warningClassRemoved.render();
        frameCounterRemoveWarning++;
        if (frameCounterRemoveWarning == 600) {
            frameCounterRemoveWarning = 0;
            isRemoveClicked = false;
        }
    }
    //--------------------------------------
    editYear.render();
    inputStartYear.render(mousePoint);
    change.render(mousePoint);
    if (isChangeClicked) {
        if (isStartYearEmpty) {
            warningStartYear = "Start year must not be empty";
            warningStartYear.setColor(RED);
        }
        else {
            warningStartYear = "Start year changed";
            warningStartYear.setColor(BLUE);
        }
        warningStartYear.render();
        frameCounterChangeWarning++;
        if (frameCounterChangeWarning == 600) {
            frameCounterChangeWarning = 0;
            isChangeClicked = false;
        }
    }
    //--------------------------------------
    back.render(mousePoint);
}

Scene* SchoolYearScene::process() {
    this->mousePoint = GetMousePosition();
    //--------------------------------------
    listClass.process(mousePoint);
    if (view.clicked(mousePoint)) {
        if (listClass.getSelected() == -1)
            isAnyClassChosen = false;
        else 
            isAnyClassChosen = true;
            //switch to the class scene of the class selected
    }
    //--------------------------------------
    inputClassAdded.process(mousePoint);
    if (add.clicked(mousePoint)) {
        isAddClicked = true;
        if(inputClassAdded.getContent() == "") {
            isClassAddedEmpty = true;
        }
        else {
            isClassAddedEmpty = false;
            //add class
        }
    }
    //--------------------------------------
    inputClassRemoved.process(mousePoint);
    if (remove.clicked(mousePoint)) {
        isRemoveClicked = true;
        if(inputClassRemoved.getContent() == "") {
            isClassRemovedEmpty = true;
        }
        else {
            isClassRemovedEmpty = false;
            //remove class
        }
    }
    //--------------------------------------
    inputStartYear.process(mousePoint);
    if (change.clicked(mousePoint)) {
        isChangeClicked = true;
        if (inputStartYear.getContent() == "") {
            isStartYearEmpty = true;
        }
        else {
            isStartYearEmpty = false;
            //change start year
        }
    }
    if (back.clicked(mousePoint)) return registry.listSchoolYearScene;
    return this;
} 