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

	username.setY(275);
	username.setSize({300, 50});
	username.centerX();
	username.defaultText = "Username";

	password.setY(350);
	password.setSize({300, 50});
	password.centerX();
	password.defaultText = "Password";

	test.setLabel("Hello there!");
	test.setPos({200, 200});
	test.setSize({400, 50});

	test.addNewButton("1");
	test.addNewButton("2");
	test.addNewButton("3");
	test.addNewButton("4");
	test.addNewButton("5");
}

void Menu::render() {
	title.render();
	login.render(mousePoint);
	quit.render(mousePoint);

	username.render(mousePoint);
	password.render(mousePoint);

	test.render(mousePoint);
}

Scene* Menu::process() {
	this->mousePoint = GetMousePosition();

	if(quit.clicked(mousePoint)) return nullptr;
	if(login.clicked(mousePoint)) {
		return registry.blank;
	}

	username.process(mousePoint);
	password.process(mousePoint);

	return this;
}