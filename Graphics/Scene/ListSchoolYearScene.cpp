#include "ListSchoolYearScene.h"

ListSchoolYearScene::ListSchoolYearScene() {
    sceneTitle = "List Of School Year";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(100);
    //--------------------------------------
    viewYear = "View Year";
    viewYear.setSize(30);
    viewYear.setPos({100, 250});

    chooseSchoolYear.setLabel("List of School Year");
    chooseSchoolYear.add(getListSchoolYear(schoolYears));
    chooseSchoolYear.setPos({400, 240});
    chooseSchoolYear.setSize({300, 50});

    view.label = "View";
    view.setPos({800, 240});
    view.setSize({150, 50});
    //--------------------------------------
    addYear = "Add Year";
    addYear.setSize(30);
    addYear.setPos({100, 350});

    inputSchoolYearAdded.defaultText = "Enter School Year";
    inputSchoolYearAdded.setPos({400, 340});
    inputSchoolYearAdded.setSize({300, 50});

    add.label = "Add";
    add.setPos({800, 340});
    add.setSize({150, 50});
    //--------------------------------------
    removeYear = "Remove Year";
    removeYear.setSize(30);
    removeYear.setPos({100, 450});

    inputSchoolYearRemoved.defaultText = "Enter School Year";
    inputSchoolYearRemoved.setPos({400, 440});
    inputSchoolYearRemoved.setSize({300, 50});

    remove.label = "Remove";
    remove.setPos({800, 440});
    remove.setSize({150, 50});
    //--------------------------------------
    back.label = "Back";
    back.setPos({1000, 600});
    back.setSize({200, 50});

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

    if (view.clicked(mousePoint)) {
        const size_t i = static_cast<const size_t>(chooseSchoolYear.getSelected());
        if (i >= 0) {
            ptrSchoolYear_Global = &schoolYears[i];
            inputSchoolYearAdded.clearContent();
            inputSchoolYearRemoved.clearContent();
            return registry.schoolYearScene;
        }  
    }
    inputSchoolYearAdded.process(mousePoint);
    if (add.clicked(mousePoint)) {
        std::string content = inputSchoolYearAdded.getContent();
        std::string outStr;
        if (addSchoolYear(schoolYears, content, outStr)){
            chooseSchoolYear.add(content);    
        }
        ms = outStr;
        ms.centerX();
        inputSchoolYearAdded.clearContent();
    }
    inputSchoolYearRemoved.process(mousePoint);
    if (remove.clicked(mousePoint)) {
        string startYear = inputSchoolYearRemoved.getContent();
        string outStr;
        if (removeSchoolYear(schoolYears, startYear, outStr)) {
            chooseSchoolYear.clear();
            chooseSchoolYear.add(getListSchoolYear(schoolYears));
        }
        ms = outStr;
        ms.centerX();
        inputSchoolYearRemoved.clearContent();
    }
    if (back.clicked(mousePoint)) {
        chooseSchoolYear.clear();
        chooseSchoolYear.add(getListSchoolYear(schoolYears));
        inputSchoolYearAdded.clearContent();
        inputSchoolYearRemoved.clearContent();
        return registry.staffScene;
    }
    return this;
}