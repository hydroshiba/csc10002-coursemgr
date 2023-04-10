#include "Components.h"

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

#include "ConvertType.h"
#include "SearchFunction.h"
#include "InsertFunction.h"


/*		Display function	*/

// View list of courses
void viewCourses(Semester& sem, std::ostream& outDev) {
	std::cout << "List of courses: ";
	for (size_t i = 0; i < sem.courses.size(); ++i)
		sem.courses[i].displayInfo(outDev);
}
// 14. view list of courses at current student
void viewListOfCoursesOfStudent(const Student& student, std::ostream& outDev) {
	outDev << "List of courses: ";
	for (int i = 0; i < student.scoreboards.size(); i++)
	{
		outDev << "No " << i + 1 << ": " << std::endl;
		student.scoreboards[i]->ptrCourse->displayInfoScreen();
		outDev << "--------------------------------------" << std::endl;
	}
}
// 15. view list of classes 
void viewListOfClasses(const SchoolYear& schoolYear, std::ostream& outDev) {
	outDev << "List of classes: " << std::endl;
	for (int i = 0; i < schoolYear.classes.size(); i++)
		outDev << i + 1 << ". " << schoolYear.classes[i].name << std::endl;
}
// 16. view list of students in a class
void viewListOfStudentsInClass(const Class& curClass, std::ostream& outDev) {
	outDev << "List of students in class " << curClass.name << ": " << std::endl;
	for (int i = 0; i < curClass.students.size(); i++)
	{
		outDev << i + 1 << ". " << curClass.students[i].ID << " - " << curClass.students[i].name.get();
		outDev << std::endl;
	}
}
// 17. view list of course
void viewListOfCoursesInSemester(const Semester& semester, std::ostream& outDev) {
	outDev << "List of course in this semester: " << std::endl;
	outDev << "No  " << "CourseID   " << "ClassID   " << std::endl;
	for (int i = 0; i < semester.courses.size(); i++)
	{
		outDev << "No " << i + 1 << ": " << std::endl;
		semester.courses[i].displayInfo(outDev);
	}
}
// 18. view list of students in course
void viewListOfStudentsInCourse(const Course& course, std::ostream& outDev) {
	outDev << "List of students in course " << course.ID << " - " << course.name << ": " << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		outDev << i + 1 << ". " << student->ID << " - " << student->name.get() << std::endl;
	}
}
// 21. view scoreboard of course
void viewScoreBoardOfCourse(Course& course) {
	std::cout << "1. View on screen" << std::endl;
	std::cout << "2. View on file" << std::endl;
	std::cout << "Choose one of following options to view: ";
	int option;
	std::cin >> option;
	while (option <= 0 || option > 2)
	{
		std::cout << "Invalid option! Pls input 1 or 2: ";
		std::cin >> option;
	}
	switch (option)
	{
	case 1:
	{
		course.displayScoreBoardScreen();
		break;
	}
	case 2:
	{
		std::cout << "Input filename: ";
		std::string fileName;
		std::getline(std::cin, fileName, '\n');
		fileName = "Data\\" + fileName;
		std::ofstream ofs(fileName);
		if (!ofs.is_open())
		{
			std::cout << "Can't find file with that name, pls try again!" << std::endl;
			return;
		}
		course.displayScoreBoardFile(ofs);
		break;
	}
	}
}
// 23. View scoreboard of class
void viewScoreboardOfClass(Class& curClass, const Semester& curSemester) {
	std::cout << "1. View on screen" << std::endl;
	std::cout << "2. View on file" << std::endl;
	std::cout << "Choose one of following options to view: ";
	int option;
	std::cin >> option;
	while (option <= 0 || option > 2)
	{
		std::cout << "Invalid option! Pls input 1 or 2: ";
		std::cin >> option;
	}
	switch (option)
	{
	case 1:
	{
		curClass.displayScoreboardScreen(curSemester);
		break;
	}
	case 2:
	{
		std::cout << "Input filename: ";
		std::string fileName;
		std::getline(std::cin, fileName, '\n');
		fileName = "Data\\" + fileName;
		std::ofstream ofs(fileName);
		if (!ofs.is_open())
		{
			std::cout << "Can't find file with that name, pls try again!" << std::endl;
			return;
		}
		curClass.displayScoreboardFile(curSemester, ofs);
		break;
	}
	}
}
// 24. view scoreboard of student
void viewScoreBoardOfStudent(Student& student) {
	const int noMaxLength = 3;
	const int idSemesterMaxLength = 10;
	const int idCourseNameMaxLength = 20;
	const int midtermMaxLength = 10;
	const int finalMaxLength = 8;
	const int totalMaxLength = 8;
	const int otherMaxLength = 8;
	std::cout << std::setw(noMaxLength) << std::left << "No";
	std::cout << std::setw(idSemesterMaxLength) << std::left << "Semester";
	std::cout << std::setw(idCourseNameMaxLength) << std::left << "Course";
	std::cout << std::setw(midtermMaxLength) << std::left << "Midterm";
	std::cout << std::setw(finalMaxLength) << std::left << "Final";
	std::cout << std::setw(otherMaxLength) << std::left << "Other";
	std::cout << std::setw(totalMaxLength) << std::left << "Total";
	std::cout << std::endl;
	for (int i = 0; i < student.scoreboards.size(); i++)
	{
		std::cout << std::setw(noMaxLength) << std::left << i + 1;
		std::cout << std::setw(idSemesterMaxLength) << std::left << student.scoreboards[i]->ptrCourse->ptrSemester->semesterID;
		std::cout << std::setw(idCourseNameMaxLength) << std::left << student.scoreboards[i]->ptrCourse->ID;
		std::cout << std::setw(midtermMaxLength) << std::left << student.scoreboards[i]->midterm;
		std::cout << std::setw(finalMaxLength) << std::left << student.scoreboards[i]->final;
		std::cout << std::setw(otherMaxLength) << std::left << student.scoreboards[i]->other;
		std::cout << std::setw(totalMaxLength) << std::left << student.scoreboards[i]->total;
		std::cout << std::endl;
	}
	std::cout << std::setw(noMaxLength) << std::left << "GPA:" << student.getGPA() << std::endl;
}

