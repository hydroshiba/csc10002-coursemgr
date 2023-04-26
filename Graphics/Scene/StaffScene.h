#ifndef STAFFSCENE_H
#define STAFFSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"
#include "Objects/Button.h"

#include "../../Components/User.h"

class StaffScene : public Scene {
private:
	TextBox sceneName;
	//----------------------------
	Button listAYs;
	Button listSYs;
	Button logout;
	//----------------------------
	TextBox editStaff;
	TextBox textEditID;
	TextBox textEditFirstName;
	TextBox textEditLastName;
	TextBox textEditPassword;
	InputBox inputEditID;
	InputBox inputEditFirstName;
	InputBox inputEditLastName;
	InputBox inputEditPassword;
	Button change;
	//----------------------------
	TextBox addStaff;
	TextBox textAddID;
	TextBox textAddFirstName;
	TextBox textAddLastName;
	TextBox textAddPassword;
	InputBox inputAddID;
	InputBox inputAddFirstName;
	InputBox inputAddLastName;
	InputBox inputAddPassword;
	Button add;
public:
	Staff* ptrStaff;
	StaffScene();
	void render();
	Scene* process();
};


#endif // !STAFFSCENE_H
