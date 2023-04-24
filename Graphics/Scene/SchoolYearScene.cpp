#include "SchoolYearScene.h"

SchoolYearScene::SchoolYearScene() {
    nameScene = "School Year";
    nameScene.setSize(50);
    nameScene.centerX();
    nameScene.setY(100);

    viewClass = "View Classes";
    viewClass.setSize(30);
    viewClass.setPos({100, 250});

    listClass.setLabel("List of Classes:");
    listClass.setPos({400, 240});
    listClass.setSize({300, 50});

    addClass = "Add Class";
    addClass.setSize(30);
    addClass.setPos({100, 350});

    inputClassNameAdded.defaultText = "Enter Class Name";
    inputClassNameAdded.setPos({400, 340});
    inputClassNameAdded.setSize({300, 50});

    removeClass = "Remove Class";
    removeClass.setSize(30);
    removeClass.setPos({100, 450});

    editYear = "Edit Year";
    editYear.setSize(30);
    editYear.setPos({100, 550});
}

void SchoolYearScene::render() {
    nameScene.render();

    viewClass.render();
    listClass.render(mousePoint);

    addClass.render();
    inputClassNameAdded.render(mousePoint);

    removeClass.render();
    editYear.render();
}

Scene* SchoolYearScene::process() {
    this->mousePoint = GetMousePosition();
    return this;
} 