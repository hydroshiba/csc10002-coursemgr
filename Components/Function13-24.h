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
	outDev << "List of courses in this semester: ";
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

#endif 
