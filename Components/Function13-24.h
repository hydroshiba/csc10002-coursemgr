#ifndef FUNCTION_PART2_H
#define FUNCTION_PART2_H

#include "Components.h"
#include "SchoolYear.h"
#include "Class.h"
#include "Semester.h"
#include "Course.h"

//delete course in current semester 
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

// view list of courses at current student
void viewListOfCourses(const Student& student) {
	std::cout << "List of courses in this semester: ";
	for (int i = 0; i < student.scoreboards.size(); i++)
	{
		student.scoreboards[i]->ptrCourse->display();
		std::cout << "--------------------------------------" << std::endl;
	}
}

// view list of classes 
void viewListOfClasses(const SchoolYear& schoolYear) {
	std::cout << "List of classes: " << std::endl;
	for (int i = 0; i < schoolYear.classes.size(); i++)
		std::cout << i + 1 << ". " << schoolYear.classes[i].name << std::endl;
} 

// view list of students in a class
void viewListOfStudentsInClass(const Class& curClass) {
	std::cout << "List of students in class " << curClass.name << ": " << std::endl;
	for (int i = 0; i < curClass.students.size(); i++)
	{
		std::cout << i + 1 << ". " << curClass.students[i].ID << " - " << curClass.students[i].name.get();
		std::cout << std::endl;
	}
}

// view list of students in course
void viewListOfStudentsInCourse(const Course& course) {
	std::cout << "List of students in course " << course.ID << " - " << course.name << ": " << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		std::cout << i + 1 << ". " << student->ID << " - " << student->name.get() << std::endl;
	}
}

#endif 
