#include "InsertFunction.h"
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


/*		Insert function		*/

// Add a new SchoolYear
bool addSchoolYear(Vector<SchoolYear>& yearList, const std::string& start, std::string& outStr) {
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	SchoolYear* ptrSchoolYear = getSchoolYear(yearList, startYear);
	if (ptrSchoolYear != nullptr)
	{
		//std::cout << "SchoolYear with start year " << startYear << " have been already existed!" << std::endl;
		outStr = "SchoolYear with start year " + start + " have been already existed!";
		return false;
	}
	SchoolYear newYear;
	newYear.start = startYear;
	yearList.append(newYear);
	outStr = "Complete add new SchoolYear with start year " + start + " to the list of SchoolYear!";
	return true;
}
// Add a new SchoolYear
bool addSchoolYear(Vector<SchoolYear>& yearList, const unsigned int& start, std::string& outStr) {
	/*unsigned int startYear;
	std::cout << "Enter the school year: "; std::cin >> startYear;*/
	SchoolYear* ptrSchoolYear = getSchoolYear(yearList, start);
	if (ptrSchoolYear != nullptr)
	{
		//std::cout << "SchoolYear with start year " << start << " have been already existed!" << std::endl;
		outStr = "SchoolYear with start year " + std::to_string(start) + " have been already existed!";
		return false;
	}
	SchoolYear newYear;
	newYear.start = start;
	yearList.append(newYear);
	outStr = "Complete add new SchoolYear with start year " + std::to_string(start) + " to the list of SchoolYear!";
	return true;
}
// Add new class for SchoolYear
bool addClass(SchoolYear& schoolYear, const std::string& className, std::string& outStr) {
	/*std::string className;
	do {
		std::cout << "Enter class name (enter 0 when done): ";
		std::getline(std::cin,className);
		if (className == "0") break;*/
	Class* ptrClass = schoolYear.getClass(className);
	if (ptrClass != nullptr)
	{
		//std::cout << "Class " << className << " have been already existed!" << std::endl;
		outStr = "Class " + className + " have been already existed!";
		return false;
	}
	else
	{
		Class newClass;
		newClass.name = className;
		schoolYear.addClass(newClass);
		outStr = "Complete add class " + className + " to SchoolYear " + std::to_string(schoolYear.start) + "!";
		return true;
	}
	//} /*while (className != "0");*/
}
// Add students into a specific class (from File)
bool addStudToClass(Class& actClass, std::string& outStr) {
	Student newStud;
	std::string inputStudClassFilePath = getInputStudClassFilePath(actClass);
	std::ifstream inF(inputStudClassFilePath);
	if (!inF.is_open()) {
		//std::cout << "Cannot open file path " << inputStudClassFilePath << std::endl;
		outStr = "Cannot open file path " + inputStudClassFilePath;
		return false;
	}
	std::string ignore;
	getline(inF, ignore);
	while (!inF.eof()) {
		newStud.setInfoToClass(inF);
		actClass.addStudent(newStud);
		newStud.ptrClass = &actClass;
	}
	inF.close();
	outStr = "Complete add list of student to class " + actClass.name + "!";
	return true;
}
// Add a new students to class
bool addStudToClass(Class& actClass, const std::string& studentID, std::string& outStr) { return false; }
// Add a new academic year
bool addAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start, std::string& outStr) {
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	if (getAcademicYear(academicYears, startYear) != nullptr)
	{
		//std::cout << "Academic Year " << startYear << " have been already existed! Pls input another start year!" << std::endl;
		outStr = "Academic Year " + start + " have been already existed! Pls input another start year!";
		return false;
	}
	else
	{
		AcademicYear newYear;
		newYear.start = startYear;
		academicYears.append(newYear);
		outStr = "Complete add new AcademicYear with start year " + start + " to the list of AcademicYear!";
		return true;
	}
}
// Add a new academic year
bool addAcademicYear(Vector<AcademicYear>& academicYears, const unsigned int& start, std::string& outStr) {
	/*unsigned int startyear;
	AcademicYear newYear;
	bool found = false;
	std::cout << "Enter a new year: ";
	std::cin >> startyear;
	for (int i = 0; i < academicYears.size(); i++)
		if (academicYears[i].start == startyear)
		{
			found = true;
			break;
		}*/
	if (getAcademicYear(academicYears, start) != nullptr)
	{
		//std::cout << "Academic Year " << start << " have been already existed! Pls input another start year!" << std::endl;
		outStr = "Academic Year " + std::to_string(start) + " have been already existed! Pls input another start year!";
		return false;
	}
	else
	{
		AcademicYear newYear;
		newYear.start = start;
		academicYears.append(newYear);
		outStr = "Complete add new AcademicYear with start year " + std::to_string(start) + " to the list of AcademicYear!";
		return true;
	}

}
// Add a semester to an academic year
bool addSemester(AcademicYear& newYear, const std::string& semesterID, std::string& outStr) {
	unsigned short day, month;
	unsigned int year;
	std::string id;
	std::cout << "Enter semester id: "; std::cin >> id;
	if (newYear.getSemester(id) != nullptr)
	{
		//std::cout << "This SemesterID have been already existed in this AcademicYear! Pls input another semesterID";
		outStr = "This SemesterID have been already existed in this AcademicYear! Pls input another semesterID";
		return false;
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
	outStr = "Complete add new Semester " + semesterID + " to AcademicYear " + std::to_string(newYear.start) + "!";
	return true;
}
// Add a new course
bool addCourse(Semester& semester, const std::string& courseID, std::string& outStr) {
	std::string ID, classID, name, teacher;
	int cre, maxEn;
	int day, ss;

	std::cout << "Enter Course ID: ";
	std::getline(std::cin, ID);
	if (semester.getCourse(ID) != nullptr)
	{
		//std::cout << "Course with ID " << ID << " have been already existed in this semester!";
		outStr = "Course with ID " + ID + " have been already existed in this semester!";
		return false;
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
	outStr = "Complete add new course " + courseID + " to list of course in Semester " + semester.semesterID;
	return true;
}
// Add list student to course (from file)
bool getStudentToCourse(Vector<SchoolYear>& years, Course& course, std::string& outStr) {
	std::string inputStudCourseFilePath = getInputListStudCourseFilePath(course);
	std::ifstream inF(inputStudCourseFilePath);
	if (!inF.is_open()) {
		//std::cout << "Cannot open file path " << inputStudCourseFilePath << std::endl;
		outStr = "Cannot open file path " + inputStudCourseFilePath;
		return false;
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
	outStr = "Complete add list of student to Course " + course.ID;
	return true;
}
// Add list student to course (from file)
bool getStudentToCourse(Vector<SchoolYear>& years, const std::string& courseID, std::string& outStr) { return false; }
// Add a student to course
bool addAStudentToCourse(Vector<SchoolYear>& schoolYears, Course& course, const std::string& studentID, std::string& outStr) {
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
		//std::cout << "Student with ID " << studentID << " is not exist in school! Pls try another!";
		outStr = "Student with ID " + studentID + " is not exist in school! Pls try another!";
		return false;
	}
	course.addStudent(*ptrStudent);
	//std::cout << "Complete add student with ID " << studentID << " to Course " << course.ID << std::endl;
	outStr = "Complete add student with ID " + studentID + " to Course " + course.ID;
	return true;
}
// Add a student to course
bool addAStudentToCourse(Vector<SchoolYear>& schoolYears, std::string& courseID, const std::string& studentID, std::string& outStr) { return false; }

//----------------------------------------------------------------------------------------------//