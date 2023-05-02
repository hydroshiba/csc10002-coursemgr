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
    chooseSchoolYear.setPos({400, 240});
    chooseSchoolYear.setSize({300, 50});

    view.label = "View";
    view.setPos({800, 240});
    view.setSize({150, 50});
    //--------------------------------------
    addYear = "Add Year";
    addYear.setSize(30);
    addYear.setPos({100, 350});

    inputSchoolYearAdded.defaultText = "Enter new School Year";
    inputSchoolYearAdded.setPos({400, 340});
    inputSchoolYearAdded.setSize({300, 50});

    add.label = "Add";
    add.setPos({800, 340});
    add.setSize({150, 50});
    //--------------------------------------
    back.label = "Back";
    back.setPos({1000, 600});
    back.setSize({200, 50});
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
    back.render(mousePoint);
}

Scene* ListSchoolYearScene::process() {
    mousePoint = GetMousePosition();
    chooseSchoolYear.process(mousePoint);
    if (view.clicked(mousePoint)) {
        std::cout << "View clicked\n";
    }
    inputSchoolYearAdded.process(mousePoint);
    if (add.clicked(mousePoint)) {
        std::cout << "Add clicked\n";
        std::string content = inputSchoolYearAdded.getContent();
        std::string warning;
        if (content != "") {
            chooseSchoolYear.add(content);
            // addSchoolYear(schoolYears, content, warning);
        }
        std::cout << warning << '\n';
    }
    if (back.clicked(mousePoint)) return registry.staffScene;
    return this;
}