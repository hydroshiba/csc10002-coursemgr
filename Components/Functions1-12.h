#ifndef FUNCTION_PART1_H
#define FUNCTION_PART1_H

#include "AcademicYear.h"
#include "Components.h"
#include "Course.h"
#include "SchoolYear.h"
#include "Class.h"
#include "Name.h"
#include "Semester.h"

// Add a new 1st-year & delete old 4th-year

void addNewSchoolYear(Vector<SchoolYear>& yearList){
    unsigned int startYear;
    std::cout << "Enter the school year: "; std::cin >> startYear;
    SchoolYear newYear = {startYear};
    yearList.append(newYear);
    if (yearList.size() > 4)
        yearList.remove(yearList.begin());
}

// Add several classes for 1st year
void addClasses (Vector<SchoolYear>& yearList){
    Class newClass;
    do {
        std::cout << "Enter class name (enter 0 when done): ";
        std::cin >> newClass.name;
        if (newClass.name == "0") break;
        yearList[yearList.size()-1].addClass(newClass);
    } while (newClass.name != "0");
}

// Add students into a specific class
void addStudToClass(Class &actClass,const std::string inFile){
    Student newStud;
    std::ifstream inF;
    inF.open("Data/"+inFile);
    if (!inF.is_open()){
        std::cout << "Cannot open file!\n";
        return ;
    }
    std::string ignore;
    getline(inF, ignore);
    while (!inF.eof()){
        newStud.setInfoToClass(inF);
        actClass.addStudent(newStud);
        newStud.myClass = &actClass;
    }
    inF.close();
}

// Add a new academic year
void addNewAcademicYear(AcademicYear &newYear){
    unsigned int startyear;
    std::cout << "Enter a new year: ";
    std::cin >> startyear;
    newYear = {startyear};
}

// Add a semester to an academic year

void addSemester(AcademicYear &newYear, Date startDate, Date endDate){
    Semester newSem;
    newSem.startDate = startDate;
    newSem.endDate = endDate;
    newYear.addSemester(newSem);
}

void addSemester(AcademicYear &newYear){
    unsigned short day, month;
    unsigned int year;
    std::string id;
    std::cout << "Enter semester id: "; std::cin >> id;
    Date startDate;
    std::cout << "Enter start date for the semester:\n";
    std::cin >> day >> month >> year;
    startDate.set(day, month, year);

    Date endDate;
    std::cout << "Enter end date for the semester:\n";
    std::cin >> day >> month >> year;
    endDate.set(day, month, year);

    Semester newSem = {id, startDate, endDate, 0, &newYear};
    newYear.addSemester(newSem);
}

// Add a new course
void addNewCourse(Semester &semester){
    Course newCourse;
    std::string ID, classID, name, teacher;
    int cre, maxEn;
    int day, ss;

    std::cout << "Enter Course ID: "; std::cin >> ID;
    std::cout << "Enter Course Name: "; std::cin >>name;
    std::cout << "Enter Teacher's Name: "; std::cin >>teacher;
    std::cout << "Enter Class ID: "; std::cin >> classID;
    std::cout << "Enter Number of Credits: "; std::cin >> cre;
    std::cout << "Enter Maximun students enrolled: "; std::cin >> maxEn;
    std::cout << "Day of week: "; std::cin >> day;
    std::cout << "Session performed: "; std::cin >> ss;

    newCourse = {ID, classID, name, teacher, cre, maxEn, static_cast<Weekday>(day), static_cast<Session>(ss), &semester};
    semester.addCourse(newCourse);
}

// Get students' info to course
void getStudentToCourse(Vector<SchoolYear> years, Course &course, const std::string stud_input_file){
    std::ifstream inF;
    inF.open("Data/"+stud_input_file);
    if (!inF.is_open()){
        std::cout << "Cannot open file!\n";
        return;
    }
    std::string ignore;
    getline(inF, ignore);
    std::string className;
    Class actClass;
    Class *ptrClass;
    Student student;
    Student *ptrStudent;
    while (!inF.eof()){
        student.setInfoToCourseCSV(inF, className);
        actClass = {className};
        for (int i = 0; i<4; ++i)
            if (ptrClass = years[i].classes.find(actClass))
                break;
        ptrStudent = ptrClass->students.find(student);
        course.addStudent(*ptrStudent);
    }
    inF.close();
}

// View list of courses
void viewCourses(Semester sem, std::ostream& outDev = std::cout){
    std::cout << "List of courses: ";
    for (size_t i = 0; i<sem.courses.size(); ++i)
        sem.courses[i].displayInfo(outDev);
}

// Update course informations
void updateCourse(Course &course){
    int input;
    do {
        std::cout << "Update course informations:\n";
        std::cout << "0. Back\n";
        std::cout << "1. Change course id\n";
        std::cout << "2. Change teacher's name\n";
        std::cout << "3. Change course name\n";
        std::cout << "4. Change class id\n";
        std::cout << "5. Change number of credits\n";
        std::cout << "6. Change max students enrolled\n";
        std::cout << "7. Change session\n";
        switch (input){
            case 1: 
                std::cout << "Enter Course ID: "; std::cin >> course.ID;
                break;
            case 2: 
                std::cout << "Enter Teacher's Name: "; std::cin >> course.teacher;
                break;
            case 3: 
                std::cout << "Enter Course Name: "; std::cin >> course.name; 
                break;
            case 4: 
                std::cout << "Enter Class ID: "; std::cin >> course.classID;
                break;
            case 5:
                std::cout << "Enter Number of Credits: "; std::cin >> course.credits;
                break;
            case 6:
                std::cout << "Enter Maximun students enrolled: "; std::cin >> course.maxEnroll;
                break;
            case 7: 
                int in, day, ss;
                std::cout << "0. Change weekday\n";
                std::cout << "1. Change session\n";
                std::cin >> in;
                if (!in){
                    std::cout << "Enter weekday: "; std::cin >> day;
                    course.weekday = static_cast<Weekday>(day); 
                }
                else{
                    std::cout << "Enter Session performed: "; std::cin >> ss;
                    course.session = static_cast<Session>(ss);
                }
                break;
            default: break;
        }
    }while (input);
}

// Add student to course
void addNewStudToCourse(Vector <SchoolYear>& yearlist, Course &course, std::ostream& outDev){

}
#endif