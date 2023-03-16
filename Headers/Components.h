#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Structures.h"

/* Enumerators */

enum Weekday { SUN, MON, TUE, WED, THU, FRI, SAT };
enum Gender { male, female };
enum Session { S1, S2, S3, S4 };

/* Forward declaration of structs */

struct Date;
struct Name;
struct Scoreboard;

struct User;
struct Staff;
struct Student;

struct AcademicYear;
struct Semester;
struct Course;

struct Year;
struct Class;

/* Actual struct implementation */

struct Date {
    unsigned short day, month;
    unsigned int year;

    Date() : day{0}, month{0}, year{0} {}
    Date(unsigned short newDay, unsigned short newMonth, unsigned int newYear) : 
        day{newDay}, month{newMonth}, year{newYear} {}

    void set(unsigned short newDay, unsigned short newMonth, unsigned int newYear) {
        day = newDay;
        month = newMonth;
        year = newYear;
    }

    std::string get() {
        std::string strDay = std::to_string(day);
        if(day < 10) strDay = '0' + strDay;

        std::string strMonth = std::to_string(month);
        if(month < 10) strMonth = '0' + strMonth;

        std::string strYear = std::to_string(year);
        return strDay + '/' + strMonth + '/' + strYear;
    }
};

struct Name {
    std::string first, last;

    Name() {}
    Name(const std::string &nameLast, const std::string &nameFirst) : 
        last{nameLast}, first{nameFirst} {}

    void set(const std::string &nameLast, const std::string &nameFirst) {
        last = nameLast;
        first = nameFirst;
    }

    std::string get() {
        return last + " " + first;
    }
};

struct Scoreboard {
    float midterm, final, other, total;
    Course* const ptrCourse = nullptr;
    Student* const ptrStudent = nullptr;

    Scoreboard() {}
    Scoreboard(Course* ptrC, Student* ptrS) : ptrCourse{ptrC}, ptrStudent{ptrS} {}
};

struct User {
private:
    uint64_t password;

    uint64_t hash(uint64_t left, uint64_t right) {
        left ^= right + 0x6969696969696969 + (left << 6) + (right << 9);
        return left;
    }

    uint64_t hash(std::string str) {
        uint64_t left = 0, right = 0;

        for(size_t i = 0; i < str.size(); ++i) {
            if(i & 1) left = hash(left, (uint64_t)str[i]);
            else right = hash(right, (uint64_t)str[i]);
        }

        return hash(left, right);
    }
    
public:
    Name name;
    std::string ID;

    std::string fullname() {
        return name.last + name.first;
    }

    void setName(const std::string &first, const std::string &last) {
        name.first = first;
        name.last = last;
    }

    void setPassword(const std::string &str) {
        password = hash(str);
    }

    bool isPassword(const std::string &str) {
        return (hash(str) == password);
    }

    uint64_t getHashedPass() {
        return password;
    }
};

struct Staff : User {
    
};

struct Student : User {
    int number;
    Gender gender;
    Date birth;
    std::string socialID;

    Class* myClass = nullptr;
    Vector<Scoreboard*> scoreboards;

    Scoreboard* getScoreboard(Course &course) {
        Scoreboard* cur = nullptr;

        for(int i = 0; i < scoreboards.size(); ++i) 
            if(scoreboards[i]->ptrCourse == &course) {
                cur = scoreboards[i];
                break;
            }

        return cur;
    }
};

struct AcademicYear {
    unsigned int start;
    Vector<Semester> semesters;

    void addSemester(const Semester &newSemester) {
        semesters.append(newSemester);
    }

    void removeSemester(const Semester &newSemester) {
        semesters.remove(newSemester);
    }

    std::string getPeriod() {
        return std::to_string(start) + " - " + std::to_string(start + 1);
    }
};

struct Semester {
    Date startDate, endDate;
    Vector<Course> courses;
    AcademicYear* year = nullptr;

    void addCourse(const Course &newCourse) {
        courses.append(newCourse);
    }

    void removeCourse(const Course &newCourse) {
        courses.remove(newCourse);
    }
};

struct Course {
    std::string ID, classID;
    std::string name, teacher;

    int credits, maxEnroll = 50;
    Weekday weekday;
    Session session;

    Vector<Scoreboard*> scoreboards;

    void addStudent(Student &student) {
        Scoreboard* newBoard = new Scoreboard(this, &student);
        student.scoreboards.append(newBoard);
        scoreboards.append(newBoard);
    }

    void removeStudent(Student &student) {
        Scoreboard* cur = nullptr;

        for(int i = 0; i < scoreboards.size(); ++i) 
            if(scoreboards[i]->ptrStudent == &student) {
                cur = scoreboards[i];
                break;
            }

        if(cur) {
            student.scoreboards.remove(cur);
            scoreboards.remove(cur);
            delete cur;
        }
    }

    Scoreboard* getScoreboard(Student &student) {
        Scoreboard* cur = nullptr;

        for(int i = 0; i < scoreboards.size(); ++i) 
            if(scoreboards[i]->ptrStudent == &student) {
                cur = scoreboards[i];
                break;
            }

        return cur;
    }
};

struct Year {
    unsigned int start;
    Vector<Class> classes;

    unsigned int get() {
        return start;
    }

    void addClass(const Class &newClass) {
        classes.append(newClass);
    }

    void removeClass(const Class &newClass) {
        classes.remove(newClass);
    }

    std::string getPeriod() {
        return std::to_string(start) + " - " + std::to_string(start + 4);
    }
};

struct Class {
    std::string name;
    Vector<Student> students;

    void addStudent(const Student &student) {
        students.append(student);
        (students.end() - 1)->myClass = this;
    }

    void removeStudent(const Student &student) {
        Student* pos = students.find(student);
        pos->myClass = nullptr;
        students.remove(pos);
    }
};

/* Struct compare functors */
// Leave this section alone if you don't know what you're doing

struct Compare {
    
};

/* Forward declaration of struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB);
bool operator==(const Scoreboard &boardA, const Scoreboard &boardB);

bool operator==(const Date &dateA, const Date &dateB);
bool operator==(const Name &nameA, const Name &nameB);

bool operator==(const User &userA, const User &userB);
bool operator==(const Staff &staffA, const Staff &staffB);
bool operator==(const Student &studentA, const Student &studentB);

bool operator==(const AcademicYear &yearA, const AcademicYear &yearB);
bool operator==(const Semester &semA, const Semester &semB);
bool operator==(const Course &courseA, const Course &courseB);

bool operator==(const Year &yearA, const Year &yearB);
bool operator==(const Class &classA, const Class &classB);

/* Forward declaration of task functions */

// -> Start declaring functions from here <-

#endif