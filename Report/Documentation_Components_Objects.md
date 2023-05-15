# **Documentation**
## **Components / Objects**

### Components

The `Components.h` file serves as a central header file for including various components and defining important structures and variables used in the C++ program.

#### 1. Included Libraries

The following libraries are included in the `Components.h` file:
- `<iomanip>`: Provides functions for manipulating input/output formatting.
- `<string>`: Provides string manipulation functions and classes.
- `"Vector.h"`: User-defined header file that implements a dynamic array data structure.

#### 2. Constants

- `defaultStr`: A constant string that holds the value "Error". It is used as a default value for certain string variables.

#### 3. Enumerators

The following enumerators are defined in the file:
- `Weekday`: Represents the days of the week with values from `SUN` to `SAT`.
- `Gender`: Represents gender with values `male` and `female`.
- `Session`: Represents academic sessions with values `S1`, `S2`, `S3`, and `S4`.

#### 4. Structures

The following structures are forward declared in the file:
- `Date`: Represents a date.
- `Name`: Represents a person's name.
- `User`: Represents a user.
- `Staff`: Represents a staff member.
- `SchoolYear`: Represents a school year.
- `Class`: Represents a class.
- `Student`: Represents a student.
- `AcademicYear`: Represents an academic year.
- `Semester`: Represents a semester.
- `Course`: Represents a course.
- `Scoreboard`: Represents a scoreboard for a student's scores.

#### 5. Struct Operator Overloading

The file includes a template function `operator!=` that overloads the inequality operator for comparing two objects of the same type. It returns `true` if the objects are not equal and `false` otherwise.

#### Global Variables

The file declares the following global variables:
- `schoolYears`: A `Vector` container that stores `SchoolYear` objects.
- `academicYears`: A `Vector` container that stores `AcademicYear` objects.
- `students`: A `Vector` container that stores `Student` objects.
- `staffs`: A `Vector` container that stores `Staff` objects.
- `ptrStaff_Global`: A pointer to a `Staff` object.
- `ptrStudent_Global`: A pointer to a `Student` object.
- `ptrSchoolYear_Global`: A pointer to a `SchoolYear` object.
- `ptrClass_Global`: A pointer to a `Class` object.
- `ptrAcademicYear_Global`: A pointer to an `AcademicYear` object.
- `ptrSemester_Global`: A pointer to a `Semester` object.
- `ptrCourse_Global`: A pointer to a `Course` object.
- `ptrScoreboard_Global`: A pointer to a `Scoreboard` object.

These global variables are used to maintain and access important data throughout the program.

The `Components.h` file serves as a central point for including necessary components and defining key structures and variables, making them easily accessible to other parts of the program.


### 1. Name
The `Name` struct represents a person's name with a first name and a last name. It provides methods for setting and retrieving the name, as well as an equality operator to compare two names.

| Attribute/Method | Description |
|------------------|-------------|
| - `first: std::string` | Private attribute that stores the first name of the person. |
| - `last: std::string` | Private attribute that stores the last name of the person. |
| + `Name(nameFirst: const std::string&, nameLast: const std::string&)` | Public constructor that initializes the `Name` object with the given first and last names. It has default parameter values of an empty string. |
| + `set(nameFirst: const std::string&, nameLast: const std::string&)` | Public method that allows setting the first and last names of the person. |
| + `get(): std::string` | Public method that returns the full name (first name followed by last name) as a string. |
| `operator==(nameA: const Name&, nameB: const Name&)` | Non-member function that compares two `Name` objects for equality. Returns `true` if the first names and last names are the same, and `false` otherwise. |

### 2. Date

The `Date` struct represents a specific date with day, month, and year values. It provides methods for setting and retrieving the date, as well as an equality operator to compare two dates.


