#include "RemoveFunction.h"
#include "SearchFunction.h"

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

/*		Remove function		*/

// Remove student from School
bool removeStudent(Vector<Student>& students, const string& studentID, string& outStr) {
	if (studentID.empty()) {
		outStr = "Please enter student ID to input box to remove";
		return false;
	}
	Student* ptrStudent = getStudent(students, studentID);
	if (ptrStudent == nullptr) {
		outStr = "Student with ID " + studentID + " can't be found in school! Pls try another";
		return false;
	}
	students.remove(ptrStudent);
	outStr = "Student with ID " + studentID + " is removed from school!";
	return true;
}

// Remove staff from school
bool removeStaff(string curStaffID, Vector<Staff>&staffs, const string & staffID, string & outStr) {
	if (staffID.empty()) {
		outStr = "Please enter staff ID to input box to remove";
		return false;
	}
	Staff* ptrStaff = getStaff(staffs, staffID);
	if (ptrStaff == nullptr) {
		outStr = "Staff with ID " + staffID + " can't be found in school! Pls try another";
		return false;
	}
	if (ptrStaff == ptrStaff_Global) {
		outStr = "Staff with ID " + staffID + " can't be removed from school! Pls try another";
		return false;
	}
	staffs.remove(ptrStaff);
	ptrStaff_Global = getStaff(staffs, curStaffID);
	outStr = "Staff with ID " + staffID + " is removed from school!";
	return true;
}

// Remove list SchoolYear
bool removeListSchoolYear(Vector<SchoolYear>& schoolYears) {
	for (int i = 0; i < schoolYears.size(); ++i) {
		removeListClasses(schoolYears[i]);
		schoolYears.remove(&schoolYears[i]);
	}
	return true;
}

// Remove list AcademicYear
bool removeListAcademicYear(Vector<AcademicYear>& academicYears) {
	for (int i = 0; i < academicYears.size(); ++i) {
		removeListSemesters(academicYears[i]);
		academicYears.remove(&academicYears[i]);
	}
	return true;
}

// Remove SchoolYear
bool removeSchoolYear(Vector<SchoolYear>& schoolYears, const std::string& start) {
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	SchoolYear* ptrSchoolYear = getSchoolYear(schoolYears, startYear);
	if (ptrSchoolYear == nullptr)
		return false;
	schoolYears.remove(ptrSchoolYear);
	return true;
}

// Remove AcademicYear
bool removeAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start) {
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	AcademicYear* ptrAcademicYear = getAcademicYear(academicYears, startYear);
	if (ptrAcademicYear == nullptr)
		return false;
	academicYears.remove(ptrAcademicYear);
	return true;
}

// Remove Class from School
bool removeClass(Vector<SchoolYear>& schoolYears, const std::string& className) {
	Class* ptrClass = nullptr;
	for (int i = 0; i < schoolYears.size(); ++i) {
		ptrClass = schoolYears[i].getClass(className);
		if (ptrClass == nullptr) {
			return false;
		}
		else {
			schoolYears[i].classes.remove(ptrClass);
		}
	}
	return true;
}

// Remove List Classes
bool removeListClasses(SchoolYear& schoolYear) {
	for (int i = 0; i < schoolYear.classes.size(); ++i) {
		removeListStudents(schoolYear.classes[i]);
		schoolYear.classes.remove(&schoolYear.classes[i]);
	}
	return true;
}

// Remove Semester
bool removeSemester(Vector<AcademicYear>& academicYears, const std::string& semesterID) {
	Semester semester;
	semester.semesterID = semesterID;
	Semester* ptrSemester = nullptr;
	for (int i = 0; i < academicYears.size(); ++i) {
		ptrSemester = academicYears[i].semesters.find(semester);
		if (ptrSemester == nullptr)
			return false;
		else {
			academicYears[i].semesters.remove(ptrSemester);
		}
	}
	return true;
}

// Remove List Semesters
bool removeListSemesters(AcademicYear& academicYear) {
	for (int i = 0; i < academicYear.semesters.size(); ++i) {
		removeListCourses(academicYear.semesters[i]);
		academicYear.semesters.remove(&academicYear.semesters[i]);
	}
	return true;
}

