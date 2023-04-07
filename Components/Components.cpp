#include "Components.h"

#include "AcademicYear.h"
#include "Components.h"
#include "Course.h"
#include "SchoolYear.h"
#include "Class.h"
#include "Name.h"
#include "Semester.h"
#include "Scoreboard.h"

/*			Convert enum to string function			*/ 
std::string weekday_to_string(const Weekday& weekday) {
	switch (weekday)
	{
	case MON:
		return "MON";
	case TUE:
		return "TUE";
	case WED:
		return "WED";
	case THU:
		return "THU";
	case FRI:
		return "FRI";
	case SAT:
		return "SAT";
	case SUN:
		return "SUN";
	}
	return "\n";
}
Weekday string_to_weekday(const std::string& str) {
	if (str == "MON")
		return MON;
	else if (str == "TUE")
		return TUE;
	else if (str == "WED")
		return WED;
	else if (str == "THU")
		return THU;
	else if (str == "FRI")
		return FRI;
	else if (str == "SAT")
		return SAT;
	else
		return SUN;
}
std::string session_to_string(const Session& session) {
	switch (session) {
	case S1:
		return "7:30";
	case S2:
		return "9:30";
	case S3:
		return "13:30";
	case S4:
		return "15:30";
	}
	return "\n";
}
Session string_to_session(const std::string& str) {
	if (str == "7:30")
		return S1;
	else if (str == "9:30")
		return S2;
	else if (str == "13:30")
		return S3;
	return S4;
}
std::string gender_to_string(const Gender& gender) {
	if (gender == male)
		return "Male";
	else if (gender == female) 
		return "Female";
	return "\n";
}
Gender string_to_gender(const std::string& str) {
	if (str == "Male")
		return male;
	return female;
}

//----------------------------------------------------------------------------------------------//

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

//----------------------------------------------------------------------------------------------//

/*		Insert function		*/