| Attribute/Method | Description |
|------------------|-------------|
| - `day: unsigned short` | Private attribute that stores the day value of the date. |
| - `month: unsigned short` | Private attribute that stores the month value of the date. |
| - `year: unsigned int` | Private attribute that stores the year value of the date. |
| + `Date(newDay: const unsigned short&, newMonth: const unsigned short&, newYear: const unsigned int&)` | Public constructor that initializes the `Date` object with the given day, month, and year values. It has default parameter values of 0. |
| + `set(newDay: const unsigned short&, newMonth: const unsigned short&, newYear: const unsigned int&)` | Public method that allows setting the day, month, and year values of the date. |
| + `get(): std::string` | Public method that returns the date in the format "dd/mm/yyyy" as a string. |
| `operator==(dateA: const Date&, dateB: const Date&)` | Non-member function that compares two `Date` objects for equality. Returns `true` if the day, month, and year values are the same, and `false` otherwise. |

### 3. User

The `User` struct represents a user with a name, ID, and password. It provides various methods for setting and retrieving user information, as well as password encryption and comparison.


| Attribute/Method | Description |
|------------------|-------------|
| - `password: uint64_t` | Private attribute that stores the hashed password of the user. |
| - `hash(left: uint64_t, right: uint64_t): uint64_t` | Private method that performs a custom hash operation on two `uint64_t` values and returns the result. |
| - `hash(str: std::string): uint64_t` | Private method that performs a custom hash operation on a string and returns the result. |
| + `name: Name` | Public attribute of type `Name` that represents the user's name. |
| + `ID: std::string` | Public attribute that stores the user's ID. |
| + `User(name: const Name&, ID: const std::string&, passwordStr: const std::string&)` | Public constructor that initializes the `User` object with the given name, ID, and password. The default password value is "123456". |
| + `setFirstName(firstName: const std::string&)` | Public method that allows setting the first name of the user. |
| + `setLastName(lastName: const std::string&)` | Public method that allows setting the last name of the user. |
| + `setName(first: const std::string&, last: const std::string&)` | Public method that allows setting the first and last names of the user. |
| + `setPassword(str: const std::string&)` | Public method that encrypts and sets the user's password using the given string. |
| + `isPassword(str: const std::string&): bool` | Public method that compares the given string with the user's password. Returns `true` if the passwords match, and `false` otherwise. |
| + `setID(ID: const std::string)` | Public method that allows setting the user's ID. |
| + `getHashedPass(): uint64_t` | Public method that returns the hashed password of the user. |
| `operator==(userA: const User&, userB: const User&): bool` | Non-member function that compares two `User` objects for equality. Returns `true` if the IDs and names of the users are the same, and `false` otherwise. |


### 4. Staff

The `Staff` struct is a derived struct from `User` and represents a staff member. It inherits the attributes and methods from `User`.

### 5. Student

The `Student` struct is defined in the Student.h file and inherits from the User class. It contains data related to a student such as their name, ID, password, gender, date of birth, social ID, class, and scoreboards. 


The following table provides an overview of the attributes and methods of the Student struct:

