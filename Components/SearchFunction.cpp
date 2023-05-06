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
Student* getStudent(const string& studentID) {
	for (int i = 0; i < students.size(); i++)
		if (students[i].ID == studentID)
			return &students[i];
	return nullptr;
}

// Find staff
Staff* getStaff(const string& staffID) {
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
SchoolYear* getSchoolYear(const string& start) {
	const unsigned int startYear = std::stoul(start);
	SchoolYear* ptrSchoolYear = nullptr;
	for (int i = 0; i < schoolYears.size(); i++)
		if (schoolYears[i].start == startYear){
			ptrSchoolYear = &schoolYears[i];
			break;
		}
	return ptrSchoolYear;
}

// Find AcademicYear
AcademicYear* getAcademicYear(const string& start) {
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

// Find Class
Class* getClass(SchoolYear& schoolYear, const string& className) {
	Class* ptrClass = schoolYear.getClass(className);
	return ptrClass;
}

Semester* getSemester(const string& semesterID) {
	Semester* ptrSemester = nullptr;
	for (int i = 0; i < academicYears.size(); i++) {
		if (academicYears[i].getSemester(semesterID) != nullptr) {
			ptrSemester = academicYears[i].getSemester(semesterID);
		}
	}
	return ptrSemester;
}

// Find Semester
Semester* getSemester(AcademicYear& academicYear, const string& semesterID) {
	Semester* ptrSemester = academicYear.getSemester(semesterID);
	return ptrSemester;
}

// Find Course
Course* getCourse(Semester& semester, const string& courseID) {
	Course* ptrCourse = semester.getCourse(courseID);
	return ptrCourse;	
}

// Find Scoreboard of Course of Student
Scoreboard* getScoreboard(Course& course, const string& studentID) {
	Scoreboard* ptrScoreboard = course.getScoreboard(studentID);
	return ptrScoreboard;
}

// Check student acc
bool isCorrectStaffAccount(const string& staffID, const string& password, string& outStr) {
	Staff* ptrStaff = getStaff(staffs, staffID);
	if (ptrStaff == nullptr) {
		outStr = "Invalid username or password! Pls try again!";
		return false;
	}
	if (ptrStaff->isPassword(password) == false) {
		outStr = "Invalid username or password! Pls try again!";
		return false;
	}
	return true;
}

// Check staff acc
bool isCorrectStudentAccount(const string& studentID, const string& password, string& outStr) {
	Student* ptrStudent = getStudent(students, studentID);
	if (ptrStudent == nullptr) {
		outStr = "Invalid username or password! Pls try again!";
		return false;
	}
	if (!ptrStudent->isPassword(password)) {
		outStr = "Invalid username or password! Pls try again!";
		return false;
	}
	outStr = "Complete login to student account " + studentID;
	return true;
}

//----------------------------------------------------------------------------------------------//