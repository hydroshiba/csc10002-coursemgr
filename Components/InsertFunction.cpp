#include "InsertFunction.h"
#include "SearchFunction.h"
#include "FileAndDirFunction.h"
#include "ConvertType.h"

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
// Add new student
bool addStudent(Vector<Student>& students, const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& genderStr, const std::string& birthStr, const std::string& socialID, const std::string& password, std::string& outStr) {
	if (ID.empty() || firstName.empty() || lastName.empty() || password.empty() || birthStr.empty() || genderStr.empty() || socialID.empty()) {
		outStr = "Please enter all the information of student in all input box to add new student";
		return false;
	}
	Student* ptrStudent = getStudent(students, ID);
	if (ptrStudent != nullptr) {
		outStr = "Student with ID " + ID + " have been already existed in school!";
		return false;
	}
	Student student;
	if (!ID.empty()) {
		student.setID(ID);
	}
	if (!firstName.empty()) {
		student.setFirstName(firstName);
	}
	if (!lastName.empty()) {
		student.setLastName(lastName);
	}
	if (!genderStr.empty()) {
		Gender gender = string_to_gender(genderStr);
		student.setGender(gender);
	}
	if (!birthStr.empty()) {
		std::string dayStr, monthStr, yearStr;
		std::stringstream ss(birthStr);
		getline(ss, dayStr, '/');
		getline(ss, monthStr, '/');
		getline(ss, yearStr);

		unsigned short day = static_cast<unsigned short>(std::stoi(dayStr));
		unsigned short month = static_cast<unsigned short>(std::stoi(monthStr));
		unsigned int year = static_cast<unsigned int>(std::stoul(yearStr));
		Date birth(day, month, year);
		student.setBirth(birth);
	}
	if (!socialID.empty()) {
		student.setSocialID(socialID);
	}
	if (!password.empty()) {
		student.setPassword(password);
	}
	students.append(student);
	outStr = "Complete add new student with ID " + ID + " to school";
	return true;
}

// Add new staff
bool addStaff(std::string curStaffID, Vector<Staff>& staffs, const std::string& ID, const std::string& password, const std::string& firstName, const std::string& lastName, std::string& outStr) {
	if (ID.empty() || firstName.empty() || lastName.empty() || password.empty()) {
		outStr = "Please enter all the information of staff in all input box to add new staff";
		return false;
	}
	Staff staff;
	staff.ID = ID;
	Staff* ptrStaff = getStaff(staffs, ID);
	if (ptrStaff != nullptr) 
	{
		outStr = "Staff with ID " + ID + " have been already existed!";
		return false;
	}
	staff.setName(firstName, lastName);
	staff.setPassword(password);
	staffs.append(staff);
	ptrStaff_Global = getStaff(staffs, curStaffID);
	outStr = "Complete add new staff with ID " + ID;
	return true;
}

// Add a new SchoolYear
bool addSchoolYear(Vector<SchoolYear>& yearList, const std::string& start, std::string& outStr) {
	if (start.empty()) {
		outStr = "Please enter the starting year in InputBox!";
		return false;
	}
	unsigned int startYear = static_cast<unsigned int>(stoul(start));
	SchoolYear* ptrSchoolYear = getSchoolYear(yearList, startYear);
	if (ptrSchoolYear != nullptr){
		outStr = "SchoolYear with start year " + start + " have been already existed!";
		return false;
	}
	SchoolYear newYear;
	newYear.start = startYear;
	yearList.append(newYear);
	outStr = "Complete add new SchoolYear with start year " + start + " to the list of SchoolYear!";
	return true;
}

// Add new class for SchoolYear
bool addClass(SchoolYear& schoolYear, const std::string& className, std::string& outStr) {
	if (className.empty()) {
		outStr = "Please enter the class name in InputBox!";
		return false;
	}
	Class* ptrClass = schoolYear.getClass(className);
	if (ptrClass != nullptr){
		outStr = "Class " + className + " have been already existed!";
		return false;
	}
	Class newClass;
	newClass.name = className;
	schoolYear.addClass(newClass);
	outStr = "Complete add class " + className + " to SchoolYear " + std::to_string(schoolYear.start) + "!";
	return true;
}

