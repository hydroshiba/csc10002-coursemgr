#include "UpdateFunction.h"
#include "FileAndDirFunction.h"
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

/*		Update function		*/

// Update course informations
void updateCourse(Course& course) {
	int option;
	do {
		std::cout << "Update course informations:\n";
		std::cout << "0. Back\n";
		std::cout << "1. Change course id\n";
		std::cout << "2. Change teacher's name\n";
		std::cout << "3. Change course name\n";
		std::cout << "4. Change class id\n";
		std::cout << "5. Change number of credits\n";
		std::cout << "6. Change max students enrolled\n";
		std::cout << "7. Change session\n";
		std::cout << "Choose the following option 0-7: ";
		std::cin >> option;
		while (option < 0 || option > 7)
		{
			std::cout << "Invalid option, pls try again: ";
			std::cin >> option;
		}
		switch (option) {
		case 1:
			std::cout << "Enter Course ID: "; std::cin >> course.ID;
			break;
		case 2:
			std::cout << "Enter Teacher's Name: "; std::cin >> course.teacher;
			break;
		case 3:
			std::cout << "Enter Course Name: "; std::cin >> course.name;
			break;
		case 4:
			std::cout << "Enter Class ID: "; std::cin >> course.classID;
			break;
		case 5:
			std::cout << "Enter Number of Credits: "; std::cin >> course.credits;
			break;
		case 6:
			std::cout << "Enter Maximun students enrolled: "; std::cin >> course.maxEnroll;
			break;
		case 7:
			int in, day, ss;
			std::cout << "0. Change weekday\n";
			std::cout << "1. Change session\n";
			std::cin >> in;
			if (!in) {
				std::cout << "Enter weekday: "; std::cin >> day;
				course.weekday = static_cast<Weekday>(day);
			}
			else {
				std::cout << "Enter Session performed: "; std::cin >> ss;
				course.session = static_cast<Session>(ss);
			}
			break;
		default:
			std::cout << "Exit update course information!" << std::endl;
			break;
		}
	} while (option);
}
// 22. Update student result
void updateStudentResult(Student& student) {
	viewListOfCoursesOfStudent(student);
	const int nCourse = student.scoreboards.size();
	std::cout << "Choose the course to update result (1" << " - " << nCourse << "): ";
	int option;
	std::cin >> option;
	while (option < 1 || option > nCourse)
	{
		std::cout << "Invalid option, pls try again: ";
		std::cin >> option;
	}
	Scoreboard* updateSB = student.scoreboards[option - 1];
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
	} while (updateOption != 0);
}
// 19. export list of students in course to csv file
void exportListOfStudent(Course& course) {
	std::string inputStudCouseFilePath = getInputListStudCourseFilePath(course);
	std::ofstream ofs(inputStudCouseFilePath, std::ios::out);
	course.displayInfo(ofs);
	ofs << "No,ID,Fullname" << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		ofs << i + 1 << "," << student->ID << "," << student->name.get() << std::endl;
	}
	ofs.close();
}
// 20. import scoreboard of course
void importScoreBoardOfCourse(Course& course) {
	std::string inputScoreCourseFilePath = getInputScoreCourseFilePath(course);
	std::ifstream ifs(inputScoreCourseFilePath);
	if (!ifs.is_open())
	{
		std::cout << "Can't find file with path " << inputScoreCourseFilePath << std::endl;
		return;
	}
	course.importScoreBoards(ifs);
	std::cout << "Complete importion!" << std::endl;
	ifs.close();
}

//----------------------------------------------------------------------------------------------//