#include "StudentScene.h"

bool isAddListSemester = false;

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
const float yPosSceneName = 10;
const float sizeTextSceneName = 50;
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
const float xPos1 = 50;
const float yPos1 = 150;
//-------------------------------------------------------------------------------------
const float yPos2 = yPos1 + textBoxHeight + yDis;
const float yPos3 = yPos2 + textBoxHeight + yDis;
const float yPos4 = yPos3 + textBoxHeight + yDis;
const float yPos5 = yPos4 + textBoxHeight + yDis;
const float yPos6 = yPos5 + textBoxHeight + yDis;
const float yPos7 = yPos6 + textBoxHeight + yDis;
//-------------------------------------------------------------------------------------
const float xPos2 = xPos1 + textBoxWidth + xDis;
//-------------------------------------------------------------------------------------
const float buttonHeigth = 50;
const float buttonWidth = 100;
const Vector2 buttonSize = { buttonWidth, buttonHeigth };
//-------------------------------------------------------------------------------------
const float xPos3 = xPos2 + inputBoxSize.x;
const float yMid = 30;
const float xPos4 = xPos3 + 100;
const float xPos5 = xPos4 + textBoxWidth + xDis;
const float xPos6 = xPos5 + inputBoxSize.x;
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
	textID = "ID";
	textID.setSize(textBoxContentSize);
	textID.setPos({ xPos1, yPos1 });
	//-----------------------------------------------------------------------------------
	textFirstName = "First name";
	textFirstName.setSize(textBoxContentSize);
	textFirstName.setPos({ xPos1, yPos2 });
	//-----------------------------------------------------------------------------------
	textLastName = "Last name";
	textLastName.setSize(textBoxContentSize);
	textLastName.setPos({ xPos1, yPos3 });
	//-----------------------------------------------------------------------------------
	textGender = "Gender";
	textGender.setSize(textBoxContentSize);
	textGender.setPos({ xPos1, yPos4 });
	//-----------------------------------------------------------------------------------
	textBirth = "Birth";
	textBirth.setSize(textBoxContentSize);
	textBirth.setPos({ xPos1, yPos5 });
	//-----------------------------------------------------------------------------------
	textSocialID = "SocialID";
	textSocialID.setSize(textBoxContentSize);
	textSocialID.setPos({ xPos1, yPos6 });
	//-----------------------------------------------------------------------------------
	textPassword = "Change password";
	textPassword.setSize(textBoxContentSize);
	textPassword.setPos({ xPos1, yPos7 });
	//-----------------------------------------------------------------------------------
	inputID.defaultText = "";
	inputID.setSize(inputBoxSize);
	inputID.setPos({ xPos2, yPos1 });
	//-----------------------------------------------------------------------------------
	inputFirstName.defaultText = "";
	inputFirstName.setSize(inputBoxSize);
	inputFirstName.setPos({ xPos2, yPos2 });
	//-----------------------------------------------------------------------------------
	inputLastName.defaultText = "";
	inputLastName.setSize(inputBoxSize);
	inputLastName.setPos({ xPos2, yPos3 });
	//-----------------------------------------------------------------------------------
	inputGender.defaultText = "";
	inputGender.setSize(inputBoxSize);
	inputGender.setPos({ xPos2, yPos4 });
	//-----------------------------------------------------------------------------------
	inputBirth.defaultText = "";
	inputBirth.setSize(inputBoxSize);
	inputBirth.setPos({ xPos2, yPos5 });
	//-----------------------------------------------------------------------------------
	inputSocialID.defaultText = "";
	inputSocialID.setSize(inputBoxSize);
	inputSocialID.setPos({ xPos2, yPos6 });
	//-----------------------------------------------------------------------------------
	inputPassword.defaultText = "Input new password";
	inputPassword.setSize(inputBoxSize);
	inputPassword.setPos({ xPos2, yPos7 });
	//----------------------------------------------------------------------------------
	change.label = "Change";
	change.setSize(buttonSize);
	change.setPos({ xPos3 , yPos7 });
	change.setViewColor();
	//-----------------------------------------------------------------------------------
	textExport = "Export scoreboards to file";
	textExport.setSize(textBoxContentSize);
	textExport.setPos({ xPos4, yPos3 });
	//-----------------------------------------------------------------------------------
	textSemester = "Choose semester";
	textSemester.setSize(textBoxContentSize);
	textSemester.setPos({ xPos4, yPos5 });
	////-----------------------------------------------------------------------------------
	textFileName = "Filename";
	textFileName.setSize(textBoxContentSize);
	textFileName.setPos({ xPos4, yPos4 });
	////-----------------------------------------------------------------------------------
	inputSemesterID.setLabel("Chooses semester:");
	inputSemesterID.setSize(inputBoxSize);
	inputSemesterID.setPos({ xPos5, yPos5 });
	////-----------------------------------------------------------------------------------
	inputFilename.defaultText = "Input filename...";
	inputFilename.setPos({ xPos5, yPos4 });
	inputFilename.setSize(inputBoxSize);
	exportButton.label = "Export";
	exportButton.setSize(buttonSize);
	exportButton.setPos({xPos6, yPos4 });
	exportButton.setViewColor();
	//-----------------------------------------------------------------------------------
	classname = "Class: None";
	classname.setSize(textBoxContentSize);
	classname.setPos({ xPos4, yPos1 });

	nCourse = "Number of course: 0";
	nCourse.setSize(textBoxContentSize);
	nCourse.setPos({ xPos4, yPos2 });

	logout.label = "Logout";
	logout.setSize(buttonSize);
	logout.setPos({ xPos6, yPos1});
	logout.setRemoveColor();
	//-----------------------------------------------------------------------------------
	back.label = "Back";
	back.setSize(buttonSize);
	back.setPos({ xPos6, yPos2 });
	back.setRemoveColor();
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
	exportButton.render(mousePoint);
	logout.render(mousePoint);
	//-----------------------------------------------------------------------------------
	message.render();
	//
	textExport.render();
	textSemester.render();
	textFileName.render();
	if (ptrStaff_Global != nullptr)	
		back.render(mousePoint);
	inputSemesterID.render(mousePoint);
	inputFilename.render(mousePoint);
	classname.render();
	nCourse.render();
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
	inputFilename.process(mousePoint);
	inputSemesterID.process(mousePoint);
	//----------------------------------------------------------------------------------
	if (ptrStudent_Global != nullptr) {
		if (!isAddListSemester) {
			inputSemesterID.add("All semester");
			Vector<string> listSemester = getListSemester(*ptrStudent_Global);
			inputSemesterID.add(listSemester);
			isAddListSemester = true;
		}
		sceneName = "Welcome student " + ptrStudent_Global->name.get();
		sceneName.centerX();
		inputID.defaultText = ptrStudent_Global->ID;
		inputFirstName.defaultText = ptrStudent_Global->name.first;
		inputLastName.defaultText = ptrStudent_Global->name.last;
		inputGender.defaultText = gender_to_string(ptrStudent_Global->gender);
		inputBirth.defaultText = ptrStudent_Global->birth.get();
		inputSocialID.defaultText = ptrStudent_Global->socialID;
		if (ptrStudent_Global->ptrClass != nullptr)
			classname = "Class: " + ptrStudent_Global->ptrClass->name;
		if (ptrStudent_Global->scoreboards.size() != 0)
			nCourse = "Number of course: " + to_string(ptrStudent_Global->scoreboards.size());
	}
	//-----------------------------------------------------------------------------------
	if (change.clicked(mousePoint) && ptrStudent_Global != nullptr) {
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
	else if (exportButton.clicked(mousePoint)) {
		string semesterID = inputSemesterID.getCurLabel();
		string filename = inputFilename.getContent();
		string outStr;
		if (semesterID == "All semester") {
			exportListScoreboardOfStudent(filename, *ptrStudent_Global, outStr);
			message = outStr;
			message.centerX();
			return this;
		}
		else
		{
			Semester* ptrSemester = getSemester(semesterID);
			if (ptrSemester == nullptr) {
				outStr = "Semester with ID " + semesterID + " is not existed!";
				message = outStr;
				message.centerX();
				inputFilename.clearContent();
				return this;
			}
			else
			{
				exportListScoreboardInSemesterOfStudent(filename, *ptrStudent_Global, *ptrSemester, outStr);
				message = outStr;
				message.centerX();
				inputFilename.clearContent();
				return this;
			}
		}
	}
	//-----------------------------------------------------------------------------------
	else if (logout.clicked(mousePoint)) {
		inputID.clearContent();
		inputFirstName.clearContent();
		inputLastName.clearContent();
		inputGender.clearContent();
		inputBirth.clearContent();
		inputSocialID.clearContent();
		inputPassword.clearContent();
		ptrStudent_Global = nullptr;
		if (ptrStaff_Global != nullptr)
			ptrStaff_Global = nullptr;
		message.clear();
		return registry.login;
	}
	//-----------------------------------------------------------------------------------
	else if (back.clicked(mousePoint)) {
		if (ptrStaff_Global == nullptr) {
			message = "You don't have permission to use this button!";
			message.centerX();
			return this;
		}
		inputID.clearContent();
		inputFirstName.clearContent();
		inputLastName.clearContent();
		inputGender.clearContent();
		inputBirth.clearContent();
		inputSocialID.clearContent();
		inputPassword.clearContent();
		inputFilename.clearContent();
		ptrStudent_Global = nullptr;
		message.clear();
		inputSemesterID.clear();
		isAddListSemester = false;
		return registry.staffScene2;
	}
	return this;
}