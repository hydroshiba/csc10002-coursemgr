#include "SchoolYearScene.h"

bool isAdded = false;

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
    view.setViewColor();
    //--------------------------------------
    textAddClass = "Add Class";
    textAddClass.setSize(30);
    textAddClass.setPos({550, 250});

    inputClassAdded.defaultText = "Enter Class Name";
    inputClassAdded.setPos({750, 250});
    inputClassAdded.setSize({250, 50});

    add.label = "Add";
    add.setPos({1050, 250});
    add.setSize({150, 50});
    add.setInsertColor();
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
    remove.setRemoveColor();
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
    change.setViewColor();
    //--------------------------------------
    exportOption = "Choose a location to export file";
    exportOption.setSize(30);
    exportOption.setPos({50, 550});

    Export.label = "Export";
    Export.setPos({400, 600});
    Export.setSize({200, 50});
    Export.setViewColor();

    exportPath.defaultText = "Location";
    exportPath.setPos({50, 600});
    exportPath.setSize({300, 50});

    back.label = "Back";
    back.setPos({1000, 600});
    back.setSize({200, 50});
    back.setRemoveColor();

    ms = "";
    ms.setSize(30);
    ms.setColor(RED);
    ms.setY(670);
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
    exportOption.render();
    Export.render(mousePoint);
    exportPath.render(mousePoint);
    back.render(mousePoint);
}

Scene* SchoolYearScene::process() {
    this->mousePoint = GetMousePosition();
    inputStartYear.process(mousePoint);
    inputClassAdded.process(mousePoint);
    inputClassRemoved.process(mousePoint);
    exportPath.process(mousePoint);
    //--------------------------------------
    if (ptrSchoolYear_Global != nullptr) {
        sceneTitle = "School Year " + ptrSchoolYear_Global->getPeriod();
        if (!isAdded) {
            listClass.add(getListClass(*ptrSchoolYear_Global));
            isAdded = true;
        }
    }
    listClass.process(mousePoint);
    if (view.clicked(mousePoint)) {
        const size_t i = static_cast<const size_t>(listClass.getSelected());
        if (i >= 0) {
            ptrSchoolYear_Global = &schoolYears[i];
            inputClassAdded.clearContent();
            inputClassRemoved.clearContent();
            return registry.classScene;
        }
    }
    //--------------------------------------
    inputClassAdded.process(mousePoint);
    if (add.clicked(mousePoint)) {
        string className = inputClassAdded.getContent();
        string outStr;
        if (addClass(*ptrSchoolYear_Global, className, outStr)) {
            listClass.add(className);
            listClass.process(mousePoint);
        }
        ms = outStr;
        ms.centerX();
        inputClassAdded.clearContent();
        return this;
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
    exportPath.process(mousePoint);
    if (Export.clicked(mousePoint)) {
        //export school year to path
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