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
    textRemoveClass = "Remove Class";
    textRemoveClass.setSize(30);
    textRemoveClass.setPos({550, 350});

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
    textAddClass.render();
    inputClassAdded.render(mousePoint);
    add.render(mousePoint);
    //--------------------------------------
    textRemoveClass.render();
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
    ms.render();
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
            Vector<string> ls = getListClass(*ptrSchoolYear_Global);
            listClass.add(ls);
            isAdded = true;
        }
    }
    listClass.process(mousePoint);
    if (view.clicked(mousePoint)) {
        ptrClass_Global = getClass(*ptrSchoolYear_Global, listClass.getCurLabel());
        inputClassAdded.clearContent();
        inputClassRemoved.clearContent();
        return registry.classScene;
    }
    //--------------------------------------
    else if (add.clicked(mousePoint)) {
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
    else if (remove.clicked(mousePoint)) {
        if (remove.clicked(mousePoint)) {
            string className = inputClassRemoved.getContent();
            string outStr;
            if (removeClass(*ptrSchoolYear_Global, className, outStr)) {
                listClass.remove(className);
                listClass.process(mousePoint);
            }
            ms = outStr;
            ms.centerX();
            inputClassRemoved.clearContent();
            return this;
        }
    }
    //--------------------------------------
    else if (change.clicked(mousePoint)) {
        string startYear = inputStartYear.getContent();
        string outStr;
        updateSchoolYear(*ptrSchoolYear_Global, startYear, outStr);
        ms = outStr;
        ms.centerX();
        inputStartYear.clearContent();
        return this;
    }
    //--------------------------------------
    else if (Export.clicked(mousePoint)) {
        string filename = exportPath.getContent();
        string outStr;
        exportListClassInSchoolYear(filename, *ptrSchoolYear_Global, outStr);
        ms = outStr;
        ms.centerX();
        exportPath.clearContent();
    }
    else if (back.clicked(mousePoint)) {
        ptrSchoolYear_Global = nullptr;
        inputClassAdded.clearContent();
        inputClassRemoved.clearContent();
        inputStartYear.clearContent();
        isAdded = false;
        listClass.clear();
        isAdded = false;
        return registry.listSchoolYearScene;
    }
    return this;
} 