#include "Components.h"

#include "Date.h"
#include "Name.h"
#include "User.h"

#include "SchoolYear.h"
#include "Class.h"
#include "Student.h"

#include "AcademicYear.h"
#include "Semester.h"
#include "Course.h"
#include "Scoreboard.h"

#include "ConvertType.h"
#include "SearchFunction.h"
#include "InsertFunction.h"
#include "RemoveFunction.h"
#include "UpdateFunction.h"
#include "FileAndDirFunction.h"
#include "DisplayFunction.h"
#include "DownLoadFunction.h"
#include "UpLoadFunction.h"

 Vector<SchoolYear> schoolYears;
 Vector<AcademicYear> academicYears;
 Vector<Student> students;
 Vector<Staff> staffs;

 Staff* ptrStaff = nullptr;
 Student* ptrStudent = nullptr;

 SchoolYear* ptrSchoolYear = nullptr;
 Class* ptrClass = nullptr;

 AcademicYear* ptrAcademicYear = nullptr;
 Semester* ptrSemester = nullptr;
 Course* ptrCourse = nullptr;
 Scoreboard* ptrScoreboard = nullptr;