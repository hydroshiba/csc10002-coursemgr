#include "StudentScene.h"
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
const float yPosSceneName = 10;
const float sizeTextSceneName = 100;
//-------------------------------------------------------------------------------------
const float xDis = 50;
const float yDis = 30;
//-------------------------------------------------------------------------------------
const float textBoxContentSize = 30;
const float inputBoxContentSize = textBoxContentSize;
//-------------------------------------------------------------------------------------
const float textBoxHeight = 50;
const float textBoxWidth = 150;
const Vector2 textBoxSize = { textBoxHeight, textBoxWidth };
//-------------------------------------------------------------------------------------
const float inputBoxHeight = 50;
const float inputBoxWidth = 300;
const Vector2 inputBoxSize = { inputBoxWidth, inputBoxHeight };
//-------------------------------------------------------------------------------------
const float xPosTextBox = 50;
const float yPosTextBox = 150;
//-------------------------------------------------------------------------------------
const float yPosTextBoxID = yPosTextBox;
const float yPosTextBoxFirstName = yPosTextBoxID + textBoxHeight + yDis;
const float yPosTextBoxLastName = yPosTextBoxFirstName + textBoxHeight + yDis;
const float yPosTextBoxGender = yPosTextBoxLastName + textBoxHeight + yDis;
const float yPosTextBoxBirth = yPosTextBoxGender + textBoxHeight + yDis;
const float yPosTextBoxSocialID = yPosTextBoxBirth + textBoxHeight + yDis;
const float yPosTextBoxPassword = yPosTextBoxSocialID + textBoxHeight + yDis;
//-------------------------------------------------------------------------------------
const float xPosInputBox = xPosTextBox + textBoxWidth + xDis;
//-------------------------------------------------------------------------------------
const float buttonHeigth = 100;
const float buttonWidth = 200;
const Vector2 buttonSize = { buttonWidth, buttonHeigth };
//-------------------------------------------------------------------------------------
const float yDisButton = 50;
const float xPosButton = 1000;
const float yPosChange = 150;
const float yPosViewSBs = yPosChange + buttonHeigth + yDisButton;
const float yPosLogout = yPosViewSBs + buttonHeigth + yDisButton;
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
const std::string defaultInputBoxContent = "Error InputBoxContent";
const std::string defaultTextBoxContent = "Error TextBoxContent";
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
StudentScene::StudentScene() {
	sceneName = "Student";
	sceneName.setSize(sizeTextSceneName);
	sceneName.setY(yPosSceneName);
	sceneName.centerX();
	//-----------------------------------------------------------------------------------
	textID = "ID: ";
	textID.setSize(textBoxContentSize);
	textID.setPos({ xPosTextBox, yPosTextBoxID });
	//-----------------------------------------------------------------------------------
	textFirstName = "First name: ";
	textFirstName.setSize(textBoxContentSize);
	textFirstName.setPos({ xPosTextBox, yPosTextBoxFirstName });
	//-----------------------------------------------------------------------------------
	textLastName = "Last name: ";
	textLastName.setSize(textBoxContentSize);
	textLastName.setPos({ xPosTextBox, yPosTextBoxLastName });
	//-----------------------------------------------------------------------------------
	textGender = "Gender: ";
	textGender.setSize(textBoxContentSize);
	textGender.setPos({ xPosTextBox, yPosTextBoxGender });
	//-----------------------------------------------------------------------------------
	textBirth = "Birth: ";
	textBirth.setSize(textBoxContentSize);
	textBirth.setPos({ xPosTextBox, yPosTextBoxBirth });
	//-----------------------------------------------------------------------------------
	textSocialID = "SocialID: ";
	textSocialID.setSize(textBoxContentSize);
	textSocialID.setPos({ xPosTextBox, yPosTextBoxSocialID });
	//-----------------------------------------------------------------------------------
	textPassword = "Change password: ";
	textPassword.setSize(textBoxContentSize);
	textPassword.setPos({ xPosTextBox, yPosTextBoxPassword });
	//-----------------------------------------------------------------------------------
	/*if (ptrStudent_Global == nullptr) {
		textID.setContent(textID.getContent() + defaultTextBoxContent);
		textFirstName.setContent(textFirstName.getContent() + defaultTextBoxContent);
		textLastName.setContent(textLastName.getContent() + defaultTextBoxContent);
		textGender.setContent(textGender.getContent() + defaultTextBoxContent);
		textBirth.setContent(textBirth.getContent() + defaultTextBoxContent);
		textSocialID.setContent(textSocialID.getContent() + defaultTextBoxContent);
	}
	else {
		textID.setContent(textID.getContent() + ptrStudent_Global->ID);
		textFirstName.setContent(textFirstName.getContent() + ptrStudent_Global->name.first);
		textLastName.setContent(textLastName.getContent() + ptrStudent_Global->name.last);
		textGender.setContent(textGender.getContent() + gender_to_string(ptrStudent_Global->gender));
		textBirth.setContent(textBirth.getContent() + ptrStudent_Global->birth.get());
		textSocialID.setContent(textSocialID.getContent() + ptrStudent_Global->socialID);
		textPassword.setContent(textPassword.getContent() + std::to_string(ptrStudent_Global->getHashedPass()));
	}*/

	/*if (ptrStudent_Global != nullptr)
		inputID.defaultText = ptrStudent_Global->ID;
	else
		inputID.defaultText = defaultInputBoxContent;*/
	inputID.defaultText = "";
	inputID.setSize(inputBoxSize);
	inputID.setPos({ xPosInputBox, yPosTextBoxID });

	/*if (ptrStudent_Global != nullptr)
		inputFirstName.defaultText = ptrStudent_Global->name.first;
	else
		inputFirstName.defaultText = defaultInputBoxContent;*/
	inputFirstName.defaultText = "";
	inputFirstName.setSize(inputBoxSize);
	inputFirstName.setPos({ xPosInputBox, yPosTextBoxFirstName });
	//-----------------------------------------------------------------------------------
	/*if (ptrStudent_Global != nullptr)
		inputLastName.defaultText = "Lastname";
	else
		inputLastName.defaultText = defaultInputBoxContent;*/
	inputLastName.defaultText = "";
	//-----------------------------------------------------------------------------------
	inputLastName.setSize(inputBoxSize);
	inputLastName.setPos({ xPosInputBox, yPosTextBoxLastName });
	//-----------------------------------------------------------------------------------
	/*if (ptrStudent_Global != nullptr)
		inputGender.defaultText = gender_to_string(ptrStudent_Global->gender);
	else
		inputGender.defaultText = defaultInputBoxContent;*/
	inputGender.defaultText = "";
	//-----------------------------------------------------------------------------------
	inputGender.setSize(inputBoxSize);
	inputGender.setPos({ xPosInputBox, yPosTextBoxGender });
	//-----------------------------------------------------------------------------------
	/*if (ptrStudent_Global != nullptr)
		inputBirth.defaultText = ptrStudent_Global->birth.get();
	else
		inputBirth.defaultText = defaultInputBoxContent;*/
	inputBirth.defaultText = "";
	//-----------------------------------------------------------------------------------
	inputBirth.setSize(inputBoxSize);
	inputBirth.setPos({ xPosInputBox, yPosTextBoxBirth });
	//-----------------------------------------------------------------------------------
	/*if (ptrStudent_Global != nullptr)
		inputSocialID.defaultText = ptrStudent_Global->socialID;
	else
		inputSocialID.defaultText = defaultInputBoxContent;*/
	inputSocialID.defaultText = "";
	//-----------------------------------------------------------------------------------
	inputSocialID.setSize(inputBoxSize);
	inputSocialID.setPos({ xPosInputBox, yPosTextBoxSocialID });
	//-----------------------------------------------------------------------------------
	/*if (ptrStudent_Global != nullptr)
		inputPassword.defaultText = std::to_string(ptrStudent_Global->getHashedPass());
	else
		inputPassword.defaultText = defaultInputBoxContent;*/
	inputPassword.defaultText = "Input new password";
	//-----------------------------------------------------------------------------------
	inputPassword.setSize(inputBoxSize);
	inputPassword.setPos({ xPosInputBox, yPosTextBoxPassword });
	//-----------------------------------------------------------------------------------
	change.label = "Change";
	change.setSize(buttonSize);
	change.setPos({ xPosButton, yPosChange });
	//-----------------------------------------------------------------------------------
	viewScoreboard.label = "View scoreboards";
	viewScoreboard.setSize(buttonSize);
	viewScoreboard.setPos({ xPosButton, yPosViewSBs });
	//-----------------------------------------------------------------------------------
	logout.label = "Logout";
	logout.setSize(buttonSize);
	logout.setPos({ xPosButton, yPosLogout });
	logout.fill_color = ORANGE;
	logout.hover_color = MAROON;
	//-----------------------------------------------------------------------------------
	message = "";
	message.setColor(RED);
	message.setSize(30);
	message.setPos({800, 680});
	//-----------------------------------------------------------------------------------
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
	//-----------------------------------------------------------------------------------
	inputID.render(mousePoint);
	inputFirstName.render(mousePoint);
	inputLastName.render(mousePoint);
	inputGender.render(mousePoint);
	inputBirth.render(mousePoint);
	inputSocialID.render(mousePoint);
	inputPassword.render(mousePoint);
	//-----------------------------------------------------------------------------------
	change.render(mousePoint);
	viewScoreboard.render(mousePoint);
	logout.render(mousePoint);
	//-----------------------------------------------------------------------------------
	message.render();
}

