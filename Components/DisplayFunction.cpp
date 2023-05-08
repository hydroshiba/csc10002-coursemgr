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
Vector<string> getListSchoolYear() {
	Vector<string> listSY(schoolYears.size());
	for (int i = 0; i < listSY.size(); i++){
		listSY[i] = std::to_string(schoolYears[i].start);
	}
	return listSY;
}

Vector<string> getListAcademicYear() {
	Vector<string> listAYs(academicYears.size());
	for (int i = 0; i < listAYs.size(); i++) {	
		listAYs[i] = to_string(academicYears[i].start);
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
		table[i + 2][1] = schoolYears[i].getPeriod();
		table[i + 2][2] = to_string(schoolYears[i].classes.size());
	}
	return table;
} 

Vector<Vector<string>> getTableContentOfSchoolYear(const SchoolYear& schoolYear) {
	Vector<Vector<string>> table;
	size_t n = schoolYear.classes.size();
	table.resize(n + 3);
	for (int i = 0; i < 2; i++)
		table[i].resize(2);
	for (int i = 2; i < table.size(); i++)
		table[i].resize(3);
	table[0][0] = "SchoolYear";
	table[0][1] = schoolYear.getPeriod();
	table[1][0] = "Number of classes";
	table[1][1] = std::to_string(n);
	table[2][0] = "No";
	table[2][1] = "Class";
	table[2][2] = "Number of students";
	for (int i = 0; i < n; i++) {
		table[i + 3][0] = std::to_string(i + 1);
		table[i + 3][1] = schoolYear.classes[i].name;
		table[i + 3][2] = to_string(schoolYear.classes[i].students.size());
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

Vector<Vector<string>> getTableContentOfListScoreboardInSemesterInClass(const Class& CLASS, const Semester& semester){
	Vector<Vector<string>> table;
	size_t n = CLASS.students.size();
	table.resize(n + 4);
	for (int i = 0; i < 3; i++)
		table[i].resize(2);
	table[0][0] = "Classname";
	table[0][1] = CLASS.name;
	table[1][0] = "Number of students";
	table[1][1] = to_string(n);
	table[2][0] = "Semester";
	table[2][1] = semester.semesterID;
	Vector<string> courses = CLASS.getListCourse(semester);
	size_t nCourses = courses.size();
	for (int i = 3; i < table.size(); i++) {
		table[i].resize(5 + nCourses);
	}
	table[3][0] = "No";
	table[3][1] = "StudentID";
	table[3][2] = "Fullname";
	table[3][nCourses + 3] = "Semester GPA";
	table[3][nCourses + 4] = "Overall GPA";
	for (int i = 3; i < nCourses + 3; i++) {
		table[3][i] = courses[i - 3];
	}
	for (int i = 0; i < n; i++) {
		table[i + 4][0] = to_string(i + 1);
		table[i + 4][1] = CLASS.students[i]->ID;
		table[i + 4][2] = CLASS.students[i]->name.get();
		for (int j = 0; j < nCourses; i++) {
			Scoreboard* ptrScoreboard = CLASS.students[i]->getScoreboard(courses[j]);
			if (ptrScoreboard == nullptr)
				table[i + 4][j + 3] = 'x';
			else
				table[i + 4][j + 3] = to_string(ptrScoreboard->total);
		}
		table[i + 4][nCourses + 3] = CLASS.students[i]->getGPA(semester);
		table[i + 4][nCourses + 4] = CLASS.students[i]->getGPA();
	}
	return table;
}

Vector<Vector<string>> getTableContentOfListScoreboardInClass(const Class& CLASS){
	Vector<Vector<string>> table;
	size_t n = CLASS.students.size();
	table.resize(n + 3);
	for (int i = 0; i < 2; i++)
		table[i].resize(2);
	table[0][0] = "Classname";
	table[0][1] = CLASS.name;
	table[1][0] = "Number of students";
	table[1][1] = to_string(n);
	Vector<string> courses = CLASS.getListCourse();
	size_t nCourses = courses.size();
	for (int i = 2; i < table.size(); i++) {
		table[i].resize(4 + nCourses);
	}
	table[2][0] = "No"; table[2][1] = "StudentID"; table[2][2] = "Fullname";
	table[2][nCourses + 3] = "Overall GPA";
	for (int i = 3; i < nCourses + 3; i++) {
		table[2][i] = courses[i - 3];
	}
	for (int i = 0; i < n; i++) {
		table[i + 3][0] = to_string(i + 1);
		table[i + 3][1] = CLASS.students[i]->ID;
		table[i + 3][2] = CLASS.students[i]->name.get();
		for (int j = 0; j < nCourses; i++) {
			Scoreboard* ptrScoreboard = CLASS.students[i]->getScoreboard(courses[j]);
			if (ptrScoreboard == nullptr)
				table[i + 3][j + 3] = 'x';
			else
				table[i + 3][j + 3] = to_string(ptrScoreboard->total);
		}
		table[i + 3][nCourses + 3] = CLASS.students[i]->getGPA();
	}
	return table;
}

Vector<Vector<string>> getTableContentOfScoreboardOfStudent(const Student& student) {
	Vector<Vector<string>> table;
	size_t nCourses = student.scoreboards.size();
	table.resize(nCourses + 9);
	for (int i = 0; i < 8; i++) {
		table[i].resize(2);
	}
	table[0][0] = "StudentID"; table[0][1] = student.ID;
	table[1][0] = "Fullname"; table[1][1] = student.name.get();
	table[2][0] = "Gender"; table[2][1] = gender_to_string(student.gender);
	table[3][0] = "Dob"; table[3][1] = student.birth.get();
	table[4][0] = "SocialID"; table[4][1] = student.socialID;
	table[5][0] = "Class"; table[5][1] = student.ptrClass->name;
	table[6][0] = "Number of courses"; table[6][1] = to_string(nCourses);
	table[7][0] = "Overall GPA"; table[7][1] = to_string(student.getGPA());
	for (int i = 8; i < table.size(); i++)
		table[i].resize(7);
	table[8][0] = "No";
	table[8][1] = "CourseID";
	table[8][2] = "SemesterID";
	table[8][3] = "Midterm";
	table[8][4] = "Final";
	table[8][5] = "Other";
	table[8][6] = "Total";
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

Vector<Vector<string>> getTableContentOfScoreboardInSemesterOfStudent(const Student& student, const Semester& semester) {
	Vector<Vector<string>> table;
	Vector<Scoreboard*> scoreboards	= student.getScoreboards(semester);
	size_t nCourses = scoreboards.size();
	table.resize(nCourses + 10);
	for (int i = 0; i < 9; i++) {
		table[i].resize(2);
	}
	table[0][0] = "StudentID"; table[0][1] = student.ID;
	table[1][0] = "Fullname"; table[1][1] = student.name.get();
	table[2][0] = "Gender"; table[2][1] = gender_to_string(student.gender);
	table[3][0] = "Dob"; table[3][1] = student.birth.get();
	table[4][0] = "SocialID"; table[4][1] = student.socialID;
	table[5][0] = "Class"; table[5][1] = student.ptrClass->name;
	table[6][0] = "Number of courses"; table[6][1] = to_string(nCourses);
	table[7][0] = "Overall GPA"; table[7][1] = to_string(student.getGPA());
	table[8][0] = "Semester GPA"; table[8][1] = to_string(student.getGPA(semester));
	for (int i = 9; i < table.size(); i++)
		table[i].resize(6);
	table[9][0] = "No";
	table[9][1] = "CourseID";
	table[9][2] = "Midterm";
	table[9][3] = "Final";
	table[9][4] = "Other";
	table[9][5] = "Total";
	for (int i = 0; i < student.scoreboards.size(); i++) {
		table[i + 1][0] = std::to_string(i + 1);
		table[i + 1][1] = student.scoreboards[i]->ptrCourse->ID;
		table[i + 1][2] = student.scoreboards[i]->midterm;
		table[i + 1][3] = student.scoreboards[i]->final;
		table[i + 1][4] = student.scoreboards[i]->other;
		table[i + 1][5] = student.scoreboards[i]->total;
	}
	scoreboards.~Vector();
	return table;
}

Vector<Vector<string>> getTableContentOfListAcademicYear() {
	Vector<Vector<string>> table;
	table.resize(2 + academicYears.size());
	table[0].resize(2);
	for (int i = 1; i < table.size(); i++) {
		table[i].resize(3);
	}
	table[0][0] = "Number of academicYears";
	table[0][1] = std::to_string(academicYears.size());
	table[1][0] = "No";
	table[1][1] = "AcademicYear";
	table[1][2] = "Number of semesters";
	for (int i = 0; i < academicYears.size(); i++) {
		table[i + 2][0] = std::to_string(i + 1);
		table[i + 2][1] = academicYears[i].getPeriod();
		table[i + 2][2] = to_string(academicYears[i].semesters.size());
	}
	return table;
}

Vector<Vector<string>> getTableContentOfAcademicYear(const AcademicYear& academicYear) {
	Vector<Vector<string>> table;
	size_t n = academicYear.semesters.size();
	table.resize(3 + n);
	for (int i = 0; i < 2; i++) {
		table[i].resize(2);
	}
	for (int i = 2; i < table.size(); i++) {
		table[i].resize(5);
	}
	table[0][0] = "AcademicYear";
	table[0][1] = academicYear.getPeriod();

	table[1][0] = "Number of semesters";
	table[1][1] = to_string(n);

	table[2][0] = "No";
	table[2][1] = "SemesterID";
	table[2][2] = "Start date";
	table[2][3] = "End date";
	table[2][4] = "Number of courses";

	for (int i = 0; i < n; i++) {
		table[i + 3][0] = to_string(i + 1);
		table[i + 3][1] = academicYear.semesters[i].semesterID;
		table[i + 3][2] = academicYear.semesters[i].startDate.get();
		table[i + 3][3] = academicYear.semesters[i].endDate.get();
		table[i + 3][4] = to_string(academicYear.semesters[i].courses.size());
	}
	return table;
}

Vector<Vector<string>> getTableContentOfSemester(const Semester& semester) {
	Vector<Vector<string>> table;
	size_t n = semester.courses.size();
	table.resize(5 + n);
	for (int i = 0; i < 4; i++) {
		table[i].resize(2);
	}
	for (int i = 4; i < table.size(); i++) {
		table[i].resize(10);
	}
	table[0][0] = "SemesterID";
	table[0][1] = semester.semesterID;
	table[1][0] = "Start date";
	table[1][1] = semester.startDate.get();
	table[2][0] = "End date";
	table[2][1] = semester.endDate.get();
	table[3][0] = "Number of courses";
	table[3][1] = to_string(n);
	table[4][0] = "No";
	table[4][1] = "CourseID";
	table[4][2] = "ClassID";
	table[4][3] = "Course name";
	table[4][4] = "Teacher";
	table[4][5] = "Number of credits";
	table[4][6] = "Max enroll";
	table[4][7] = "Weekday";
	table[4][8] = "Session";
	table[4][9] = "Number of students";
	for (int i = 0; i < n; i++) {
		table[i + 5][0] = to_string(i + 1);
		table[i + 5][1] = semester.courses[i].ID;
		table[i + 5][2] = semester.courses[i].classID;
		table[i + 5][3] = semester.courses[i].name;
		table[i + 5][4] = semester.courses[i].teacher;
		table[i + 5][5] = to_string(semester.courses[i].credits);
		table[i + 5][6] = to_string(semester.courses[i].maxEnroll);
		table[i + 5][7] = weekday_to_string(semester.courses[i].weekday);
		table[i + 5][8] = session_to_string(semester.courses[i].session);
		table[i + 5][9] = to_string(semester.courses[i].scoreboards.size());

	}
	return table;
}

Vector<Vector<string>> getTableContentOfListStudentInCourse(const Course& course){
	Vector<Vector<string>> table;
	size_t n = course.scoreboards.size();
	table.resize(n + 10);
	course.displayInfoTable(table);
	for (int i = 0; i < 9; i++) {
		table[i].resize(2);
	}

	table[0][0] = "Course ID"; table[0][1] = course.ID;
	table[1][0] = "Class ID"; table[1][1] = course.classID;
	table[2][0] = "Course name"; table[2][1] = course.name;
	table[3][0] = "Teacher"; table[3][1] = course.teacher;
	table[4][0] = "Number of credits"; table[4][1] = std::to_string(course.credits);
	table[5][0] = "Max enroll"; table[5][1] = std::to_string(course.maxEnroll);
	table[6][0] = "Weekday"; table[6][1] = weekday_to_string(course.weekday);
	table[7][0] = "Session"; table[7][1] = session_to_string(course.session);
	table[8][0] = "Number of students"; table[8][1] = std::to_string(course.scoreboards.size());
	for (int i = 9 ; i < table.size(); ++i)
		table[i].resize(7);
	table[9][0] = "No";
	table[9][1] = "StudentID";
	table[9][2] = "Fullname";
	table[9][3] = "Midterm";
	table[9][4] = "Final";
	table[9][5] = "Other";
	table[9][6] = "Total";

	for (int i = 0; i<course.scoreboards.size();++i){
		table[i+10][0] = std::to_string(i+1);
		table[i+10][1] = course.scoreboards[i]->ptrStudent->ID;
		table[i + 10][2] = course.scoreboards[i]->ptrStudent->name.get();
		table[i+10][3] = std::to_string(course.scoreboards[i]->midterm);
		table[i+10][4] = std::to_string(course.scoreboards[i]->final);
		table[i+10][5] = std::to_string(course.scoreboards[i]->other);
		table[i+10][6] = std::to_string(course.scoreboards[i]->total);
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