//----------------------------------------------------------------------------------------------//

/*		Fild and folder path function		*/

void createDirectoryIfNotExists(const std::string& dirPath)
{
	if (!std::filesystem::exists(dirPath)) {
		std::filesystem::create_directory(dirPath);
		std::cout << "Create directory " << dirPath << std::endl;
	}
}

std::string getListSchoolYearFilePath() {
	return "Data\\SchoolYear\\ListSchoolYear.txt";
}

std::string getListAcademicYearFilePath() {
	return "Data\\AcademicYear\\ListAcademicYear.txt";
}

std::string getSchoolYearFolderPath(const SchoolYear& schoolyear) {
	std::string schoolYearDirPath = "Data\\SchoolYear\\HCMUS_" + std::to_string(schoolyear.start) + "\\";
	createDirectoryIfNotExists(schoolYearDirPath);
	return schoolYearDirPath;
}

std::string getInputSchoolYearFilePath(const SchoolYear& schoolyear) {
	std::string schoolYearFolderPath = getSchoolYearFolderPath(schoolyear);
	return schoolYearFolderPath + "HCMUS_" + std::to_string(schoolyear.start) + ".txt";
}

std::string getClassFolderPath(const Class& CLASS) {
	std::string schoolYearFolderPath = getSchoolYearFolderPath(*(CLASS.ptrSchoolYear));
	std::string classFolderPath = schoolYearFolderPath + CLASS.name + "\\";
	createDirectoryIfNotExists(classFolderPath);
	return classFolderPath;
}

std::string getInputStudClassFilePath(const Class& CLASS) {
	std::string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_InputStud.csv";
}

std::string getOutputStudClassFilePath(const Class& CLASS) {
	std::string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_OutputStud.csv";
}

std::string getInputScoreClassFilePath(const Class& CLASS) {
	std::string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_OutputScore.csv";
}

std::string getStudentFolderPath(const Student& student) {
	std::string classFolderPath = getClassFolderPath(*(student.ptrClass));
	std::string studentFolderPath = classFolderPath + "Students\\" + student.ID + "\\";
	createDirectoryIfNotExists(studentFolderPath);
	return studentFolderPath;
}

