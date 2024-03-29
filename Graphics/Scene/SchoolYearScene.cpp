#include "SchoolYearScene.h"

bool isAddedListClasses = false;

const float buttonWidth = 150;
const float buttonHeight = 50;
const float inputWidth = 250;
const float inputHeight = 50;

const Vector2 buttonSize = { buttonWidth, buttonHeight };
const Vector2 inputSize = { inputWidth, inputHeight };

const float xDis = 180;
const float yDis = 50;
const float textSize = 30;

const float xPos1 = 550;
const float xPos2 = xPos1 + xDis;
const float xPos3 = xPos2 + inputSize.x;

const float yPos1 = 250;
const float yPos2 = yPos1 + inputSize.y + yDis;
const float yPos3 = yPos2 + inputSize.y + yDis;
const float yPos4 = yPos3 + inputSize.y + yDis;

SchoolYearScene::SchoolYearScene() {
    //---------------------------------------------------------------------------------------------------------------
    sceneTitle = "School Year";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(50);
    //---------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------
    viewClass = "View Classes";
    viewClass.setSize(textSize);
    viewClass.setPos({50, 200});
    //---------------------------------------------------------------------------------------------------------------
    listClass.setLabel("List of Classes:");
    listClass.setPos({50, yPos1});
    listClass.setSize({250, 50});
    //---------------------------------------------------------------------------------------------------------------
    view.label = "View";
    view.setPos({300, 250});
    view.setSize(buttonSize);
    view.setViewColor();
    //---------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------
    textAddClass = "Add Class";
    textAddClass.setSize(textSize);
    textAddClass.setPos({xPos1, yPos1});
    //---------------------------------------------------------------------------------------------------------------
    inputClassAdded.defaultText = "Enter Class Name...";
    inputClassAdded.setPos({ xPos2, yPos1 });
    inputClassAdded.setSize(inputSize);
    //---------------------------------------------------------------------------------------------------------------
    add.label = "Add";
    add.setPos({ xPos3, yPos1 });
    add.setSize(buttonSize);
    add.setInsertColor();
    //---------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------
    textRemoveClass = "Remove Class";
    textRemoveClass.setSize(textSize);
    textRemoveClass.setPos({xPos1, yPos2});
    //---------------------------------------------------------------------------------------------------------------
    inputClassRemoved.defaultText = "Enter Class Name...";
    inputClassRemoved.setPos({xPos2, yPos2});
    inputClassRemoved.setSize(inputSize);
    //---------------------------------------------------------------------------------------------------------------
    remove.label = "Remove";
    remove.setPos({xPos3, yPos2});
    remove.setSize(buttonSize);
    remove.setRemoveColor();
    //---------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------
    editYear = "Edit Year";
    editYear.setSize(textSize);
    editYear.setPos({xPos1, yPos3});
    //---------------------------------------------------------------------------------------------------------------
    inputStartYear.defaultText = "Enter startYear...";
    inputStartYear.setPos({xPos2, yPos3});
    inputStartYear.setSize(inputSize);
    //---------------------------------------------------------------------------------------------------------------
    change.label = "Change";
    change.setPos({ xPos3, yPos3 });
    change.setSize(buttonSize);
    change.setViewColor();
    //---------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------
    exportOption = "Filename";
    exportOption.setSize(textSize);
    exportOption.setPos({ xPos1, yPos4 });
    //---------------------------------------------------------------------------------------------------------------
    Export.label = "Export";
    Export.setPos({xPos3, yPos4});
    Export.setSize(buttonSize);
    Export.setViewColor();
    //---------------------------------------------------------------------------------------------------------------
    exportPath.defaultText = "Enter filename...";
    exportPath.setPos({ xPos2, yPos4 });
    exportPath.setSize(inputSize);
    //---------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------
    back.label = "Back";
    back.setPos({xPos3 + xDis - 30, 650});
    back.setSize(buttonSize);
    back.setRemoveColor();
    //---------------------------------------------------------------------------------------------------------------
    ms = "";
    ms.setSize(textSize);
    ms.setColor(RED);
    ms.setY(670);
    //---------------------------------------------------------------------------------------------------------------
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
        sceneTitle.centerX();
        if (!isAddedListClasses) {
            Vector<string> ls = getListClass(*ptrSchoolYear_Global);
            listClass.add(ls);
            isAddedListClasses = true;
        }
    }
    listClass.process(mousePoint);
    if (view.clicked(mousePoint)) {
        ptrClass_Global = getClass(*ptrSchoolYear_Global, listClass.getCurLabel());
        inputClassAdded.clearContent();
        inputClassRemoved.clearContent();
        inputStartYear.clearContent();
        exportPath.clearContent();
        listClass.clear();
        isAddedListClasses = false;
        ms.clear();
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
        exportPath.clearContent();
        listClass.clear();
        isAddedListClasses = false;
        ms.clear();
        return registry.listSchoolYearScene;
    }
    return this;
} 