#include "StaffScene.h"

const float sceneNameSize = 60;
const float yPosSceneName = 20;
//-----------------------------------
const float dX = 50;
const float dY = 50;
//-----------------------------------
const float textBoxContentSize = 30;
const float textBoxWidth = 150;
const float textBoxHeight = 50;
const Vector2 textBoxSize = { textBoxWidth, textBoxHeight };
//-----------------------------------
const float inputBoxWidth = 300;
const float inputBoxHeight = 50;
const Vector2 inputBoxSize = { inputBoxWidth, inputBoxHeight };
//-----------------------------------
const float xEditStaffText = 250;
const float yEditStaffText = 100;
const float xAddStaffText = xEditStaffText + 600;
//-----------------------------------
const float xTextEdit = 50;
const float xInputEdit = xTextEdit + textBoxWidth + dX;
//-----------------------------------
const float xTextAdd = 700;
const float xInputAdd = xTextAdd + textBoxWidth + dX;
//-----------------------------------
const float yTextEdit = 200;
const float yInputEdit = yTextEdit;

const float yTextEditID = yTextEdit;
const float yTextEditFirstName = yTextEditID + textBoxHeight + dY;
const float yTextEditLastName = yTextEditFirstName + textBoxHeight + dY;
const float yTextEditPassword = yTextEditLastName + textBoxHeight + dY;
//-------------------------------------------------------------------
const float buttonHeight = 100;
const float buttonWidth = 200;
const Vector2 buttonSize = { buttonWidth, buttonHeight };

const string defaultInputBoxContent = "Error";
StaffScene::StaffScene() {
	//-------------------------------------------------------------------
	sceneName = "Welcome staff ";
	sceneName.setSize(sceneNameSize);
	sceneName.setY(yPosSceneName);
	sceneName.centerX();
	//-------------------------------------------------------------------
	editStaff = "Edit Staff";
	editStaff.setSize(textBoxContentSize + 20);
	editStaff.setPos({ xEditStaffText, yEditStaffText });
	//-------------------------------------------------------------------
	textEditID = "ID: ";
	textEditID.setSize(textBoxContentSize);
	textEditID.setPos({ xTextEdit, yTextEditID });
	//-------------------------------------------------------------------
	textEditFirstName = "First name: ";
	textEditFirstName.setSize(textBoxContentSize);
	textEditFirstName.setPos({ xTextEdit, yTextEditFirstName });
	//-------------------------------------------------------------------
	textEditLastName = "Last name: ";
	textEditLastName.setSize(textBoxContentSize);
	textEditLastName.setPos({ xTextEdit, yTextEditLastName });
	//-------------------------------------------------------------------
	textEditPassword = "Change password: ";
	textEditPassword.setSize(textBoxContentSize);
	textEditPassword.setPos({ xTextEdit, yTextEditPassword });
	//-------------------------------------------------------------------
	inputEditID.defaultText = defaultInputBoxContent;
	inputEditID.setSize(inputBoxSize);
	inputEditID.setPos({ xInputEdit, yTextEditID });
	//-------------------------------------------------------------------
	inputEditFirstName.defaultText = defaultInputBoxContent;
	inputEditFirstName.setSize(inputBoxSize);
	inputEditFirstName.setPos({ xInputEdit, yTextEditFirstName });
	//-------------------------------------------------------------------
	inputEditLastName.defaultText = defaultInputBoxContent;
	inputEditLastName.setSize(inputBoxSize);
	inputEditLastName.setPos({ xInputEdit, yTextEditLastName });
	//-------------------------------------------------------------------
	inputEditPassword.defaultText = "Input new password";
	inputEditPassword.setSize(inputBoxSize);
	inputEditPassword.setPos({ xInputEdit, yTextEditPassword });
	//-------------------------------------------------------------------
	//-------------------------------------------------------------------
	textAddStaff = "Add new staff";
	textAddStaff.setSize(textBoxContentSize + 20);
	textAddStaff.setPos({ xAddStaffText, yEditStaffText });
	//-------------------------------------------------------------------
	textAddID = "ID: ";
	textAddID.setSize(textBoxContentSize);
	textAddID.setPos({ xTextAdd, yTextEditID });
	//-------------------------------------------------------------------
	textAddFirstName = "First name: ";
	textAddFirstName.setSize(textBoxContentSize);
	textAddFirstName.setPos({ xTextAdd, yTextEditFirstName });
	//-------------------------------------------------------------------
	textAddLastName = "Last name: ";
	textAddLastName.setSize(textBoxContentSize);
	textAddLastName.setPos({ xTextAdd, yTextEditLastName });
	//-------------------------------------------------------------------
	textAddPassword = "Password: ";
	textAddPassword.setSize(textBoxContentSize);
	textAddPassword.setPos({ xTextAdd, yTextEditPassword });
	//-------------------------------------------------------------------
	inputAddID.defaultText = "Input staff ID";
	inputAddID.setSize(inputBoxSize);
	inputAddID.setPos({ xInputAdd, yTextEditID });
	//-------------------------------------------------------------------
	inputAddFirstName.defaultText = "Input firstname";
	inputAddFirstName.setSize(inputBoxSize);
	inputAddFirstName.setPos({ xInputAdd, yTextEditFirstName });
	//-------------------------------------------------------------------
	inputAddLastName.defaultText = "Input lastname";
	inputAddLastName.setSize(inputBoxSize);
	inputAddLastName.setPos({ xInputAdd, yTextEditLastName });
	//-------------------------------------------------------------------
	inputAddPassword.defaultText = "Input password";
	inputAddPassword.setSize(inputBoxSize);
	inputAddPassword.setPos({ xInputAdd, yTextEditPassword });
	//-------------------------------------------------------------------
	//-------------------------------------------------------------------
	change.label = "Change";
	change.setSize(buttonSize);
	change.setPos({ 25, 600 });
	change.hover_color = GOLD;
	change.press_color = YELLOW;
	//-------------------------------------------------------------------
	listAYs.label = "AcademicYears";
	listAYs.setSize(buttonSize);
	listAYs.setPos({ 625, 600 });
	listAYs.hover_color = GOLD;
	listAYs.press_color = YELLOW;
	//-------------------------------------------------------------------
	listSYs.label = "SchoolYears";
	listSYs.setSize(buttonSize);
	listSYs.setPos({ 825, 600 });
	listSYs.hover_color = GOLD;
	listSYs.press_color = YELLOW;
	//-------------------------------------------------------------------
	logout.label = "Logout";
	logout.setSize(buttonSize);
	logout.setPos({ 1025, 600 });
	logout.fill_color = ORANGE;
	logout.press_color = RED;
	logout.hover_color = MAROON;
	//-------------------------------------------------------------------
	add.label = "Add";
	add.setSize(buttonSize);
	add.setPos({ 225, 600 });
	add.fill_color = GREEN;
	add.hover_color = DARKGREEN;
	add.press_color = GRAY;
	//-------------------------------------------------------------------
	next.label = "Next";
	next.setSize(buttonSize);
	next.setPos({ 425, 600 });
	next.press_color = YELLOW;
	next.hover_color = GOLD;
	message = "";
	message.setColor(RED);
	message.setSize(30);
	message.setPos({ 800, 560 });
	//-------------------------------------------------------------------
}

