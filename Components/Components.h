#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Structures.h"
#include <iomanip>

//#include "AcademicYear.h"
//#include "Class.h"
//#include "Course.h"
//#include "Name.h"
//#include "Student.h"
//#include "Scoreboard.h"
//#include "Date.h"
//#include "Semester.h"
//#include "User.h"
//#include "SchoolYear.h"

/* Enumerators */

enum Weekday { SUN, MON, TUE, WED, THU, FRI, SAT };
enum Gender { male, female };
enum Session { S1, S2, S3, S4 };

/* Structures forward declaration */

struct Date;
struct Name;
struct Scoreboard;

struct User;
struct Staff;
struct Student;

struct AcademicYear;
struct Semester;
struct Course;

struct SchoolYear;
struct Class;

struct Compare {

};

/* Forward declaration of struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB) {
    return !(typeA == typeB);
}



#endif