std::string getOutputScoreStudentFilePath(const Student& student) {
	std::string studentFolderPath = getStudentFolderPath(student);
	return studentFolderPath + student.ID + "_OutputScore.csv";
}

std::string getInputStandardIn4StudentFilePath(const Student& student) {
	std::string studentFolderPath = getStudentFolderPath(student);
	return studentFolderPath + student.ID + "_OutputStdIn4.csv";
}

std::string getAcademicYearFolderPath(const AcademicYear& academicYear) {
	std::string academicYearFolderPath = "Data\\AcademicYear\\" + std::to_string(academicYear.start) + "_" + std::to_string(academicYear.start + 1) + "\\";
	createDirectoryIfNotExists(academicYearFolderPath);
	return academicYearFolderPath;
}

std::string getAcademicYearFilePath(const AcademicYear& academicYear) {
	std::string academicYearFolderPath = getAcademicYearFolderPath(academicYear);
	return academicYearFolderPath + std::to_string(academicYear.start) + "_" + std::to_string(academicYear.start + 1) + ".txt";
}

std::string getSemesterFolderPath(const Semester& semester) {
	std::string academicYearFolderPath = getAcademicYearFolderPath(*(semester.ptrAcademicYear));
	std::string semesterFolderPath = academicYearFolderPath + semester.semesterID + "\\";
	return semesterFolderPath;
}

std::string getSemesterFilePath(const Semester& semester) {
	std::string semesterFolderPath = getSemesterFolderPath(semester);
	return semesterFolderPath + semester.semesterID + ".txt";
}

std::string getCourseFolderPath(const Course& course) {
	std::string semesterFolderPath = getSemesterFolderPath(*(course.ptrSemester));
	std::string courseFolderPath = semesterFolderPath + course.ID + "\\";
	return courseFolderPath;
}

std::string getCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + ".txt";
}

std::string getInputListStudCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_InputStud.csv";
}

std::string getOutputListStudCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_OutputStud.csv";
}

std::string getInputScoreCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_InputScore.csv";
}

std::string getOutputScoreStudCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_OutputScore.csv";
}

//----------------------------------------------------------------------------------------------//

/*			Upload and download function		*/

// SchoolYear

void downloadListSchoolYearFolder(Vector <SchoolYear>& schoolYears){
	std::string listSchoolYearDir = getListSchoolYearFilePath();
	std::ofstream ofs(listSchoolYearDir);
	/*if (!ofs.is_open()){
		std::cout << "Cannot open " << listSchoolYearDir << '\n';
		return;
	}*/
	ofs << schoolYears.size() << '\n';
	for (int i = 0; i<schoolYears.size(); ++i){
		ofs << schoolYears[i].start << '\n';
		downloadSchoolYearFolder(schoolYears[i]);
	}
	ofs.close();
}

void downloadSchoolYearFolder(SchoolYear &schoolYear){
	std::string schoolYearDir = getInputSchoolYearFilePath(schoolYear);
	std::ofstream ofs(schoolYearDir);
	/*if (!ofs.is_open()){
		std::cout << "Cannot open " << schoolYearDir;
		return;
	}*/
	ofs << schoolYear.start << '\n';
	ofs << schoolYear.classes.size() << '\n';
	for (int i = 0; i<schoolYear.classes.size(); ++i){
		ofs << schoolYear.classes[i].name;
		downloadOutputStudClassFile(schoolYear.classes[i]);
		for (int j = 0; j<schoolYear.classes[i].students.size(); ++j)
			downloadStudentFolder(schoolYear.classes[i].students[j]);
	}
	ofs.close();
}

void downloadOutputStudClassFile(Class &actClass){
	std::string outputStudentDir = getOutputStudClassFilePath(actClass);
	std::ofstream ofs (outputStudentDir);
	ofs << "Class," << actClass.name << '\n';
	ofs << "Number of student," << actClass.students.size();
	ofs << "No,StudentID,First name,Last name,Gender,Date of Birth,SocialID\n";
	for (int i = 0; i<actClass.students.size(); ++i){
		ofs << i+1 << ",";
		ofs << actClass.students[i].ID << ",";
		ofs << actClass.students[i].name.first << "," << actClass.students[i].name.last << ",";
		ofs << gender_to_string(actClass.students[i].gender) << ",";
		ofs << actClass.students[i].birth.day << "/" << actClass.students[i].birth.month << "/" << actClass.students[i].birth.year << ",";
		ofs << actClass.students[i].socialID << "\n";
	}	
	ofs.close();
}

