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
Vector<std::string> getListSchoolYear(Vector<SchoolYear>& schoolYears) {
	Vector<std::string> listSY(schoolYears.size());
	for (int i = 0; i < listSY.size(); i++){
		listSY[i] = std::to_string(schoolYears[i].start);
	}
	return listSY;
}

// DropBox
Vector<std::string> getListAcademicYear(Vector<AcademicYear>& academicYears) {
	Vector<std::string> listAYs(academicYears.size());
	for (int i = 0; i < listAYs.size(); i++) {
		listAYs[i] = academicYears[i].getPeriod();
	}
	return listAYs;
}

// DropBox
Vector<std::string> getListClass(const SchoolYear& schoolYear) {
	Vector<std::string> listClass(schoolYear.classes.size());
	for (int i = 0; i < schoolYear.classes.size(); i++) {
		listClass[i] = schoolYear.classes[i].name;
	}
	return listClass;
}

// DropBox
Vector<std::string> getListSemester(const AcademicYear& academicYear) {
	Vector<std::string> listSemester(academicYear.semesters.size());
	for (int i = 0; i < academicYear.semesters.size(); i++) {
		listSemester[i] = academicYear.semesters[i].semesterID;
	}
	return listSemester;
}

// DropBox
Vector<std::string> getListCourse(const Semester& semester) {
	Vector<std::string> listCourse(semester.courses.size());
	for (int i = 0; i < semester.courses.size(); i++) {
		listCourse[i] = semester.courses[i].ID;
	}
	return listCourse;
}

// Table
Vector<Vector<std::string>> getTableContentOfScoreboardsofStudent(const Student& student) {
	Vector<Vector<std::string>> table(student.scoreboards.size() + 1);
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

//----------------------------------------------------------------------------------------------//