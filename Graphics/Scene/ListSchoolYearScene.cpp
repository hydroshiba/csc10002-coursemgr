#include "ListSchoolYearScene.h"

ListSchoolYearScene::ListSchoolYearScene() {
    sceneTitle = "List Of School Year";
    sceneTitle.setSize(50);
    sceneTitle.centerX();
    sceneTitle.setY(100);
}

void ListSchoolYearScene::render() {
    sceneTitle.render();
}

Scene* ListSchoolYearScene::process() {
    this->mousePoint = GetMousePosition();
    return this;
}