void downloadStudentFolder(Student& student){
	std::string studentDir = getInputStandardIn4StudentFilePath(student);
	std::ofstream ofs(studentDir);
	/*if (!ofs.is_open()){
		std::cout << "Cannot open " << studentDir;
		return;
	}*/
	ofs << "ID," << student.ID << std::endl;
	ofs << "Name," << student.name.get() << std::endl;
	ofs << "Gender," << gender_to_string(student.gender) << std::endl;
	ofs << "Dob," << student.birth.get() << std::endl;
	ofs << "SocialID," << student.socialID << std::endl;
	ofs << "Class," << student.ptrClass->name << std::endl;
	ofs.close();
}

void uploadAllData(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears){
	uploadListSchoolYearFolder(schoolYears);
	uploadListAcademicYearFolder(schoolYears, academicYears);
}

void uploadListSchoolYearFolder(Vector <SchoolYear>& schoolYears){
	std::string listSchoolYearDir = getListSchoolYearFilePath();
	std::ifstream ifs(listSchoolYearDir);
	if (!ifs.is_open()){
		std::cout << "Cannot open " << listSchoolYearDir;
		return;
	}
	size_t nSchoolYear;
	ifs >> nSchoolYear;
	schoolYears.resize(nSchoolYear);
	for (int i = 0; i<schoolYears.size(); ++i){
		unsigned int startYear;
		SchoolYear school_year;
		ifs >> startYear;
		school_year.start = startYear;
		schoolYears[i] = school_year;
		uploadSchoolYearFolder(schoolYears[i]);
	}
	ifs.close();
}	

void uploadSchoolYearFolder(SchoolYear &schoolYear){
	std::string schoolYearDir = getInputSchoolYearFilePath(schoolYear);
	std::ifstream ifs(schoolYearDir);
	if (!ifs.is_open()){
		std::cout << "Cannot open " << schoolYearDir << '\n';
		return;
	}
	unsigned int start;
	ifs >> start;
	if (start == schoolYear.start){
		std::cout << "Incorrect directory\n";
		return;
	}
	size_t nClasses;
	ifs >> nClasses;
	schoolYear.classes.resize(nClasses);
	for (int i = 0; i<nClasses; ++i){
		std::string className;
		ifs >> className;
		schoolYear.classes[i].name = className; 
		schoolYear.classes[i].ptrSchoolYear = &schoolYear;
		get_students_priority(schoolYear.classes[i]);
	}
	ifs.close();
}

void uploadStudentFolder(Class &actClass, Student &student, std::string id){
	std::string studentDir = "Students\\"+ id + "\\" + id + "_OutputStdIn4.csv";
	std::ifstream ifs (studentDir);
	if (!ifs.is_open()){
		std::cout << "Cannot open " << studentDir;
		return;
	}
	std::string ignore;
	std::string ID, first, last, gender, socialId, className, day, month, year;
	uint64_t password;
	std::getline(ifs, ignore, ',');
	ifs >> id;
	std::getline(ifs, ignore, ',');
	ifs >> password;
	std::getline(ifs, ignore, ',');
	std::getline(ifs, first);
	std::getline(ifs, ignore, ',');
	std::getline(ifs, last);
	std::getline(ifs, ignore, ',');
	ifs >> gender;
	std::getline(ifs, ignore, ',');
	std::getline(ifs, day, '/');
	std::getline(ifs, month, '/');
	std::getline(ifs, year);
	std::getline(ifs, ignore, ',');
	ifs >> socialId;
	std::getline(ifs, ignore, ',');
	ifs >> className;
	if (actClass.name != className){
		std::cout << "Incorrect class directory";
		return;
	}
	unsigned short d = static_cast<unsigned short>(std::stoul(day)), m = static_cast<unsigned short>(std::stoul(month));
	unsigned int y = static_cast<unsigned int>(std::stoul(year));

	Student studInfo({first, last}, id, password,string_to_gender(gender),{d, m, y}, socialId, &actClass);
}

