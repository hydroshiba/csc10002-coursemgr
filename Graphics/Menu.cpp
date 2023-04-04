#include "Menu.h"

Menu::Menu() {
	login.label = "Login";
	login.setSize({125, 50});
	login.setY(500);
	login.centerX();

	quit.label = "Quit";
	quit.setSize({125, 50});
	quit.setY(600);
	quit.centerX();

	quit.hover_color = RED;
	quit.press_color = MAROON;

	title = "Course Management System";
	title.setSize(75);
	title.setY(100);
	title.centerX();
}

void Menu::render() {
	login.render(this->mousePoint);
	quit.render(this->mousePoint);
	title.render();
}

Scene *Menu::process() {
	this->mousePoint = GetMousePosition();

	if(quit.clicked(mousePoint)) return nullptr;
	return this;
}
