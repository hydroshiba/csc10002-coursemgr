#include "RemoveFunction.h"
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

/*		Remove function		*/

// Remove student list - Free memory
bool removeListStudent() {
	students.~Vector();
	return (students.size() == 0);
}

// Remove staff list - Free memory
bool removeListStaff() {
	staffs.~Vector();
	return (staffs.size() == 0);
}

// Remove list SchoolYear - Free memory
bool removeListSchoolYear() {
	for (int i = 0; i < schoolYears.size(); i++) {
		schoolYears[i].removeAllClass();
	}
	schoolYears.~Vector();
	return (schoolYears.size() == 0);
}

// Remove list AcademicYear - Free memory
bool removeListAcademicYear() {
	for (int i = 0; i < academicYears.size(); i++) {
		academicYears[i].removeAllSemester();
	}
	academicYears.~Vector();
	return (academicYears.size() == 0);
}

// Free memory
bool freeMemory() {
	bool b1 = removeListSchoolYear();
	bool b2 = removeListAcademicYear();
	bool b3 = removeListStaff();
	bool b4 = removeListStudent();
	return (b1 && b2 && b3 && b4);
}

// Remove student from School - Button
bool removeStudent(const string& studentID, string& outStr) {
	if (studentID.empty()) {
		outStr = "Please enter student ID to input box to remove";
		return false;
	}
	Student* ptrStudent = getStudent(studentID);
	if (ptrStudent == nullptr) {
		outStr = "Student with ID " + studentID + " can't be found in school! Pls try another";
		return false;
	}
	students.remove(ptrStudent);
	outStr = "Student with ID " + studentID + " is removed from school!";
	return true;
}

// Remove staff from school - Button
bool removeStaff(string curStaffID, const string & staffID, string & outStr) {
	if (staffID.empty()) {
		outStr = "Please enter staff ID to input box to remove";
		return false;
	}
	Staff* ptrStaff = getStaff(staffID);
	if (ptrStaff == nullptr) {
		outStr = "Staff with ID " + staffID + " can't be found in school! Pls try another";
		return false;
	}
	if (ptrStaff == ptrStaff_Global) {
		outStr = "Staff with ID " + staffID + " can't be removed from school! Pls try another";
		return false;
	}
	staffs.remove(ptrStaff);
	ptrStaff_Global = getStaff(curStaffID);
	outStr = "Staff with ID " + staffID + " is removed from school!";
	return true;
}

// Remove SchoolYear - Button
bool removeSchoolYear(const string& start, string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	SchoolYear* ptrSchoolYear = getSchoolYear(start);
	if (ptrSchoolYear == nullptr) {
		outStr = "SchoolYear with start year " + start + " is not existed!";
		return false;
	}
	ptrSchoolYear->removeAllClass();
	schoolYears.remove(ptrSchoolYear);
	for (int i = 0; i < schoolYears.size(); i++) {
		for (int j = 0; j < schoolYears[i].classes.size(); j++) {
			schoolYears[i].classes[j].ptrSchoolYear = &schoolYears[i];
			for (int k = 0; k < schoolYears[i].classes[j].students.size(); k++) {
				schoolYears[i].classes[j].students[k]->ptrClass = &schoolYears[i].classes[j];
				for (int l = 0; l < schoolYears[i].classes[j].students[k]->scoreboards.size(); i++) {
					schoolYears[i].classes[j].students[k]->scoreboards[l]->ptrStudent = schoolYears[i].classes[j].students[k];
				}
			}
		}
	}
	outStr = "Successfully deleted the school year with start year " + start;
	return true;
}

// Remove Class from School - Button
bool removeClass(SchoolYear& schoolYear, const string& className, string& outStr) {
	if (className.empty()) {
		outStr = "Please enter the class name in InputBox!";
		return false;
	}
	Class* ptrClass = schoolYear.getClass(className);
	if (ptrClass == nullptr) {
		outStr = "Class " + className + " have not been already existed!";
		return false;
	}
	ptrClass->removeAllStudent();
	schoolYear.removeClass(*ptrClass);
	for (int i = 0; i < schoolYear.classes.size(); i++) {
		for (int j = 0; j < schoolYear.classes[i].students.size(); j++) {
			schoolYear.classes[i].students[j]->ptrClass = &schoolYear.classes[i];
			for (int k = 0; k < schoolYear.classes[i].students[j]->scoreboards.size(); k++)
				schoolYear.classes[i].students[j]->scoreboards[k]->ptrStudent = schoolYear.classes[i].students[j];
		}
	}
	outStr = "Successfully removed class " + className + " from school year " + schoolYear.getPeriod();
	return true;
}

