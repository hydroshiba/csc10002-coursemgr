#ifndef FUNCTION_PART2_H
#define FUNCTION_PART2_H

#include "Components.h"
#include "SchoolYear.h"
#include "Class.h"
#include "Semester.h"
#include "Course.h"
#include "Scoreboard.h"

// 13. delete course in current semester 
bool deleteCourse(Semester& semester, const std::string& courseID) {
	bool found = false;
	Course* course = nullptr;
	for (int i = 0; i < semester.courses.size(); i++)
		if (semester.courses[i].ID == courseID)
		{
			found = true;
			course = &semester.courses[i];
			break;
		}
	if (!found)
		std::cout << "Can't find a course with ID " << courseID;
	else
	{
		course->ptrSemester = nullptr;
		for (int i = 0; i < course->scoreboards.size(); i++)
		{
			Student* student = course->scoreboards[i]->ptrStudent; 
			student->scoreboards.remove(course->scoreboards[i]); // delete link from student->scoreboard
			course->scoreboards[i]->ptrStudent = nullptr; // delete link sb->student
			course->scoreboards[i]->ptrCourse = nullptr; // delete link sb->course
			delete course->scoreboards[i]; // delete scoreboard
		}
		semester.removeCourse(course); // delete course
		std::cout << "Course with ID " << courseID << " have been removed from semester!";
	}
	std::cout << std::endl;
}

// 14. view list of courses at current student
void viewListOfCoursesOfStudent(const Student& student, std::ostream& outDev = std::cout) {
	outDev << "List of courses: ";
	for (int i = 0; i < student.scoreboards.size(); i++)
	{
		outDev << "No " << i + 1 << ": " << std::endl;
		student.scoreboards[i]->ptrCourse->displayInfoScreen();
		outDev << "--------------------------------------" << std::endl;
	}
}

// 15. view list of classes 
void viewListOfClasses(const SchoolYear& schoolYear, std::ostream& outDev = std::cout) {
	outDev << "List of classes: " << std::endl;
	for (int i = 0; i < schoolYear.classes.size(); i++)
		outDev << i + 1 << ". " << schoolYear.classes[i].name << std::endl;
} 

// 16. view list of students in a class
void viewListOfStudentsInClass(const Class& curClass, std::ostream& outDev = std::cout) {
	outDev << "List of students in class " << curClass.name << ": " << std::endl;
	for (int i = 0; i < curClass.students.size(); i++)
	{
		outDev << i + 1 << ". " << curClass.students[i].ID << " - " << curClass.students[i].name.get();
		outDev << std::endl;
	}
}

// 17. view list of course
void viewListOfCoursesInSemester(const Semester& semester, std::ostream& outDev = std::cout) {
	outDev << "List of course in this semester: " << std::endl;
	outDev << "No  " << "CourseID   " << "ClassID   " << std::endl;
	for (int i = 0; i < semester.courses.size(); i++)
	{
		outDev << "No " << i + 1 << ": " << std::endl;
		semester.courses[i].displayInfo(outDev);
	}
}

// 18. view list of students in course
void viewListOfStudentsInCourse(const Course& course, std::ostream& outDev = std::cout) {
	outDev << "List of students in course " << course.ID << " - " << course.name << ": " << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		outDev << i + 1 << ". " << student->ID << " - " << student->name.get() << std::endl;
	}
}

// 19. export list of students in course to csv file
void exportListOfStudent(const Course& course, const std::string& fileName) {
	std::ofstream ofs(fileName, std::ios::out);
	course.display(ofs);
	ofs << "No,ID,Fullname" << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		ofs << i + 1 << "," << student->ID << "," << student->name << std::endl;
	}
	ofs.close();
}
 
// 20. import scoreboard of course
void importScoreBoardOfCourse(Course& course) {
	std::cout << "Input filename: ";
	std::string fileName;
	std::getline(std::cin, fileName, '\n');
	fileName = "Data\\" + fileName;
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cout << "Can't find file with that name, pls try again!" << std::endl;
		return;
	}
	course.importScoreBoards(ifs);
	std::cout << "Complete importion!" << std::endl;
	ifs.close();
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

// 22. Update student result
void updateStudentResult(Student& student) {
	viewListOfCoursesOfStudent(student);
	const int nCourse = student.scoreboards.size();
	std::cout << "Choose the course to update result (1" << << " - " << nCourse << "): ";
	int option;
	std::cin >> option;
	while (option < 1 || option > nCourse)
	{
		std::cout << "Invalid option, pls try again: ";
		std::cin >> option;
	}
	Scoreboard* updateSB = &student.scoreboards[option - 1];
	int updateOption;
	do
	{
		std::cout << "1. Midterm" << std::endl;
		std::cout << "2. Final" << std::endl;
		std::cout << "3. Other" << std::endl;
		std::cout << "4. Total" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "Choose the following option (0 - 4): ";
		std::cin >> updateOption;
		while (updateOption < 0 || updateOption > 4)
		{
			std::cout << "Invalid option, pls try again: ";
			std::cin >> updateOption;
		}
		if (updateOption == 0)
		{
			std::cout << "Finish update result!";
			return;
		}
		int updateScore;
		switch (updateOption)
		{
		case 1:
		{
			std::cout << "Input updated midterm score: ";
			std::cin >> updateScore;
			updateSB->midterm = updateScore;
			break;
		}
		case 2:
		{
			std::cout << "Input updated final score: ";
			std::cin >> updateScore;
			updateSB->final = updateScore;
			break;
		}
		case 3:
		{
			std::cout << "Input updated other score: ";
			std::cin >> updateScore;
			updateSB->other = updateScore;
			break;
		}
		case 4:
		{
			std::cout << "Input updated total score: ";
			std::cin >> updateScore;
			updateSB->total = updateScore;
			break;
		}
		}
	} while (updateOption != 0)
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
}

#endif 