// Remove Course
bool removeCourse(Vector<AcademicYear>& academicYears, const std::string& courseID) {
	Course* ptrCourse = nullptr;
	Course course;
	course.ID = courseID;
	for (int i = 0; i < academicYears.size(); ++i) {
		for (int j = 0; j < academicYears[i].semesters.size(); ++j) {
			ptrCourse = academicYears[i].semesters[j].courses.find(course);
			if (ptrCourse) {
				ptrCourse->ptrSemester = nullptr;
				for (int i = 0; i < ptrCourse->scoreboards.size(); i++)
				{
					Student* student = ptrCourse->scoreboards[i]->ptrStudent;
					student->scoreboards.remove(ptrCourse->scoreboards[i]); // delete link from student->scoreboard
					delete ptrCourse->scoreboards[i]; // delete scoreboard
				}
				ptrCourse->scoreboards.~Vector(); // delete Vector pointer of scoreboards 
				academicYears[i].semesters[j].courses.remove(ptrCourse); // delete course
				return true;
			}
		}
	}
	return false;
}

// Remove List Courses
bool removeListCourses(Semester& semester) {
	for (int i = 0; i < semester.courses.size(); ++i) {
		for (int j = 0; j < semester.courses[i].scoreboards.size(); ++j)
			delete semester.courses[i].scoreboards[j]; // delete scoreboard
		semester.courses[i].scoreboards.~Vector(); // delete Vector pointer of Scoreboards
		semester.courses.remove(&semester.courses[i]); // delete course
	}
	return true;
}

// Remove Student from School
bool removeStudent(Vector<SchoolYear>& schoolYears, const std::string& studentID) {
	Student* ptrStudent = nullptr;
	for (int i = 0; i < schoolYears.size(); ++i)
		for (int j = 0; j < schoolYears[i].classes.size(); ++j) {
			ptrStudent = schoolYears[i].classes[j].getStudent(studentID);
			if (ptrStudent) {
				for (int k = 0; k < ptrStudent->scoreboards.size(); ++k) {
					Course* ptrCourse = ptrStudent->scoreboards[k]->ptrCourse;
					ptrCourse->scoreboards.remove(ptrStudent->scoreboards[k]);
					delete ptrStudent->scoreboards[k];
				}
				ptrStudent->scoreboards.~Vector();
				schoolYears[i].classes[j].students.remove(ptrStudent);
				return true;
			}
		}
	return false;
}

// Remove List Students
bool removeListStudents(Class& thisClass) {
	for (int i = 0; i < thisClass.students.size(); ++i) {
		thisClass.students[i]->scoreboards.~Vector(); // delete a student's scoreboard pointers
		thisClass.students.remove(&thisClass.students[i]);
	}
	return true;
}

// Remove student from course
bool removeStudFromCourse(Course& course, const std::string& studentID, std::string &outDev) {
	Student* ptrStudent = course.getStudent(studentID);
	if (ptrStudent == nullptr)
	{
		outDev = "Student with ID " + studentID + " is not exist in this Course " + course.ID;
		return false;
	}
	Scoreboard* ptrScoreboard = course.getScoreboard(studentID);
	ptrStudent->scoreboards.remove(ptrScoreboard);
	ptrScoreboard->ptrStudent = nullptr;
	course.scoreboards.remove(ptrScoreboard);
	ptrScoreboard->ptrCourse = nullptr;
	outDev = "Successfully remove student with ID " + studentID + " from course " + course.ID;
	return true;
}

// Remove course from semester
bool deleteCourse(Semester& semester, const std::string& courseID) {
	Course* ptrCourse = semester.getCourse(courseID);
	if (ptrCourse == nullptr) {
		std::cout << "Can't find a course with ID " << courseID;
		return false;
	}
	else
	{
		ptrCourse->ptrSemester = nullptr;
		for (int i = 0; i < ptrCourse->scoreboards.size(); i++)
		{
			Student* student = ptrCourse->scoreboards[i]->ptrStudent;
			student->scoreboards.remove(ptrCourse->scoreboards[i]); // delete link from student->scoreboard
			ptrCourse->scoreboards[i]->ptrStudent = nullptr; // delete link sb->student
			ptrCourse->scoreboards[i]->ptrCourse = nullptr; // delete link sb->course
			delete ptrCourse->scoreboards[i]; // delete scoreboard
		}
		ptrCourse->scoreboards.~Vector(); // delete Vector pointer of scoreboards
		semester.removeCourse(*ptrCourse); // delete course
		std::cout << "Course with ID " << courseID << " have been removed from semester!";
	}
	std::cout << std::endl;
	return true;
}

// Free memory
bool freeMemory(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears) {
	bool b1 = removeListSchoolYear(schoolYears);
	bool b2 = removeListAcademicYear(academicYears);
	return (b1 && b2);
}
//----------------------------------------------------------------------------------------------//
