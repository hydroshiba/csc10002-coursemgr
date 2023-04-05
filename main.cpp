#include <iostream>

/*--------- COMPONENTS INCLUDE ---------*/

#include "Components/Components.h"

#include "Components/AcademicYear.h"
#include "Components/Class.h"
#include "Components/Course.h"
#include "Components/Date.h"
#include "Components/Name.h"
#include "Components/SchoolYear.h"
#include "Components/Scoreboard.h"
#include "Components/Semester.h"
#include "Components/Student.h"
#include "Components/User.h"

/*---------- GRAPHICS INCLUDE ----------*/

#include "Graphics/Graphics.h"

/*--------------------------------------*/

int main() {
    SetTargetFPS(app_const::fps);
    InitWindow(app_const::width, app_const::height, app_const::title.c_str());

    Application newApp;
    
    while(!newApp.appShouldClose()) {
        newApp.tick();
    }
}