| Attribute / Method | Description |
| --- | --- |
| `+ Gender gender` | A public attribute representing the gender of the student. |
| `+ Date birth` | A public attribute representing the date of birth of the student. |
| `+ std::string socialID` | A public attribute representing the social ID of the student. |
| `+ Class* ptrClass` | A public attribute representing a pointer to the class that the student belongs to. |
| `+ Vector<Scoreboard*> scoreboards` | A public attribute representing a vector of scoreboards for the student. |
| `+ Student(const Name& name, const std::string& id, const std::string& password, const Gender& gender = male, const Date& birth = {0, 0, 0}, const std::string& socialID = defaultStr, Class* ptrClass = nullptr, const Vector<Scoreboard*>& scoreboards = Vector<Scoreboard*>())` | A public constructor that takes in the name, ID, password, gender, date of birth, social ID, class, and scoreboards of a student. |
| `+ Vector<Scoreboard*> getScoreboards(const Semester& semester) const` | A public method that takes in a semester and returns a vector of scoreboards for the student in that semester. |
| `+ Scoreboard* getScoreboard(const string& courseID) const` | A public method that takes in a course ID and returns a pointer to the scoreboard of that course for the student. |
| `+ Scoreboard* getScoreboard(Course& course) const` | A public method that takes in a course and returns a pointer to the scoreboard of that course for the student. |
| `+ void set(const Name& name, const std::string& id, const std::string& password, const Gender& gender, const Date& birth, const std::string& socialID, Class* ptrClass, const Vector<Scoreboard*>& scoreboards)` | A public method that sets the name, ID, password, gender, date of birth, social ID, class, and scoreboards of a student. |
| `+ void setName(const Name& name)` | A public method that sets the name of a student. |
| `+ void setGender(const Gender& gender)` | A public method that sets the gender of a student. |
| `+ void setBirth(const Date& birth)` | A public method that sets the date of birth of a student. |
| `+ void setSocialID(const std::string& socialID)` | A public method that sets the social ID of a student. |
| `+ void setClass(Class* ptrClass)` | A public method that sets the class of a student. |
| `+ void setScoreboards(Vector<Scoreboard*>& scoreboards)` | A public method that sets the scoreboards of a student. |
| `+ float getGPA() const` | A public method that returns the overall GPA of a student. |
| `+ float getGPA(const Semester& semester) const` | A public method that takes in a semester and returns the GPA of the student for that semester. |
| `+ void setInfoToClass(std::ifstream &ifs)` | A public method that reads student information from a file and sets it to

### 6. SchoolYear

The `SchoolYear` struct represents a school year in a educational system. It contains information about the start year and the classes associated with that year.

| Attribute/Method | Description |
|-----------------|-------------|
| - `start` : unsigned int | The starting year of the school year. |
| - `classes` : Vector<Class> | A vector of `Class` objects representing the classes associated with the school year. |
| + `getStartYear()` : unsigned int | Returns the starting year of the school year. |
| + `set(const unsigned int& start, const Vector<Class>& classes)` | Sets the start year and classes of the school year. |
| + `update(const unsigned int& start)` | Updates the start year of the school year. |
| + `update(Vector<Class>& classes)` | Updates the classes of the school year. |
| + `getStudent(const std::string& studentID)` : Student* | Returns a pointer to a `Student` object with the given student ID, if found in any of the classes within the school year. |
| + `getClass(const std::string& className)` : Class* | Returns a pointer to a `Class` object with the given class name, if found within the school year. |
| + `addClass(Class& CLASS)` | Adds a `Class` object to the school year and assigns the school year as its parent. |
| + `removeClass(Class& CLASS)` | Removes a `Class` object from the school year and removes the school year reference from the class. |
| + `removeAllClass()` | Removes all classes from the school year and removes the school year reference from each class. |
| + `getPeriod()` : std::string | Returns a string representation of the school year period, indicating the start year and end year. |

### 7. Class

The `Class` struct represents a class within a school year in a C++ program. It contains information about the class name, the associated school year, and the students enrolled in the class.

| Attribute / Method | Description |
| ----------------- | ----------- |
| - `ptrSchoolYear: SchoolYear*` | A pointer to the associated school year for the class. |
| - `name: std::string` | The name of the class. |
| - `students: Vector<Student*>` | A vector containing pointers to the students enrolled in the class. |
| + `Class(SchoolYear* ptrSchoolYear = nullptr, const std::string& name = defaultStr, const Vector<Student*>& students = Vector<Student*>())` | Constructor for the `Class` struct. Initializes the `ptrSchoolYear`, `name`, and `students` attributes. |
| + `void set(SchoolYear* ptrSchoolYear, const std::string& name, const Vector<Student*>& students)` | Sets the `ptrSchoolYear`, `name`, and `students` attributes of the class. |
| + `void update(SchoolYear* ptrSchoolYear)` | Updates the `ptrSchoolYear` attribute of the class. |
| + `void update(const std::string& name)` | Updates the `name` attribute of the class. |
| + `void addStudent(Student*& student)` | Adds a student to the class by appending the student pointer to the `students` vector. |
| + `void removeStudent(Student*& student)` | Removes a student from the class by removing the corresponding student pointer from the `students` vector. |
| + `Vector<string> getListCourse(const Semester& semester) const` | Retrieves a vector of course IDs associated with the specified semester for the class. |
| + `Vector<std::string> getListCourse() const` | Retrieves a vector of all course IDs for the class. |
| + `void removeAllStudent()` | Removes all students from the class by resetting the `students` vector. |
| + `Student* getStudent(const std::string& studentID)` | Retrieves a pointer to a student in the class based on their student ID. |
| + `void displayScoreboardScreen(const Semester& semester)` | Displays the scoreboard of the class for the specified semester on the console. |
| + `void displayScoreboardFile(const Semester& semester, std::ofstream& ofs)` | Writes the scoreboard of the class for the specified semester to a file. |
| <br>**Friend Functions** |
| bool operator==(const Class& classA, const Class& classB) | Checks whether two `Class` objects are equal by comparing their `name` and `ptrSchoolYear` attributes. |
    
