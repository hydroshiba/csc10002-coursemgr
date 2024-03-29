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


#include "UpLoadFunction.h"
#include "DownLoadFunction.h"

/*---------- GRAPHICS INCLUDE ----------*/

#include "Application.h"

/*--------------------------------------*/

int main() {
    if (!uploadAllData()) return 0;
    
    Application app;
    while(!app.shouldClose()) {
        app.run();
    }
    
    if (downloadAllData())  
        freeMemory();
}