// Add a new SchoolYear
void addNewSchoolYear(Vector<SchoolYear>& yearList){
    unsigned int startYear;
    std::cout << "Enter the school year: "; std::cin >> startYear;
	SchoolYear* ptrSchoolYear = getSchoolYear(yearList, startYear);
	if (ptrSchoolYear != nullptr)
	{
		std::cout << "SchoolYear with start year " << startYear << " have been already existed!" << std::endl;
		return;
	}
	SchoolYear newYear;
	newYear.start = startYear;
    yearList.append(newYear);
}
// Add new class for SchoolYear
void addNewClass(SchoolYear& schoolYear){
	std::string className;
    do {
        std::cout << "Enter class name (enter 0 when done): ";
        std::getline(std::cin,className);
        if (className == "0") break;
		Class* ptrClass = schoolYear.getClass(className);
		if (ptrClass != nullptr)
		{
			std::cout << "Class " << className << " have been already existed!" << std::endl;
			return;
		}
		else
		{
			Class newClass;
			newClass.name = className;
			schoolYear.addClass(newClass);
		}
    } while (className != "0");
}
// Add a new academic year
void addNewAcademicYear(Vector<AcademicYear>& academicYears) {
	unsigned int startyear;
	AcademicYear newYear;
	bool found = false;
	std::cout << "Enter a new year: ";
	std::cin >> startyear;
	for (int i = 0; i < academicYears.size(); i++)
		if (academicYears[i].start == startyear)
		{
			found = true;
			break;
		}
	if (found)
	{
		std::cout << "Academic Year " << startyear << " have been already existed! Pls input another start year!" << std::endl;
		return;
	}
	else
	{
		newYear = { startyear };
		academicYears.append(newYear);
	}

}
// Add students into a specific class
void addStudToClass(Class &actClass){
    Student newStud;
	std::string inputStudClassFilePath = getInputStudClassFilePath(actClass);
    std::ifstream inF(inputStudClassFilePath);
    if (!inF.is_open()){
		std::cout << "Cannot open file path " << inputStudClassFilePath << std::endl;
        return;
    }
    std::string ignore;
    getline(inF, ignore);
    while (!inF.eof()){
        newStud.setInfoToClass(inF);
        actClass.addStudent(newStud);
        newStud.ptrClass = &actClass;
    }
    inF.close();
}
// Add a semester to an academic year
void addSemester(AcademicYear& newYear) {
	unsigned short day, month;
	unsigned int year;
	std::string id;
	std::cout << "Enter semester id: "; std::cin >> id;
	if (newYear.getSemester(id) != nullptr)
	{
		std::cout << "This SemesterID have been already existed in this AcademicYear! Pls input another semesterID";
		return;
	}
	Date startDate;
	std::cout << "Enter start date for the semester:\n";
	std::cin >> day >> month >> year;
	startDate.set(day, month, year);

	Date endDate;
	std::cout << "Enter end date for the semester:\n";
	std::cin >> day >> month >> year;
	endDate.set(day, month, year);

	Semester newSem;
	newSem.semesterID = id;
	newSem.startDate = startDate;
	newSem.endDate = endDate;
	newSem.ptrAcademicYear = &newYear;

	newYear.addSemester(newSem);
}
// Add a new course
void addNewCourse(Semester& semester) {
	std::string ID, classID, name, teacher;
	int cre, maxEn;
	int day, ss;

	std::cout << "Enter Course ID: ";
	std::getline(std::cin, ID);
	if (semester.getCourse(ID) != nullptr)
	{
		std::cout << "Course with ID " << ID << " have been already existed in this semester!";
		return;
	}
	std::cout << "Enter Course Name: "; std::cin >> name;
	std::cout << "Enter Teacher's Name: "; std::cin >> teacher;
	std::cout << "Enter Class ID: "; std::cin >> classID;
	std::cout << "Enter Number of Credits: "; std::cin >> cre;
	std::cout << "Enter Maximun students enrolled: "; std::cin >> maxEn;

	std::cout << "Day of week: "; std::cin >> day;
	std::cout << "Session performed: "; std::cin >> ss;

	Weekday weekday = static_cast<Weekday>(day);
	Session session = static_cast<Session>(ss);

	Course newCourse;
	newCourse.ID = ID;
	newCourse.classID = classID;
	newCourse.name = name;
	newCourse.teacher = teacher;
	newCourse.credits = cre;
	newCourse.maxEnroll = maxEn;
	//Course newCourse(ID, classID, name, teacher, cre, maxEn, weekday, session);
	semester.addCourse(newCourse);
}
// Add list student to course (from file)
void getStudentToCourse(Vector<SchoolYear>& years, Course& course) {
	std::string inputStudCourseFilePath = getInputListStudCourseFilePath(course);
	std::ifstream inF(inputStudCourseFilePath);
	if (!inF.is_open()) {
		std::cout << "Cannot open file path " << inputStudCourseFilePath << std::endl;
		return;
	}
	std::string ignore;
	getline(inF, ignore);
	getline(inF, ignore);
	getline(inF, ignore);
	getline(inF, ignore);
	getline(inF, ignore);
	getline(inF, ignore);
	getline(inF, ignore);
	getline(inF, ignore);
	getline(inF, ignore);
	std::string className;
	Class actClass;
	Class* ptrClass = nullptr;
	Student student;
	Student* ptrStudent = nullptr;
	while (!inF.eof()) {
		student.setInfoToCourseCSV(inF, className);
		actClass.name = className;
		for (int i = 0; i < years.size(); ++i)
			if (years[i].classes.find(actClass))
			{
				ptrClass = years[i].classes.find(actClass);
				break;
			}
		if (ptrClass != nullptr)
			ptrStudent = ptrClass->students.find(student);
		if (ptrStudent != nullptr)
			course.addStudent(*ptrStudent);
	}
	inF.close();
}
// Add a student to course
void addANewStudentToCourse(Vector<SchoolYear>& schoolYears, Course& course) {
	std::string studentID;
	std::cout << "Input studentID to insert to course: ";
	std::getline(std::cin, studentID);
	Student* ptrStudent = nullptr;
	for (int i = 0; i < schoolYears.size(); i++)
		for (int j = 0; j < schoolYears[i].classes.size(); j++)
			if (schoolYears[i].classes[j].getStudent(studentID) != nullptr)
			{
				ptrStudent = schoolYears[i].classes[j].getStudent(studentID);
				break;
			}
	if (ptrStudent == nullptr)
	{
		std::cout << "Student with ID " << studentID << " is not exist in school! Pls try another!";
		return;
	}
	course.addStudent(*ptrStudent);
	std::cout << "Complete add student with ID " << studentID << " to Course " << course.ID << std::endl;
}

