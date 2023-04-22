#include "UpdateFunction.h"
#include "FileAndDirFunction.h"
#include "DisplayFunction.h"
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

/*		Update function		*/

// Update course informations
void updateAcademicYear(AcademicYear &academuicYear, const std::string& newStartYear){
	academuicYear.start = (unsigned int)stoi(newStartYear);
}

void updateSchoolYear(SchoolYear &schoolYear, const std::string &newStartYear){
	schoolYear.start = (unsigned int)stoi(newStartYear);
}

void updateClass(Class &CLASS, const std::string &newClassName){
	CLASS.name = newClassName;
}

void updateSemester(Semester &semester, const std::string startDate, const std::string endDate){
	Date start, end;
	std::string day, month, year;
	std::stringstream ss(startDate);
	getline(ss, day, '/');
	getline(ss, month, '/');
	getline(ss, year);
	start.set((unsigned short)std::stoi(day), (unsigned short)std::stoi(month), (unsigned int)std::stoi(year));
	std::stringstream sstring(endDate);
	getline(sstring, day, '/');
	getline(sstring, month, '/');
	getline(sstring, year);
	end.set((unsigned short)std::stoi(day), (unsigned short)std::stoi(month), (unsigned int)std::stoi(year));
	semester.startDate = start;
	semester.endDate = end;
}

void updateCourse(Course& course, const std::string& courseID, const std::string& classID, const std::string& name, const std::string& teacher, const std::string& cre, const std::string& maxEn, const std::string& day, const std::string& ss) {
	Weekday weekday = string_to_weekday(day);
	Session session = string_to_session(ss);
	course.ID = courseID;
	course.classID = classID;
	course.name = name;
	course.teacher = teacher;
	course.credits = std::stoi(cre);
	course.maxEnroll = std::stoi(maxEn);
	course.weekday = weekday;
	course.session = session;
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