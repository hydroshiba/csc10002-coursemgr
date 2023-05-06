#ifndef EDIT_SCOREBOARD_H
#define EDIT_SCOREBOARD_H

#include "raylib.h"
#include "Scene.h"
#include "Registry.h"

#include "Objects/Button.h"
#include "Objects/TextBox.h"
#include "Objects/InputBox.h"

#include "Components.h"
#include "Course.h"
#include "Scoreboard.h"
#include "UpdateFunction.h"
#include "InsertFunction.h"
#include "RemoveFunction.h"
#include "ImportAndExportFunction.h"
#include "SearchFunction.h"

class EditScoreboardScene : public Scene{
private:
    TextBox title, studentID, midTerm, final, other, total, result;
    InputBox IDBox, midTermBox, finalBox, otherBox, totalBox;
    Button change, view, back;

public:
    EditScoreboardScene();
    void render();
    Scene* process();
};

#endif