#include "StaffScene2.h"
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
const float yPosSceneName = 10;
const float sizeTextSceneName = 100;
//-------------------------------------------------------------------------------------
const float xDis = 70;
const float yDis = 30;
//-------------------------------------------------------------------------------------
const float textBoxContentSize = 30;
const float inputBoxContentSize = textBoxContentSize;
//-------------------------------------------------------------------------------------
const float textBoxHeight = 50;
const float textBoxWidth = 100;
const Vector2 textBoxSize = { textBoxHeight, textBoxWidth };
//-------------------------------------------------------------------------------------
const float inputBoxHeight = 50;
const float inputBoxWidth = 350;
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
const float xDisButton = 50;
const float xPosButton = 700;
const float xPosAdd = xPosButton;
const float yPosAdd = 580;
const float xPosBack = xPosAdd + buttonWidth + xDisButton + 50;
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
const std::string defaultInputBoxContent = "Error InputBoxContent";
const std::string defaultTextBoxContent = "Error TextBoxContent";
//-----------------------------------------------------------------------------------
const float removeTextBoxWidth = 100;
const float xPosTextRemoveStudentID = 600;
const float yPosTextRemoveStudentID = 150;
const float yPosTextRemoveStaffID = yPosTextRemoveStudentID + textBoxHeight + yDis;
const float xPosInputRemoveStudentID = xPosTextRemoveStudentID + removeTextBoxWidth + xDis;
const float yPosTextExportLSYs = yPosTextRemoveStaffID + textBoxHeight + yDis;
const float yPosTextExportLAYs = yPosTextExportLSYs + textBoxHeight + yDis;
const Vector2 removeStudentTextBoxPos = { xPosTextRemoveStudentID, yPosTextRemoveStudentID };
const Vector2 removeStaffTextBoxPos = { xPosTextRemoveStudentID, yPosTextRemoveStaffID };
const Vector2 removeInputBoxSize = { 250, 50 };
const Vector2 removeButtonSize = { 100, 50 };
const Vector2 removeStudentButtonPos = { xPosInputRemoveStudentID + removeInputBoxSize.x, yPosTextRemoveStudentID };
const Vector2 viewStudentButtonPos = { removeStudentButtonPos.x + removeButtonSize.x , yPosTextRemoveStudentID };
const Vector2 removeStaffButtonPos = { xPosInputRemoveStudentID + removeInputBoxSize.x, yPosTextRemoveStaffID };
const Vector2 exportLSYsButtonPos = { xPosInputRemoveStudentID + removeInputBoxSize.x, yPosTextExportLSYs };
const Vector2 exportLAYsButtonPos = { xPosInputRemoveStudentID + removeInputBoxSize.x, yPosTextExportLAYs };
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
StaffScene2::StaffScene2() {
	sceneName = "Wellcome staff";
	sceneName.setSize(sizeTextSceneName);
	sceneName.setY(yPosSceneName);
	sceneName.centerX();
	//-----------------------------------------------------------------------------------
	textID = "StudentID: ";
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
	textPassword = "Password: ";
	textPassword.setSize(textBoxContentSize);
	textPassword.setPos({ xPosTextBox, yPosTextBoxPassword });
	//-----------------------------------------------------------------------------------
	inputID.defaultText = "Input StudentID";
	inputID.setSize(inputBoxSize);
	inputID.setPos({ xPosInputBox, yPosTextBoxID });
	//-----------------------------------------------------------------------------------
	inputFirstName.defaultText = "Input first name";
	inputFirstName.setSize(inputBoxSize);
	inputFirstName.setPos({ xPosInputBox, yPosTextBoxFirstName });
	//-----------------------------------------------------------------------------------
	inputLastName.defaultText = "Input last name";
	inputLastName.setSize(inputBoxSize);
	inputLastName.setPos({ xPosInputBox, yPosTextBoxLastName });
	//-----------------------------------------------------------------------------------
	inputGender.defaultText = "Input gender (male/female)";
	inputGender.setSize(inputBoxSize);
	inputGender.setPos({ xPosInputBox, yPosTextBoxGender });
	//-----------------------------------------------------------------------------------
	inputBirth.defaultText = "Input birth (dd/mm/yyyy)";
	inputBirth.setSize(inputBoxSize);
	inputBirth.setPos({ xPosInputBox, yPosTextBoxBirth });
	//-----------------------------------------------------------------------------------
	inputSocialID.defaultText = "Input socialID";
	inputSocialID.setSize(inputBoxSize);
	inputSocialID.setPos({ xPosInputBox, yPosTextBoxSocialID });
	//-----------------------------------------------------------------------------------
	inputPassword.defaultText = "Input password";
	inputPassword.setSize(inputBoxSize);
	inputPassword.setPos({ xPosInputBox, yPosTextBoxPassword });
	//-----------------------------------------------------------------------------------
	add.label = "Add";
	add.setSize(buttonSize);
	add.setPos({ xPosAdd, yPosAdd});
	add.press_color = GRAY;
	add.hover_color = DARKGREEN;
	add.fill_color = GREEN;
	add.setInsertColor();
	//-----------------------------------------------------------------------------------
	back.label = "Back";
	back.setSize(buttonSize);
	back.setPos({ xPosBack, yPosAdd});
	back.fill_color = ORANGE;
	back.hover_color = MAROON;
	back.press_color = RED;
	back.setRemoveColor();
	//-----------------------------------------------------------------------------------
	message = "";
	message.setColor(RED);
	message.setSize(30);
	message.setPos({ 800, 690 });
	//-----------------------------------------------------------------------------------
	textStudentID = "StudentID: ";
	textStudentID.setSize(textBoxContentSize);
	textStudentID.setPos(removeStudentTextBoxPos);
	//-----------------------------------------------------------------------------------
	textStaffID = "StaffID: ";
	textStaffID.setSize(textBoxContentSize);
	textStaffID.setPos(removeStaffTextBoxPos);
	//-----------------------------------------------------------------------------------
	inputStudentID.defaultText = "Input StudentID";
	inputStudentID.setSize(removeInputBoxSize);
	inputStudentID.setPos({ xPosInputRemoveStudentID, yPosTextRemoveStudentID });
	//-----------------------------------------------------------------------------------
	inputStaffID.defaultText = "Input StaffID";
	inputStaffID.setSize(removeInputBoxSize);
	inputStaffID.setPos({ xPosInputRemoveStudentID, yPosTextRemoveStaffID });
	//-----------------------------------------------------------------------------------
	textExportLSYs = "LSYs filename: ";
	textExportLSYs.setSize(textBoxContentSize);
	textExportLSYs.setPos({ removeStudentTextBoxPos.x, yPosTextExportLSYs });
	//-----------------------------------------------------------------------------------
	textExportLAYs = "LAYs filename: ";
	textExportLAYs.setSize(textBoxContentSize);
	textExportLAYs.setPos({ removeStudentTextBoxPos.x, yPosTextExportLAYs });
	//-----------------------------------------------------------------------------------
	inputLSYsFilePath.defaultText = "Input filepath...";
	inputLSYsFilePath.setSize(removeInputBoxSize);
	inputLSYsFilePath.setPos({ inputStaffID.getPos().x, yPosTextExportLSYs });
	//-----------------------------------------------------------------------------------
	inputLAYsFilePath.defaultText = "Input filepath...";
	inputLAYsFilePath.setSize(removeInputBoxSize);
	inputLAYsFilePath.setPos({ inputStaffID.getPos().x, yPosTextExportLAYs });
	//-----------------------------------------------------------------------------------
	exportLSYs.label = "Export";
	exportLSYs.setSize(removeButtonSize);
	exportLSYs.setPos(exportLSYsButtonPos);
	exportLSYs.fill_color = YELLOW;
	exportLSYs.hover_color = GOLD;
	exportLSYs.press_color = ORANGE;
	exportLSYs.setViewColor();
	//-----------------------------------------------------------------------------------
	exportLAYs.label = "Export";
	exportLAYs.setSize(removeButtonSize);
	exportLAYs.setPos(exportLAYsButtonPos);
	exportLAYs.fill_color = YELLOW;
	exportLAYs.hover_color = GOLD;
	exportLAYs.press_color = ORANGE;
	exportLAYs.setViewColor();
	//-----------------------------------------------------------------------------------
	removeStudentButton.label = "Remove";
	removeStudentButton.fill_color = RED;
	removeStudentButton.press_color = MAROON;
	removeStudentButton.hover_color = ORANGE;
	removeStudentButton.setSize(removeButtonSize);
	removeStudentButton.setPos(removeStudentButtonPos);
	removeStudentButton.setRemoveColor();
	//-----------------------------------------------------------------------------------
	viewStudentButton.label = "View";
	viewStudentButton.fill_color = YELLOW;
	viewStudentButton.press_color = GOLD;
	viewStudentButton.hover_color = ORANGE;
	viewStudentButton.setSize(removeButtonSize);
	viewStudentButton.setPos(viewStudentButtonPos);
	viewStudentButton.setViewColor();
	//-----------------------------------------------------------------------------------
	removeStaffButton.label = "Remove";
	removeStaffButton.fill_color = RED;
	removeStaffButton.press_color = MAROON;
	removeStaffButton.hover_color = ORANGE;
	removeStaffButton.setSize(removeButtonSize);
	removeStaffButton.setPos(removeStaffButtonPos);
	removeStaffButton.setRemoveColor();
	//-----------------------------------------------------------------------------------
}

