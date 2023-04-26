#include "SearchFunction.h"

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

/*		Search function		*/

// Find student
Student* getStudent(Vector<Student>& students, const std::string& studentID) {
	for (int i = 0; i < students.size(); i++)
		if (students[i].ID == studentID)
			return &students[i];
	return nullptr;
}
// Find staff
Staff* getStaff(Vector<Staff>& staffs, const std::string& staffID) {
	Staff* ptrStaff = nullptr;
	for (int i = 0; i < staffs.size(); i++)
		if (staffs[i].ID == staffID)
		{
			ptrStaff = &staffs[i];
			break;
		}
	return ptrStaff;
}
// Find SchoolYear
SchoolYear* getSchoolYear(Vector<SchoolYear>& schoolYears, const std::string& start) {
	const unsigned int startYear = std::stoul(start);
	SchoolYear* ptrSchoolYear = nullptr;
	for (int i = 0; i < schoolYears.size(); i++)
		if (schoolYears[i].start == startYear)
		{
			ptrSchoolYear = &schoolYears[i];
			break;
		}
	return ptrSchoolYear;
}
// Find SchoolYear
SchoolYear* getSchoolYear(Vector<SchoolYear>& schoolYears, const unsigned int& start) {
	SchoolYear* ptrSchoolYear = nullptr;
	for (int i = 0; i < schoolYears.size(); i++)
		if (schoolYears[i].start == start)
		{
			ptrSchoolYear = &schoolYears[i];
			break;
		}
	return ptrSchoolYear;
}
// Find AcademicYear
AcademicYear* getAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start) {
	const unsigned int startYear = std::stoul(start);
	AcademicYear* ptrAcademicYear = nullptr;
	for (int i = 0; i < academicYears.size(); i++)
		if (academicYears[i].start == startYear)
		{
			ptrAcademicYear = &academicYears[i];
			break;
		}
	return ptrAcademicYear;
}
// Find Academic Year
AcademicYear* getAcademicYear(Vector<AcademicYear>& academicYears, const unsigned int& start) {
	AcademicYear* ptrAcademicYear = nullptr;
	for (int i = 0; i < academicYears.size(); i++)
		if (academicYears[i].start == start)
		{
			ptrAcademicYear = &academicYears[i];
			break;
		}
	return ptrAcademicYear;
}
// Find Class
Class* getClass(Vector<SchoolYear>& schoolYears, const std::string& className) {
	for (int i = 0; i < schoolYears.size(); i++)
	{
		Class* ptrClass = schoolYears[i].getClass(className);
		if (ptrClass != nullptr)
			return ptrClass;
	}
	return nullptr;
}
// Find Semester
Semester* getSemester(Vector<AcademicYear>& academicYears, const std::string& semesterID) {
	for (int i = 0; i < academicYears.size(); i++)
	{
		Semester* ptrSemester = academicYears[i].getSemester(semesterID);
		if (ptrSemester != nullptr)
			return ptrSemester;
	}
	return nullptr;
}
// Find Course
Course* getCourse(Vector<AcademicYear>& academicYears, const std::string& courseID) {
	for (int i = 0; i < academicYears.size(); i++)
		for (int j = 0; j < academicYears[i].semesters.size(); j++)
		{
			Course* ptrCourse = academicYears[i].semesters[j].getCourse(courseID);
			if (ptrCourse != nullptr)
				return ptrCourse;
		}
	return nullptr;
}
// Find Scoreboard of Course of Student
Scoreboard* getScoreboard(Vector<AcademicYear>& academicYears, const std::string& courseID, const std::string& studentID) {
	Scoreboard* ptrScoreboard = nullptr;
	Course* ptrCourse = getCourse(academicYears, courseID);
	if (ptrCourse != nullptr)
		ptrScoreboard = ptrCourse->getScoreboard(studentID);
	return ptrScoreboard;
}
// Check student acc
bool isCorrectStaffAccount(Vector<Staff>& staffs, const std::string& staffID, const std::string& password, std::string& outStr) {
	Staff* ptrStaff = getStaff(staffs, staffID);
	if (ptrStaff == nullptr) 
	{
		outStr = "Invalid username or password! Pls try again!";
		return false;
	}
	if (ptrStaff->isPassword(password) == false) 
	{
		outStr = "Invalid username or password! Pls try again!";
		return false;
	}
	return true;
}
// Check staff acc
bool isCorrectStudentAccount(Vector<Student>& students, const std::string& studentID, const std::string& password, std::string& outStr) {
	Student* ptrStudent = getStudent(students, studentID);
	if (ptrStudent == nullptr) 
	{
		outStr = "Invalid username or password! Pls try again!";
		return false;
	}
	if (!ptrStudent->isPassword(password)) 
	{
		outStr = "Invalid username or password! Pls try again!";
		return false;
	}
	outStr = "Complete login to student account " + studentID;
	return true;
}
// Check student
bool isStudent(Vector<Student>& students, const std::string& studentID, std::string& outStr) {
	Student* ptrStudent = getStudent(students, studentID);
	if (ptrStudent == nullptr)
	{
		outStr = "Student with ID " + studentID + " is not existed in school!";
		return false;
	}
	return true;
}
// Check staff
bool isStaff(Vector<Staff>& staffs, const std::string& staffID, std::string& outStr) {
	Staff* ptrStaff = getStaff(staffs, staffID);
	if (ptrStaff == nullptr)
	{
		outStr = "Staff with ID " + staffID + " is not existed in school!";
		return false;
	}
	return true;
}

// Check SchoolYear
bool isSchoolYear(Vector<SchoolYear>& schoolYears, const std::string& start, std::string& outStr) {
	SchoolYear* ptrSchoolYear = getSchoolYear(schoolYears, start);
	if (ptrSchoolYear == nullptr)
	{
		outStr = "SchoolYear with start year " + start + " is not existed!";
		return false;
	}
	return true;
}
// Check AcademicYear
bool isAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start, std::string& outStr) {
	AcademicYear* ptrAcademicYear = getAcademicYear(academicYears, start);
	if (ptrAcademicYear == nullptr)
	{
		outStr = "AcademicYear with start year " + start + " is not existed!";
		return false;
	}
	return true;
}
// Check Class
bool isClass(Vector<SchoolYear>& schoolYears, const std::string& className, std::string& outStr) {
	Class* ptrClass = getClass(schoolYears, className);
	if (ptrClass == nullptr)
	{
		outStr = "Class with classname " + className + " is not existed!";
		return false;
	}
	return true;
}
// Check Semester
bool isSemester(Vector<AcademicYear>& academicYears, const std::string& semesterID, std::string& outStr) {
	Semester* ptrSemester = getSemester(academicYears, semesterID);
	if (ptrSemester == nullptr)
	{
		outStr = "Semester with semesterID " + semesterID + " is not existed!";
		return false;
	}
	return true;
}
// Check Course
bool isCourse(Vector<AcademicYear>& academicYears, const std::string& courseID, std::string& outStr) {
	Course* ptrCourse = getCourse(academicYears, courseID);
	if (ptrCourse == nullptr)
	{
		outStr = "Course with courseID " + courseID + " is not existed!";
		return false;
	}
	return true;
}

//----------------------------------------------------------------------------------------------//