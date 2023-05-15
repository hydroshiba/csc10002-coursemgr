# **Project Report: Components Functions**

## **1. Display functions**

The following functions are used for displaying the respective structs as a drop box.

| Function | Description |
|----------|-------------|
|`Vector<string> getListSchoolYear()` | return the list of school years (as the start year of each school year) to display to the screen|
|`Vector<string> getListAcademicYear()` |  return the list of academic years (as the start year of each academic year) to display to the screen|
|`Vector<string> getListClass(const SchoolYear& schoolYear)` | return the list of classes inside a school year|
|`Vector<string> getListSemester(const AcademicYear& academicYear)` | return the list of semesters inside an academic year|
|`Vector<string> getListSemester(const Class& CLASS)` | return the list of semesters inside a class|
|`Vector<string> getListSemester(const Student &student)` | return the list of semester of a student|
|`Vector<string> getListCourse(const Semester& semester)` | return the list of courses from a semester|

The following functions are used for displaying the respective structs as a table.

| Function | Description |
|----------|-------------|
|`Vector<Vector<string>> getTableContentOfListSchoolYear()` | return the list of school years with number of classes in each year|
|`Vector<Vector<string>> getTableContentOfSchoolYear(const SchoolYear& schoolYear)` | return the list of classes with number of student in each class|
|`Vector<Vector<string>> getTableContentOfListStudentInClass(const Class& CLASS)` | return the list of student with their information|
|`Vector<Vector<string>> getTableContentOfListScoreboardInSemesterInClass(const Class& CLASS, const Semester& semester)` | return the scoreboard in a semester of a class|
|`Vector<Vector<string>> getTableContentOfListScoreboardInClass(const Class& CLASS)` | return the scoreboard in a year of a class|
|`Vector<Vector<string>> getTableContentOfScoreboardOfStudent(const Student& student)` | return the scoreboard of a student in a year|
|`Vector<Vector<string>> getTableContentOfScoreboardInSemesterOfStudent(const Student& student, const Semester& semester)` | return the scoreboard of a student in a semester|
|`Vector<Vector<string>> getTableContentOfListAcademicYear()` | return the list of academic years with number of semesters in each year|
|`Vector<Vector<string>> getTableContentOfAcademicYear(const AcademicYear& academicYear)` | return the list of semesters and information of each in an academic year|
|`Vector<Vector<string>> getTableContentOfSemester(const Semester& semester)` | return the information of a semester|
|`Vector<Vector<string>> getTableContentOfListStudentInCourse(const Course& course)` | return the information of students in a course|

## **2. Download functions**

The following functions download the data into a CSV file.

| Function | Description |
|----------|-------------|
|`bool downloadAllData()` | download all the data|
|`bool downloadListStaff()` | download a list of staves|
|`bool downloadListStudent()` | download a list of students|
|`bool downloadListSchoolYear()` | download a list of school years| 
|`bool downloadSchoolYear(SchoolYear& schoolYear)` | download the selected school year|
|`bool downloadClass(Class& CLASS)` | download the selected class|
|`bool downloadListAcademicYear()` | download a list of academic years|
|`bool downloadAcademicYear(AcademicYear& academicYear)` | download the selected academic year|
|`bool downloadSemester(Semester& semester)` | download the selected semester information|
|`bool downloadCourse(Course& course)` | download the selected course information|

## **3. File and Directory functions**

The following functions help create the directory for importing and exporting functions.

| Function | Description |
|----------|-------------|
|`void createDirectoryIfNotExists(const string& dirPath)` | create a new directory if it doesn't exist|
|`string getListStaffFilePath()` | return the directory of the list of staves file|
|`string getListStudentFilePath()` | return the directory of the list of student file|
|`string getListSchoolYearFilePath()` | return the directory of the list of school year file|
|`string getListAcademicYearFilePath()` | return the directory of the list of academic year file|
|`string getSchoolYearFolderPath(const SchoolYear& schoolyear)` | return the folder path of the start of school year|
|`string getSchoolYearFilePath(const SchoolYear& schoolyear)` | return the file path of the start of school year|
|`string getClassFolderPath(const Class& CLASS)` | return the folder path of the class|
|`string getClassFilePath(const Class& CLASS)` | return the file path of the class|
|`string getAcademicYearFolderPath(const AcademicYear& academicYear)` | return the folder path of the start of academic year|
|`string getAcademicYearFilePath(const AcademicYear& academicYear)` | return the file path of the start of academic year|
|`string getSemesterFolderPath(const Semester& semester)` | return the folder path of the semester|
|`string getSemesterFilePath(const Semester& semester)` | return the file path of the semester|
|`string getCourseFolderPath(const Course& course)` | return the folder path of the course|
|`string getCourseFilePath(const Course& course)` | return the file path of the course|
|`string getExportFolderPath()` | add prefix for data exporting path|
|`string getImportFolderPath()` | add prefix for data importing path|

