#include "Login.h"

Login::Login() {
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

	test.setPos({200, 200});
	test.setSize({400, 50});

	test.add("yo wtf bro");
	test.add("anyone there");
	test.add("this is a very long text, with the purpose of testing the display of the option box");
	test.add("please send me hope");
	test.add("or nudes");
	test.add("or a rope");

	invalid = "";
	invalid.setColor(RED);
	invalid.setSize(24);
	invalid.centerX();
	invalid.setY(425);
}

void Login::render() {
	title.render();
	login.render(mousePoint);
	quit.render(mousePoint);

	username.render(mousePoint);
	password.render(mousePoint);
	invalid.render();

	test.render(mousePoint);
}

Scene* Login::process() {
	this->mousePoint = GetMousePosition();

	if(quit.clicked(mousePoint)) return nullptr;

	if(login.clicked(mousePoint)) {
		if(username.content.text.empty() || password.content.text.empty()) {
			invalid = "Invalid username/password, please retry";
			invalid.centerX();
			return this;
		}
		
		invalid = "";
		invalid.centerX();
		return registry.blank;
	}

	if(!test.process(mousePoint)) {
		username.process(mousePoint);
		password.process(mousePoint);
	}

	return this;
}