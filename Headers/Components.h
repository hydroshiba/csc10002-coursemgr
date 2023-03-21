#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Structures.h"

/* Enumerators */

enum Weekday { SUN, MON, TUE, WED, THU, FRI, SAT };
enum Gender { male, female };
enum Session { S1, S2, S3, S4 };

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
bool operator!=(const Type& typeA, const Type& typeB);
bool operator==(const Scoreboard& boardA, const Scoreboard& boardB);

bool operator==(const Date& dateA, const Date& dateB);
bool operator==(const Name& nameA, const Name& nameB);

bool operator==(const User& userA, const User& userB);
bool operator==(const Staff& staffA, const Staff& staffB);
bool operator==(const Student& studentA, const Student& studentB);

bool operator==(const AcademicYear& yearA, const AcademicYear& yearB);
bool operator==(const Semester& semA, const Semester& semB);
bool operator==(const Course& courseA, const Course& courseB);

bool operator==(const SchoolYear& yearA, const SchoolYear& yearB);
bool operator==(const Class& classA, const Class& classB);

#endif