void StaffScene::render() {
	sceneName.render();
	//----------------------------
	listAYs.render(mousePoint);
	listSYs.render(mousePoint);
	logout.render(mousePoint);
	//----------------------------
	editStaff.render();
	textEditID.render();
	textEditFirstName.render();
	textEditLastName.render();
	textEditPassword.render();
	inputEditID.render(mousePoint);
	inputEditFirstName.render(mousePoint);
	inputEditLastName.render(mousePoint);
	inputEditPassword.render(mousePoint);
	change.render(mousePoint);
	//----------------------------
	textAddStaff.render();
	textAddID.render();
	textAddFirstName.render();
	textAddLastName.render();
	textAddPassword.render();
	inputAddID.render(mousePoint);
	inputAddFirstName.render(mousePoint);
	inputAddLastName.render(mousePoint);
	inputAddPassword.render(mousePoint);
	add.render(mousePoint);
	next.render(mousePoint);
	//-------------------------------------------------------------------
	message.render();
}

Scene* StaffScene::process() {
	this->mousePoint = GetMousePosition();
	//-------------------------------------------------------------------
	inputEditID.process(mousePoint);
	inputEditFirstName.process(mousePoint);
	inputEditLastName.process(mousePoint);
	inputEditPassword.process(mousePoint);
	//-------------------------------------------------------------------
	inputAddID.process(mousePoint);
	inputAddFirstName.process(mousePoint);
	inputAddLastName.process(mousePoint);
	inputAddPassword.process(mousePoint);
	//-------------------------------------------------------------------
	if (ptrStaff_Global != nullptr) {
		sceneName = "Welcome staff " + ptrStaff_Global->name.get();
		sceneName.centerX();
		inputEditID.defaultText = ptrStaff_Global->ID;
		inputEditFirstName.defaultText = ptrStaff_Global->name.first;
		inputEditLastName.defaultText = ptrStaff_Global->name.last;
	}
	//-------------------------------------------------------------------
	if (add.clicked(mousePoint)) {
		string ID = inputAddID.getContent();
		string firstName = inputAddFirstName.getContent();
		string lastName = inputAddLastName.getContent();
		string password = inputAddPassword.getContent();
		string outStr = "";
		addStaff(ptrStaff_Global->ID, staffs, ID, password, firstName, lastName, outStr);
		message = outStr;
		message.centerX();
		inputAddID.clearContent();
		inputAddFirstName.clearContent();
		inputAddLastName.clearContent();
		inputAddPassword.clearContent();
		return this;
	}
	//-------------------------------------------------------------------
	else if (change.clicked(mousePoint) && ptrStaff_Global != nullptr) {
		string ID = inputEditID.getContent();
		string firstName = inputEditFirstName.getContent();
		string lastName = inputEditLastName.getContent();
		string password = inputEditPassword.getContent();
		string outStr = "";
		updateStaffIn4(*ptrStaff_Global, ID, firstName, lastName, password, outStr);
		message = outStr;
		message.centerX();
		inputEditID.clearContent();
		inputEditFirstName.clearContent();
		inputEditLastName.clearContent();
		inputEditPassword.clearContent();
		return this;
	}
	//-------------------------------------------------------------------
	else if (listAYs.clicked(mousePoint))
		return registry.blank;
	//-------------------------------------------------------------------
	else if (listSYs.clicked(mousePoint)) {
		return registry.editListSchoolYearScene;
	}
		
	//-------------------------------------------------------------------
	else if (logout.clicked(mousePoint)) {
		ptrStaff_Global = nullptr;
		return registry.login;
	}
	//-------------------------------------------------------------------
	else if (next.clicked(mousePoint))
		return registry.staffScene2;
	return this;
}