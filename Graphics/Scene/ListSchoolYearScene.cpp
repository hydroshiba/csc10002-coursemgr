#include "ListSchoolYearScene.h"

bool isAddedListSchoolYear = false;

const Vector2 buttonSize = { 150, 50 };
const Vector2 inputSize = { 250, 50 };
const float yDis = 50;
const float textSize = 30;
const float textBoxWidth = 200;

ListSchoolYearScene::ListSchoolYearScene() {
    sceneTitle = "List Of School Years ( " + to_string(schoolYears.size()) + " )";

    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(30);
    //--------------------------------------
    viewYear = "View list of SchoolYears";
    viewYear.setSize(textSize);
    viewYear.setPos({50, 200});

    chooseSchoolYear.setLabel("Choose School Year");
    chooseSchoolYear.setPos({50, 250});
    chooseSchoolYear.setSize({350, 50});

    view.label = "View";
    view.setPos({400, 250});
    view.setSize(buttonSize);
    view.setViewColor();
    //--------------------------------------
    addYear = "Add SchoolYear";
    addYear.setSize(textSize);
    addYear.setPos({600, 250});

    inputSchoolYearAdded.defaultText = "Enter start year";
    inputSchoolYearAdded.setPos({addYear.getPos().x + textBoxWidth, addYear.getPos().y});
    inputSchoolYearAdded.setSize(inputSize);

    add.label = "Add";
    add.setPos({ inputSchoolYearAdded.getPos().x + inputSchoolYearAdded.getSize().x, inputSchoolYearAdded.getPos().y });
    add.setSize(buttonSize);
    add.setInsertColor();
    //--------------------------------------
    removeYear = "Remove Year";
    removeYear.setSize(textSize);
    removeYear.setPos({addYear.getPos().x, addYear.getPos().y + yDis + add.getSize().y});

    inputSchoolYearRemoved.defaultText = "Enter start year";
    inputSchoolYearRemoved.setPos({inputSchoolYearAdded.getPos().x, removeYear.getPos().y});
    inputSchoolYearRemoved.setSize(inputSchoolYearAdded.getSize());

    remove.label = "Remove";
    remove.setPos({add.getPos().x, inputSchoolYearRemoved.getPos().y});
    remove.setSize(buttonSize);
    remove.setRemoveColor();
    //--------------------------------------
    back.label = "Back";
    back.setPos({remove.getPos().x, 600});
    back.setSize(buttonSize);
    back.setRemoveColor();

    ms = "";
    ms.setSize(textSize);
    ms.setY(680);
}

void ListSchoolYearScene::render() {
    sceneTitle.render();
    //--------------------------------------
    viewYear.render();
    chooseSchoolYear.render(mousePoint);
    view.render(mousePoint);
    //--------------------------------------
    addYear.render();
    inputSchoolYearAdded.render(mousePoint);
    add.render(mousePoint);
    //--------------------------------------
    removeYear.render();
    inputSchoolYearRemoved.render(mousePoint);
    remove.render(mousePoint);
    //--------------------------------------
    back.render(mousePoint);
    //--------------------------------------
    ms.render();
}

Scene* ListSchoolYearScene::process() {
    sceneTitle = "List Of School Years(" + to_string(schoolYears.size()) + ")";
    sceneTitle.centerX();
    mousePoint = GetMousePosition();
    chooseSchoolYear.process(mousePoint);
    inputSchoolYearAdded.process(mousePoint);
    inputSchoolYearRemoved.process(mousePoint);
    if (!isAddedListSchoolYear) {
        chooseSchoolYear.add(getListSchoolYear());
        isAddedListSchoolYear = true;
    }
    if (view.clicked(mousePoint)) {
          ptrSchoolYear_Global = getSchoolYear(chooseSchoolYear.getCurLabel());
          inputSchoolYearAdded.clearContent();
          inputSchoolYearRemoved.clearContent();
          chooseSchoolYear.clear();
          isAddedListSchoolYear = false;
          ms.clear();
          return registry.schoolYearScene;
    }  
    else if (add.clicked(mousePoint)) {
        std::string content = inputSchoolYearAdded.getContent();
        std::string outStr;
        if (addSchoolYear(content, outStr)){
            chooseSchoolYear.add(content);    
            chooseSchoolYear.process(mousePoint);
        }
        ms = outStr;
        ms.centerX();
        inputSchoolYearAdded.clearContent();
    }
    else if (remove.clicked(mousePoint)) {
        string startYear = inputSchoolYearRemoved.getContent();
        string outStr;
        if (removeSchoolYear(startYear, outStr)) {
            chooseSchoolYear.remove(startYear);
            chooseSchoolYear.process(mousePoint);
        }
        ms = outStr;
        ms.centerX();
        inputSchoolYearRemoved.clearContent();
    }
    if (back.clicked(mousePoint)) {
        chooseSchoolYear.process(mousePoint);
        inputSchoolYearAdded.clearContent();
        inputSchoolYearRemoved.clearContent();
        chooseSchoolYear.clear();
        isAddedListSchoolYear = false;
        ms.clear();
        return registry.staffScene;
    }
    return this;
}