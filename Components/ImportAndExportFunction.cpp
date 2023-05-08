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

bool importStudentListOfClassFromFile(const string& filename, Class& actClass, string& outStr) {
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (actClass.students.size() != 0) {
		outStr = "This class has already imported list of student!";
		return false;
	}
	string inputStudClassFilePath = getImportFolderPath() + filename + ".csv";
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
	getline(inF, ignore);
	for (size_t i = 0; i < n; i++) {
		string studentID;
		getline(inF, ignore, ',');
		getline(inF, studentID);
		ptrStudent = getStudent(studentID);
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
		actClass.addStudent(ptrStudent);
	}
	inF.close();
	outStr = "Complete add list of student to class " + actClass.name + "!";
	return true;
}

bool importStudentListOfCourseFromFile(const string& filename, Course& course, string& outStr) {
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (course.scoreboards.size() != 0) {
		outStr = "This course has already imported list of student!";
		return false;
	}
	string inputStudCourseFilePath = getImportFolderPath() + filename + ".csv";
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
	for (int i = 0; i < 6; i++) {
		getline(inF, ignore);
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
		ptrStudent = getStudent(studentID);
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

bool importScoreBoardOfCourse(const string& filename, Course& course, string& outStr) {
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	string inputScoreCourseFilePath = getImportFolderPath() + filename + ".csv";
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
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (schoolYears.size() == 0) {
		outStr = "List of SchoolYears is empty now!";
		return false;
	}
	string getListSchoolYearFile = getExportFolderPath() + filename + ".csv";
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
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (schoolYear.classes.size() == 0) {
		outStr = "List of classes in schoolYear " + schoolYear.getPeriod() + " is empty now!";
		return false;
	}
	string getListClassFile = getExportFolderPath() + filename + ".csv";
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
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (CLASS.students.size() == 0) {
		outStr = "List students in class " + CLASS.name + " is empty now!";
		return false;
	}
	string getListStudClassFile = getExportFolderPath() + filename + ".csv";
	std::ofstream fout(getListStudClassFile, std::ios::out);
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
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	string getListScoreInSemesterOfCLassFile = getExportFolderPath() + filename + ".csv";
	
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
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	string getListScoreboardOfCLassFile = getExportFolderPath() + filename + ".csv";
	
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
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (academicYears.size() == 0) {
		outStr = "List of AcademicYear is empty now!";
		return false;
	}
	string getListAcademicYearFile = getExportFolderPath() + filename + ".csv";
	
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
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (academicYear.semesters.size() == 0) {
		outStr = "List semester in AcademicYear " + academicYear.getPeriod() + " is empty now!";
		return false;
	}
	string getListSemesterFile = getExportFolderPath() + filename + ".csv";
	
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
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (semester.courses.size() == 0) {
		outStr = "List course in semester " + semester.semesterID + " is emtpy now!";
		return false;
	}
	string getListCourseFile = getExportFolderPath() + filename + ".csv";
	
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

bool exportListOfStudentInCourse(const string& filename, Course& course, string &outStr) {
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	/*if (course.scoreboards.size() == 0) {
		outStr = "This course don't have any students";
		return false;
	}*/
	string inputStudCouseFilePath = getExportFolderPath() + filename + ".csv";
	
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
		ofs << to_string(i + 1) << "," << student->ID << "," << student->name.get() << std::endl;
	}
	ofs.close();
	outStr = "Completely exported students list from course to " + inputStudCouseFilePath;
	return true;
}

bool exportListScoreboardOfCourse(const string& filename, Course& course, string& outStr){
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	/*if (course.scoreboards.size() == 0) {
		outStr = "This course don't have any students";
		return false;
	}*/
	string getCourseScoreboardFile = getExportFolderPath() + filename + ".csv";
	
	std::ofstream fout(getCourseScoreboardFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getCourseScoreboardFile + '!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfListStudentInCourse(course);
	for (int i = 0; i < table.size(); ++i){
		for (int j = 0; j < table[i].size(); ++j) {
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

bool exportListScoreboardOfStudent(const string& filename, Student& student, string& outStr){
	if (student.ptrClass == nullptr) {
		outStr = "Student with ID " + student.ID + " is not existed in any class!";
		return false;
	}
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (student.scoreboards.size() == 0) {
		outStr = "Student don't have any courses in courses list";
		return false;
	}
	string getStudentScoreboardListFile = getExportFolderPath() + filename + ".csv";
	std::ofstream fout(getStudentScoreboardListFile, std::ios::out);
	if (!fout.is_open()){
		outStr = "Cannot open file " + getStudentScoreboardListFile + '!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfScoreboardOfStudent(student);
	for (int i = 0; i < table.size(); ++i){
		for (int j = 0; j < table[i].size(); ++j) {
			fout << table[i][j];
			if (j != table[i].size()-1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported scoreboard of student to " + getStudentScoreboardListFile;
	removeTable(table);
	return true;	
}

// StudentScene
bool exportListScoreboardInSemesterOfStudent(const string& filename, Student& student, Semester& semester, string& outStr) {
	if (student.ptrClass == nullptr) {
		outStr = "Student with ID " + student.ID + " is not existed in any class!";
		return false;
	}
	if (filename.empty()) {
		outStr = "Empty InputBox error, please input something!";
		return false;
	}
	if (student.scoreboards.size() == 0) {
		outStr = "Student don't have any courses in courses list";
		return false;
	}
	string getStudentScoreboardListFile = getExportFolderPath() + filename + ".csv";
	
	std::ofstream fout(getStudentScoreboardListFile, std::ios::out);
	if (!fout.is_open()) {
		outStr = "Cannot open file " + getStudentScoreboardListFile + '!';
		return false;
	}
	Vector<Vector<string>> table = getTableContentOfScoreboardInSemesterOfStudent(student, semester);
	for (int i = 0; i < table.size(); ++i) {
		for (int j = 0; j < table[i].size(); ++j) {
			fout << table[i][j];
			if (j != table[i].size() - 1)
				fout << ',';
		}
		fout << std::endl;
	}
	fout.close();
	outStr = "Completely exported scoreboard in semester " + semester.semesterID + " of student to " + getStudentScoreboardListFile;
	removeTable(table);
	return true;
}