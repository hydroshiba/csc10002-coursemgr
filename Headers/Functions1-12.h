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

void addNewSchoolYear(Vector<SchoolYear>& yearList, unsigned int start){
    SchoolYear newYear = {start};
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
void addStudToClass(Class &actClass, const char* inFile){
    std::string no, id, first_name, last_name, gender, sID, day, month, year;
    Student newStud;
    std::ifstream inF;
    inF.open(inFile);
    if (!inF.is_open()){
        std::cout << "Cannot open file!\n";
        return ;
    }
    std::string ignore;
    getline(inF, ignore);
    while (!inF.eof()){
        getline(inF, no, ',');
        getline(inF, id, ',');
        getline(inF, first_name, ',');
        getline(inF, last_name, ',');
        getline(inF, gender, ',');
        getline(inF, day, '/');
        getline(inF, month, '/');
        getline(inF, year, ',');
        getline(inF, sID);
        
        newStud.number = stoi(no);
        newStud.ID = id;
        newStud.setName(first_name, last_name);
        newStud.gender = (gender == "Male") ? male : female;
        newStud.birth.set(stoi(day), stoi(month), stoi(year));
        newStud.socialID = sID;
        actClass.addStudent(newStud);
        newStud.myClass = &actClass;
    }
    inF.close();
}

// Add a new academic year
void addNewAcademicYear(AcademicYear &newYear, unsigned int startYear){
    newYear = {startYear};
}

// Add a semester to an academic year
void addSemester(AcademicYear &newYear, Date startDate, Date endDate){
    Semester newSem = {startDate, endDate};
    newYear.addSemester(newSem);
}
#endif