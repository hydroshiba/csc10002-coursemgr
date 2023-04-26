#include "DisplayFunction.h"

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

/*		Display function	*/
Vector<std::string> getListSchoolYear(Vector<SchoolYear>& schoolYears) {
	Vector<std::string> listSY(schoolYears.size());
	for (int i = 0; i < listSY.size(); i++){
		listSY[i] = std::to_string(schoolYears[i].start);
	}
	return listSY;
}

Vector<std::string> getListAcademicYear(Vector<AcademicYear>& academicYears) {
	Vector<std::string> listAYs(academicYears.size());
	for (int i = 0; i < listAYs.size(); i++) {
		listAYs[i] = std::to_string(academicYears[i].start);
	}
	return listAYs;
}

Vector<std::string> getListClass(const SchoolYear& schoolYear) {
	Vector<std::string> listClass(schoolYear.classes.size());
	for (int i = 0; i < schoolYear.classes.size(); i++) {
		listClass[i] = schoolYear.classes[i].name;
	}
	return listClass;
}

Vector<std::string> getListSemester(const AcademicYear& academicYear) {
	Vector<std::string> listSemester(academicYear.semesters.size());
	for (int i = 0; i < academicYear.semesters.size(); i++) {
		listSemester[i] = academicYear.semesters[i].semesterID;
	}
	return listSemester;
}

Vector<std::string> getListCourse(const Semester& semester) {
	Vector<std::string> listCourse(semester.courses.size());
	for (int i = 0; i < semester.courses.size(); i++) {
		listCourse[i] = semester.courses[i].ID;
	}
	return listCourse;
}

Vector<Vector<std::string>> getTableContentOfScoreboardsofStudent(const Student& student) {
	Vector<Vector<std::string>> table(student.scoreboards.size() + 1);
	for (int i = 0; i < table.size(); i++) {
		table[i].resize(7);
	}
	table[0][0] = "No";
	table[0][1] = "CourseID";
	table[0][2] = "SemesterID";
	table[0][3] = "Midterm";
	table[0][4] = "Final";
	table[0][5] = "Other";
	table[0][6] = "Total";
	for (int i = 0; i < student.scoreboards.size(); i++) {
		table[i + 1][0] = std::to_string(i + 1);
		table[i + 1][1] = student.scoreboards[i]->ptrCourse->ID;
		table[i + 1][2] = student.scoreboards[i]->ptrCourse->ptrSemester->semesterID;
		table[i + 1][3] = student.scoreboards[i]->midterm;
		table[i + 1][4] = student.scoreboards[i]->final;
		table[i + 1][5] = student.scoreboards[i]->other;
		table[i + 1][6] = student.scoreboards[i]->total;
	}
	return table;
}