### 8. AcademicYear

The `AcademicYear` struct represents an academic year, which is defined by a start year and a collection of semesters. It contains methods for adding, removing, and getting a semester by its ID.


| Attribute/Method | Description |
| --- | --- |
| - `unsigned int start` | The start year of the academic year. |
| - `Vector<Semester> semesters` | A vector of semesters in the academic year. |
| + `AcademicYear(const unsigned int& start = 0, const Vector<Semester>& semester = Vector<Semester>())` | Constructor to create an academic year with a start year and a vector of semesters. |
| + `Semester* getSemester(const std::string& semesterID)` | Returns a pointer to the semester with the specified ID, or nullptr if it does not exist. |
| + `void addSemester(Semester& semester)` | Adds a semester to the academic year. |
| + `void removeSemester(Semester& semester)` | Removes a semester from the academic year. |
| + `void removeAllSemester()` | Removes all semesters from the academic year. |
| + `std::string getPeriod() const` | Returns a string representing the period of the academic year, in the format "start year - end year". |
| - `bool operator==(const AcademicYear& yearA, const AcademicYear& yearB)` | Returns true if two academic years are equal (have the same start year), false otherwise. |

### 9. Semester

The `Semester` struct represents a semester in an academic year. It contains information about the semester ID, start and end dates, a collection of courses, and a pointer to the academic year it belongs to. It provides methods for managing courses within the semester.

| Attribute/Method | Description |
| --- | --- |
| + `std::string semesterID` | The ID of the semester. |
| + `Date startDate` | The start date of the semester. |
| + `Date endDate` | The end date of the semester. |
| + `Vector<Course> courses` | A vector of courses in the semester. |
| + `AcademicYear* ptrAcademicYear` | A pointer to the academic year that the semester belongs to. |
| + `Semester(const std::string& semesterID = defaultStr, const Date& startDate = { 0, 0, 0 }, const Date& endDate = { 0, 0, 0 }, const Vector<Course>& course = Vector<Course>(), AcademicYear* ptrAcademicYear = nullptr)` | Constructor to create a semester with the specified semester ID, start and end dates, a vector of courses, and a pointer to the academic year. |
| + `void set(const std::string& semesterID, const Date& startDate, const Date& endDate, const Vector<Course>& course, AcademicYear* ptrAcademicYear)` | Sets the attributes of the semester to the specified values. |
| + `void updateSemesterID(const std::string& semesterID)` | Updates the semester ID. |
| + `void updateStartDate(const Date& startDate)` | Updates the start date of the semester. |
| + `void updateEndDate(const Date& endDate)` | Updates the end date of the semester. |
| + `void updateCourses(Vector<Course>& course)` | Updates the courses in the semester. |
| + `void updateAcademicYear(AcademicYear* ptrAcademicYear)` | Updates the academic year that the semester belongs to. |
| + `Course* getCourse(const std::string& courseID)` | Returns a pointer to the course with the specified ID, or nullptr if it does not exist. |
| + `void addCourse(Course& course)` | Adds a course to the semester. |
| + `void removeCourse(Course& course)` | Removes a course from the semester. |
| + `void removeAllCourse()` | Removes all courses from the semester. |
| - `bool operator==(const Semester& semA, const Semester& semB)` | Returns true if two semesters are equal (have the same semester ID, start and end dates), false otherwise. |

