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
    Student student({ "Nguyen Van", "A" }, "22120000", "123456", male, {6, 9, 2004}, "only@fans");
    Staff staff({ "Ho", "Tuan Thanh" }, "ADMIN", "123456");
    staffs.append(staff);
    students.append(student);
    Application app;
    
    while(!app.shouldClose()) {
        app.run();
    }
    //Vector<SchoolYear> schoolYears;
    //Vector<AcademicYear> academicYears;
    //uploadAllData(schoolYears, academicYears);
    //// Do all thing
    //downloadAllData(schoolYears, academicYears);
    //freeMemory(academicYears);
}