//----------------------------------------------------------------------------------------------//

/*		Remove function		*/
// Remove list SchoolYear
void removeListSchoolYear(Vector<SchoolYear>& schoolYears){
	schoolYears.~Vector();
}
// Remove SchoolYear
void removeSchoolYear(Vector<SchoolYear>& schoolYears, const unsigned int& start) {
	SchoolYear* ptrSchoolYear = getSchoolYear(schoolYears, start);
	if (ptrSchoolYear == nullptr)
	{
		std::cout << "SchoolYear with start year " << start << "is not exist!" << std::endl;
		return;
	}
	schoolYears.remove(*ptrSchoolYear);
}
// Remove AcademicYear
void removeAcademicYear(Vector<AcademicYear>& academicYears, const unsigned int& start) {
	AcademicYear* ptrAcademicYear = getAcademicYear(academicYears, start);
	if (ptrAcademicYear == nullptr)
	{
		std::cout << "AcademicYear with start year " << start << "is not exist!" << std::endl;
		return;
	}
	academicYears.remove(*ptrAcademicYear);
}
// Remove student from course
void removeStudFromCourse(Course& course) {
	std::string studentID;
	std::cout << "Input studentID to remove from course: ";
	std::getline(std::cin, studentID);
	Student* ptrStudent = course.getStudent(studentID);
	if (ptrStudent == nullptr)
	{
		std::cout << "Student with ID " << studentID << " is not exist in this Course " << course.ID << std::endl;
		return;
	}
	Scoreboard* ptrScoreboard = course.getScoreboard(studentID);
	ptrStudent->scoreboards.remove(ptrScoreboard);
	ptrScoreboard->ptrStudent = nullptr;
	course.scoreboards.remove(ptrScoreboard);
	ptrScoreboard->ptrCourse = nullptr;
}
// Remove course from semester
void deleteCourse(Semester& semester, const std::string& courseID) {
	Course* ptrCourse = semester.getCourse(courseID);
	if (ptrCourse == nullptr)
		std::cout << "Can't find a course with ID " << courseID;
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
		semester.removeCourse(*ptrCourse); // delete course
		std::cout << "Course with ID " << courseID << " have been removed from semester!";
	}
	std::cout << std::endl;
}

//----------------------------------------------------------------------------------------------//

/*		Update function		*/	