void get_students_priority(Class &actClass){
	std::string oFile = getOutputStudClassFilePath(actClass);
	std::ifstream ifs (oFile);
	if (!ifs.is_open()){
		std::cout << "Cannot open " << oFile;
		return;
	}
	std::string ignore;
	std::string className;
	std::getline(ifs, ignore, ',');
	std::getline(ifs, className);
	if (className != actClass.name){
		std::cout << "Incorrect file!";
		return;
	}
	std::getline(ifs, ignore, ',');
	size_t nStud;
	ifs >> nStud;
	actClass.students.resize(nStud);
	std::string id;
	std::getline(ifs, ignore);
	for (int i = 0; i<actClass.students.size(); ++i){
		std::getline(ifs, ignore, ',');
		std::getline(ifs, id, ',');
		uploadStudentFolder(actClass, actClass.students[i], id);
		std::getline(ifs, ignore);
	}
	ifs.close();
}


// AcademicYear

void downloadAllData(Vector <SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears){
	downloadListSchoolYearFolder(schoolYears);
	downloadListAcademicYearFolder(academicYears);
}

void downloadListAcademicYearFolder(Vector<AcademicYear>& academicYears) {
	std::string listAcademicYearFilePath = getListAcademicYearFilePath();
	std::ofstream ofs(listAcademicYearFilePath);
	ofs << academicYears.size() << std::endl;
	for (int i = 0; i < academicYears.size(); i++)
	{
		ofs << academicYears[i].start << std::endl;
		downloadAcademicYearFolder(academicYears[i]);
	}
	ofs.close();
}

void downloadAcademicYearFolder(AcademicYear& academicYear) {
	std::string academicYearFilePath = getAcademicYearFilePath(academicYear);
	std::ofstream ofs(academicYearFilePath);
	ofs << academicYear.start << std::endl;
	ofs << academicYear.semesters.size() << std::endl;
	for (int i = 0; i < academicYear.semesters.size(); i++)
	{
		ofs << academicYear.semesters[i].semesterID << std::endl;
		downloadSemesterFolder(academicYear.semesters[i]);
	}
	ofs.close();
}

void downloadSemesterFolder(Semester& semester) {
	std::string semesterFilePath = getSemesterFilePath(semester);
	std::ofstream ofs(semesterFilePath);
	ofs << semester.semesterID << std::endl;
	ofs << semester.startDate.day << "/" << semester.startDate.month << "/" << semester.startDate.year << std::endl;
	ofs << semester.endDate.day << "/" << semester.endDate.month << "/" << semester.endDate.year << std::endl;
	ofs << semester.courses.size() << std::endl;
	for (int i = 0; i < semester.courses.size(); i++)
		ofs << semester.courses[i].ID << std::endl;
	for (int i = 0; i < semester.courses.size(); i++)
	{
		downloadCourseFolder(semester.courses[i]);
		dowdloadScoreboardFile(semester.courses[i]);
	}
	ofs.close();
}

void downloadCourseFolder(Course& course) {
	std::string courseFilePath = getCourseFilePath(course);
	std::ofstream ofs(courseFilePath);
	ofs << course.ID << std::endl;
	ofs << course.classID << std::endl;
	ofs << course.name << std::endl;
	ofs << course.teacher << std::endl;
	ofs << course.credits << std::endl;
	ofs << course.maxEnroll << std::endl;
	ofs << course.weekday << std::endl;
	ofs << course.session << std::endl;
	ofs.close();
}

void dowdloadScoreboardFile(Course& course) {
	std::string scoreBoardFilePath = getOutputScoreStudCourseFilePath(course);
	std::ofstream ofs(scoreBoardFilePath);
	course.displayScoreBoardFile(ofs);
	ofs.close();
}

void uploadListAcademicYearFolder(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears) {
	std::string listAcademicYearFilePath = getListAcademicYearFilePath();
	std::ifstream ifs(listAcademicYearFilePath);
	if (!ifs.is_open())
	{
		std::cout << "Can't open " << listAcademicYearFilePath << std::endl;
		return;
	}
	int nAcademicYear;
	ifs >> nAcademicYear;
	academicYears.resize(nAcademicYear);
	unsigned int startOfAcademicYear;
	for (int i = 0; i < academicYears.size(); i++)
	{
		ifs >> startOfAcademicYear;
		AcademicYear academicYear;
		academicYear.start = startOfAcademicYear;
		academicYears.append(academicYear);
		uploadAcademicYearFolder(schoolYears, academicYears[i]);
	}
	ifs.close();
}

