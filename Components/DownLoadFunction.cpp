#include "DownLoadFunction.h"
#include "FileAndDirFunction.h"
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

#include "SortFunction.h"

bool downloadAllData() {
	bool b1 = downloadListStudent();
	bool b2 = downloadListStaff();
	bool b3 = downloadListSchoolYearFolder();
	//bool b4 = downloadListAcademicYearFolder(academicYears);
	return (b1 && b2 && b3);
}

bool downloadListStudent(){
	sortStudentList(students, 0, students.size() - 1);
	std::string list_stud_dir = getListStudentFilePath();
	std::ofstream ofs(list_stud_dir);
	ofs << "Number of students," << std::to_string(students.size()) << std::endl;
	ofs << "No,ID,Password,First name,Last name,Gender,Dob,SocialID\n";
	for (int i = 0; i < students.size(); ++i){
		ofs << i + 1 << ",";
		ofs << students[i].ID << ",";
		ofs << std::to_string(students[i].getHashedPass()) << ",";
		ofs << students[i].name.first << ",";
		ofs << students[i].name.last << ",";
		ofs << gender_to_string(students[i].gender) << ",";
		ofs << students[i].birth.get() << ",";
		ofs << students[i].socialID << '\n';
	}
	ofs.close();
	return true;
}

bool downloadListStaff(){
	sortStaffList(staffs, 0, staffs.size() - 1);
	std::string list_staff_dir = getListStaffFilePath();
	std::ofstream ofs(list_staff_dir);
	ofs << "Number of staffs,";
	size_t nStaffs = staffs.size();
	ofs << nStaffs << std::endl;
	ofs << "No,First name,Last name,Staff ID,Password\n";
	for (int i = 0; i<nStaffs; ++i){
		ofs << (i + 1) << "," <<  staffs[i].name.first << "," << staffs[i].name.last << ","  << staffs[i].ID << "," << std::to_string(staffs[i].getHashedPass()) << std::endl;
	}
	ofs.close();
	return true;
}

bool downloadListSchoolYearFolder() {
	std::string listSchoolYearDir = getListSchoolYearFilePath();
	std::ofstream ofs(listSchoolYearDir);
	ofs << "Number of SchoolYears, " << schoolYears.size() << '\n';
	ofs << "No, SchoolYear\n";
	for (int i = 0; i < schoolYears.size(); ++i) {
		ofs << std::to_string(i + 1) << ", " << std::to_string(schoolYears[i].start) << '\n';
		//downloadSchoolYearFolder(schoolYears[i]);
	}
	ofs.close();
	return true;
}

bool downloadSchoolYearFolder(SchoolYear& schoolYear) {
	std::string schoolYearDir = getInputSchoolYearFilePath(schoolYear);
	std::ofstream ofs(schoolYearDir);
	/*if (!ofs.is_open()){
		std::cout << "Cannot open " << schoolYearDir;
		return;
	}*/
	ofs << schoolYear.start << '\n';
	ofs << schoolYear.classes.size() << '\n';
	for (int i = 0; i < schoolYear.classes.size(); ++i) {
		ofs << schoolYear.classes[i].name;
		downloadDataStudClassFile(schoolYear.classes[i]);
	}
	ofs.close();
	return true;
}
// Download student id
bool downloadDataStudClassFile(Class& actClass) {
	std::string outputStudentDir = getDataStudClassFilePath(actClass);
	std::ofstream ofs(outputStudentDir);
	ofs << actClass.name << std::endl;
	ofs << actClass.students.size() << std::endl;
	for (int i = 0; i < actClass.students.size(); ++i) {
		ofs << actClass.students[i]->ID << std::endl;
	}
	ofs.close();
	return true;
}

bool downloadStudentFolder(Student& student) {
	std::string studentDir = getInputStandardIn4StudentFilePath(student);
	std::ofstream ofs(studentDir);
	/*if (!ofs.is_open()){
		std::cout << "Cannot open " << studentDir;
		return;
	}*/
	ofs << "ID," << student.ID << std::endl;
	ofs << "Name," << student.name.get() << std::endl;
	ofs << "Gender," << gender_to_string(student.gender) << std::endl;
	ofs << "Dob," << student.birth.get() << std::endl;
	ofs << "SocialID," << student.socialID << std::endl;
	ofs << "Class," << student.ptrClass->name << std::endl;
	ofs.close();
	return true;
}

bool downloadListAcademicYearFolder(Vector<AcademicYear>& academicYears) {
	std::string listAcademicYearFilePath = getListAcademicYearFilePath();
	std::ofstream ofs(listAcademicYearFilePath);
	ofs << academicYears.size() << std::endl;
	for (int i = 0; i < academicYears.size(); i++)
	{
		ofs << academicYears[i].start << std::endl;
		downloadAcademicYearFolder(academicYears[i]);
	}
	ofs.close();
	return true;
}

bool downloadAcademicYearFolder(AcademicYear& academicYear) {
	std::string academicYearFilePath = getAcademicYearFilePath(academicYear);
	std::ofstream ofs(academicYearFilePath);
	ofs << academicYear.start << std::endl;
	ofs << academicYear.semesters.size() << std::endl;
	for (int i = 0; i < academicYear.semesters.size(); i++)
	{
		ofs << academicYear.semesters[i].semesterID << std::endl;
		downloadSemesterFolder(academicYear.semesters[i]);
	}
	ofs.close();
	return true;
}

bool downloadSemesterFolder(Semester& semester) {
	std::string semesterFilePath = getSemesterFilePath(semester);
	std::ofstream ofs(semesterFilePath);
	ofs << semester.semesterID << std::endl;
	ofs << semester.startDate.day << "/" << semester.startDate.month << "/" << semester.startDate.year << std::endl;
	ofs << semester.endDate.day << "/" << semester.endDate.month << "/" << semester.endDate.year << std::endl;
	ofs << semester.courses.size() << std::endl;
	for (int i = 0; i < semester.courses.size(); i++)
		ofs << semester.courses[i].ID << std::endl;
	for (int i = 0; i < semester.courses.size(); i++)
	{
		// downloadCourseFolder(semester.courses[i]);
		dowdloadScoreboardFile(semester.courses[i]);
	}
	ofs.close();
	return true;
}

bool downloadCourseFolder(Course& course) {
	std::string courseFilePath = getCourseFilePath(course);
	std::ofstream ofs(courseFilePath);
	ofs << course.ID << std::endl;
	ofs << course.classID << std::endl;
	ofs << course.name << std::endl;
	ofs << course.teacher << std::endl;
	ofs << course.credits << std::endl;
	ofs << course.maxEnroll << std::endl;
	ofs << course.weekday << std::endl;
	ofs << course.session << std::endl;
	ofs.close();
	return true;
}

bool dowdloadScoreboardFile(Course& course) {
	std::string scoreBoardFilePath = getOutputScoreStudCourseFilePath(course);
	std::ofstream ofs(scoreBoardFilePath);
	ofs << "Course ID," << course.ID << std::endl;
	ofs << "Class ID," << course.classID << std::endl;
	ofs << "Course name," << course.name << std::endl;
	ofs << "Teacher," << course.teacher << std::endl;
	ofs << "Number of credits," << course.credits << std::endl;
	ofs << "Max enrolled," << course.maxEnroll << std::endl;
	ofs << "Weekday," << weekday_to_string(course.weekday) << std::endl;
	ofs << "Session," << session_to_string(course.session) << std::endl;
	ofs << "Students," << course.scoreboards.size() << std::endl;
	course.displayScoreBoardFile(ofs);
	ofs.close();
	return true;
}
