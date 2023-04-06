#include <iostream>

/*--------- COMPONENTS INCLUDE ---------*/

#include "Components.h"

#include "AcademicYear.h"
#include "Class.h"
#include "Course.h"
#include "Date.h"
#include "Name.h"
#include "SchoolYear.h"
#include "Scoreboard.h"
#include "Semester.h"
#include "Student.h"
#include "User.h"

/*---------- GRAPHICS INCLUDE ----------*/

#include "Application.h"

/*--------------------------------------*/

int main() {
    SetTargetFPS(app_const::fps);
    InitWindow(app_const::width, app_const::height, app_const::title.c_str());

    Application newApp;
    
    while(!newApp.appShouldClose()) {
        newApp.tick();
    }
}