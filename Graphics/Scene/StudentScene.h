#ifndef STUDENTSCENE_H
#define STUDENTSCENE_H

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

class StudentScene : public Scene {
private:
    TextBox sceneName;

    TextBox textID;
    InputBox inputID;

    TextBox textFirstName;
    InputBox inputFirstName;

    TextBox textLastName;
    InputBox inputLastName;

    TextBox textGender;
    InputBox inputGender;

    TextBox textBirth;
    InputBox inputBirth;

    TextBox textSocialID;
    InputBox inputSocialID;

    TextBox textPassword;
    InputBox inputPassword;

    TextBox message;

    Button change;
    Button viewScoreboard;
    Button logout;
public:
    StudentScene();
    void render();
    Scene* process();
};


#endif // STUDENT_SCENE