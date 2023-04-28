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

void downloadAllData(const Vector<Staff>& staffs, Vector <Student>& students, Vector <SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears) {
	downloadListStudent(students);
	downloadListStaff(staffs);
	downloadListSchoolYearFolder(schoolYears);
	downloadListAcademicYearFolder(academicYears);
}

void downloadListStudent(Vector<Student>& students){
	std::string list_stud_dir = getListStudentFilePath();
	std::ofstream ofs(list_stud_dir);
	ofs << "ID,Password,First name,Last name,Gender,Dob,SocialID\n";
	for (int i = 0; i < students.size(); ++i){
		ofs << students[i].ID << ",";
		ofs << students[i].getHashedPass() << ",";
		ofs << students[i].name.first << ",";
		ofs << students[i].name.last << ",";
		ofs << gender_to_string(students[i].gender) << ",";
		ofs << students[i].birth.get() << ",";
		ofs << students[i].socialID << '\n';
	}
	ofs.close();
}

void downloadListStaff(const Vector<Staff>& staffs){
	std::string list_staff_dir = getListStaffFilePath();
	std::ofstream ofs(list_staff_dir);
	ofs << "Number of staffs,";
	size_t nStaffs = staffs.size();
	ofs << nStaffs << std::endl;
	ofs << "No,First name,Last name,Staff ID,Password\n";
	for (int i = 0; i<nStaffs; ++i){
		ofs << (i + 1) << "," <<  staffs[i].name.first << "," << staffs[i].name.last << ","  << staffs[i].ID << "," << staffs[i].getHashedPass() << std::endl;
	}
	ofs.close();
}

void downloadListSchoolYearFolder(Vector <SchoolYear>& schoolYears) {
	std::string listSchoolYearDir = getListSchoolYearFilePath();
	std::ofstream ofs(listSchoolYearDir);
	/*if (!ofs.is_open()){
		std::cout << "Cannot open " << listSchoolYearDir << '\n';
		return;
	}*/
	ofs << schoolYears.size() << '\n';
	for (int i = 0; i < schoolYears.size(); ++i) {
		ofs << schoolYears[i].start << '\n';
		downloadSchoolYearFolder(schoolYears[i]);
	}
	ofs.close();
}

void downloadSchoolYearFolder(SchoolYear& schoolYear) {
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
		downloadOutputStudClassFile(schoolYear.classes[i]);
	}
	ofs.close();
}

void downloadOutputStudClassFile(Class& actClass) {
	std::string outputStudentDir = getOutputStudClassFilePath(actClass);
	std::ofstream ofs(outputStudentDir);
	ofs << "Class," << actClass.name << '\n';
	ofs << "Number of student," << actClass.students.size();
	ofs << "No,StudentID,First name,Last name,Gender,Date of Birth,SocialID\n";
	for (int i = 0; i < actClass.students.size(); ++i) {
		ofs << i + 1 << ",";
		ofs << actClass.students[i]->ID << ",";
		ofs << actClass.students[i]->name.first << "," << actClass.students[i]->name.last << ",";
		ofs << gender_to_string(actClass.students[i]->gender) << ",";
		ofs << actClass.students[i]->birth.day << "/" << actClass.students[i]->birth.month << "/" << actClass.students[i]->birth.year << ",";
		ofs << actClass.students[i]->socialID << "\n";
	}
	ofs.close();
}

void downloadStudentFolder(Student& student) {
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
}

void downloadListAcademicYearFolder(Vector<AcademicYear>& academicYears) {
	std::string listAcademicYearFilePath = getListAcademicYearFilePath();
	std::ofstream ofs(listAcademicYearFilePath);
	ofs << academicYears.size() << std::endl;
	for (int i = 0; i < academicYears.size(); i++)
	{
		ofs << academicYears[i].start << std::endl;
		downloadAcademicYearFolder(academicYears[i]);
	}
	ofs.close();
}

void downloadAcademicYearFolder(AcademicYear& academicYear) {
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
}

void downloadSemesterFolder(Semester& semester) {
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
		downloadCourseFolder(semester.courses[i]);
		dowdloadScoreboardFile(semester.courses[i]);
	}
	ofs.close();
}

void downloadCourseFolder(Course& course) {
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
}

void dowdloadScoreboardFile(Course& course) {
	std::string scoreBoardFilePath = getOutputScoreStudCourseFilePath(course);
	std::ofstream ofs(scoreBoardFilePath);
	course.displayScoreBoardFile(ofs);
	ofs.close();
}