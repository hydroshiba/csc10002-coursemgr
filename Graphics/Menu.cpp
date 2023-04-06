#include "Menu.h"

Menu::Menu() {
	login.label = "Login";
	login.setSize({125, 50});
	login.setY(525);
	login.centerX();

	quit.label = "Quit";
	quit.setSize({125, 50});
	quit.setY(600);
	quit.centerX();

	quit.hover_color = RED;
	quit.press_color = MAROON;

	title = app_const::title;
	title.setSize(75);
	title.setY(100);
	title.centerX();

	username.pos = {300, 300};

	test.pos = {200, 200};
}

void Menu::render() {
	title.render();
	login.render(this->mousePoint);
	quit.render(this->mousePoint);

	username.render();

	test.drawButton();
}

Scene* Menu::process() {
	this->mousePoint = GetMousePosition();

	if(quit.clicked(mousePoint)) return nullptr;
	if(login.clicked(mousePoint)) {
		
	}

	return this;
}