// Update course informations
void updateCourse(Course &course){
    int option;
    do {
        std::cout << "Update course informations:\n";
        std::cout << "0. Back\n";
        std::cout << "1. Change course id\n";
        std::cout << "2. Change teacher's name\n";
        std::cout << "3. Change course name\n";
        std::cout << "4. Change class id\n";
        std::cout << "5. Change number of credits\n";
        std::cout << "6. Change max students enrolled\n";
        std::cout << "7. Change session\n";
		std::cout << "Choose the following option 0-7: ";
		std::cin >> option;
		while (option < 0 || option > 7)
		{
			std::cout << "Invalid option, pls try again: ";
			std::cin >> option;
		}
        switch (option){
            case 1: 
                std::cout << "Enter Course ID: "; std::cin >> course.ID;
                break;
            case 2: 
                std::cout << "Enter Teacher's Name: "; std::cin >> course.teacher;
                break;
            case 3: 
                std::cout << "Enter Course Name: "; std::cin >> course.name; 
                break;
            case 4: 
                std::cout << "Enter Class ID: "; std::cin >> course.classID;
                break;
            case 5:
                std::cout << "Enter Number of Credits: "; std::cin >> course.credits;
                break;
            case 6:
                std::cout << "Enter Maximun students enrolled: "; std::cin >> course.maxEnroll;
                break;
            case 7: 
                int in, day, ss;
                std::cout << "0. Change weekday\n";
                std::cout << "1. Change session\n";
                std::cin >> in;
                if (!in){
                    std::cout << "Enter weekday: "; std::cin >> day;
                    course.weekday = static_cast<Weekday>(day); 
                }
                else{
                    std::cout << "Enter Session performed: "; std::cin >> ss;
                    course.session = static_cast<Session>(ss);
                }
                break;
            default: 
				std::cout << "Exit update course information!" << std::endl;
				break;
        }
    }while (option);
}
// 22. Update student result
void updateStudentResult(Student& student) {
	viewListOfCoursesOfStudent(student);
	const int nCourse = student.scoreboards.size();
	std::cout << "Choose the course to update result (1" << " - " << nCourse << "): ";
	int option;
	std::cin >> option;
	while (option < 1 || option > nCourse)
	{
		std::cout << "Invalid option, pls try again: ";
		std::cin >> option;
	}
	Scoreboard* updateSB = student.scoreboards[option - 1];
	int updateOption;
	do
	{
		std::cout << "1. Midterm" << std::endl;
		std::cout << "2. Final" << std::endl;
		std::cout << "3. Other" << std::endl;
		std::cout << "4. Total" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "Choose the following option (0 - 4): ";
		std::cin >> updateOption;
		while (updateOption < 0 || updateOption > 4)
		{
			std::cout << "Invalid option, pls try again: ";
			std::cin >> updateOption;
		}
		if (updateOption == 0)
		{
			std::cout << "Finish update result!";
			return;
		}
		int updateScore;
		switch (updateOption)
		{
		case 1:
		{
			std::cout << "Input updated midterm score: ";
			std::cin >> updateScore;
			updateSB->midterm = updateScore;
			break;
		}
		case 2:
		{
			std::cout << "Input updated final score: ";
			std::cin >> updateScore;
			updateSB->final = updateScore;
			break;
		}
		case 3:
		{
			std::cout << "Input updated other score: ";
			std::cin >> updateScore;
			updateSB->other = updateScore;
			break;
		}
		case 4:
		{
			std::cout << "Input updated total score: ";
			std::cin >> updateScore;
			updateSB->total = updateScore;
			break;
		}
		}
	} while (updateOption != 0);
}
// 19. export list of students in course to csv file
void exportListOfStudent(Course & course) {
	std::string inputStudCouseFilePath = getInputListStudCourseFilePath(course);
	std::ofstream ofs(inputStudCouseFilePath, std::ios::out);
	course.displayInfo(ofs);
	ofs << "No,ID,Fullname" << std::endl;
	for (int i = 0; i < course.scoreboards.size(); i++)
	{
		Student* student = course.scoreboards[i]->ptrStudent;
		ofs << i + 1 << "," << student->ID << "," << student->name.get() << std::endl;
	}
	ofs.close();
}
// 20. import scoreboard of course
void importScoreBoardOfCourse(Course& course) {
	std::string inputScoreCourseFilePath = getInputScoreCourseFilePath(course);
	std::ifstream ifs(inputScoreCourseFilePath);
	if (!ifs.is_open())
	{
		std::cout << "Can't find file with path " << inputScoreCourseFilePath << std::endl;
		return;
	}
	course.importScoreBoards(ifs);
	std::cout << "Complete importion!" << std::endl;
	ifs.close();
}

//----------------------------------------------------------------------------------------------//

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