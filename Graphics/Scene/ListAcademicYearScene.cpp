#include "ListAcademicYearScene.h"

bool isAddedListAcademicYear = false;

const Vector2 buttonSize = { 150, 50 };
const Vector2 inputSize = { 250, 50 };
const float yDis = 50;
const float textSize = 30;
const float textBoxWidth = 250;

ListAcademicYearScene::ListAcademicYearScene() {
    sceneTitle = "List Of Academic Years ( " + to_string(academicYears.size()) + " )";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(30);
    //--------------------------------------
    viewYear = "View list of AcademicYears";
    viewYear.setSize(textSize);
    viewYear.setPos({ 50, 200 });

    chooseAcademicYear.setLabel("Choose Academic Year");
    chooseAcademicYear.setPos({ 50, 250 });
    chooseAcademicYear.setSize({ 350, 50 });

    view.label = "View";
    view.setPos({ 400, 250 });
    view.setSize(buttonSize);
    view.setViewColor();
    //--------------------------------------
    addYear = "Add AcademicYear";
    addYear.setSize(textSize);
    addYear.setPos({ 600, 250 });

    inputAcademicYearAdded.defaultText = "Enter start year";
    inputAcademicYearAdded.setPos({ addYear.getPos().x + textBoxWidth, addYear.getPos().y });
    inputAcademicYearAdded.setSize(inputSize);

    add.label = "Add";
    add.setPos({ inputAcademicYearAdded.getPos().x + inputAcademicYearAdded.getSize().x, inputAcademicYearAdded.getPos().y });
    add.setSize(buttonSize);
    add.setInsertColor();
    //--------------------------------------
    removeYear = "Remove AcademicYear";
    removeYear.setSize(textSize);
    removeYear.setPos({ addYear.getPos().x, addYear.getPos().y + yDis + add.getSize().y });

    inputAcademicYearRemoved.defaultText = "Enter start year";
    inputAcademicYearRemoved.setPos({ inputAcademicYearAdded.getPos().x, removeYear.getPos().y });
    inputAcademicYearRemoved.setSize(inputAcademicYearAdded.getSize());

    remove.label = "Remove";
    remove.setPos({ add.getPos().x, inputAcademicYearRemoved.getPos().y });
    remove.setSize(buttonSize);
    remove.setRemoveColor();
    //--------------------------------------
    back.label = "Back";
    back.setPos({ remove.getPos().x, 600 });
    back.setSize(buttonSize);
    back.setRemoveColor();

    ms = "";
    ms.setSize(textSize);
    ms.setY(680);
}

void ListAcademicYearScene::render() {
    sceneTitle.render();
    //--------------------------------------
    viewYear.render();
    chooseAcademicYear.render(mousePoint);
    view.render(mousePoint);
    //--------------------------------------
    addYear.render();
    inputAcademicYearAdded.render(mousePoint);
    add.render(mousePoint);
    //--------------------------------------
    removeYear.render();
    inputAcademicYearRemoved.render(mousePoint);
    remove.render(mousePoint);
    //--------------------------------------
    back.render(mousePoint);
    //--------------------------------------
    ms.render();
}

Scene* ListAcademicYearScene::process() {
    mousePoint = GetMousePosition();
    sceneTitle = "List Of Academic Years (" + to_string(academicYears.size()) + ")";
    sceneTitle.centerX();
    chooseAcademicYear.process(mousePoint);
    inputAcademicYearAdded.process(mousePoint);
    inputAcademicYearRemoved.process(mousePoint);

    if (!isAddedListAcademicYear) {
        chooseAcademicYear.add(getListAcademicYear());
        isAddedListAcademicYear = true;
    }
    if (view.clicked(mousePoint)) {
        ptrAcademicYear_Global = getAcademicYear(chooseAcademicYear.getCurLabel());
        inputAcademicYearAdded.clearContent();
        inputAcademicYearRemoved.clearContent();
        chooseAcademicYear.clear();
        isAddedListAcademicYear = false;
        ms.clear();
        return registry.academicYearScene;
    }
    else if (add.clicked(mousePoint)) {
        string content = inputAcademicYearAdded.getContent();
        string outStr;
        if (addAcademicYear(content, outStr)) {
            chooseAcademicYear.add(content);
            chooseAcademicYear.process(mousePoint);
        }
        ms = outStr;
        ms.centerX();
        inputAcademicYearAdded.clearContent();
    }
    else if (remove.clicked(mousePoint)) {
        string startYear = inputAcademicYearRemoved.getContent();
        string outStr;
        if (removeAcademicYear(startYear, outStr)) {
            chooseAcademicYear.remove(startYear);
            chooseAcademicYear.process(mousePoint);
        }
        ms = outStr;
        ms.centerX();
        inputAcademicYearRemoved.clearContent();
    }
    else if (back.clicked(mousePoint)) {
        chooseAcademicYear.process(mousePoint);
        inputAcademicYearAdded.clearContent();
        inputAcademicYearRemoved.clearContent();
        chooseAcademicYear.clear();
        isAddedListAcademicYear = false;
        ms.clear();
        return registry.staffScene;
    }
    return this;
}