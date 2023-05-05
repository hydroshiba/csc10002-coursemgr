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

Vector<Vector<string>> getTableContentOfListSchoolYear() {
	Vector<Vector<string>> table;
	table.resize(2 + schoolYears.size());
	table[0].resize(2);
	for (int i = 1; i < table.size(); i++) {
		table[i].resize(3);
	}
	table[0][0] = "Number of SchoolYears";
	table[0][1] = std::to_string(schoolYears.size());
	table[1][0] = "No";
	table[1][1] = "SchoolYear";
	table[1][2] = "Number of classes";
	for (int i = 0; i < schoolYears.size(); i++) {
		table[i + 2][0] = std::to_string(i + 1);
		table[i + 2][1] = std::to_string(schoolYears[i].start);
		table[i + 2][2] = to_string(schoolYears[i].classes.size());
	}
	return table;
}

Vector<Vector<string>> getTableContentOfListClass(const SchoolYear& schoolYear) {
	Vector<Vector<string>> table;
	size_t n = schoolYear.classes.size();
	table.resize(n + 3);
	for (int i = 0; i < table.size(); i++)
		table[i].resize(2);
	table[0][0] = "SchoolYear";
	table[0][1] = schoolYear.getPeriod();
	table[1][0] = "Number of classes";
	table[1][1] = std::to_string(n);
	table[2][0] = "No";
	table[2][1] = "Class";
	for (int i = 0; i < n; i++) {
		table[i + 3][0] = std::to_string(i + 1);
		table[i + 3][1] = schoolYear.classes[i].name;
	}
	return table;
}

Vector<Vector<string>> getTableContentOfListStudentInClass(const Class& CLASS) {
	size_t n = CLASS.students.size();
	Vector<Vector<string>> table;
	table.resize(3 + n);
	for (int i = 0; i < 2; i++)
		table[i].resize(2);
	for (int i = 2; i < table.size(); i++)
		table[i].resize(6);
	table[0][0] = "Class";
	table[0][1] = CLASS.name;
	table[1][0] = "Number of students";
	table[1][1] = to_string(n);
	table[2][0] = "No";
	table[2][1] = "StudentID";
	table[2][2] = "Fullnam";
	table[2][3] = "Gender";
	table[2][4] = "Dob";
	table[2][5] = "SocialID";
	for (int i = 0; i < n; i++) {
		table[i + 3][0] = to_string(i + 1);
		table[i + 3][1] = CLASS.students[i]->ID;
		table[i + 3][2] = CLASS.students[i]->name.get();
		table[i + 3][3] = gender_to_string(CLASS.students[i]->gender);
		table[i + 3][4] = CLASS.students[i]->birth.get();
		table[i + 3][5] = CLASS.students[i]->socialID;
	}
	return table;
}

Vector<Vector<string>> getTableContentOfListScoreboardInSemesterInClass(const Class& CLASS, const Semester& semester){}

Vector<Vector<string>> getTableContentOfListScoreboardInClass(const Class& CLASS){}

Vector<Vector<string>> getTableContentOfScoreboardOfStudent(const Student& student){}

Vector<Vector<string>> getTableContentOfListAcademicYear() {
	Vector<Vector<string>> table;
	table.resize(2 + academicYears.size());
	for (int i = 0; i < table.size(); i++) {
		table[i].resize(2);
	}
	table[0][0] = "Number of academicYears";
	table[0][1] = std::to_string(academicYears.size());
	table[1][0] = "No";
	table[1][1] = "AcademicYear";
	for (int i = 0; i < academicYears.size(); i++) {
		table[i + 2][0] = std::to_string(i + 1);
		table[i + 2][1] = std::to_string(academicYears[i].start);
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


bool removeTable(Vector<Vector<string>>& table) {
	for (int i = 0; i < table.size(); i++)
		table[i].~Vector();
	table.~Vector();
	return true;
}
//----------------------------------------------------------------------------------------------//