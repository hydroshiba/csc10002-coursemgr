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

bool updateStudentIn4(Student& student, const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& genderStr, const std::string& birthStr, const std::string& socialID, const std::string& password, std::string& outStr) {
	if (ID.empty() && firstName.empty() && lastName.empty() && genderStr.empty() && birthStr.empty() && socialID.empty() && password.empty()) {
		outStr = "Please enter the change information in at least one input box";
		return false;
	}
	if (!ID.empty()) {
		student.setID(ID);
	}
	if (!firstName.empty()) {
		student.setFirstName(firstName);
	}
	if (!lastName.empty()) {
		student.setLastName(lastName);
	}
	if (!genderStr.empty()) {
		Gender gender = string_to_gender(genderStr);
		student.setGender(gender);
	}
	if (!birthStr.empty()) {
		std::string dayStr, monthStr, yearStr;
		std::stringstream ss(birthStr);
		getline(ss, dayStr, '/');
		getline(ss, monthStr, '/');
		getline(ss, yearStr);

		unsigned short day = static_cast<unsigned short>(std::stoi(dayStr));
		unsigned short month = static_cast<unsigned short>(std::stoi(monthStr));
		unsigned int year = static_cast<unsigned int>(std::stoul(yearStr));
		Date birth(day, month, year);
		student.setBirth(birth);
	}
	if (!socialID.empty()) {
		student.setSocialID(socialID);
	}
	if (!password.empty()) {
		student.setPassword(password);
	}
	outStr = "Complete change information of student!";
	return true;
 }

bool updateStaffIn4(Staff& staff, const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password, std::string& outStr) {
	if (ID.empty() && firstName.empty() && lastName.empty() && password.empty()) {
		outStr = "Please enter the change information in at least one input box";
		return false;
	}
	if (!ID.empty()) {
		staff.setID(ID);
	}
	if (!firstName.empty()) {
		staff.setFirstName(firstName);
	}
	if (!lastName.empty()) {
		staff.setLastName(lastName);
	}
	if (!password.empty()) {
		staff.setPassword(password);
	}
	outStr = "Complete change information of staff!";
	return true;
}

void updateAcademicYear(AcademicYear &academicYear, const std::string& newStartYear){
	academicYear.start = (unsigned int)stoi(newStartYear);
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

bool updateCourse(Course& course, const std::string& courseID, const std::string& classID, const std::string& name, const std::string& teacher, const std::string& cre,const std::string& maxEnroll, const std::string& day, const std::string& ss, std::string &outStr) {
	if (courseID.empty() && classID.empty() && name.empty() && teacher.empty() && cre.empty() && day.empty() && ss.empty()){
		outStr = "All input boxes are empty, please try again!";
		return false;
	}

	if (!courseID.empty()) course.updateID(courseID);
	if (!classID.empty()) course.updateClassID(classID);
	if (!name.empty()) course.updateName(name);
	if (!teacher.empty()) course.updateTeacher(teacher);
	if (!cre.empty()) course.updateCredits(std::stoi(cre));
	if (!maxEnroll.empty()) course.updateMaxEnroll(std::stoi(maxEnroll));
	if (!day.empty()) course.updateWeekday(string_to_weekday(day));
	if (!ss.empty()) course.updateSession(string_to_session(ss));
	outStr = "Successfully update course information!";
	return true;
}
// 22. Update student result
void updateStudentResult(Course &course, const std::string studentID, const std::string midTerm, const std::string other, const std::string finalScore, const std::string totalScore) {
	Scoreboard *ptrScoreboard = course.getScoreboard(studentID);
	float mid, others, final, total;
	mid = std::stof(midTerm);
	others = std::stof(other);
	final = std::stof(finalScore);
	total = std::stof(totalScore);
	ptrScoreboard->midterm = mid;
	ptrScoreboard->final = final;
	ptrScoreboard->other = others;
	ptrScoreboard->total = total;
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