#ifndef FILE_AND_DIR_FUNCTION_H
#define FILE_AND_DIR_FUNCTION_H

#include "Components.h"

/*		Fild and folder path function		*/

void createDirectoryIfNotExists(const std::string& dirPath);

std::string getListStaffFilePath();

std::string getListSchoolYearFilePath();

std::string getListAcademicYearFilePath();

std::string getSchoolYearFolderPath(const SchoolYear& schoolyear);

std::string getInputSchoolYearFilePath(const SchoolYear& schoolyear);

std::string getClassFolderPath(const Class& CLASS);

std::string getInputStudClassFilePath(const Class& CLASS);

std::string getOutputStudClassFilePath(const Class& CLASS);

std::string getInputScoreClassFilePath(const Class& CLASS);

std::string getStudentFolderPath(const Student& student);

std::string getOutputScoreStudentFilePath(const Student& student);

std::string getInputStandardIn4StudentFilePath(const Student& student);

std::string getAcademicYearFolderPath(const AcademicYear& academicYear);

std::string getAcademicYearFilePath(const AcademicYear& academicYear);

std::string getSemesterFolderPath(const Semester& semester);

std::string getSemesterFilePath(const Semester& semester);

std::string getCourseFolderPath(const Course& course);

std::string getCourseFilePath(const Course& course);

std::string getInputListStudCourseFilePath(const Course& course);

std::string getOutputListStudCourseFilePath(const Course& course);

std::string getInputScoreCourseFilePath(const Course& course);

std::string getOutputScoreStudCourseFilePath(const Course& course);

//----------------------------------------------------------------------------------------------//

#endif