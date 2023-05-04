#ifndef FILE_AND_DIR_FUNCTION_H
#define FILE_AND_DIR_FUNCTION_H

#include "Components.h"

/*		Fild and folder path function		*/

void createDirectoryIfNotExists(const string& dirPath);

// Download and upload
string getListStaffFilePath();

string getListStudentFilePath();

string getListSchoolYearFilePath();

string getListAcademicYearFilePath();

string getSchoolYearFolderPath(const SchoolYear& schoolyear);

string getSchoolYearFilePath(const SchoolYear& schoolyear);

string getClassFolderPath(const Class& CLASS);

string getClassFilePath(const Class& CLASS);

string getAcademicYearFolderPath(const AcademicYear& academicYear);

string getAcademicYearFilePath(const AcademicYear& academicYear);

string getSemesterFolderPath(const Semester& semester);

string getSemesterFilePath(const Semester& semester);

string getCourseFolderPath(const Course& course);

string getCourseFilePath(const Course& course);

// Import and export
string getExportFolderPath();

string getImportFolderPath();

//----------------------------------------------------------------------------------------------//

#endif