#ifndef COMPONENT_H
#define COMPONENT_H

#include <iomanip>
#include <string>
#include "Vector.h"
#include <filesystem>

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

//#include "Date.h"
//#include "Name.h"
//#include "User.h"
//
//#include "SchoolYear.h"
//#include "Class.h"
//#include "Student.h"
//
//#include "AcademicYear.h"
//#include "Semester.h"
//#include "Course.h"
//#include "Scoreboard.h"

//#include "InsertFunction.h"
//#include "SearchFunction.h"

/* Forward declaration of struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB) {
    return !(typeA == typeB);
}



#endif