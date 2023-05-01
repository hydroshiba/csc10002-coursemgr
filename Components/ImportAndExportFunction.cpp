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