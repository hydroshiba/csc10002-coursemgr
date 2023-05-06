#include "UploadFunction.h"
#include "ConvertType.h"
#include "FileAndDirFunction.h"
#include "SearchFunction.h"
#include "RemoveFunction.h"

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

bool uploadAllData() {
	bool b1 = uploadListStudent();
	bool b2 = uploadListStaff();
	bool b3 = uploadListSchoolYear();
	bool b4 = uploadListAcademicYear();
	if (b1 && b2 && b3 && b4 == false) {
		freeMemory();
		return false;
	}
	return true;
}

bool uploadListStaff(){
	string list_staff_dir = getListStaffFilePath();
	std::ifstream ifs (list_staff_dir);
	if (!ifs) return false;
	string first, last, ID, pass, ignore;
	string nStaffs;
	getline(ifs, ignore, ',');
	getline(ifs, nStaffs);
	size_t n = stoull(nStaffs);
	if (n == 0) return true;
	staffs.resize(n);
	getline(ifs, ignore);
	for (int i = 0; i<n; ++i){
		getline(ifs, ignore, ',');
		getline(ifs, first, ',');
		getline(ifs, last, ',');
		getline(ifs,ID, ',');
		getline(ifs, pass);
		Staff newStaff({first, last}, ID);
		newStaff.setPassWordUpLoad(pass);
		staffs[i] = newStaff;
	}
	ifs.close();
	return true;
}

bool uploadListStudent(){
	string list_stud_dir = getListStudentFilePath();
	std::ifstream ifs (list_stud_dir);
	if (!ifs) return false;
	string nStudents;
	string ID, pass, first, last, gender, socialId, className, day, month, year;
	string ignore;
	std::getline (ifs, ignore, ',');
	std::getline(ifs, nStudents);
	if (nStudents == "0") return true;
	size_t n = static_cast<size_t>(std::stoul(nStudents));
	if (n == 0) return true;
	students.resize(n); 
	std::getline(ifs, ignore);
	for (int i = 0; i < n; i++) {
		std::getline(ifs, ignore, ',');
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
		newStudent.setPassWordUpLoad(pass);
		students[i] = newStudent;
	}
	ifs.close();
	return true;
}

bool uploadListSchoolYear() {
	string listSchoolYearDir = getListSchoolYearFilePath();
	std::ifstream ifs(listSchoolYearDir);
	if (!ifs.is_open()) {
		std::cout << "Cannot open " << listSchoolYearDir;
		return false;
	}
	string ignore;
	getline(ifs, ignore, ',');
	getline(ifs, ignore);
	size_t nSchoolYear = static_cast<size_t>(std::stoull(ignore));
	if (nSchoolYear == 0) return true;
	schoolYears.resize(nSchoolYear);
	getline(ifs, ignore);
	for (int i = 0; i < schoolYears.size(); ++i) {
		SchoolYear school_year;
		getline(ifs, ignore, ',');
		getline(ifs, ignore);
		unsigned int startYear = static_cast<unsigned int>(std::stoul(ignore));
		school_year.start = startYear;
		schoolYears[i] = school_year;
		uploadSchoolYear(schoolYears[i]);
	}
	ifs.close();
	return true;
}

bool uploadSchoolYear(SchoolYear& schoolYear) {
	string schoolYearDir = getSchoolYearFilePath(schoolYear);
	std::ifstream ifs(schoolYearDir);
	if (!ifs.is_open()) {
		std::cout << "Cannot open " << schoolYearDir << '\n';
		return false;
	}
	unsigned int start;
	string ignore;
	getline(ifs, ignore, ',');
	ifs >> start;
	if (start != schoolYear.start) {
		std::cout << "Incorrect directory\n";
		return false;
	}
	getline(ifs, ignore, ',');
	getline(ifs, ignore);
	size_t nClasses = static_cast<size_t>(std::stoull(ignore));
	if (nClasses == 0) return true;

	schoolYear.classes.resize(nClasses);
	getline(ifs, ignore);
	for (int i = 0; i < nClasses; ++i) {
		string className;
		getline(ifs, ignore, ',');
		ifs >> className;
		schoolYear.classes[i].name = className;
		schoolYear.classes[i].ptrSchoolYear = &schoolYear;
		uploadClass(schoolYear.classes[i]);
	}
	ifs.close();
	return true;
}

bool uploadClass(Class& actClass) {
	string oFile = getClassFilePath(actClass);
	std::ifstream ifs(oFile);
	if (!ifs.is_open()) {
		std::cout << "Cannot open " << oFile;
		return false;
	}
	string className, ignore;
	getline(ifs, ignore, ',');
	ifs >> className;
	if (className != actClass.name) {
		std::cout << "Incorrect Class!";
		return false;
	}

	getline(ifs, ignore, ',');
	getline(ifs, ignore);
	size_t nStud = static_cast<size_t>(std::stoull(ignore));
	if (nStud == 0) return true;
	actClass.students.resize(nStud);
	string id;
	getline(ifs, ignore);
	for (int i = 0; i<nStud; ++i){
	 	getline(ifs, ignore, ',');
		Student *ptrStudent;
		ifs >> id; 
		ptrStudent = getStudent(id);
		actClass.students[i] = ptrStudent;
		ptrStudent->ptrClass = &actClass;
	}
	ifs.close();
	return true;
}