void uploadAcademicYearFolder(Vector<SchoolYear>& schoolYears, AcademicYear& academicYear) {
	std::string academicYearFilePath = getAcademicYearFilePath(academicYear);
	std::ifstream ifs(academicYearFilePath);
	if (!ifs.is_open())
	{
		std::cout << "Can't open " << academicYearFilePath << std::endl;
		return;
	}
	unsigned int startOfAcademicYear;
	ifs >> startOfAcademicYear;
	if (startOfAcademicYear != academicYear.start)
	{
		std::cout << "Incorrect file path " << academicYearFilePath << std::endl;
		return;
	}
	int nSemester;
	ifs >> nSemester;
	academicYear.semesters.resize(nSemester);
	std::string semesterID = "";
	std::getline(ifs, semesterID);
	for (int i = 0; i < academicYear.semesters.size(); i++)
	{
		std::getline(ifs, semesterID);
		Semester semester;
		semester.semesterID = semesterID;
		academicYear.semesters.append(semester);
		academicYear.semesters[i].ptrAcademicYear = &academicYear;
		uploadSemesterFolder(schoolYears, academicYear.semesters[i]);
	}
	ifs.close();
}

void uploadSemesterFolder(Vector<SchoolYear>& schoolYears, Semester& semester) {
	std::string semesterFilePath = getSemesterFilePath(semester);
	std::ifstream ifs(semesterFilePath);
	if (!ifs.is_open())
	{
		std::cout << "Can't open " << semesterFilePath << std::endl;
		return;
	}
	std::string semesterID;
	std::getline(ifs, semesterID);
	if (semester.semesterID != semesterID)
	{
		std::cout << "Incorrect file path " << semesterFilePath << std::endl;
		return;
	}
	Date startDate, endDate;
	std::string day, month, year;
	getline(ifs, day, '/');
	getline(ifs, month, '/');
	getline(ifs, year);
	startDate.set(std::stoi(day), std::stoi(month), std::stoi(year));
	getline(ifs, day, '/');
	getline(ifs, month, '/');
	getline(ifs, year);
	endDate.set(std::stoi(day), std::stoi(month), std::stoi(year));
	semester.startDate = startDate;
	semester.endDate = endDate;
	int nCourse;
	std::string courseID = "";
	ifs >> nCourse;
	semester.courses.resize(nCourse);
	std::getline(ifs, courseID);
	for (int i = 0; i < semester.courses.size(); i++)
	{
		std::getline(ifs, courseID);
		Course course;
		course.ID = courseID;
		semester.courses.append(course);
		semester.courses[i].ptrSemester = &semester;
		uploadCourseFolder(semester.courses[i]);
	}
	ifs.close();
}

void uploadCourseFolder(Course& course) {
	std::string courseFilePath = getCourseFilePath(course);
	std::ifstream ifs(courseFilePath);
	if (!ifs.is_open())
	{
		std::cout << "Can't open " << courseFilePath << std::endl;
		return;
	}
	std::string courseID;
	std::getline(ifs, courseID);
	if (course.ID != courseID)
	{
		std::cout << "Incorrect file path " << courseFilePath << std::endl;
		return;
	}
	std::string classID, name, teacher, weekdayStr, sessionStr, sTemp;
	Weekday weekday;
	Session session;
	int credits, maxEnroll;
	std::getline(ifs, classID);
	std::getline(ifs, name);
	std::getline(ifs, teacher);
	ifs >> credits >> maxEnroll;
	std::getline(ifs, sTemp);
	std::getline(ifs, weekdayStr);
	weekday = string_to_weekday(weekdayStr);
	std::getline(ifs, sessionStr);
	session = string_to_session(sessionStr);
	course.classID = classID;
	course.name = name;
	course.teacher = teacher;
	course.credits = credits;
	course.maxEnroll = maxEnroll;
	course.weekday = weekday;
	course.session = session;
	ifs.close();
}

//----------------------------------------------------------------------------------------------//