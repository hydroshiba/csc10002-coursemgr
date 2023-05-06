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

	quit.setRemoveColor();

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

	table.render(mousePoint);
}

Scene* Login::process() {
	this->mousePoint = GetMousePosition();

	if(quit.clicked(mousePoint)) return nullptr;

	if(login.clicked(mousePoint)) {
		std::string outStr = "";
		std::string usernameStr = username.getContent();
		std::string passwordStr = password.getContent();

		if (isCorrectStaffAccount(usernameStr, passwordStr, outStr)) {
			ptrStaff_Global = getStaff(usernameStr);
			
			invalid = "";
			invalid.centerX();

			username.content = "";
			password.content = "";

			return registry.staffScene;
		}
		else if (isCorrectStudentAccount(usernameStr, passwordStr, outStr)) {
			ptrStudent_Global = getStudent(usernameStr);
			
			invalid = "";
			invalid.centerX();

			username.content = "";
			password.content = "";

			return registry.studentScene;
		}

		invalid = "Invalid username/password, please retry";
		invalid.centerX();
		return this;
	}

	username.process(mousePoint);
	password.process(mousePoint);

	table.process(mousePoint);

	return this;
}