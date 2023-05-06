#include "InsertFunction.h"
#include "SearchFunction.h"
#include "FileAndDirFunction.h"
#include "ConvertType.h"

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


/*		Insert function		*/
// Add new student
bool addStudent(const string& ID, const string& firstName, const string& lastName, const string& genderStr, const string& birthStr, const string& socialID, const string& password, string& outStr) {
	if (ID.empty() || firstName.empty() || lastName.empty() || password.empty() || birthStr.empty() || genderStr.empty() || socialID.empty()) {
		outStr = "Please enter all the information of student in all input box to add new student";
		return false;
	}
	Student* ptrStudent = getStudent(ID);
	if (ptrStudent != nullptr) {
		outStr = "Student with ID " + ID + " have been already existed in school!";
		return false;
	}
	Student student;
	if (!ID.empty()) {
		student.setID(ID);
	}
	if (!firstName.empty()) {
		student.setFirstName(firstName);
	}
	if (!lastName.empty()) {
		student.setLastName(lastName);
	}
	if (!genderStr.empty()) {
		Gender gender = string_to_gender(genderStr);
		student.setGender(gender);
	}
	if (!birthStr.empty()) {
		string dayStr, monthStr, yearStr;
		std::stringstream ss(birthStr);
		getline(ss, dayStr, '/');
		getline(ss, monthStr, '/');
		getline(ss, yearStr);

		unsigned short day = static_cast<unsigned short>(std::stoi(dayStr));
		unsigned short month = static_cast<unsigned short>(std::stoi(monthStr));
		unsigned int year = static_cast<unsigned int>(std::stoul(yearStr));
		Date birth(day, month, year);
		student.setBirth(birth);
	}
	if (!socialID.empty()) {
		student.setSocialID(socialID);
	}
	if (!password.empty()) {
		student.setPassword(password);
	}
	students.append(student);
	outStr = "Complete add new student with ID " + ID + " to school";
	return true;
}

// Add new staff
bool addStaff(string curStaffID, const string& ID, const string& password, const string& firstName, const string& lastName, string& outStr) {
	if (ID.empty() || firstName.empty() || lastName.empty() || password.empty()) {
		outStr = "Please enter all the information of staff in all input box to add new staff";
		return false;
	}
	Staff staff;
	staff.ID = ID;
	Staff* ptrStaff = getStaff(ID);
	if (ptrStaff != nullptr) 
	{
		outStr = "Staff with ID " + ID + " have been already existed!";
		return false;
	}
	staff.setName(firstName, lastName);
	staff.setPassword(password);
	staffs.append(staff);
	ptrStaff_Global = getStaff(curStaffID);
	outStr = "Complete add new staff with ID " + ID;
	return true;
}

// Add a new SchoolYear
bool addSchoolYear(const string& start, string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	SchoolYear* ptrSchoolYear = getSchoolYear(start);
	if (ptrSchoolYear != nullptr){
		outStr = "SchoolYear with start year " + start + " have been already existed!";
		return false;
	}
	SchoolYear newYear;
	newYear.start = startYear;
	schoolYears.append(newYear);
	outStr = "Complete add new SchoolYear with start year " + start + " to the list of SchoolYear!";
	return true;
}

// Add new class for SchoolYear
bool addClass(SchoolYear& schoolYear, const string& className, string& outStr) {
	if (className.empty()) {
		outStr = "Please enter the class name in InputBox!";
		return false;
	}
	Class* ptrClass = schoolYear.getClass(className);
	if (ptrClass != nullptr){
		outStr = "Class " + className + " have been already existed!";
		return false;
	}
	Class newClass;
	newClass.name = className;
	schoolYear.addClass(newClass);
	outStr = "Complete add class " + className + " to SchoolYear " + std::to_string(schoolYear.start) + "!";
	return true;
}

// Add a new students to class
bool addStudentToClass(Class& actClass, const string& studentID, string& outStr) { 
	if (studentID.empty()) {
		outStr = "Please enter the student ID in InputBox!";
		return false;
	}
	Student *ptrStudent = getStudent(studentID);
	if (ptrStudent == nullptr) {
		outStr = "Student with ID " + studentID + " is not existed in school!";
		return false;
	}
	if (ptrStudent->ptrClass != nullptr) {
		outStr = "Student with ID " + studentID + " have been already existed in class " + ptrStudent->ptrClass->name;
		return false;
	}
	actClass.students.append(ptrStudent);
	outStr = "Complete add new student with ID " + studentID + " to class " + actClass.name;
	return true;
}

// Add a new academic year
bool addAcademicYear(const string& start, string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	AcademicYear* ptrAcademicYear = getAcademicYear(start);
	if (ptrAcademicYear != nullptr) {
		outStr = "AcademicYear with start year " + start + " have been already existed!";
		return false;
	}
	AcademicYear newYear;
	newYear.start = startYear;
	academicYears.append(newYear);
	outStr = "Complete add new AcademicYear with start year " + start + " to the list of AcademicYear!";
	return true;
}

// Add a semester to an academic year
bool addSemester(AcademicYear& academicYear, const string& semesterID, string& outStr) {
	if (semesterID.empty()) {
		outStr = "Please enter the semester ID in InputBox!";
		return false;
	}
	if (academicYear.getSemester(semesterID) != nullptr){
		outStr = "This SemesterID " + semesterID + " have been already existed in this AcademicYear " + academicYear.getPeriod();
		return false;
	}
	Semester semester;
	semester.semesterID = semesterID;
	academicYear.addSemester(semester);
	outStr = "Complete add new Semester " + semesterID + " to AcademicYear " + academicYear.getPeriod();
	return true;
}

// Add a new course
bool addCourse(Semester& semester, const string& courseID, string& outStr) {
	if (courseID.empty()) {
		outStr = "Please enter the course ID in InputBox!";
		return false;
	}
	if (semester.getCourse(courseID) != nullptr){
		outStr = "Course with ID " + courseID + " have been already existed in this semester!";
		return false;
	}
	Course newCourse;
	newCourse.ID = courseID;
	newCourse.ptrSemester = &semester;
	semester.addCourse(newCourse);
	outStr = "Complete add new course " + courseID + " to list of course in Semester " + semester.semesterID;
	return true;
}

// Add a student to course
bool addStudentToCourse(Course& course, const string& studentID, string& outStr) {
	if (studentID.empty()) {
		outStr = "Please enter the student ID in InputBox!";
		return false;
	}
	Student* ptrStudent = getStudent(studentID);
	if (ptrStudent == nullptr){
		outStr = "Student with ID " + studentID + " is not exist in school! Pls try another!";
		return false;
	}
	if (ptrStudent->getScoreboard(course) != nullptr) {
		outStr = "Student with ID " + studentID + " have been already existed in course " + course.ID;
		return false;
	}
	course.addStudent(*ptrStudent);
	outStr = "Complete add student with ID " + studentID + " to Course " + course.ID;
	return true;
}


//----------------------------------------------------------------------------------------------//