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

	for(int i = 1; i <= 50; ++i) test.add(std::to_string(i));

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
		std::string outStr = "";
		std::string usernameStr = username.getContent();
		std::string passwordStr = password.getContent();
		if(usernameStr.empty() || passwordStr.empty()) {
			invalid = "Invalid username/password, please retry";
			invalid.centerX();
			return this;
		}
		if (isCorrectStaffAccount(staffs, usernameStr, passwordStr, outStr)) {
			ptrStaff_Global = getStaff(staffs, usernameStr);
			invalid = outStr;
			return registry.staffScene;
		}
		if (isCorrectStudentAccount(students, usernameStr, passwordStr, outStr)) {
			ptrStudent_Global = getStudent(students, usernameStr);
			invalid = outStr;
			return registry.studentScene;
		}
		invalid = "Invalid username/password, please retry";
		invalid.centerX();
		return this;
	}

	if(!test.process(mousePoint)) {
		username.process(mousePoint);
		password.process(mousePoint);
	}

	return this;
}