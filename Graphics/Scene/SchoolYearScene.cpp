#include "SchoolYearScene.h"

SchoolYearScene::SchoolYearScene() {
    content = "School Year";
    content.setSize(50);
    content.centerX();
    content.setY(150);
}

void SchoolYearScene::render() {
    content.render();
}

Scene* SchoolYearScene::process() {
    mousePoint = GetMousePosition();
    return this;
} 