// Add students into a specific class (from File)
bool importStudentListOfClassFromFile(Vector<Student> &students, Class& actClass, std::string& outStr) {	
	std::string inputStudClassFilePath = getInputStudClassFilePath(actClass);
	std::ifstream inF(inputStudClassFilePath);
	if (!inF.is_open()) {
		outStr = "Cannot open file path " + inputStudClassFilePath;
		return false;
	}
	Student* ptrStudent = nullptr;
	std::string ignore;
	string nStudents;
	getline(inF, ignore, ',');
	getline(inF, nStudents);
	size_t n = stoull(nStudents);
	if (n == 0) {
		outStr = "Student list file is empty!";
		return false;
	}
	getline(inF, ignore);
	for (size_t i = 0; i < n; i++) {
		string studentID;
		getline(inF, ignore, ',');
		getline(inF, studentID);
		ptrStudent = getStudent(students, studentID);
		if (ptrStudent == nullptr) {
			outStr = "Student with ID " + studentID + " is not existed in school!";
			return false;
		}
		if (ptrStudent->ptrClass != nullptr) {
			outStr = "Student with ID " + studentID + " have been already existed in class " + ptrStudent->ptrClass->name;
			return false;
		}
		actClass.students.append(ptrStudent);
	}
	inF.close();
	outStr = "Complete add list of student to class " + actClass.name + "!";
	return true;
}