## **4. Import and Export functions**

The following functions import from and export to a CSV file.

| Function | Description |
|----------|-------------|
|`bool importStudentListOfClassFromFile(const string& filename, Class& actClass, string& outStr)` | import the student list in a class|
|`bool importStudentListOfCourseFromFile(const string& filename, Course& course, string& outStr)` | import the student list in a course|
|`bool exportListOfStudentInCourse(const string& filename, Course& course, string& outStr)` | export the student list in a course|
|`bool importScoreBoardOfCourse(const string& filename, Course& course, string& outStr)` | import the scoreboard of a course|
|`bool exportListScoreboardOfStudent(const string& filename, Student& student, string& outStr)` | export the scoreboard in an academic year of a student|
|`bool exportListScoreboardInSemesterOfStudent(const string& filename, Student& student, Semester& semester, string& outStr)` | export the scoreboard in a semester of a student|
|`bool exportListSchoolYear(const string& filename, string& outStr)` | export the list of school years|
|`bool exportListClassInSchoolYear(const string& filename, SchoolYear& schoolYear, string& outStr)` | export the list of classes|
|`bool exportListStudentInClass(const string& filename, Class& CLASS, string& outStr)` | export the list of students in a class|
|`bool exportListScoreboardInSemesterOfClass(const string& filename, Class& CLASS, Semester& semester, string& outStr)` | export the scoreboard in a semester of a class|
|`bool exportListScoreboardOfClass(const string& filename, Class& CLASS, string& outStr)` | export the scoreboard of a class|
|`bool exportListAcademicYear(const string& filename, string& outStr)` | export the list of academic years|
|`bool exportListSemesterInAcademicYear(const string& filename, AcademicYear& academicYear, string& outStr)` | export the list of semesters in an academic year|
|`bool exportListCourseInSemester(const string& filename, Semester& semester, string& outStr)` | export the list of courses in a semester|
|`bool exportListScoreboardOfCourse(const string& filename, Course& course, string& outStr)` | export the scoreboard of the course|

## **5. Insert functions**

The following functions insert data.

| Function | Description |
|----------|-------------|
|`bool addStudent(const string& ID, const string& firstName, const string& lastName, const string& genderStr, const string& birthStr, const string& socialID, const string& password, string& outStr)` | add a new student|
|`bool addStaff(string curStaffID, const string& ID, const string& password, const string& firstName, const string& lastName, string& outStr)` | add a new staff|
|`bool addSchoolYear(const string& start, string& outStr)` | add a new school year|
|`bool addClass(SchoolYear& schoolYear, const string& className, string& outStr)` | add a new class for the school year|
|`bool addStudentToClass(Class& actClass, const string& studentID, string& outStr)` | add a new student to the class|
|`bool addAcademicYear(const string& start, string& outStr)` | add a new academic year|
|`bool addSemester(AcademicYear& newYear, const string& semesterID, string& outStr)` | add a new semester to the academic year|
|`bool addCourse(Semester& semester, const string& courseID, string& outStr)` | add a new course to the semester|
|`bool addStudentToCourse(Course& course, const string& studentID, string& outStr)` | add a new student to the course|

## **6. Remove functions**

The following functions remove data and free memory in the process.

| Function | Description |
|----------|-------------|
|`bool removeListStudent()` | remove the list of students|
|`bool removeListStaff()` | remove the list of staves|
|`bool removeListSchoolYear()` | remove the list of school year|
|`bool removeListAcademicYear()` | remove the list of academic years|
|`bool freeMemory()` | remove everthing|
|`bool removeStudent(const string& studentID, string& outStr)` | remove a student from school|
|`bool removeStaff(string curStaffID, const string& staffID, string& outStr)` | remove a staff from school|
|`bool removeSchoolYear(const string& start, string& outStr)` | remove a school year|
|`bool removeClass(SchoolYear& schoolYears, const string& className, string& outStr)` | remove a class|
|`bool removeStudentFromClass(Class& CLASS, const string& studentID, string& outStr)` | remove a student from the class|
|`bool removeAcademicYear(const string& start, string& outStr)` | remove an academic year|
|`bool removeSemester(AcademicYear& academicYear, const string& semesterID, string& outStr)` | remove a semester|
|`bool removeCourse(Semester& semester, const string& courseID, string& outStr)` | remove a course|
|`bool removeStudFromCourse(Course& course, const string& studentID, string& outStr)` | remove a student from the course|

