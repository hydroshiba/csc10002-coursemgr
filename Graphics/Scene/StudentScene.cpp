#include "StudentScene.h"


const float yPosSceneName = 10;
const float sizeTextSceneName = 100;

const float xDis = 150;
const float yDis = 30;

const float textBoxContentSize = 30;
const float inputBoxContentSize = textBoxContentSize;

const float textBoxHeight = 50;
const float textBoxWidth = 100;

const Vector2 textBoxSize = { textBoxHeight, textBoxWidth };

const float inputBoxHeight = 50;
const float inputBoxWidth = 300;

const Vector2 inputBoxSize = { inputBoxWidth, inputBoxHeight };

const float xPosTextBox = 50;
const float yPosTextBox = 100;

const float yPosTextBoxID = yPosTextBox;
const float yPosTextBoxFirstName = yPosTextBoxID + textBoxHeight + yDis;
const float yPosTextBoxLastName = yPosTextBoxFirstName + textBoxHeight + yDis;
const float yPosTextBoxGender = yPosTextBoxLastName + textBoxHeight + yDis;
const float yPosTextBoxBirth = yPosTextBoxGender + textBoxHeight + yDis;
const float yPosTextBoxSocialID = yPosTextBoxBirth + textBoxHeight + yDis;
const float yPosTextBoxPassword = yPosTextBoxSocialID + textBoxHeight + yDis;

const float xPosInputBox = xPosTextBox + xDis;

const Vector2 buttonSize = { 200, 100 };

StudentScene::StudentScene() {
	ptrStudent = new Student();
	//ptrStaff = nullptr;

	sceneName = "Student";
	sceneName.centerX();
	sceneName.setSize(sizeTextSceneName);
	sceneName.setY(yPosSceneName);

	textID = "ID";
	textID.setSize(textBoxContentSize);
	textID.setPos({ xPosTextBox, yPosTextBoxID });

	textFirstName = "First name";
	textFirstName.setSize(textBoxContentSize);
	textFirstName.setPos({ xPosTextBox, yPosTextBoxFirstName });

	textLastName = "Last name";
	textLastName.setSize(textBoxContentSize);
	textLastName.setPos({ xPosTextBox, yPosTextBoxLastName });

	textGender = "Gender";
	textGender.setSize(textBoxContentSize);
	textGender.setPos({ xPosTextBox, yPosTextBoxGender });

	textBirth = "Birth";
	textBirth.setSize(textBoxContentSize);
	textBirth.setPos({ xPosTextBox, yPosTextBoxBirth });

	textSocialID = "SocialID";
	textSocialID.setSize(textBoxContentSize);
	textSocialID.setPos({ xPosTextBox, yPosTextBoxSocialID });

	textPassword = "Password";
	textPassword.setSize(textBoxContentSize);
	textPassword.setPos({ xPosTextBox, yPosTextBoxPassword });

	inputID.defaultText = ptrStudent->ID;
	inputID.setSize(inputBoxSize);
	inputID.setPos({ xPosInputBox, yPosTextBoxID });

	inputFirstName.defaultText = ptrStudent->name.first;
	inputFirstName.setSize(inputBoxSize);
	inputFirstName.setPos({ xPosInputBox, yPosTextBoxFirstName });

	inputLastName.defaultText = ptrStudent->name.last;
	inputLastName.setSize(inputBoxSize);
	inputLastName.setPos({ xPosInputBox, yPosTextBoxLastName });

	inputGender.defaultText = gender_to_string(ptrStudent->gender);
	inputGender.setSize(inputBoxSize);
	inputGender.setPos({ xPosInputBox, yPosTextBoxGender });

	inputBirth.defaultText = ptrStudent->birth.get();
	inputBirth.setSize(inputBoxSize);
	inputBirth.setPos({ xPosInputBox, yPosTextBoxBirth });

	inputSocialID.defaultText = ptrStudent->socialID;
	inputSocialID.setSize(inputBoxSize);
	inputSocialID.setPos({ xPosInputBox, yPosTextBoxSocialID });

	inputPassword.defaultText = std::to_string(ptrStudent->getHashedPass());
	inputPassword.setSize(inputBoxSize);
	inputPassword.setPos({ xPosInputBox, yPosTextBoxPassword });

	change.label = "Change";
	change.setSize(buttonSize);
	change.setPos({ 1000, 300 });
	
	viewScoreboard.label = "View scoreboards";
	viewScoreboard.setSize(buttonSize);
	viewScoreboard.setPos({ 1000, 400 });

	logout.label = "Logout";
	logout.setSize(buttonSize);
	logout.setPos({ 1000, 500 });
	
	back.label = "Back";
	back.setSize(buttonSize);
	back.setPos({ 1000, 600 });
}

void StudentScene::render() {
	sceneName.render();
	textID.render();
	textFirstName.render();
	textLastName.render();
	textGender.render();
	textBirth.render();
	textSocialID.render();
	textPassword.render();

	inputID.render(mousePoint);
	inputFirstName.render(mousePoint);
	inputLastName.render(mousePoint);
	inputGender.render(mousePoint);
	inputBirth.render(mousePoint);
	inputSocialID.render(mousePoint);
	inputPassword.render(mousePoint);

	change.render(mousePoint);
	viewScoreboard.render(mousePoint);
	logout.render(mousePoint);
	back.render(mousePoint);
}

Scene* StudentScene::process() {
	this->mousePoint = GetMousePosition();
	inputID.process(mousePoint);
	inputFirstName.process(mousePoint);
	inputLastName.process(mousePoint);
	inputGender.process(mousePoint);
	inputBirth.process(mousePoint);
	inputSocialID.process(mousePoint);
	inputPassword.process(mousePoint);

	if (back.clicked(mousePoint))
		return registry.login;
	return this;
}