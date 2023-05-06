#include "ListSchoolYearScene.h"

bool isAddedListSchoolYear = false;

ListSchoolYearScene::ListSchoolYearScene() {
    sceneTitle = "List Of School Years";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(100);
    //--------------------------------------
    viewYear = "View Year";
    viewYear.setSize(30);
    viewYear.setPos({50, 250});

    chooseSchoolYear.setLabel("Choose School Year");
    chooseSchoolYear.setPos({50, 300});
    chooseSchoolYear.setSize({300, 50});

    view.label = "View";
    view.setPos({400, 300});
    view.setSize({150, 50});
    view.setViewColor();
    //--------------------------------------
    addYear = "Add Year";
    addYear.setSize(30);
    addYear.setPos({600, 250});

    inputSchoolYearAdded.defaultText = "Enter School Year";
    inputSchoolYearAdded.setPos({750, 250});
    inputSchoolYearAdded.setSize({250, 50});

    add.label = "Add";
    add.setPos({1050, 250});
    add.setSize({150, 50});
    add.setInsertColor();
    //--------------------------------------
    removeYear = "Remove Year";
    removeYear.setSize(30);
    removeYear.setPos({600, 350});

    inputSchoolYearRemoved.defaultText = "Enter School Year";
    inputSchoolYearRemoved.setPos({750, 350});
    inputSchoolYearRemoved.setSize({250, 50});

    remove.label = "Remove";
    remove.setPos({1050, 350});
    remove.setSize({150, 50});
    remove.setRemoveColor();
    //--------------------------------------
    back.label = "Back";
    back.setPos({1000, 600});
    back.setSize({200, 50});
    back.setRemoveColor();

    ms = "";
    ms.setSize(24);
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
    mousePoint = GetMousePosition();
    chooseSchoolYear.process(mousePoint);
    inputSchoolYearAdded.process(mousePoint);
    inputSchoolYearRemoved.process(mousePoint);
    if (!isAddedListSchoolYear) {
        chooseSchoolYear.add(getListSchoolYear(schoolYears));
        isAddedListSchoolYear = true;
    }
    if (view.clicked(mousePoint)) {
          ptrSchoolYear_Global = getSchoolYear(schoolYears, chooseSchoolYear.getCurLabel());
          inputSchoolYearAdded.clearContent();
          inputSchoolYearRemoved.clearContent();
          return registry.schoolYearScene;
    }  
    else if (add.clicked(mousePoint)) {
        std::string content = inputSchoolYearAdded.getContent();
        std::string outStr;
        if (addSchoolYear(schoolYears, content, outStr)){
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
        if (removeSchoolYear(schoolYears, startYear, outStr)) {
            chooseSchoolYear.remove(startYear);
            chooseSchoolYear.process(mousePoint);
        }
        ms = outStr;
        ms.centerX();
        inputSchoolYearRemoved.clearContent();
    }
    else if (back.clicked(mousePoint)) {
        chooseSchoolYear.process(mousePoint);
        inputSchoolYearAdded.clearContent();
        inputSchoolYearRemoved.clearContent();
        chooseSchoolYear.clear();
        isAddedListSchoolYear = false;
        return registry.staffScene;
    }
    return this;
}