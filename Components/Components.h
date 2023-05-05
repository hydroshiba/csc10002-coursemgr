#ifndef COMPONENT_H
#define COMPONENT_H

#include <iomanip>
#include <string>
#include "Vector.h"
#include <filesystem>
#include <sstream>

using std::string;
using std::to_string;

const std::string defaultStr = "Error";
/* Enumerators */

enum Weekday { SUN, MON, TUE, WED, THU, FRI, SAT };
enum Gender { male, female };
enum Session { S1, S2, S3, S4 };

/* Structures forward declaration */

struct Date;
struct Name;

struct User;
struct Staff;

struct SchoolYear;
struct Class;
struct Student;

struct AcademicYear;
struct Semester;
struct Course;
struct Scoreboard;

/* Forward declaration of struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB) {
    return !(typeA == typeB);
}

extern Vector<SchoolYear> schoolYears;
extern Vector<AcademicYear> academicYears;
extern Vector<Student> students;
extern Vector<Staff> staffs;

extern Staff* ptrStaff_Global;
extern Student* ptrStudent_Global;

extern SchoolYear* ptrSchoolYear_Global;
extern Class* ptrClass_Global;

extern AcademicYear* ptrAcademicYear_Global;
extern Semester* ptrSemester_Global;
extern Course* ptrCourse_Global;
extern Scoreboard* ptrScoreboard_Global;


#endif