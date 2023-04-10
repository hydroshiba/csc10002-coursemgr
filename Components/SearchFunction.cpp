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

/*		Search function		*/

// Find student
Student* getStudent(Vector<SchoolYear>& schoolYears, const std::string& studentID) {
	Student* ptrStudent = nullptr;
	for (int i = 0; i < schoolYears.size(); i++)
	{
		Student* temp = schoolYears[i].getStudent(studentID);
		if (temp != nullptr)
		{
			ptrStudent = temp;
			break;
		}
	}
	return ptrStudent;
}
// Find staff
Staff* getStaff(Vector<Staff> staffs, const std::string& staffID) {
	Staff* ptrStaff = nullptr;
	for (int i = 0; i < staffs.size(); i++)
		if (staffs[i].ID == staffID)
		{
			ptrStaff = &staffs[i];
			break;
		}
	return ptrStaff;
}
// Find SchoolYear
SchoolYear* getSchoolYear(Vector<SchoolYear>& schoolYears, const std::string& start) {
	const unsigned int startYear = std::stoul(start);
	SchoolYear* ptrSchoolYear = nullptr;
	for (int i = 0; i < schoolYears.size(); i++)
		if (schoolYears[i].start == startYear)
		{
			ptrSchoolYear = &schoolYears[i];
			break;
		}
	return ptrSchoolYear;
}
// Find SchoolYear
SchoolYear* getSchoolYear(Vector<SchoolYear>& schoolYears, const unsigned int& start) {
	SchoolYear* ptrSchoolYear = nullptr;
	for (int i = 0; i < schoolYears.size(); i++)
		if (schoolYears[i].start == start)
		{
			ptrSchoolYear = &schoolYears[i];
			break;
		}
	return ptrSchoolYear;
}
// Find AcademicYear
AcademicYear* getAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start) {
	const unsigned int startYear = std::stoul(start);
	AcademicYear* ptrAcademicYear = nullptr;
	for (int i = 0; i < academicYears.size(); i++)
		if (academicYears[i].start == startYear)
		{
			ptrAcademicYear = &academicYears[i];
			break;
		}
	return ptrAcademicYear;
}
// Find Academic Year
AcademicYear* getAcademicYear(Vector<AcademicYear>& academicYears, const unsigned int& start) {
	AcademicYear* ptrAcademicYear = nullptr;
	for (int i = 0; i < academicYears.size(); i++)
		if (academicYears[i].start == start)
		{
			ptrAcademicYear = &academicYears[i];
			break;
		}
	return ptrAcademicYear;
}
// Find Class
Class* getClass(Vector<SchoolYear>& schoolYears, const std::string& className) {
	for (int i = 0; i < schoolYears.size(); i++)
	{
		Class* ptrClass = schoolYears[i].getClass(className);
		if (ptrClass != nullptr)
			return ptrClass;
	}
	return nullptr;
}
// Find Semester
Semester* getSemester(Vector<AcademicYear>& academicYears, const std::string& semesterID) {
	for (int i = 0; i < academicYears.size(); i++)
	{
		Semester* ptrSemester = academicYears[i].getSemester(semesterID);
		if (ptrSemester != nullptr)
			return ptrSemester;
	}
	return nullptr;
}
// Find Course
Course* getCourse(Vector<AcademicYear>& academicYears, const std::string& courseID) {
	for (int i = 0; i < academicYears.size(); i++)
		for (int j = 0; j < academicYears[i].semesters.size(); j++)
		{
			Course* ptrCourse = academicYears[i].semesters[j].getCourse(courseID);
			if (ptrCourse != nullptr)
				return ptrCourse;
		}
	return nullptr;
}
// Find Scoreboard of Course of Student
Scoreboard* getScoreboard(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears, const std::string& courseID, const std::string& studentID) {
	Scoreboard* ptrScoreboard = nullptr;
	Course* ptrCourse = getCourse(academicYears, courseID);
	if (ptrCourse != nullptr)
		ptrScoreboard = ptrCourse->getScoreboard(studentID);
	return ptrScoreboard;
}
//----------------------------------------------------------------------------------------------//