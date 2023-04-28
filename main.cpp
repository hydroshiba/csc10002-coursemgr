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
    uploadListStaff(staffs);
    Student student({ "Nguyen Van", "A" }, "22120000", "123456", male, {6, 9, 2004}, "only@fans");
    students.append(student);
    Application app;
    
    while(!app.shouldClose()) {
        app.run();
    }

    downloadListStaff(staffs);
}