### 10. Course

The `Course` struct in the C++ programming language represents a course offered in an educational system. It contains various attributes and methods to manage and manipulate course information. Below is a description of the attributes and methods of the `Course` struct.


| Attribute/Method | Description |
|---|---|
| - `ID` (`string`) | The ID of the course. |
| - `classID` (`string`) | The ID of the class associated with the course. |
| - `name` (`string`) | The name of the course. |
| - `teacher` (`string`) | The name of the teacher who teaches the course. |
| - `credits` (`int`) | The number of credits assigned to the course. |
| - `maxEnroll` (`int`) | The maximum number of students that can enroll in the course. |
| - `weekday` (`Weekday`) | The day of the week when the course is scheduled. |
| - `session` (`Session`) | The session of the course (e.g., morning, afternoon). |
| - `ptrSemester` (`Semester*`) | A pointer to the semester associated with the course. |
| - `scoreboards` (`Vector<Scoreboard*>`) | A vector of pointers to scoreboards, representing the performance of students in the course. |
| + `Course()` | Constructor of the `Course` struct. |
| + `void set(ID, classID, name, teacher, credits, maxEnroll, weekday, session, ptrSemester, scoreboards)` | Sets the values of the attributes of the course. |
| + `void updateID(ID)` | Updates the ID of the course. |
| + `void updateClassID(classID)` | Updates the class ID of the course. |
| + `void updateName(name)` | Updates the name of the course. |
| + `void updateTeacher(teacher)` | Updates the name of the teacher of the course. |
| + `void updateCredits(credits)` | Updates the number of credits assigned to the course. |
| + `void updateMaxEnroll(maxEnroll)` | Updates the maximum number of students that can enroll in the course. |
| + `void updateWeekday(weekday)` | Updates the day of the week when the course is scheduled. |
| + `void updateSession(session)` | Updates the session of the course. |
| + `void updateSemester(ptrSemester)` | Updates the semester associated with the course. |
| + `void updateScoreboard(scoreboards)` | Updates the scoreboards associated with the course. |
| + `Student* getStudent(studentID)` | Retrieves a pointer to a student enrolled in the course based on their ID. |
| + `Scoreboard* getScoreboard(studentID)` | Retrieves a pointer to the scoreboard of a student in the course based on their ID. |
| + `void addStudent(student)` | Adds a student to the course by creating a new scoreboard for the student. |
| + `void removeStudent(student)` | Removes a student from the course and deletes their associated scoreboard. |
| + `void removeAllStudent()` | Removes all students from the course and deletes their associated scoreboards. |
| + `void displayInfoFile(ofs)` | Displays the course information in a formatted manner in the specified output stream. |
| + `void displayInfoTable(table)` | Displays the course information in a tabular format using the provided table. |
| + `void importScoreBoards(ifs)` | Imports scoreboards for the course from the specified input file stream. |
| + `bool operator==(courseA, courseB)`| Compare two Course variable|

### 11. Scoreboard

The `Scoreboard` struct represents a score record for a specific course and student. It contains information about the scores obtained by the student in different assessments of the course.


| Attribute / Method | Description |
|---|---|
| - `midterm` (float) | The score obtained by the student in the midterm assessment. |
| - `final` (float) | The score obtained by the student in the final assessment. |
| - `other` (float) | The score obtained by the student in other assessments. |
| - `total` (float) | The total score obtained by the student in the course. |
| - `ptrCourse` (Course*) | A pointer to the course associated with the scoreboard. |
| - `ptrStudent` (Student*) | A pointer to the student associated with the scoreboard. |

