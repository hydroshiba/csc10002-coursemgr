#ifndef ADDSTUDENTSCENE_H
#define ADDSTUDENTSCENE_H

#include "raylib.h"

#include "Scene.h"
#include "Registry.h"

#include "Objects/TextBox.h"
#include "Objects/Dropbox.h"
#include "Objects/InputBox.h"
#include "Objects/Button.h"

#include "Components.h"
#include "Student.h"
#include "User.h"
#include "ConvertType.h"
#include "UpdateFunction.h"
#include <string>
#include "InsertFunction.h"
#include "RemoveFunction.h"

class AddStudentScene : public Scene {
private:
    TextBox sceneName;
    //-----------------------------------------------------------------------------------
    TextBox textID;
    InputBox inputID;
    //-----------------------------------------------------------------------------------
    TextBox textFirstName;
    InputBox inputFirstName;
    //-----------------------------------------------------------------------------------
    TextBox textLastName;
    InputBox inputLastName;
    //-----------------------------------------------------------------------------------
    TextBox textGender;
    InputBox inputGender;
    //-----------------------------------------------------------------------------------
    TextBox textBirth;
    InputBox inputBirth;
    //-----------------------------------------------------------------------------------
    TextBox textSocialID;
    InputBox inputSocialID;
    //-----------------------------------------------------------------------------------
    TextBox textPassword;
    InputBox inputPassword;
    //-----------------------------------------------------------------------------------
    TextBox textStudentID;
    InputBox inputStudentID;
    Button removeStudentButton;
    //-----------------------------------------------------------------------------------
    TextBox textStaffID;
    InputBox inputStaffID;
    Button removeStaffButton;
    //-----------------------------------------------------------------------------------
    TextBox message;
    //-----------------------------------------------------------------------------------
    Button add;
    Button back;
    
public:
    AddStudentScene();
    void render();
    Scene* process();
};


#endif // ADDSTUDENT_SCENE