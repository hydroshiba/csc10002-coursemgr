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