## **7. Search functions**

The following functions search the content inside the data.

| Function | Description |
|----------|-------------|
|`Student* getStudent(const string& studentID)` | find a student|
|`Staff* getStaff(const string& staffID)` | find a staff|
|`SchoolYear* getSchoolYear(const string& start)` | find a school year|
|`AcademicYear* getAcademicYear(const string& start)` | find an academic year|
|`Class* getClass(SchoolYear& schoolYear, const string& className)` | find a class inside the school year|
|`Semester* getSemester(const string& semesterID)` | find a semester|
|`Semester* getSemester(AcademicYear& academicYear, const string& semesterID)` | find a semester inside the academic year|
|`Course* getCourse(Semester& semester, const string& courseID)` | find a course inside a semester|
|`Scoreboard* getScoreboard(Course& course, const string& studentID)` | find the scoreboard of the student inside his/her course|
|`bool isCorrectStaffAccount(const string& staffID, const string& password, string& outStr)` | check the validity of the staff account|
|`bool isCorrectStudentAccount(const string& studentID, const string& password, string& outStr)` | check the validity of the student account|

## **8. Sorting functions**

The following functions are based on quicksort algorithm.

| Function | Description |
|----------|-------------|
|`void sortStudentList(Vector<Student>& students, const int& left, const int& right)` | sort the list of students|
|`void sortStaffList(Vector<Staff>& staffs, const int& left, const int& right)` | sort the list of staves|
|`void sortSchoolYearList(Vector<SchoolYear>& schoolYears, const int& left, const int& right)` | sort the list of school year|
|`void sortAcademicYearList(Vector<AcademicYear>& academicYears, const int& left, const int& right)` | sort the list academic year|
|`void sortSemesters(Vector<Semester>& semesters, const int& left, const int& right)` | sort the list of semesters|
|`void sortClasses(Vector<Class>& classes, const int& left, const int& right)` | sort the list of classes|
|`void sortCourses(Vector<Course>& courses, const int& left, const int& right)` | sort the list of courses|
|`void sortStudentsInClass(Class& CLASS, const int& left, const int& right)` | sort the list of students inside a class|
|`void sortStudentsInCourse(Course& course, const int& left, const int& right)` | sort the list of students inside a course|

## **9. Update functions**

The following functions update the data.

| Function | Description |
|----------|-------------|
|`bool updateStudentIn4(Student& student, const string& ID, const string& firstName, const string& lastName, const string& genderStr, const string& birthStr, const string& socialID, const string& password, string& outStr)` | update the student information|
|`bool updateStaffIn4(Staff& staff, const string& ID, const string& firstName, const string& lastName, const string& password, string& outStr)` | update the staff information|
|`bool updateSchoolYear(SchoolYear& schoolYear, const string& newStartYear, string& outStr)` | update the school year information|
|`bool updateClass(Class& CLASS, const string& newClassName, string& outStr)` | update the class information|
|`bool updateAcademicYear(AcademicYear& academicYear, const string& newStartYear, string& outStr)` | update the academic year information|
|`bool updateSemester(Semester& semester, const string& semesterID, const string startDate, const string endDate, string& outStr)` | update the semester information|
|`bool updateCourse(Course& course, const string& courseID, const string& classID, const string& name, const string& teacher, const string& cre, const string& maxEnroll, const string& day, const string& ss, string &outStr)` | update the course information|
|`bool updateScoreboard(Course& course, const string& studentID, const string& midTerm, const string& other, const string& final, const string& total, string& outStr)` | update the student scoreboard|

## **10. Upload functions**

The following functions upload the data from CSV files.

| Function | Description |
|----------|-------------|
|`bool uploadAllData()` | upload all the data|
|`bool uploadListStaff()` | upload the list of staves|
|`bool uploadListStudent()` | upload the list of students|
|`bool uploadListSchoolYear()` | uplooad the list of school years|
|`bool uploadSchoolYear(SchoolYear& schoolYear)` | upload the school year|
|`bool uploadStudent(Class& actClass, Student& student, std::string id)` | upload the student to a class|
|`bool uploadClass(Class& actClass)` | upload the class|
|`bool uploadListAcademicYear()` | upload the list of academic years|
|`bool uploadAcademicYear(AcademicYear& academicYear)` | upload the academic year|
|`bool uploadSemester(Semester& semester)` | upload the semester|
|`bool uploadCourse(Course& course)` | upload the course|
