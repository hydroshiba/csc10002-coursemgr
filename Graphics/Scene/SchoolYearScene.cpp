#include "SchoolYearScene.h"

SchoolYearScene::SchoolYearScene() {
    sceneTitle = "School Year Error";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(100);
    //--------------------------------------
    viewClass = "View Classes";
    viewClass.setSize(30);
    viewClass.setPos({50, 250});

    listClass.setLabel("List of Classes:");
    listClass.setPos({50, 300});
    listClass.setSize({250, 50});

    view.label = "View";
    view.setPos({350, 300});
    view.setSize({150, 50});
    //--------------------------------------
    addClass = "Add Class";
    addClass.setSize(30);
    addClass.setPos({550, 250});

    inputClassAdded.defaultText = "Enter Class Name";
    inputClassAdded.setPos({750, 250});
    inputClassAdded.setSize({250, 50});

    add.label = "Add";
    add.setPos({1050, 250});
    add.setSize({150, 50});
    //--------------------------------------
    removeClass = "Remove Class";
    removeClass.setSize(30);
    removeClass.setPos({550, 350});

    inputClassRemoved.defaultText = "Enter Class Name";
    inputClassRemoved.setPos({750, 350});
    inputClassRemoved.setSize({250, 50});

    remove.label = "Remove";
    remove.setPos({1050, 350});
    remove.setSize({150, 50});
    //--------------------------------------
    editYear = "Edit Year";
    editYear.setSize(30);
    editYear.setPos({550, 450});

    inputStartYear.defaultText = "Enter Year";
    inputStartYear.setPos({750, 450});
    inputStartYear.setSize({250, 50});

    change.label = "Change";
    change.setPos({1050, 450});
    change.setSize({150, 50});
    //--------------------------------------
    Export.label = "Export";
    Export.setPos({50, 600});
    Export.setSize({200, 50});

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
    //--------------------------------------
    addClass.render();
    inputClassAdded.render(mousePoint);
    add.render(mousePoint);
    //--------------------------------------
    removeClass.render();
    inputClassRemoved.render(mousePoint);
    remove.render(mousePoint);
    //--------------------------------------
    editYear.render();
    inputStartYear.render(mousePoint);
    change.render(mousePoint);
    //--------------------------------------
    Export.render(mousePoint);
    back.render(mousePoint);
}

Scene* SchoolYearScene::process() {
    this->mousePoint = GetMousePosition();
    //--------------------------------------
    if (ptrSchoolYear_Global != nullptr) {
        sceneTitle = "School Year " + std::to_string(ptrSchoolYear_Global->start);
    }
    listClass.process(mousePoint);
    if (view.clicked(mousePoint)) {
        //switch to the class scene of the class selected
    }
    //--------------------------------------
    inputClassAdded.process(mousePoint);
    if (add.clicked(mousePoint)) {
        std::string content = inputClassAdded.getContent();
        if (content != "") listClass.add(content);
        //add class
    }
    //--------------------------------------
    inputClassRemoved.process(mousePoint);
    if (remove.clicked(mousePoint)) {
        if (remove.clicked(mousePoint)) {
            std::string content = inputClassRemoved.getContent();
            if (content != "") listClass.remove(content);
            //remove class
        }
    }
    //--------------------------------------
    inputStartYear.process(mousePoint);
    if (change.clicked(mousePoint)) {
        //change start year
    }
    //--------------------------------------
    if (Export.clicked(mousePoint)) {
        //export
    }
    if (back.clicked(mousePoint)) {
        ptrSchoolYear_Global = nullptr;
        inputClassAdded.clearContent();
        inputClassRemoved.clearContent();
        inputStartYear.clearContent();
        return registry.listSchoolYearScene;
    }
    return this;
} 