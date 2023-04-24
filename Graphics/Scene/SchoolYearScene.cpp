#include "SchoolYearScene.h"

SchoolYearScene::SchoolYearScene() {
    nameScene = "School Year";
    nameScene.setSize(50);
    nameScene.centerX();
    nameScene.setY(100);

    viewClass = "View Classes";
    viewClass.setSize(30);
    viewClass.setPos({100, 250});

    addClass = "Add Class";
    addClass.setSize(30);
    addClass.setPos({100, 350});

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
    addClass.render();
    removeClass.render();
    editYear.render();
}

Scene* SchoolYearScene::process() {
    mousePoint = GetMousePosition();
    return this;
} 