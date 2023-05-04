#ifndef FILE_AND_DIR_FUNCTION_H
#define FILE_AND_DIR_FUNCTION_H

#include "Components.h"

/*		Fild and folder path function		*/

void createDirectoryIfNotExists(const string& dirPath);

string getListStaffFilePath();

string getListStudentFilePath();

string getListSchoolYearFilePath();

string getListAcademicYearFilePath();

string getSchoolYearFolderPath(const SchoolYear& schoolyear);

string getSchoolYearFilePath(const SchoolYear& schoolyear);

string getClassFolderPath(const Class& CLASS);

string getClassFilePath(const Class& CLASS);

string getInputStudClassFilePath(const Class& CLASS);

string getDataStudClassFilePath(const Class& CLASS);

string getInputScoreClassFilePath(const Class& CLASS);

string getStudentFolderPath(const Student& student);

string getOutputScoreStudentFilePath(const Student& student);

string getInputStandardIn4StudentFilePath(const Student& student);

string getAcademicYearFolderPath(const AcademicYear& academicYear);

string getAcademicYearFilePath(const AcademicYear& academicYear);

string getSemesterFolderPath(const Semester& semester);

string getSemesterFilePath(const Semester& semester);

string getCourseFolderPath(const Course& course);

string getCourseFilePath(const Course& course);

string getInputListStudCourseFilePath(const Course& course);

string getOutputListStudCourseFilePath(const Course& course);

string getInputScoreCourseFilePath(const Course& course);

string getOutputScoreStudCourseFilePath(const Course& course);

//----------------------------------------------------------------------------------------------//

#endif