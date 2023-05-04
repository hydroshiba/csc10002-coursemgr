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
#include "RemoveFunction.h"

bool downloadAllData() {
	bool b1 = downloadListStudent();
	bool b2 = downloadListStaff();
	bool b3 = downloadListSchoolYear();
	bool b4 = downloadListAcademicYear();
	if (b1 && b2 && b3 && b4 == false) {
		freeMemory();
		return false;
	}
	return true;
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

bool downloadListSchoolYear() {
	std::string listSchoolYearDir = getListSchoolYearFilePath();
	std::ofstream ofs(listSchoolYearDir);
	if (!ofs) {
		std::cout << "Can't open " << listSchoolYearDir << std::endl;
		return false;
	}
	ofs << "Number of SchoolYears, " << schoolYears.size() << '\n';
	ofs << "No, SchoolYear\n";
	for (int i = 0; i < schoolYears.size(); ++i) {
		ofs << std::to_string(i + 1) << ", " << std::to_string(schoolYears[i].start) << '\n';
		downloadSchoolYear(schoolYears[i]);
	}
	ofs.close();
	return true;
}

bool downloadSchoolYear(SchoolYear& schoolYear) {
	std::string schoolYearDir = getSchoolYearFilePath(schoolYear);
	std::ofstream ofs(schoolYearDir);
	if (!ofs.is_open()){
		std::cout << "Cannot open " << schoolYearDir;
		return false;
	}
	ofs << "Startyear, " << schoolYear.start << '\n';
	ofs << "Number of classes, " << schoolYear.classes.size() << '\n';
	ofs << "No, Class\n";
	for (int i = 0; i < schoolYear.classes.size(); ++i) {
		ofs << std::to_string(i + 1) << ", " << schoolYear.classes[i].name << "\n";
		downloadClass(schoolYear.classes[i]);
	}
	ofs.close();
	return true;
}

bool downloadClass(Class& CLASS) {
	string classFilePath = getClassFilePath(CLASS);
	std::ofstream ofs(classFilePath);
	if (!ofs) {
		std::cout << "Can't open " << classFilePath << std::endl;
		return false;
	}
	ofs << "Classname, " << CLASS.name << std::endl;
	ofs << "Number of students, " << CLASS.students.size() << std::endl;
	ofs << "No, StudentID\n";
	for (int i = 0; i < CLASS.students.size(); i++) {
		ofs << std::to_string(i + 1) << ", " << CLASS.students[i]->ID << std::endl;
	}
	ofs.close();
	return true;
}

bool downloadListAcademicYear() {
	std::string listAcademicYearFilePath = getListAcademicYearFilePath();
	std::ofstream ofs(listAcademicYearFilePath);
	if (!ofs) {
		std::cout << "Can't open " << listAcademicYearFilePath << std::endl;
		return false;
	}
	ofs << "Number of AcademicYears, " << academicYears.size() << std::endl;
	ofs << "No, AcademicYear\n";
	for (int i = 0; i < academicYears.size(); i++){
		ofs << std::to_string(i + 1) << academicYears[i].start << std::endl;
		downloadAcademicYear(academicYears[i]);
	}
	ofs.close();
	return true;
}

bool downloadAcademicYear(AcademicYear& academicYear) {
	std::string academicYearFilePath = getAcademicYearFilePath(academicYear);
	std::ofstream ofs(academicYearFilePath);
	if (!ofs) {
		std::cout << "Can't open " << academicYearFilePath << std::endl;
		return false;
	}
	ofs << "Start year, " << academicYear.start << std::endl;
	ofs << "Number of semesters, " << academicYear.semesters.size() << std::endl;
	ofs << "No, SemesterID\n";
	for (int i = 0; i < academicYear.semesters.size(); i++){
		ofs << std::to_string(i + 1) << ", " << academicYear.semesters[i].semesterID << std::endl;
		downloadSemester(academicYear.semesters[i]);
	}
	ofs.close();
	return true;
}

bool downloadSemester(Semester& semester) {
	std::string semesterFilePath = getSemesterFilePath(semester);
	std::ofstream ofs(semesterFilePath);
	if (!ofs) {
		std::cout << "Can't open " << semesterFilePath << std::endl;
		return false;
	}
	ofs << "SemesterID, " << semester.semesterID << std::endl;
	ofs << "Start date, " << semester.startDate.day << "/" << semester.startDate.month << "/" << semester.startDate.year << std::endl;
	ofs << "End date, " << semester.endDate.day << "/" << semester.endDate.month << "/" << semester.endDate.year << std::endl;
	ofs << "Number of couses, " << semester.courses.size() << std::endl;
	ofs << "No, CourseID\n";
	for (int i = 0; i < semester.courses.size(); i++){
		ofs << std::to_string(i + 1) << ", " << semester.courses[i].ID << std::endl;
		downloadCourse(semester.courses[i]);
	}
	ofs.close();
	return true;
}

bool downloadCourse(Course& course) {
	std::string courseFilePath = getCourseFilePath(course);
	std::ofstream ofs(courseFilePath);
	if (!ofs) {
		std::cout << "Can't open " << courseFilePath << std::endl;
		return false;
	}
	ofs << "Course ID," << course.ID << std::endl;
	ofs << "Class ID," << course.classID << std::endl;
	ofs << "Course name," << course.name << std::endl;
	ofs << "Teacher," << course.teacher << std::endl;
	ofs << "Number of credits," << course.credits << std::endl;
	ofs << "Max enrolled," << course.maxEnroll << std::endl;
	ofs << "Weekday," << weekday_to_string(course.weekday) << std::endl;
	ofs << "Session," << session_to_string(course.session) << std::endl;
	ofs << "Number of students," << course.scoreboards.size() << std::endl;
	ofs << "No, StudentID, Midterm, Final, Other, Total" << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++){
		ofs << std::to_string(i + 1) << ", " << course.scoreboards[i]->ptrStudent->ID << ",";
		ofs << course.scoreboards[i]->midterm << "," << course.scoreboards[i]->final << "," << course.scoreboards[i]->other << ",";
		ofs << course.scoreboards[i]->total << std::endl;
	}
	ofs.close();
	return true;
}