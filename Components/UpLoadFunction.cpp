#include "UploadFunction.h"
#include "ConvertType.h"
#include "FileAndDirFunction.h"
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

void uploadAllData(Vector<Staff::User>& staffs, Vector<Student> &students, Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears) {
	uploadListStudent(students);
	uploadListStaff(staffs);
	uploadListSchoolYearFolder(students, schoolYears);
	uploadListAcademicYearFolder(schoolYears, academicYears);
}

void uploadListStaff(Vector<Staff::User>& staffs){
	std::string list_staff_dir = getListStaffFilePath();
	std::ifstream ifs (list_staff_dir);
	std::string first, last, ID, pass, ignore;
	std::string nStaffs;
	getline(ifs, ignore, ',');
	getline(ifs, nStaffs);
	size_t n = stoull(nStaffs);
	getline(ifs, ignore);
	for (int i = 0; i<n; ++i){
		getline(ifs, ignore, ',');
		getline(ifs, first, ',');
		getline(ifs, last, ',');
		getline(ifs,ID, ',');
		getline(ifs, pass);
		Staff newStaff({first, last}, ID, pass);
		staffs.append(newStaff);
	}
	ifs.close();
}

void uploadListStudent(Vector<Student>& students){
	std::string list_stud_dir = getListStudentFilePath();
	std::ifstream ifs (list_stud_dir);
	std::string ID, pass, first, last, gender, socialId, className, day, month, year;
	std::string ignore;
	std::getline (ifs, ignore);
	while (!ifs.eof()){
		std::getline(ifs, ID, ',');
		std::getline(ifs, pass, ',');
		std::getline(ifs, first, ',');
		std::getline(ifs, last, ',');
		std::getline(ifs, gender, ',');
		std::getline(ifs, day, '/');
		std::getline(ifs, month, '/');
		std::getline(ifs, year, ',');
		std::getline(ifs, socialId);
		unsigned short d = static_cast<unsigned short>(std::stoul(day)), m = static_cast<unsigned short>(std::stoul(month));
		unsigned int y = static_cast<unsigned int>(std::stoul(year));
		Student newStudent({ first, last }, ID, pass, string_to_gender(gender), { d, m, y }, socialId);
		students.append(newStudent);
	}
	ifs.close();
}

void uploadListSchoolYearFolder(Vector <Student> &students, Vector <SchoolYear>& schoolYears) {
	std::string listSchoolYearDir = getListSchoolYearFilePath();
	std::ifstream ifs(listSchoolYearDir);
	if (!ifs.is_open()) {
		std::cout << "Cannot open " << listSchoolYearDir;
		return;
	}
	size_t nSchoolYear;
	ifs >> nSchoolYear;
	schoolYears.resize(nSchoolYear);
	for (int i = 0; i < schoolYears.size(); ++i) {
		unsigned int startYear;
		SchoolYear school_year;
		ifs >> startYear;
		school_year.start = startYear;
		schoolYears[i] = school_year;
		uploadSchoolYearFolder(students, schoolYears[i]);
	}
	ifs.close();
}

void uploadSchoolYearFolder(Vector <Student>& students, SchoolYear& schoolYear) {
	std::string schoolYearDir = getInputSchoolYearFilePath(schoolYear);
	std::ifstream ifs(schoolYearDir);
	if (!ifs.is_open()) {
		std::cout << "Cannot open " << schoolYearDir << '\n';
		return;
	}
	unsigned int start;
	ifs >> start;
	if (start == schoolYear.start) {
		std::cout << "Incorrect directory\n";
		return;
	}
	size_t nClasses;
	ifs >> nClasses;
	schoolYear.classes.resize(nClasses);
	for (int i = 0; i < nClasses; ++i) {
		std::string className;
		ifs >> className;
		schoolYear.classes[i].name = className;
		schoolYear.classes[i].ptrSchoolYear = &schoolYear;
		get_students_priority(students, schoolYear.classes[i]);
	}
	ifs.close();
}
/*
void uploadStudentFolder(Class& actClass, Student& student, std::string id) {
	std::string studentDir = "Students\\" + id + "\\" + id + "_OutputStdIn4.csv";
	std::ifstream ifs(studentDir);
	if (!ifs.is_open()) {
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
	if (actClass.name != className) {
		std::cout << "Incorrect class directory";
		return;
	}
	unsigned short d = static_cast<unsigned short>(std::stoul(day)), m = static_cast<unsigned short>(std::stoul(month));
	unsigned int y = static_cast<unsigned int>(std::stoul(year));

	Student studInfo({ first, last }, id, password, string_to_gender(gender), { d, m, y }, socialId, &actClass);
}
*/
void get_students_priority(Vector<Student> &students, Class& actClass) {
	std::string oFile = getOutputStudClassFilePath(actClass);
	std::ifstream ifs(oFile);
	if (!ifs.is_open()) {
		std::cout << "Cannot open " << oFile;
		return;
	}
	std::string ignore;
	std::string className;
	std::getline(ifs, ignore, ',');
	std::getline(ifs, className);
	if (className != actClass.name) {
		std::cout << "Incorrect file!";
		return;
	}
	std::getline(ifs, ignore, ',');
	size_t nStud;
	ifs >> nStud;
	actClass.students.resize(nStud);
	std::string id;
	Student *ptrStudent;
	std::getline(ifs, ignore);
	for (int i = 0; i < actClass.students.size(); ++i) {
		std::getline(ifs, ignore, ',');
		std::getline(ifs, id, ',');
		std::getline(ifs, ignore);
		ptrStudent = getStudent(students, id);
		actClass.students[i] = ptrStudent;
		actClass.students[i]->ptrClass = &actClass;
	}
	ifs.close();
}


// AcademicYear



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
		academicYears[i] = academicYear;
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
		academicYear.semesters[i] = semester;
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
		semester.courses[i] = course;
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