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

#include "FileAndDirFunction.h"
/*		Display function	*/

// DropBox
Vector<string> getListSchoolYear(Vector<SchoolYear>& schoolYears) {
	Vector<string> listSY(schoolYears.size());
	for (int i = 0; i < listSY.size(); i++){
		listSY[i] = std::to_string(schoolYears[i].start);
	}
	return listSY;
}

Vector<string> getListAcademicYear(Vector<AcademicYear>& academicYears) {
	Vector<string> listAYs(academicYears.size());
	for (int i = 0; i < listAYs.size(); i++) {
		listAYs[i] = academicYears[i].getPeriod();
	}
	return listAYs;
}

Vector<string> getListClass(const SchoolYear& schoolYear) {
	Vector<string> listClass(schoolYear.classes.size());
	for (int i = 0; i < schoolYear.classes.size(); i++) {
		listClass[i] = schoolYear.classes[i].name;
	}
	return listClass;
}

Vector<string> getListSemester(const AcademicYear& academicYear) {
	Vector<string> listSemester(academicYear.semesters.size());
	for (int i = 0; i < academicYear.semesters.size(); i++) {
		listSemester[i] = academicYear.semesters[i].semesterID;
	}
	return listSemester;
}

Vector<string> getListCourse(const Semester& semester) {
	Vector<string> listCourse(semester.courses.size());
	for (int i = 0; i < semester.courses.size(); i++) {
		listCourse[i] = semester.courses[i].ID;
	}
	return listCourse;
}

// Table
Vector<Vector<string>> getTableContentOfScoreboardOfStudent(const Student& student) {
	Vector<Vector<string>> table(student.scoreboards.size() + 1);
	for (int i = 0; i < table.size(); i++) {
		table[i].resize(7);
	}
	table[0][0] = "No";
	table[0][1] = "CourseID";
	table[0][2] = "SemesterID";
	table[0][3] = "Midterm";
	table[0][4] = "Final";
	table[0][5] = "Other";
	table[0][6] = "Total";
	for (int i = 0; i < student.scoreboards.size(); i++) {
		table[i + 1][0] = std::to_string(i + 1);
		table[i + 1][1] = student.scoreboards[i]->ptrCourse->ID;
		table[i + 1][2] = student.scoreboards[i]->ptrCourse->ptrSemester->semesterID;
		table[i + 1][3] = student.scoreboards[i]->midterm;
		table[i + 1][4] = student.scoreboards[i]->final;
		table[i + 1][5] = student.scoreboards[i]->other;
		table[i + 1][6] = student.scoreboards[i]->total;
	}
	return table;
}

Vector<Vector<string>> getTableContentOfListCourse(const Course& course){
	Vector<Vector<string>> table;
	course.displayInfoTable(table);
	table.resize(course.scoreboards.size()+9+1);
	for (int i = 0; i<course.scoreboards.size()+1; ++i)
		table[i+9].resize(3);
	table[9][0] = "No";
	table[9][1] = "StudnetID";
	table[9][2] = "Fullname";
	for (int i = 0; i < course.scoreboards.size(); ++i){
		table[i+10][0] = std::to_string(i+1);
		table[i+10][1] = course.scoreboards[i]->ptrStudent->ID;
		table[i+10][2] = course.scoreboards[i]->ptrStudent->name.get();
	}
	return table;
}

// Student and scoreboards
Vector<Vector<string>> getTableContentOfListStudentInCourse(const Course& course){
	Vector<Vector<string>> table(course.scoreboards.size()+10);
	course.displayInfoTable(table);
	for (int i = 0; i<course.scoreboards.size()+1;++i)
		table[i+9].resize(6);
	table[9][0] = "No";
	table[9][1] = "StudnetID";
	table[9][2] = "Midterm";
	table[9][3] = "Final";
	table[9][4] = "Other";
	table[9][5] = "Total";
	for (int i = 0; i<course.scoreboards.size();++i){
		table[i+10][0] = std::to_string(i+1);
		table[i+10][1] = course.scoreboards[i]->ptrStudent->ID;
		table[i+10][2] = std::to_string(course.scoreboards[i]->midterm);
		table[i+10][3] = std::to_string(course.scoreboards[i]->final);
		table[i+10][4] = std::to_string(course.scoreboards[i]->other);
		table[i+10][5] = std::to_string(course.scoreboards[i]->total);
	}
	return table;
}


//----------------------------------------------------------------------------------------------//