void StaffScene2::render() {
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
	add.render(mousePoint);
	back.render(mousePoint);
	//-----------------------------------------------------------------------------------
	message.render();
	//-----------------------------------------------------------------------------------
	textStaffID.render();
	inputStaffID.render(mousePoint);
	removeStaffButton.render(mousePoint);
	//-----------------------------------------------------------------------------------
	textStudentID.render();
	inputStudentID.render(mousePoint);
	removeStudentButton.render(mousePoint);
	viewStudentButton.render(mousePoint);
	//-----------------------------------------------------------------------------------
	textExportLSYs.render();
	textExportLAYs.render();
	inputLSYsFilePath.render(mousePoint);
	exportLSYs.render(mousePoint);
	inputLAYsFilePath.render(mousePoint);
	exportLAYs.render(mousePoint);
}

Scene* StaffScene2::process() {
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
	inputStudentID.process(mousePoint);
	inputStaffID.process(mousePoint);
	inputLSYsFilePath.process(mousePoint);
	inputLAYsFilePath.process(mousePoint);
	if (ptrStaff_Global != nullptr) {
		sceneName = "Welcome staff " + ptrStaff_Global->name.get();
		sceneName.centerX();
	}
	//-----------------------------------------------------------------------------------
	if (add.clicked(mousePoint)) {
		string ID = inputID.getContent();
		string firstName = inputFirstName.getContent();
		string lastName = inputLastName.getContent();
		string genderStr = inputGender.getContent();
		string birthStr = inputBirth.getContent();
		string socialID = inputSocialID.getContent();
		string password = inputPassword.getContent();
		string outStr = "";
		addStudent(students, ID, firstName, lastName, genderStr, birthStr, socialID, password, outStr);
		message = outStr;
		message.centerX();
		inputID.clearContent();
		inputFirstName.clearContent();
		inputLastName.clearContent();
		inputGender.clearContent();
		inputBirth.clearContent();
		inputSocialID.clearContent();
		inputPassword.clearContent();
		return this;
	}
	//-----------------------------------------------------------------------------------
	else if (removeStudentButton.clicked(mousePoint)) {
		string studentID = inputStudentID.getContent();
		string outStr = "";
		removeStudent(students, studentID, outStr);
		message = outStr;
		message.centerX();
		inputID.clearContent();
		inputFirstName.clearContent();
		inputLastName.clearContent();
		inputGender.clearContent();
		inputBirth.clearContent();
		inputSocialID.clearContent();
		inputPassword.clearContent();
		inputStudentID.clearContent();
		return this;
	}
		
	//-----------------------------------------------------------------------------------
	else if (removeStaffButton.clicked(mousePoint)) {
		string staffID = inputStaffID.getContent();
		string outStr = "";
		removeStaff(ptrStaff_Global->ID, staffs, staffID, outStr);
		message = outStr;
		message.centerX();
		inputID.clearContent();
		inputFirstName.clearContent();
		inputLastName.clearContent();
		inputGender.clearContent();
		inputBirth.clearContent();
		inputSocialID.clearContent();
		inputPassword.clearContent();
		inputStaffID.clearContent();
		return this;
	}
		
	//-----------------------------------------------------------------------------------
	else if (back.clicked(mousePoint)) {
		inputID.clearContent();
		inputFirstName.clearContent();
		inputLastName.clearContent();
		inputGender.clearContent();
		inputBirth.clearContent();
		inputSocialID.clearContent();
		inputPassword.clearContent();
		inputStudentID.clearContent();
		inputStaffID.clearContent();
		return registry.staffScene;
	}
		
	//-----------------------------------------------------------------------------------
	else if (viewStudentButton.clicked(mousePoint)) {
		string studentID = inputStudentID.getContent();
		string outStr = "";
		ptrStudent_Global = getStudent(students, studentID);
		if (ptrStudent_Global == nullptr) {
			outStr = "Student with ID " + studentID + " can't be found in school! Pls try another";
			message = outStr;
			message.centerX();
			inputStudentID.clearContent();
		}
		else {
			inputLAYsFilePath.clearContent();
			inputLSYsFilePath.clearContent();
			inputID.clearContent();
			inputFirstName.clearContent();
			inputLastName.clearContent();
			inputGender.clearContent();
			inputBirth.clearContent();
			inputSocialID.clearContent();
			inputPassword.clearContent();
			inputStudentID.clearContent();
			return registry.studentScene;
		}
		return this;
	}
	else if (exportLSYs.clicked(mousePoint)) {
		string filename = inputLSYsFilePath.getContent();
		string outStr;
		exportListSchoolYear(filename, outStr);
		message = outStr;
		message.centerX();
		inputLSYsFilePath.clearContent();
		return this;
	}
	else if (exportLAYs.clicked(mousePoint)) {
		string filename = inputLAYsFilePath.getContent();
		string outStr;
		exportListAcademicYear(filename, outStr);
		message = outStr;
		message.centerX();
		inputLAYsFilePath.clearContent();
		return this;
	}
	return this;
}