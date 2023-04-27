#include "SchoolYearScene.h"

SchoolYearScene::SchoolYearScene() {
    nameScene = "School Year";
    nameScene.setSize(50);
    nameScene.centerX();
    nameScene.setY(100);
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
    //--------------------------------------
    addClass = "Add Class";
    addClass.setSize(30);
    addClass.setPos({100, 350});

    inputClassNameAdded.defaultText = "Enter Class Name";
    inputClassNameAdded.setPos({400, 340});
    inputClassNameAdded.setSize({300, 50});

    add.label = "Add";
    add.setPos({800, 340});
    add.setSize({150, 50});
    //--------------------------------------
    removeClass = "Remove Class";
    removeClass.setSize(30);
    removeClass.setPos({100, 450});

    inputClassNameRemoved.defaultText = "Enter Class Name";
    inputClassNameRemoved.setPos({400, 440});
    inputClassNameRemoved.setSize({300, 50});

    remove.label = "Remove";
    remove.setPos({800, 440});
    remove.setSize({150, 50});
    //--------------------------------------
    editYear = "Edit Year";
    editYear.setSize(30);
    editYear.setPos({100, 550});

    inputYearEditted.defaultText = "Enter Year";
    inputYearEditted.setPos({400, 540});
    inputYearEditted.setSize({300, 50});
}

void SchoolYearScene::render() {
    nameScene.render();
    //--------------------------------------
    viewClass.render();
    listClass.render(mousePoint);
    view.render(mousePoint);
    //--------------------------------------
    addClass.render();
    inputClassNameAdded.render(mousePoint);
    add.render(mousePoint);
    //--------------------------------------
    removeClass.render();
    inputClassNameRemoved.render(mousePoint);
    remove.render(mousePoint);
    //--------------------------------------
    editYear.render();
    inputYearEditted.render(mousePoint);
}

Scene* SchoolYearScene::process() {
    this->mousePoint = GetMousePosition();
    //--------------------------------------
    listClass.process(mousePoint);
    if (view.clicked(mousePoint)) {
        std::cout << "View button clicked\n";
    }
    //--------------------------------------
    inputClassNameAdded.process(mousePoint);
    if (add.clicked(mousePoint)) {
        std::cout << "Add button clicked\n";
    }
    //--------------------------------------
    inputClassNameRemoved.process(mousePoint);
    if (remove.clicked(mousePoint)) {
        std::cout << "Remove button clicked\n";
    }
    //--------------------------------------
    inputYearEditted.process(mousePoint);

    return this;
} 