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

// Remove student list
bool removeListStudent() {
	students.~Vector();
	if (students.size() != 0) return false;
	return true;
}

// Remove staff list
bool removeListStaff() {
	staffs.~Vector();
	if (staffs.size() != 0) return false;
	return true;
}

// Remove student from School - Button
bool removeStudent(Vector<Student>& students, const string& studentID, string& outStr) {
	if (studentID.empty()) {
		outStr = "Please enter student ID to input box to remove";
		return false;
	}
	Student* ptrStudent = getStudent(students, studentID);
	if (ptrStudent == nullptr) {
		outStr = "Student with ID " + studentID + " can't be found in school! Pls try another";
		return false;
	}
	students.remove(ptrStudent);
	outStr = "Student with ID " + studentID + " is removed from school!";
	return true;
}

// Remove staff from school - Button
bool removeStaff(string curStaffID, Vector<Staff>&staffs, const string & staffID, string & outStr) {
	if (staffID.empty()) {
		outStr = "Please enter staff ID to input box to remove";
		return false;
	}
	Staff* ptrStaff = getStaff(staffs, staffID);
	if (ptrStaff == nullptr) {
		outStr = "Staff with ID " + staffID + " can't be found in school! Pls try another";
		return false;
	}
	if (ptrStaff == ptrStaff_Global) {
		outStr = "Staff with ID " + staffID + " can't be removed from school! Pls try another";
		return false;
	}
	staffs.remove(ptrStaff);
	ptrStaff_Global = getStaff(staffs, curStaffID);
	outStr = "Staff with ID " + staffID + " is removed from school!";
	return true;
}

// Remove list SchoolYear - Free memory
bool removeListSchoolYear(Vector<SchoolYear>& schoolYears) {
	for (int i = 0; i < schoolYears.size(); ++i) {
		removeListClasses(schoolYears[i]);
		schoolYears.remove(&schoolYears[i]);
	}
	return true;
}

// Remove SchoolYear - Button
bool removeSchoolYear(Vector<SchoolYear>& schoolYears, const string& start, string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	SchoolYear* ptrSchoolYear = getSchoolYear(schoolYears, start);
	if (ptrSchoolYear == nullptr) {
		outStr = "SchoolYear with start year " + start + " is not existed!";
		return false;
	}
	ptrSchoolYear->removeAllClass();
	schoolYears.remove(ptrSchoolYear);
	outStr = "Successfully deleted the school year with start year " + start;
	return true;
}

// Remove List Classes - Free memory
bool removeListClasses(SchoolYear& schoolYear) {
	for (int i = 0; i < schoolYear.classes.size(); ++i) {
		removeListStudents(schoolYear.classes[i]);
		schoolYear.classes.remove(&schoolYear.classes[i]);
	}
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
	outStr = "Student with ID " + studentID + " is removed from  class " + CLASS.name;
	return true;
}

// Remove List Students - Free memory
bool removeListStudents(Class& thisClass) {
	for (int i = 0; i < thisClass.students.size(); ++i) {
		thisClass.students[i]->scoreboards.~Vector(); // delete a student's scoreboard pointers
		thisClass.students.remove(&thisClass.students[i]);
	}
	return true;
}

// Remove list AcademicYear - Free memory
bool removeListAcademicYear(Vector<AcademicYear>& academicYears) {
	for (int i = 0; i < academicYears.size(); ++i) {
		removeListSemesters(academicYears[i]);
		academicYears.remove(&academicYears[i]);
	}
	return true;
}

// Remove AcademicYear - Button
bool removeAcademicYear(Vector<AcademicYear>& academicYears, const string& start, string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	AcademicYear* ptrAcademicYear = getAcademicYear(academicYears, start);
	if (ptrAcademicYear == nullptr) {
		outStr = "AcademicYear with start year " + start + " is not existed!";
		return false;
	}
	ptrAcademicYear->removeAllSemester();
	academicYears.remove(ptrAcademicYear);
	outStr = "Successfully deleted the academic year with start year " + start;
	return true;
}

// Remove List Semesters - Free memory
bool removeListSemesters(AcademicYear& academicYear) {
	for (int i = 0; i < academicYear.semesters.size(); ++i) {
		removeListCourses(academicYear.semesters[i]);
		academicYear.semesters.remove(&academicYear.semesters[i]);
	}
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
		outStr = "This SemesterID " + semesterID + " have not been already existed in this AcademicYear " + academicYear.getPeriod();
		return false;
	}
	for (int i = 0; i < ptrSemester->courses.size(); i++) {
		ptrSemester->removeAllCourse();
	}
	academicYear.removeSemester(*ptrSemester);
	outStr = "Successfully removed semester " + semesterID + " from academic year " + academicYear.getPeriod();
	return true;
}

// Remove List Courses - Free memory
bool removeListCourses(Semester & semester) {
	for (int i = 0; i < semester.courses.size(); ++i) {
		for (int j = 0; j < semester.courses[i].scoreboards.size(); ++j)
			delete semester.courses[i].scoreboards[j]; // delete scoreboard
		semester.courses[i].scoreboards.~Vector(); // delete Vector pointer of Scoreboards
		semester.courses.remove(&semester.courses[i]); // delete course
	}
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
	outStr = "Successfully remove student with ID " + studentID + " from course " + course.ID;
	return true;
}

// Free memory
bool freeMemory(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears) {
	bool b1 = removeListSchoolYear(schoolYears);
	bool b2 = removeListAcademicYear(academicYears);
	return (b1 && b2);
}
//----------------------------------------------------------------------------------------------//