// View list of courses
void viewCourses(Semester& sem, std::ostream& outDev) {
	std::cout << "List of courses: ";
	for (size_t i = 0; i < sem.courses.size(); ++i)
		sem.courses[i].displayInfo(outDev);
}
// 14. view list of courses at current student
void viewListOfCoursesOfStudent(const Student& student, std::ostream& outDev) {
	outDev << "List of courses: ";
	for (int i = 0; i < student.scoreboards.size(); i++)
	{
		outDev << "No " << i + 1 << ": " << std::endl;
		student.scoreboards[i]->ptrCourse->displayInfoScreen();
		outDev << "--------------------------------------" << std::endl;
	}
}
// 15. view list of classes 
void viewListOfClasses(const SchoolYear& schoolYear, std::ostream& outDev) {
	outDev << "List of classes: " << std::endl;
	for (int i = 0; i < schoolYear.classes.size(); i++)
		outDev << i + 1 << ". " << schoolYear.classes[i].name << std::endl;
}
// 16. view list of students in a class
void viewListOfStudentsInClass(const Class& curClass, std::ostream& outDev) {
	outDev << "List of students in class " << curClass.name << ": " << std::endl;
	for (int i = 0; i < curClass.students.size(); i++)
	{
		outDev << i + 1 << ". " << curClass.students[i]->ID << " - " << curClass.students[i]->name.get();
		outDev << std::endl;
	}
}
// 17. view list of course
void viewListOfCoursesInSemester(const Semester& semester, std::ostream& outDev) {
	outDev << "List of course in this semester: " << std::endl;
	outDev << "No  " << "CourseID   " << "ClassID   " << std::endl;
	for (int i = 0; i < semester.courses.size(); i++)
	{
		outDev << "No " << i + 1 << ": " << std::endl;
		semester.courses[i].displayInfo(outDev);
	}
}
// 18. view list of students in course
void viewListOfStudentsInCourse(const Course& course, std::ostream& outDev) {
	outDev << "List of students in course " << course.ID << " - " << course.name << ": " << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		outDev << i + 1 << ". " << student->ID << " - " << student->name.get() << std::endl;
	}
}
// 21. view scoreboard of course
void viewScoreBoardOfCourse(Course& course) {
	std::cout << "1. View on screen" << std::endl;
	std::cout << "2. View on file" << std::endl;
	std::cout << "Choose one of following options to view: ";
	int option;
	std::cin >> option;
	while (option <= 0 || option > 2)
	{
		std::cout << "Invalid option! Pls input 1 or 2: ";
		std::cin >> option;
	}
	switch (option)
	{
	case 1:
	{
		course.displayScoreBoardScreen();
		break;
	}
	case 2:
	{
		std::cout << "Input filename: ";
		std::string fileName;
		std::getline(std::cin, fileName, '\n');
		fileName = "Data\\" + fileName;
		std::ofstream ofs(fileName);
		if (!ofs.is_open())
		{
			std::cout << "Can't find file with that name, pls try again!" << std::endl;
			return;
		}
		course.displayScoreBoardFile(ofs);
		break;
	}
	}
}
// 23. View scoreboard of class
void viewScoreboardOfClass(Class& curClass, const Semester& curSemester) {
	std::cout << "1. View on screen" << std::endl;
	std::cout << "2. View on file" << std::endl;
	std::cout << "Choose one of following options to view: ";
	int option;
	std::cin >> option;
	while (option <= 0 || option > 2)
	{
		std::cout << "Invalid option! Pls input 1 or 2: ";
		std::cin >> option;
	}
	switch (option)
	{
	case 1:
	{
		curClass.displayScoreboardScreen(curSemester);
		break;
	}
	case 2:
	{
		std::cout << "Input filename: ";
		std::string fileName;
		std::getline(std::cin, fileName, '\n');
		fileName = "Data\\" + fileName;
		std::ofstream ofs(fileName);
		if (!ofs.is_open())
		{
			std::cout << "Can't find file with that name, pls try again!" << std::endl;
			return;
		}
		curClass.displayScoreboardFile(curSemester, ofs);
		break;
	}
	}
}
// 24. view scoreboard of student
void viewScoreBoardOfStudent(Student& student) {
	const int noMaxLength = 3;
	const int idSemesterMaxLength = 10;
	const int idCourseNameMaxLength = 20;
	const int midtermMaxLength = 10;
	const int finalMaxLength = 8;
	const int totalMaxLength = 8;
	const int otherMaxLength = 8;
	std::cout << std::setw(noMaxLength) << std::left << "No";
	std::cout << std::setw(idSemesterMaxLength) << std::left << "Semester";
	std::cout << std::setw(idCourseNameMaxLength) << std::left << "Course";
	std::cout << std::setw(midtermMaxLength) << std::left << "Midterm";
	std::cout << std::setw(finalMaxLength) << std::left << "Final";
	std::cout << std::setw(otherMaxLength) << std::left << "Other";
	std::cout << std::setw(totalMaxLength) << std::left << "Total";
	std::cout << std::endl;
	for (int i = 0; i < student.scoreboards.size(); i++)
	{
		std::cout << std::setw(noMaxLength) << std::left << i + 1;
		std::cout << std::setw(idSemesterMaxLength) << std::left << student.scoreboards[i]->ptrCourse->ptrSemester->semesterID;
		std::cout << std::setw(idCourseNameMaxLength) << std::left << student.scoreboards[i]->ptrCourse->ID;
		std::cout << std::setw(midtermMaxLength) << std::left << student.scoreboards[i]->midterm;
		std::cout << std::setw(finalMaxLength) << std::left << student.scoreboards[i]->final;
		std::cout << std::setw(otherMaxLength) << std::left << student.scoreboards[i]->other;
		std::cout << std::setw(totalMaxLength) << std::left << student.scoreboards[i]->total;
		std::cout << std::endl;
	}
	std::cout << std::setw(noMaxLength) << std::left << "GPA:" << student.getGPA() << std::endl;
}

//----------------------------------------------------------------------------------------------//