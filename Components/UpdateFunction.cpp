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

bool updateStudentIn4(Student& student, const string& ID, const string& firstName, const string& lastName, const string& genderStr, const string& birthStr, const string& socialID, const string& password, string& outStr) {
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
		string dayStr, monthStr, yearStr;
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

bool updateStaffIn4(Staff& staff, const string& ID, const string& firstName, const string& lastName, const string& password, string& outStr) {
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

bool updateSchoolYear(SchoolYear &schoolYear, const string &newStartYear, string& outStr){
	if (newStartYear.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	outStr = "Successfully changed start year of schoolyear from " + std::to_string(schoolYear.start) + " to " + newStartYear;
	schoolYear.start = static_cast<unsigned int>(std::stoul(newStartYear));
	return true;
}

bool updateClass(Class &CLASS, const string &newClassName, string& outStr){
	if (newClassName.empty()) {
		outStr = "Please enter the new class name in InputBox!";
		return false;
	}
	outStr = "Successfully changed class name of class from " + CLASS.name + " to " + newClassName;
	CLASS.name = newClassName;
	return true;
}

bool updateAcademicYear(AcademicYear& academicYear, const string& newStartYear, string& outStr) {
	if (newStartYear.empty()) {
		outStr = "Please enter the new starting year in InputBox!";
		return false;
	}
	outStr = "Successfully changed start year of academicyear from " + std::to_string(academicYear.start) + " to " + newStartYear;
	academicYear.start = static_cast<unsigned int>(std::stoul(newStartYear));
	return true;
}

bool updateSemester(Semester &semester, const string startDate, const string endDate, string& outStr){
	if (startDate.empty() && endDate.empty()) {
		outStr = "Please input new date in at least one InputBox!";
		return false;
	}
	Date start, end;
	string day, month, year;
	if (!startDate.empty()) {
		std::stringstream ss(startDate);
		getline(ss, day, '/');
		getline(ss, month, '/');
		getline(ss, year);
		start.set((unsigned short)std::stoi(day), (unsigned short)std::stoi(month), (unsigned int)std::stoi(year));

	}	
	if (!endDate.empty()) {	
		std::stringstream sstring(endDate);
		getline(sstring, day, '/');
		getline(sstring, month, '/');
		getline(sstring, year);
		end.set((unsigned short)std::stoi(day), (unsigned short)std::stoi(month), (unsigned int)std::stoi(year));
	}
	semester.startDate = start;
	semester.endDate = end;
	outStr = "Successfully changed start date and end date of semester " + semester.semesterID;
	return true;
}

bool updateCourse(Course& course, const string& courseID, const string& classID, const string& name, const string& teacher, const string& cre,const string& maxEnroll, const string& day, const string& ss, string &outStr) {
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

bool updateScoreboard(Course &course, const string& studentID, const string& midTerm, const string& other, const string& finalScore, const string& totalScore, string& outStr) {
	if (studentID.empty()) {
		outStr = "Pls input studentID to update result";
		return false;
	}
	if (midTerm.empty() && other.empty() && finalScore.empty() && totalScore.empty()) {
		outStr = "All input boxes of new score are empty, please try again!";
		return false;
	}
	Scoreboard *ptrScoreboard = course.getScoreboard(studentID);
	float mid, others, final, total;
	if (!midTerm.empty()) {
		mid = std::stof(midTerm);
		ptrScoreboard->midterm = mid;
	}
	if (!other.empty()) {
		others = std::stof(other);
		ptrScoreboard->final = final;
	}
	if (!finalScore.empty()) {
		final = std::stof(finalScore);
		ptrScoreboard->other = others;
	}
	if (!totalScore.empty()) {
		total = std::stof(totalScore);
		ptrScoreboard->total = total;
	}
	outStr = "Successfully update result of student " + studentID + " in course " + course.ID;
	return true;
}


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
}
// 20. import scoreboard of course
bool importScoreBoardOfCourse(Course& course) {
	string inputScoreCourseFilePath = getInputScoreCourseFilePath(course);
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