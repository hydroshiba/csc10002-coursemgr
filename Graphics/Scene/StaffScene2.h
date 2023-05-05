#ifndef STAFFSCENE_2_H
#define STAFFSCENE_2_H

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

class StaffScene2 : public Scene {
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
    Button viewStudentButton;
    //-----------------------------------------------------------------------------------
    TextBox textStaffID;
    InputBox inputStaffID;
    Button removeStaffButton;
    //-----------------------------------------------------------------------------------
    TextBox message;
    //-----------------------------------------------------------------------------------
    TextBox textExportLSYs;
    InputBox inputLSYsFilePath;
    Button exportLSYs;
    //-----------------------------------------------------------------------------------
    TextBox textExportLAYs;
    InputBox inputLAYsFilePath;
    Button exportLAYs;
    //-----------------------------------------------------------------------------------
    Button add;
    Button back;
    
    
public:
    StaffScene2();
    void render();
    Scene* process();
};


#endif // STAFFSCENE_2_H