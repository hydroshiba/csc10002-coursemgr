#ifndef FUNCTION_PART2_H
#define FUNCTION_PART2_H

#include "Components.h"
#include "SchoolYear.h"
#include "Class.h"
#include "Semester.h"
#include "Course.h"

// 13. delete course in current semester 
bool deleteACourse(Semester& semester, const std::string& courseID) {
	bool found = false;
	Course course;
	for (int i = 0; i < semester.courses.size(); i++)
		if (semester.courses[i].ID == courseID)
		{
			found = true;
			course = semester.courses[i];
			break;
		}
	if (!found)
		std::cout << "Can't find a course with ID " << courseID;
	else
	{
		semester.removeCourse(course);
		std::cout << "Course with ID " << courseID << " have been removed from semester!";
	}
	std::cout << std::endl;
}

// 14. view list of courses at current student
void viewListOfCourses(const Student& student, std::ostream& outDev = std::cout) {
	outDev << "List of courses in this semester: ";
	for (int i = 0; i < student.scoreboards.size(); i++)
	{
		student.scoreboards[i]->ptrCourse->display();
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
void viewListOfCourse(const Semester& semester, std::ostream& outDev = std::cout) {
	outDev << "List of course in this semester: " << std::endl;
	outDev << "No  " << "CourseID   " << "ClassID   " << std::endl;
	for (int i = 0; i < semester.courses.size(); i++)
	{
		outDev << "No " << i + 1 << ": " << std::endl;
		semester.courses[i].display(outDev);
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
 
#endif 
