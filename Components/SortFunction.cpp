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
	sortSchoolYearList (schoolYears, left, i);
	sortSchoolYearList (schoolYears, i+1, right);
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
	sortAcademicYearList (academicYears, left, i);
	sortAcademicYearList (academicYears, i+1, right);
}

void sortSemesters(Vector<Semester>& semesters, const int& left, const int& right){
	if (left >= right) return;
	int i = left, j = right;
	std::string pivot = semesters[i].semesterID;
	while (i > j){
		while (semesters[i].semesterID < pivot) ++i;
		while (semesters[i].semesterID > pivot) --j;
		std::swap(semesters[i], semesters[j]);
		++i;
		--j;
	}
	sortSemesters(semesters, left, i);
	sortSemesters(semesters, i+1, right);
}