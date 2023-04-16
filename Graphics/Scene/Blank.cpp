#include "Blank.h"

Blank::Blank() {
	notice = "This scene is not yet implemented";
	notice.setSize(75);
	notice.setY(300);
	notice.centerX();

	back.label = "Back";
	back.setSize({125, 50});
	back.setY(600);
	back.centerX();
}

Scene* Blank::process() {
	this->mousePoint = GetMousePosition();

	if(back.clicked(mousePoint)) return registry.login;
	return this;
}

void Blank::render() {
	notice.render();
	back.render(mousePoint);
}
