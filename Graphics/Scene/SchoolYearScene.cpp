#include "SchoolYearScene.h"

SchoolYearScene::SchoolYearScene() {
    nameScene = "School Year";
    nameScene.setSize(50);
    nameScene.centerX();
    nameScene.setY(100);

    nameViewClass = "View Classes";
    nameViewClass.setSize(30);
    nameViewClass.setPos({100, 250});

    nameAddClass = "Add Class";
    nameAddClass.setSize(30);
    nameAddClass.setPos({100, 350});

    nameRemoveClass = "Remove Class";
    nameRemoveClass.setSize(30);
    nameRemoveClass.setPos({100, 450});

    nameEditYear = "Edit Year";
    nameEditYear.setSize(30);
    nameEditYear.setPos({100, 550});
}

void SchoolYearScene::render() {
    nameScene.render();
    nameViewClass.render();
    nameAddClass.render();
    nameRemoveClass.render();
    nameEditYear.render();
}

Scene* SchoolYearScene::process() {
    mousePoint = GetMousePosition();
    return this;
} 