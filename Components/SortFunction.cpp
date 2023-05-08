#include "SortFunction.h"

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

void sortStudentList(Vector<Student>& students, const int& left, const int& right) {
	int i = left;
	int j = right;
	string pivot = students[left + (right - left) / 2].ID;
	while (i < j) {
		while (students[i].ID < pivot) i++;
		while (students[j].ID > pivot) j--;
		if (i <= j) {
			std::swap(students[i], students[j]);
			i++;
			j--;
		}
	}
	if (i < right) {
		sortStudentList(students, i, right);
	}
	if (left < j) {
		sortStudentList(students, left, j);
	}
}

void sortStaffList(Vector<Staff>& staffs, const int& left, const int& right) {
	int i = left;
	int j = right;
	string pivot = staffs[left + (right - left) / 2].ID;
	while (i < j) {
		while (staffs[i].ID < pivot) i++;
		while (staffs[j].ID > pivot) j--;
		if (i <= j) {
			std::swap(staffs[i], staffs[j]);
			i++;
			j--;
		}
	}
	if (i < right) {
		sortStaffList(staffs, i, right);
	}
	if (left < j) {
		sortStaffList(staffs, left, j);
	}
}

void sortSchoolYearList (Vector<SchoolYear>& schoolYears, const int& left, const int& right){
	if (left >= right) return;
	int i = left, j = right;
	unsigned int pivot = schoolYears[i].start;
	while (i < j){
		while (schoolYears[i].start < pivot) ++i;
		while (schoolYears[j].start > pivot) --j;
		std::swap(schoolYears[i], schoolYears[j]);
		++i;
		--j;
	}
	sortSchoolYearList (schoolYears, left, j);
	sortSchoolYearList (schoolYears, i, right);
}

void sortAcademicYearList(Vector<AcademicYear>& academicYears, const int& left, const int& right){
	if (left >= right) return;
	int i = left, j = right;
	unsigned int pivot = academicYears[i].start;
	while (i < j){
		while (academicYears[i].start < pivot) ++i;
		while (academicYears[j].start > pivot) --j;
		std::swap(academicYears[i], academicYears[j]);
		++i;
		--j;
	}
	sortAcademicYearList (academicYears, left, j);
	sortAcademicYearList (academicYears, i, right);
}

void sortSemesters(Vector<Semester>& semesters, const int& left, const int& right){
	if (left >= right) return;
	int i = left, j = right;
	std::string pivot = semesters[i].semesterID;
	while (i < j){
		while (semesters[i].semesterID < pivot) ++i;
		while (semesters[i].semesterID > pivot) --j;
		std::swap(semesters[i], semesters[j]);
		++i;
		--j;
	}
	sortSemesters(semesters, left, j);
	sortSemesters(semesters, i, right);
}

void sortClasses(Vector<Class>& classes, const int& left, const int& right){
	if (left >= right) return;
	int i = left, j = right;
	std::string pivot = classes[i].name;
	while (i < j){
		while (classes[i].name < pivot) ++i;
		while (classes[i].name > pivot) --j;
		std::swap(classes[i], classes[j]);
		++i;
		--j;
	}
	sortClasses(classes, left, j);
	sortClasses(classes, i, right);	
}

void sortCourses(Vector<Course>& courses, const int& left, const int& right){
	if (left >= right) return;
	int i = left, j = right;
	std::string pivot = courses[i].ID;
	while (i < j){
		while (courses[i].ID < pivot) ++i;
		while (courses[i].ID > pivot) --j;
		std::swap(courses[i], courses[j]);
		++i;
		--j;
	}
	sortCourses(courses, left, j);
	sortCourses(courses, i, right);	
}

void sortStudentsInClass(Class& CLASS, const int& left, const int& right){
	if (left >= right) return;
	int i = left, j = right;
	std::string pivot = CLASS.students[i]->ID;
	while (i < j){
		while (CLASS.students[i]->ID < pivot) ++i;
		while (CLASS.students[j]->ID > pivot) --j;
		std::swap(CLASS.students[i], CLASS.students[j]);
		++i;
		--j;
	}
	sortStudentsInClass(CLASS, left, j);
	sortStudentsInClass(CLASS, i, right);
}

void sortStudentsInCourse(Course& course, const int& left, const int& right){
	if (left >= right) return;
	int i = left, j = right;
	std::string pivot = course.scoreboards[i]->ptrStudent->ID;
	while (i < j){
		while (course.scoreboards[i]->ptrStudent->ID < pivot) ++i;
		while (course.scoreboards[j]->ptrStudent->ID > pivot) --j;
		std::swap(course.scoreboards[i]->ptrStudent, course.scoreboards[j]->ptrStudent);
		++i;
		--j;
	}
	sortStudentsInCourse(course, left, j);
	sortStudentsInCourse(course, i, right);
}