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
bool addStudent(Vector<Student>& students, const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& genderStr, const std::string& birthStr, const std::string& socialID, const std::string& password, std::string& outStr) {
	if (ID.empty() || firstName.empty() || lastName.empty() || password.empty() || birthStr.empty() || genderStr.empty() || socialID.empty()) {
		outStr = "Please enter all the information of student in all input box to add new student";
		return false;
	}
	Student* ptrStudent = getStudent(students, ID);
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
		std::string dayStr, monthStr, yearStr;
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
bool addStaff(std::string curStaffID, Vector<Staff>& staffs, const std::string& ID, const std::string& password, const std::string& firstName, const std::string& lastName, std::string& outStr) {
	if (ID.empty() || firstName.empty() || lastName.empty() || password.empty()) {
		outStr = "Please enter all the information of staff in all input box to add new staff";
		return false;
	}
	Staff staff;
	staff.ID = ID;
	Staff* ptrStaff = getStaff(staffs, ID);
	if (ptrStaff != nullptr) 
	{
		outStr = "Staff with ID " + ID + " have been already existed!";
		return false;
	}
	staff.setName(firstName, lastName);
	staff.setPassword(password);
	staffs.append(staff);
	ptrStaff_Global = getStaff(staffs, curStaffID);
	outStr = "Complete add new staff with ID " + ID;
	return true;
}

// Add a new SchoolYear
bool addSchoolYear(Vector<SchoolYear>& yearList, const std::string& start, std::string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	SchoolYear* ptrSchoolYear = getSchoolYear(yearList, startYear);
	if (ptrSchoolYear != nullptr){
		outStr = "SchoolYear with start year " + start + " have been already existed!";
		return false;
	}
	SchoolYear newYear;
	newYear.start = startYear;
	yearList.append(newYear);
	outStr = "Complete add new SchoolYear with start year " + start + " to the list of SchoolYear!";
	return true;
}

// Add new class for SchoolYear
bool addClass(SchoolYear& schoolYear, const std::string& className, std::string& outStr) {
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

// Add students into a specific class (from File)
bool importStudentListOfClassFromFile(Vector<Student> &students, Class& actClass, std::string& outStr) {	
	std::string inputStudClassFilePath = getInputStudClassFilePath(actClass);
	std::ifstream inF(inputStudClassFilePath);
	if (!inF.is_open()) {
		outStr = "Cannot open file path " + inputStudClassFilePath;
		return false;
	}
	Student* ptrStudent = nullptr;
	std::string ignore;
	string nStudents;
	getline(inF, ignore, ',');
	getline(inF, nStudents);
	size_t n = stoull(nStudents);
	if (n == 0) {
		outStr = "Student list file is empty!";
		return false;
	}
	getline(inF, ignore);
	for (size_t i = 0; i < n; i++) {
		string studentID;
		getline(inF, ignore, ',');
		getline(inF, studentID);
		ptrStudent = getStudent(students, studentID);
		if (ptrStudent == nullptr) {
			outStr = "Student with ID " + studentID + " is not existed in school!";
			return false;
		}
		if (ptrStudent->ptrClass != nullptr) {
			outStr = "Student with ID " + studentID + " have been already existed in class " + ptrStudent->ptrClass->name;
			return false;
		}
		actClass.students.append(ptrStudent);
	}
	inF.close();
	outStr = "Complete add list of student to class " + actClass.name + "!";
	return true;
}

// Add a new students to class
bool addStudentToClass(Vector<Student>& students, Class& actClass, const std::string& studentID, std::string& outStr) { 
	if (studentID.empty()) {
		outStr = "Please enter the student ID in InputBox!";
		return false;
	}
	Student *ptrStudent = getStudent(students, studentID);
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
bool addAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start, std::string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	AcademicYear* ptrAcademicYear = getAcademicYear(academicYears, startYear);
	if (ptrAcademicYear != nullptr) {
		outStr = "AcademicYear with start year " + start + " have been already existed!";
		return false;
	}
	AcademicYear newYear;
	newYear.start = startYear;
	academicYears.append(newYear);
	outStr = "Complete add new SchoolYear with start year " + start + " to the list of SchoolYear!";
	return true;
}

// Add a semester to an academic year
bool addSemester(AcademicYear& academicYear, const std::string& semesterID, std::string& outStr) {
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
bool addCourse(Semester& semester, const std::string& courseID, std::string& outStr) {
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

// Add list student to course (from file)
bool importStudentListOfCourseFromFile(Vector<Student> &students, Course& course, std::string& outStr) {
	std::string inputStudCourseFilePath = getInputListStudCourseFilePath(course);
	std::ifstream inF(inputStudCourseFilePath);
	if (!inF.is_open()) {
		outStr = "Cannot open file path " + inputStudCourseFilePath;
		return false;
	}
	std::string ignore;
	string nStudents;
	getline(inF, ignore, ',');
	getline(inF, nStudents);
	size_t n = stoull(nStudents);
	if (n == 0) {
		outStr = "Student list file is empty!";
		return false;
	}
	Student* ptrStudent = nullptr;
	getline(inF, ignore);
	for (size_t i = 0; i < n; i++) {
		string studentID;
		getline(inF, ignore, ',');
		getline(inF, studentID);
		ptrStudent = getStudent(students, studentID);
		if (ptrStudent == nullptr) {
			outStr = "Student with ID " + studentID + " is not existed in school!";
			return false;
		}
		if (ptrStudent->getScoreboard(course) != nullptr) {
			outStr = "Student with ID " + studentID + " have been already existed in course " + course.ID;
			return false;
		}
		course.addStudent(*ptrStudent);
	}
	inF.close();
	outStr = "Complete add list of student to Course " + course.ID;
	return true;
}

// Add a student to course
bool addStudentToCourse(Vector<Student>& students, Course& course, const std::string& studentID, std::string& outStr) {
	if (studentID.empty()) {
		outStr = "Please enter the student ID in InputBox!";
		return false;
	}
	Student* ptrStudent = getStudent(students, studentID);
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