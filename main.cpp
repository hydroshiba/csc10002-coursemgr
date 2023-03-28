#include <iostream>

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

#include "Graphics/Graphics.h"

int main() {
    Application newApp;
    
    while(!newApp.appShouldClose()) {
        newApp.tick();
    }
}