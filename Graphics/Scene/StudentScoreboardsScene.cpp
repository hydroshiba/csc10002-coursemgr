#include "StudentScoreboardsScene.h"

StudentScoreBoardsScene::StudentScoreBoardsScene() {
	sceneName = "Welcome";
	sceneName.setY(10);
	sceneName.setSize(80);
	sceneName.centerX();

	back.label = "Back";
	back.setSize({200, 100});
	back.setPos({ 1000, 600 });
	back.fill_color = ORANGE;
	back.hover_color = MAROON;
	back.press_color = RED;
}

void StudentScoreBoardsScene::render() {
	sceneName.render();
	back.render(mousePoint);
}


Scene* StudentScoreBoardsScene::process() {
	this->mousePoint = GetMousePosition();

	if (ptrStudent_Global != nullptr) {
		sceneName = "Welcome student " + ptrStudent_Global->name.get();
		sceneName.centerX();
	}
	else {
		sceneName = "Access nullptr error";
		sceneName.centerX();
	}
	if (back.clicked(mousePoint)) {
		return registry.studentScene;
	}
	return this;
}