// AcademicYear
bool uploadListAcademicYear() {
	string listAcademicYearFilePath = getListAcademicYearFilePath();
	std::ifstream ifs(listAcademicYearFilePath);
	if (!ifs.is_open()){
		std::cout << "Can't open " << listAcademicYearFilePath << std::endl;
		return false;
	}
	string ignore;
	getline(ifs, ignore, ',');
	getline(ifs, ignore);

	size_t nAcademicYear = static_cast<size_t>(std::stoull(ignore));

	if (nAcademicYear == 0) return true;

	academicYears.resize(nAcademicYear);
	unsigned int startOfAcademicYear;
	getline(ifs, ignore);
	for (int i = 0; i < academicYears.size(); i++)
	{
		getline(ifs, ignore, ',');
		ifs >> startOfAcademicYear;
		AcademicYear academicYear;
		academicYear.start = startOfAcademicYear;
		academicYears[i] = academicYear;
		uploadAcademicYear(academicYears[i]);
	}
	ifs.close();
	return true;
}

bool uploadAcademicYear(AcademicYear& academicYear) {
	string academicYearFilePath = getAcademicYearFilePath(academicYear);
	std::ifstream ifs(academicYearFilePath);
	if (!ifs.is_open()){
		std::cout << "Can't open " << academicYearFilePath << std::endl;
		return false;
	}
	unsigned int startOfAcademicYear;
	string ignore;
	getline(ifs, ignore, ',');
	ifs >> startOfAcademicYear;
	if (startOfAcademicYear != academicYear.start){
		std::cout << "Incorrect file path " << academicYearFilePath << std::endl;
		return false;
	}
	getline(ifs, ignore, ',');
	getline(ifs, ignore);
	size_t nSemester = static_cast<size_t>(std::stoull(ignore));
	if (nSemester == 0) return 0;

	academicYear.semesters.resize(nSemester);
	string semesterID = "";
	std::getline(ifs, semesterID);
	for (int i = 0; i < academicYear.semesters.size(); i++)
	{
		getline(ifs, ignore, ',');
		std::getline(ifs, semesterID);
		Semester semester;
		semester.semesterID = semesterID;
		academicYear.semesters[i] = semester;
		academicYear.semesters[i].ptrAcademicYear = &academicYear;
		uploadSemester(academicYear.semesters[i]);
	}
	ifs.close();
	return true;
}

bool uploadSemester(Semester& semester) {
	string semesterFilePath = getSemesterFilePath(semester);
	std::ifstream ifs(semesterFilePath);
	if (!ifs.is_open()){
		std::cout << "Can't open " << semesterFilePath << std::endl;
		return false;
	}
	string semesterID, ignore;
	getline(ifs, ignore, ',');
	std::getline(ifs, semesterID);
	if (semester.semesterID != semesterID){
		std::cout << "Incorrect file path " << semesterFilePath << std::endl;
		return false;
	}
	getline(ifs, ignore, ',');
	getline(ifs, ignore);
	semester.startDate = string_to_date(ignore);
	getline(ifs, ignore, ',');
	getline(ifs, ignore);
	semester.endDate = string_to_date(ignore);
	string courseID = "";
	size_t nCourse;
	getline(ifs, ignore, ',');
	ifs >> nCourse;
	if (nCourse == 0) return true;

	semester.courses.resize(nCourse);
	std::getline(ifs, courseID);
	for (int i = 0; i < semester.courses.size(); i++){
		getline(ifs, ignore, ',');
		std::getline(ifs, courseID);
		Course course;
		course.ID = courseID;
		semester.courses[i] = course;
		semester.courses[i].ptrSemester = &semester;
		uploadCourse(semester.courses[i]);
	}
	ifs.close();
	return true;
}

bool uploadCourse(Course& course) {
	string courseFilePath = getCourseFilePath(course);
	std::ifstream ifs(courseFilePath);
	if (!ifs.is_open()){
		std::cout << "Can't open " << courseFilePath << std::endl;
		return false;
	}
	string courseID, ignore;
	std::getline(ifs, ignore, ',');
	std::getline(ifs, courseID);
	if (course.ID != courseID)
	{
		std::cout << "Incorrect file path " << courseFilePath << std::endl;
		return false;
	}
	string classID, name, teacher, weekdayStr, sessionStr;
	Weekday weekday;
	Session session;
	int credits, maxEnroll;
	std::getline(ifs, ignore, ',');
	std::getline(ifs, classID);
	std::getline(ifs, ignore, ',');
	std::getline(ifs, name);
	std::getline(ifs, ignore, ',');
	std::getline(ifs, teacher);
	std::getline(ifs, ignore, ',');
	ifs >> credits;
	std::getline(ifs, ignore, ',');
	ifs >> maxEnroll;
	std::getline(ifs, ignore, ',');
	std::getline(ifs, weekdayStr);
	weekday = string_to_weekday(weekdayStr);
	std::getline(ifs, ignore, ',');
	std::getline(ifs, sessionStr);
	session = string_to_session(sessionStr);
	course.classID = classID;
	course.name = name;
	course.teacher = teacher;
	course.credits = credits;
	course.maxEnroll = maxEnroll;
	course.weekday = weekday;
	course.session = session;

	std::getline(ifs, ignore, ',');
	int nStud;
	string studentID;
	string midTerm, final, other, total;
	Student *ptrStudent;
	ifs >> nStud;
	course.scoreboards.resize(nStud);
	getline(ifs, ignore);
	for (int i = 0; i<nStud; ++i){
		getline(ifs, ignore, ',');
		getline(ifs, studentID,',');
		ptrStudent = getStudent(studentID);
		getline(ifs, midTerm, ',');
		getline(ifs, final, ',');
		getline(ifs, other,',');
		getline(ifs, total,',');
		course.scoreboards[i]->setScore(std::stof(midTerm), std::stof(final), std::stof(other), std::stof(total));
		course.scoreboards[i]->ptrCourse = &course;
		course.scoreboards[i]->ptrStudent = ptrStudent;
		ptrStudent->scoreboards.append(course.scoreboards[i]);
	}	
	ifs.close();
	return true;
}

//----------------------------------------------------------------------------------------------//