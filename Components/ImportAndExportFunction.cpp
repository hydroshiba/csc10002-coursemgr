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
#include "DisplayFunction.h"

// Add students into a specific class (from File)
bool importStudentListOfClassFromFile(const string& filename, Vector<Student> &students, Class& actClass, string& outStr) {
	string inputStudClassFilePath = getImportFolderPath() + filename;
	std::ifstream inF(inputStudClassFilePath);
	if (!inF.is_open()) {
		outStr = "Cannot open file path " + inputStudClassFilePath;
		return false;
	}
	Student* ptrStudent = nullptr;
	string ignore, className;
	getline(inF, ignore,',');
	getline(inF, className);
	if (className != actClass.name){
		outStr = "Imported students to wrong class " + className + ", please try again";
		return false;
	}
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
			actClass.removeAllStudent();
			return false;
		}
		if (ptrStudent->ptrClass != nullptr) {
			outStr = "Student with ID " + studentID + " have been already existed in class " + ptrStudent->ptrClass->name;
			actClass.removeAllStudent();
			return false;
		}
		actClass.students[i] = ptrStudent;
	}
	inF.close();
	outStr = "Complete add list of student to class " + actClass.name + "!";
	return true;
}

// Add list student to course (from file)
bool importStudentListOfCourseFromFile(const string& filename, Vector<Student> &students, Course& course, string& outStr) {
	string inputStudCourseFilePath = getImportFolderPath() + filename;
	std::ifstream inF(inputStudCourseFilePath);
	if (!inF.is_open()) {
		outStr = "Cannot open file path " + inputStudCourseFilePath;
		return false;
	}
	string ignore, courseID;
	getline(inF, ignore, ',');
	getline(inF, courseID);
	if (courseID != course.ID){
		outStr = "Imported students to wrong course " + courseID + ", please try again!";
		return false;
	}
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
			course.removeAllStudent();
			return false;
		}
		if (ptrStudent->getScoreboard(course) != nullptr) {
			outStr = "Student with ID " + studentID + " have been already existed in course " + course.ID;
			course.removeAllStudent();
			return false;
		}
		course.addStudent(*ptrStudent);
	}
	inF.close();
	outStr = "Complete add list of student to Course " + course.ID;
	return true;
}

// 20. import scoreboard of course
bool importScoreBoardOfCourse(const string& filename, Course& course) {
	string inputScoreCourseFilePath = getImportFolderPath() + filename;
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

bool exportListSchoolYear(const string& filename, string& outStr){
	string getListSchoolYearFile = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream fout (getListSchoolYearFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getListSchoolYearFile + '!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfListSchoolYear();
	for (int i = 0; i<table.size(); ++i){
		for (int j = 0; j <table[i].size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported list school years to " + getListSchoolYearFile;
	removeTable(table);
	return true;
}

bool exportListClassInSchoolYear(const string& filename, SchoolYear& schoolYear, string& outStr){
	string getListClassFile = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream fout (getListClassFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getListClassFile + '!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfSchoolYear(schoolYear);
	for (int i = 0; i<table.size(); ++i){
		for (int j = 0; j<table[i].size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported list classes from school year " + std::to_string(schoolYear.start) + " to " + getListClassFile;
	removeTable(table);
	return true;
}

bool exportListStudentInClass(const string& filename, Class& CLASS, string& outStr){
	string getListStudClassFile = getExportFolderPath() + filename + ".csv";
	std::ofstream fout(getListStudClassFile, std::ios::out);
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (!fout.is_open()){
		outStr = "Cannot open file " + getListStudClassFile + "!";
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfListStudentInClass(CLASS);
	for (int i = 0; i<table.size(); ++i){
		for (int j = 0; j<table[i].size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported list students from class " + CLASS.name + " to " + getListStudClassFile;
	removeTable(table);
	return true;
}

bool exportListScoreboardInSemesterOfClass(const string& filename, Class& CLASS, Semester& semester, string& outStr){
	string getListScoreInSemesterOfCLassFile = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream fout (getListScoreInSemesterOfCLassFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getListScoreInSemesterOfCLassFile + '!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfListScoreboardInSemesterInClass(CLASS, semester);
	for (int i = 0; i<table.size(); ++i){
		for (int j = 0; j<table[i].size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported scoreboard in a semester " + semester.semesterID + " from class " + CLASS.name + " to " + getListScoreInSemesterOfCLassFile;
	removeTable(table);
	return true;
}

bool exportListScoreboardOfClass(const string& filename, Class& CLASS, string& outStr){
	string getListScoreboardOfCLassFile = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream fout (getListScoreboardOfCLassFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getListScoreboardOfCLassFile + '!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfListScoreboardInClass(CLASS);
	for (int i = 0; i<table.size(); ++i){
		for (int j = 0; j<table[i].size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported scoreboards of students from class " + CLASS.name + " to " + getListScoreboardOfCLassFile;
	removeTable(table);
	return true;
}

bool exportListAcademicYear(const string& filename, string& outStr){
	string getListAcademicYearFile = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream fout (getListAcademicYearFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getListAcademicYearFile +'!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfListAcademicYear();
	for (int i = 0; i<table.size(); ++i){
		for (int j = 0; j<table[i].size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported list academic years to " + getListAcademicYearFile;
	removeTable(table);
	return true;
}

bool exportListSemesterInAcademicYear(const string& filename, AcademicYear& academicYear, string& outStr){
	string getListSemesterFile = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream fout (getListSemesterFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getListSemesterFile +'!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfAcademicYear(academicYear);
	for (int i = 0; i<table.size(); ++i){
		for (int j = 0; j<table[i].size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported list semester from academic year " + std::to_string(academicYear.start) + " to " + getListSemesterFile;
	removeTable(table);
	return true;
}

bool exportListCourseInSemester(const string& filename, Semester& semester, string& outStr){
	string getListCourseFile = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream fout (getListCourseFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getListCourseFile +'!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfSemester(semester);
	for (int i = 0; i<table.size(); ++i){
		for (int j = 0; j<table[i].size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported list course from semester " + semester.semesterID + " to " + getListCourseFile;
	removeTable(table);
	return true;
}

// 19. export list of students in course to csv file
bool exportListOfStudentInCourse(const string& filename, Course& course, string &outStr) {
	string inputStudCouseFilePath = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream ofs(inputStudCouseFilePath, std::ios::out);
	if (!ofs.is_open()){
		outStr = "Cannot open file " + inputStudCouseFilePath + "!";
		return false;
	}
	course.displayInfoFile(ofs);
	ofs << "No,ID,Fullname" << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		ofs << i + 1 << "," << student->ID << "," << student->name.get() << std::endl;
	}
	ofs.close();
	outStr = "Completely exported students list from course to " + inputStudCouseFilePath;
	return true;
}

bool exportListScoreboardOfCourse(const string& filename, Course& course, string& outStr){
	string getCourseScoreboardFile = getExportFolderPath() + filename + ".csv";
	if (filename.empty()){
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	std::ofstream fout(getCourseScoreboardFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getCourseScoreboardFile + '!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfListStudentInCourse(course);
	for (int i = 0; i < table.size(); ++i){
		for (int j = 0; j < table.size(); ++j){
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported scoreboard of course to " + getCourseScoreboardFile;
	removeTable(table);
	return true;
}