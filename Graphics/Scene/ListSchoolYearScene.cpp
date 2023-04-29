#include "ListSchoolYearScene.h"

ListSchoolYearScene::ListSchoolYearScene() {
    sceneTitle = "List Of School Year";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(100);

    viewYear = "View Year";
    viewYear.setSize(30);
    viewYear.setPos({100, 250});

    back.label = "Back";
    back.setPos({1000, 600});
    back.setSize({200, 50});
}

void ListSchoolYearScene::render() {
    sceneTitle.render();
    viewYear.render();
    back.render(mousePoint);
}

Scene* ListSchoolYearScene::process() {
    this->mousePoint = GetMousePosition();
    if (back.clicked(mousePoint)) return registry.blank;
    return this;
}