#include "Menu.h"

Menu::Menu() {
	login.label = "Login";
	login.setSize({150, 75});
	login.centerX();
}

void Menu::render() {
	login.render(this->mousePoint);
}

Scene *Menu::process() {
	this->mousePoint = GetMousePosition();
	render();
	return nullptr;
}
