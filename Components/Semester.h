#ifndef SEMESTER_H
#define SEMESTER_H

#include "Components.h"

#include "Course.h"
#include "Date.h"

struct Semester {
    std::string semesterID;
    Date startDate, endDate;
    Vector<Course> courses;
    AcademicYear* ptrAcademicYear;

    Semester(const std::string& semesterID = defaultStr, const Date& startDate = { 0, 0, 0 }, const Date& endDate = { 0, 0, 0 }, const Vector<Course>& course = Vector<Course>(), AcademicYear* ptrAcademicYear = nullptr);

    Course* getCourse(const std::string& courseID);

    void set(const std::string& semesterID, const Date& startDate, const Date& endDate, const Vector<Course>& course, AcademicYear* ptrAcademicYear);
    
    void updateSemesterID(const std::string& semesterID);
    void updateStartDate(const Date& startDate);
    void updateEndDate(const Date& endDate);
    void updateCourses(Vector<Course>& course);
    void updateAcademicYear(AcademicYear* ptrAcademicYear);

    void addCourse(Course& course);

    void removeCourse(Course& course);

    void removeAllCourse();
};

bool operator==(const Semester& semA, const Semester& semB);
#endif