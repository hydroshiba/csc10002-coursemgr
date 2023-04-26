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

 Staff* ptrStaff_Global = nullptr;
 Student* ptrStudent_Global = nullptr;

 SchoolYear* ptrSchoolYear_Global = nullptr;
 Class* ptrClass_Global = nullptr;

 AcademicYear* ptrAcademicYear_Global = nullptr;
 Semester* ptrSemester_Global = nullptr;
 Course* ptrCourse_Global = nullptr;
 Scoreboard* ptrScoreboard_Global = nullptr;