// Remove a student from class - Button
bool removeStudentFromClass(Class& CLASS, const string& studentID, string& outStr) {
	if (studentID.empty()) {
		outStr = "Please enter the student ID in InputBox!";
		return false;
	}
	Student* ptrStudent = CLASS.getStudent(studentID);
	if (ptrStudent == nullptr) {
		outStr = "Student with ID " + studentID + " is not existed in class " + CLASS.name;
		return false;
	}
	ptrStudent->ptrClass = nullptr;
	CLASS.students.remove(ptrStudent);
	for (int i = 0; i < CLASS.students.size(); i++) {
		CLASS.students[i]->ptrClass = &CLASS;
		for (int j = 0; j < CLASS.students[i]->scoreboards.size(); j++)
			CLASS.students[i]->scoreboards[j]->ptrStudent = CLASS.students[i];
	}
	outStr = "Student with ID " + studentID + " is removed from  class " + CLASS.name;
	return true;
}

// Remove AcademicYear - Button
bool removeAcademicYear(const string& start, string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	AcademicYear* ptrAcademicYear = getAcademicYear(start);
	if (ptrAcademicYear == nullptr) {
		outStr = "AcademicYear with start year " + start + " is not existed!";
		return false;
	}
	ptrAcademicYear->removeAllSemester();
	academicYears.remove(ptrAcademicYear);
	for (int i = 0; i < academicYears.size(); i++)
		for (int j = 0; j < academicYears[i].semesters.size(); j++) {
			academicYears[i].semesters[j].ptrAcademicYear = &academicYears[i];
			for (int k = 0; k < academicYears[i].semesters[j].courses.size(); k++) {
				academicYears[i].semesters[j].courses[k].ptrSemester = &academicYears[i].semesters[j];
				for (int l = 0; l < academicYears[i].semesters[j].courses[k].scoreboards.size(); l++) {
					academicYears[i].semesters[j].courses[k].scoreboards[l]->ptrCourse = &academicYears[i].semesters[j].courses[k];
				}
			}
		}
	outStr = "Successfully deleted the academic year with start year " + start;
	return true;
}

// Remove Semester - Button
bool removeSemester(AcademicYear& academicYear, const string& semesterID, string& outStr) {
	if (semesterID.empty()) {
		outStr = "Please enter the semester ID in InputBox!";
		return false;
	}
	Semester* ptrSemester = academicYear.getSemester(semesterID);
	if (ptrSemester == nullptr) {
		outStr = "Semester " + semesterID + " have not been already existed in this AcademicYear " + academicYear.getPeriod();
		return false;
	}
	for (int i = 0; i < ptrSemester->courses.size(); i++) {
		ptrSemester->removeAllCourse();
	}
	academicYear.removeSemester(*ptrSemester);
	for (int i = 0; i < academicYear.semesters.size(); i++) {
		academicYear.semesters[i].ptrAcademicYear = &academicYear;
		for (int j = 0; j < academicYear.semesters[i].courses.size(); j++) {
			academicYear.semesters[i].courses[j].ptrSemester = &academicYear.semesters[i];
			for (int k = 0; k < academicYear.semesters[i].courses[j].scoreboards.size(); k++) {
				academicYear.semesters[i].courses[j].scoreboards[k]->ptrCourse = &academicYear.semesters[i].courses[j];
			}
		}
	}
	outStr = "Successfully removed semester " + semesterID + " from academic year " + academicYear.getPeriod();
	return true;
}

// Remove Course - Button
bool removeCourse(Semester& semester, const string& courseID, string& outStr) {
	if (courseID.empty()) {
		outStr = "Please enter the course ID in InputBox!";
		return false;
	}
	Course* ptrCourse = semester.getCourse(courseID);
	if (ptrCourse == nullptr) {
		outStr = "Course with ID " + courseID + " have not been already existed in this semester!";
		return false;
	}
	ptrCourse->removeAllStudent();
	semester.removeCourse(*ptrCourse);
	for (int i = 0; i < semester.courses.size(); i++) {
		semester.courses[i].ptrSemester = &semester;
		for (int j = 0; j < semester.courses[i].scoreboards.size(); j++) {
			semester.courses[i].scoreboards[j]->ptrCourse = &semester.courses[i];
		}
	}
	outStr = "Successfully removed course " + courseID + " from semester " + semester.semesterID;
	return true;
}

// Remove student from course - Button
bool removeStudFromCourse(Course& course, const string& studentID, string& outStr) {
	if (studentID.empty()) {
		outStr = "Please enter the student ID in InputBox!";
		return false;
	}
	Student* ptrStudent = course.getStudent(studentID);
	if (ptrStudent == nullptr){
		outStr = "Student with ID " + studentID + " is not exist in this Course " + course.ID;
		return false;
	}
	Scoreboard* ptrScoreboard = course.getScoreboard(studentID);
	ptrStudent->scoreboards.remove(ptrScoreboard);
	ptrScoreboard->ptrStudent = nullptr;
	course.scoreboards.remove(ptrScoreboard);
	ptrScoreboard->ptrCourse = nullptr;
	for (int i = 0; i < course.scoreboards.size(); i++) {
		course.scoreboards[i]->ptrCourse = &course;
	}
	outStr = "Successfully remove student with ID " + studentID + " from course " + course.ID;
	return true;
}

//----------------------------------------------------------------------------------------------//