// Add a new students to class
bool addStudentToClass(Vector<Student>& students, Class& actClass, const std::string& studentID, std::string& outStr) { 
	if (studentID.empty()) {
		outStr = "Please enter the student ID in InputBox!";
		return false;
	}
	Student *ptrStudent = getStudent(students, studentID);
	if (ptrStudent == nullptr) {
		outStr = "Student with ID " + studentID + " is not existed in school!";
		return false;
	}
	if (ptrStudent->ptrClass != nullptr) {
		outStr = "Student with ID " + studentID + " have been already existed in class " + ptrStudent->ptrClass->name;
		return false;
	}
	actClass.students.append(ptrStudent);
	outStr = "Complete add new student with ID " + studentID + " to class " + actClass.name;
	return true;
}
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
bool addSemester(AcademicYear& newYear, const std::string& semesterID, const std::string& startDay, const std::string &startMonth, const std::string& startYear, const std::string &endDay, const std::string &endMonth, const std::string &endYear, std::string& outStr) {
	if (newYear.getSemester(semesterID) != nullptr)
	{
		//std::cout << "This SemesterID have been already existed in this AcademicYear! Pls input another semesterID";
		outStr = "This SemesterID have been already existed in this AcademicYear! Pls input another semesterID";
		return false;
	}
	unsigned short d = static_cast<unsigned short>(std::stoul(startDay));
	unsigned short m = static_cast<unsigned short>(std::stoul(startMonth));
	unsigned int y = static_cast<unsigned int>(std::stoul(startYear));
	Date startDate;
	outStr = "Enter start date for the semester:\n";
	startDate.set(d, m, y);

	d = static_cast<unsigned short>(std::stoul(endDay));
	m = static_cast<unsigned short>(std::stoul(endMonth));
	y = static_cast<unsigned int>(std::stoul(endYear));
	Date endDate;
	outStr = "Enter end date for the semester:\n";
	endDate.set(d, m, y);

	Semester newSem;
	newSem.semesterID = semesterID;
	newSem.startDate = startDate;
	newSem.endDate = endDate;
	newSem.ptrAcademicYear = &newYear;

	newYear.addSemester(newSem);
	outStr = "Complete add new Semester " + semesterID + " to AcademicYear " + std::to_string(newYear.start) + "!";
	return true;
}
// Add a new course
bool addCourse(Semester& semester, const std::string& courseID, const std::string& classID, const std::string& name, const std::string& teacher, const std::string& cre, const std::string& maxEn, const std::string& day, const std::string& ss, std::string& outStr) {
	Weekday weekday = string_to_weekday(day);
	Session session = string_to_session(ss);

	if (semester.getCourse(courseID) != nullptr)
	{
		//std::cout << "Course with ID " << ID << " have been already existed in this semester!";
		outStr = "Course with ID " + courseID + " have been already existed in this semester!";
		return false;
	}
	// std::cout << "Enter Course Name: "; std::cin >> name;
	// std::cout << "Enter Teacher's Name: "; std::cin >> teacher;
	// std::cout << "Enter Class ID: "; std::cin >> classID;
	// std::cout << "Enter Number of Credits: "; std::cin >> cre;
	// std::cout << "Enter Maximun students enrolled: "; std::cin >> maxEn;

	// std::cout << "Day of week: "; std::cin >> day;
	// std::cout << "Session performed: "; std::cin >> ss;

	Course newCourse;
	newCourse.ID = courseID;
	newCourse.classID = classID;
	newCourse.name = name;
	newCourse.teacher = teacher;
	newCourse.credits = std::stoi(cre);
	newCourse.maxEnroll = std::stoi(maxEn);
	newCourse.weekday = weekday;
	newCourse.session = session;
	//Course newCourse(ID, classID, name, teacher, cre, maxEn, weekday, session);
	semester.addCourse(newCourse);
	outStr = "Complete add new course " + courseID + " to list of course in Semester " + semester.semesterID;
	return true;
}
// Add list student to course (from file)
bool getStudentToCourse(Vector <Student> &students, Course& course, std::string& outStr) {
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
	Student student;
	Student* ptrStudent = nullptr;
	while (!inF.eof()) {
		student.setInfoToCourseCSV(inF);
		ptrStudent = getStudent(students, student.ID);
		if (ptrStudent != nullptr)
			course.addStudent(*ptrStudent);
	}
	inF.close();
	outStr = "Complete add list of student to Course " + course.ID;
	return true;
}
// Add list student to course (from file)
bool getStudentToCourse(Vector<AcademicYear>& academicYears, Vector<Student>& students, const std::string& courseID, std::string& outStr) {
	Course *ptrCourse = getCourse(academicYears, courseID);
	if (ptrCourse != nullptr){
		outStr = "Course with ID " + courseID + " have been already existed in this semester!";
		return false;
	}
	std::string inputStudCourseFilePath = getInputListStudCourseFilePath(*ptrCourse);
	std::ifstream ifs(inputStudCourseFilePath);

	if (!ifs.is_open()){
		outStr = "Cannot open file path " + inputStudCourseFilePath;
		return false;
	}

	std::string ignore;
	getline(ifs, ignore);
	getline(ifs, ignore);
	getline(ifs, ignore);
	getline(ifs, ignore);
	getline(ifs, ignore);
	getline(ifs, ignore);
	getline(ifs, ignore);
	getline(ifs, ignore);
	getline(ifs, ignore);
	Student student;
	Student* ptrStudent = nullptr;
	while (!ifs.eof()) {
		student.setInfoToCourseCSV(ifs);
		ptrStudent = getStudent(students, student.ID);
		if (ptrStudent != nullptr)
			ptrCourse->addStudent(*ptrStudent);
	}
	ifs.close();
	outStr = "Complete add list of student to Course " + ptrCourse->ID;
	return true; 
}
// Add a student to course
bool addAStudentToCourse(Vector<Student>& students, Course& course, const std::string& studentID, std::string& outStr) {
	Student* ptrStudent = getStudent(students, studentID);
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
bool addAStudentToCourse(Vector<AcademicYear>& academicYears, Vector<Student>& students, std::string& courseID, const std::string& studentID, std::string& outStr) {
	Course* ptrCourse = getCourse(academicYears, courseID);
	Student* ptrStudent = getStudent(students, studentID);
	if (ptrCourse != nullptr){
		outStr = "Course with ID " + courseID + " have been already existed in this semester!";
		return false;
	}
	if (ptrStudent == nullptr){
		outStr = "Student with ID " + studentID + " is not exist in school! Pls try another!";
		return false;
	}
	ptrCourse->addStudent(*ptrStudent);
	outStr = "Complete add student with ID " + studentID + " to Course " + ptrCourse->ID;
	return true;
}

//----------------------------------------------------------------------------------------------//