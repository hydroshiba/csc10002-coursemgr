#include "ImportAndExportFunction.h"

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

#include "FileAndDirFunction.h"
#include "SearchFunction.h"

// Add students into a specific class (from File)
bool importStudentListOfClassFromFile(Vector<Student> &students, Class& actClass, std::string& outStr) {	
	std::string inputStudClassFilePath = getImportStudClassFilePath(actClass);
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
	actClass.students.resize(n);
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
		actClass.students[i] = ptrStudent;
	}
	inF.close();
	outStr = "Complete add list of student to class " + actClass.name + "!";
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

// 19. export list of students in course to csv file
bool exportListOfStudent(Course& course) {
	string inputStudCouseFilePath = getInputListStudCourseFilePath(course);
	std::ofstream ofs(inputStudCouseFilePath, std::ios::out);
	course.displayInfo(ofs);
	ofs << "No,ID,Fullname" << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		ofs << i + 1 << "," << student->ID << "," << student->name.get() << std::endl;
	}
	ofs.close();
	return true;
}

// 20. import scoreboard of course
bool importScoreBoardOfCourse(Course& course) {
	string inputScoreCourseFilePath = getInputScoreCourseFilePath(course);
	std::ifstream ifs(inputScoreCourseFilePath);
	if (!ifs.is_open())
	{
		std::cout << "Can't find file with path " << inputScoreCourseFilePath << std::endl;
		return false;
	}
	course.importScoreBoards(ifs);
	std::cout << "Complete importion!" << std::endl;
	ifs.close();
	return true;
}