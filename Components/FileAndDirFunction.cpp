#include "FileAndDirFunction.h"


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

/*		Fild and folder path function		*/

void createDirectoryIfNotExists(const string& dirPath)
{
	if (!std::filesystem::exists(dirPath)) {
		std::filesystem::create_directory(dirPath);
		std::cout << "Create directory " << dirPath << std::endl;
	}
}

string getListStaffFilePath(){
	return "Data/StaffList.csv";
}

string getListStudentFilePath(){
	return "Data/StudentList.csv";
}

string getListSchoolYearFilePath() {
	return "Data/SchoolYear/ListSchoolYear.csv";
}

string getListAcademicYearFilePath() {
	return "Data/AcademicYear/ListAcademicYear.csv";
}

string getSchoolYearFolderPath(const SchoolYear& schoolyear) {
	string schoolYearDirPath = "Data/SchoolYear/HCMUS_" + std::to_string(schoolyear.start) + "/";
	createDirectoryIfNotExists(schoolYearDirPath);
	return schoolYearDirPath;
}

string getSchoolYearFilePath(const SchoolYear& schoolyear) {
	string schoolYearFolderPath = getSchoolYearFolderPath(schoolyear);
	return schoolYearFolderPath + "HCMUS_" + std::to_string(schoolyear.start) + ".csv";
}

string getClassFolderPath(const Class& CLASS) {
	string schoolYearFolderPath = getSchoolYearFolderPath(*(CLASS.ptrSchoolYear));
	string classFolderPath = schoolYearFolderPath + CLASS.name + "/";
	createDirectoryIfNotExists(classFolderPath);
	return classFolderPath;
}

string getClassFilePath(const Class& CLASS) {
	string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + ".csv";
}

string getAcademicYearFolderPath(const AcademicYear& academicYear) {
	string academicYearFolderPath = "Data/AcademicYear/" + std::to_string(academicYear.start) + "_" + std::to_string(academicYear.start + 1) + "/";
	createDirectoryIfNotExists(academicYearFolderPath);
	return academicYearFolderPath;
}

string getAcademicYearFilePath(const AcademicYear& academicYear) {
	string academicYearFolderPath = getAcademicYearFolderPath(academicYear);
	return academicYearFolderPath + std::to_string(academicYear.start) + "_" + std::to_string(academicYear.start + 1) + ".csv";
}

string getSemesterFolderPath(const Semester& semester) {
	string academicYearFolderPath = getAcademicYearFolderPath(*(semester.ptrAcademicYear));
	string semesterFolderPath = academicYearFolderPath + semester.semesterID + "/";
	return semesterFolderPath;
}

string getSemesterFilePath(const Semester& semester) {
	string semesterFolderPath = getSemesterFolderPath(semester);
	return semesterFolderPath + semester.semesterID + ".csv";
}

string getCourseFolderPath(const Course& course) {
	string semesterFolderPath = getSemesterFolderPath(*(course.ptrSemester));
	string courseFolderPath = semesterFolderPath + course.ID + "/";
	return courseFolderPath;
}

string getCourseFilePath(const Course& course) {
	string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + ".csv";
}

// Import and export
string getExportFolderPath() {
	return "Data/ExportData/";
}

string getImportFolderPath() {
	return "Data/ImportData/";
}
//----------------------------------------------------------------------------------------------//