Scene* StudentScene::process() {
	this->mousePoint = GetMousePosition();
	//-----------------------------------------------------------------------------------
	inputID.process(mousePoint);
	inputFirstName.process(mousePoint);
	inputLastName.process(mousePoint);
	inputGender.process(mousePoint);
	inputBirth.process(mousePoint);
	inputSocialID.process(mousePoint);
	inputPassword.process(mousePoint);
	//-----------------------------------------------------------------------------------
	/*if (ptrStudent_Global != nullptr) {
		textID.setContent("ID: " + ptrStudent_Global->ID);
		textFirstName.setContent("First name: " + ptrStudent_Global->name.first);
		textLastName.setContent("Last name: " + ptrStudent_Global->name.last);
		textGender.setContent("Gender: " + gender_to_string(ptrStudent_Global->gender));
		textBirth.setContent("Birth: " + ptrStudent_Global->birth.get());
		textSocialID.setContent("SocialID: " + ptrStudent_Global->socialID);
	}*/
	//-----------------------------------------------------------------------------------
	if (ptrStudent_Global != nullptr) {
		inputID.defaultText = ptrStudent_Global->ID;
		inputFirstName.defaultText = ptrStudent_Global->name.first;
		inputLastName.defaultText = ptrStudent_Global->name.last;
		inputGender.defaultText = gender_to_string(ptrStudent_Global->gender);
		inputBirth.defaultText = ptrStudent_Global->birth.get();
		inputSocialID.defaultText = ptrStudent_Global->socialID;
	}
	//-----------------------------------------------------------------------------------
	if (change.clicked(mousePoint)) {
		string ID = inputID.getContent();
		string firstName = inputFirstName.getContent();
		string lastName = inputLastName.getContent();
		string genderStr = inputGender.getContent();
		string birthStr = inputBirth.getContent();
		string socialID = inputSocialID.getContent();
		string password = inputPassword.getContent();
		string outStr = "";
		updateStudentIn4(*ptrStudent_Global, ID, firstName, lastName, genderStr, birthStr, socialID, password, outStr);
		message = outStr;
		message.centerX();
		return this;
	}
	//-----------------------------------------------------------------------------------
	if (viewScoreboard.clicked(mousePoint))
		return registry.blank;
	//-----------------------------------------------------------------------------------
	if (logout.clicked(mousePoint))
		return registry.login;
	//-----------------------------------------------------------------------------------
	return this;
}