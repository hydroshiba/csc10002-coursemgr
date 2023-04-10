#include "SearchFunction.h"

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