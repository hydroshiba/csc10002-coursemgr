# **Documentation**
## **Graphics / Scene**
### **1. Scene**
(Defined in Scene.h)
`Scene` is a base class that can be inherited by the derived classes, these classes inherite the attributes and methods in `Scene` class, which is used to create specific scenes.

| Attribute / Method | Description |
| -------- | -------- |
| `Vector2 mousePoint`   |   The protected attribute locate the mouse cursor position in the scene.   |
| `virtual void render()` | Renders all the graphic objects to the scene. |
| `virtual Scene* process()` | Updates and returns the scene to the application. |
### **2. Login**
(Define in Login.h and implemented in Login.cpp)
`Login` is a derived class inherited from `Scene` class used to create a login scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `Login()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `login` button, if the username and password are valid, it will return the next scene (Student Scene / Staff Scene). Otherwise the warning text will occur. <br> + Click on `Quit` button, the application will be closed. |

### **3. StudentScene**
(Defined in StudentScene.h and implemented in StudentScene.cpp)
`StudentScene` is a derived class inherited from `Scene` class used to create a student scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `StudentScene()` | The constructor initializes all private graphic objects. |
| `void render()` | Renders all the objects implemented in the private class to the student scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br>  +Click on `Change` button, if the inputs are valid, it will access to `updateStudentIn4()` function, then the information will be updated and return the current scene (Student Scene). Otherwise the warning text will occur. <br>  +Click on `Export` button, if the input in the file name input box is valid, it will access to the `exportListScoreboardOfStudnet()` function, then a `.csv` file will be exported. In addition, if user choose a semester from semester drop box, then it will access to the `exportListScoreboardInSemesterOfStudent()`, then a `.csv` file will be exported. Otherwise, the warning text will occur. It also returns the current scene. <br> +Click on `Back` button (it only appears when user access this scene through `StaffScene2` scene, the application will turn to `StaffScene2` scene. <br> +Click on `Logout` button, the application will turn to `Login` scene.|

### **4. StaffScene**
(Defined in StaffScene.h and implemented in StaffScene.cpp)
`StaffScene` is a derived class inherited from `Scene` class used to create a staff scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `StaffScene()` | The constructor initializes all private graphic objects. |
| `void render()` | Renders all the objects implemented in the private class to the student scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br>  +Click on `Change` button, if the inputs in `Edit Staff` tab are valid, it will access to `updateStaffIn4()` function, then the information will be updated and return the current scene (Staff Scene). Otherwise the warning text will occur. <br>  +Click on `Add` button, if the inputs in `Add new staff` tab are valid, it will access to `addStaff()` function, then a new staff will be added and it returns the current scene. Otherwise, the warning text will occur. <br> +Click on `Next` button, the application will turn to the `StaffScene2` scene. <br> +Click on `SchoolYears` button, the application will turn to `ListSchoolYearScene` scene. <br> +Click on `AcademicYears` button, the application will turn to `ListAcademicYearScene` scene. <br> +Click on `Logout` button, the application will turn to `Login` scene.|

### **5. StaffScene2**
(Defined in StaffScene2.h and implemented in StaffScene2.cpp)
`StaffScene2` is a derived class inherited from `Scene` class used to create a additional staff scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `StaffScene()` | The constructor initializes all private graphic objects. |
| `void render()` | Renders all the objects implemented in the private class to the student scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br>  +Click on `Add` button, if the inputs of student's information are valid, it will access to `addStudent()` function, then a new student will be added and it returns the current scene (Staff Scene). Otherwise the warning text will occur. <br>  +Click on `Remove` button next to the `inputStudentID` input box, if the input is valid, it will access to `removeStudent()` function, then that student will be removed from school and it returns the current scene. Otherwise, the warning text will occur. <br> +Click on `Remove` button next to `inputStaffID` input box, if the input is valid, it will access to `removeStaff()` function, then that staff will be removed and it returns the current scene. Otherwise, the warning text will occur. <br> +Click on `Export` button next to `inputLSYsFilePath` input box, it will access to `exportListSchoolYear()` function, then a `.csv` file will be exported and the application returns the current scene. Otherwise, the warning text will occur. <br> +Click on `Export` button next to `inputLAYsFilePath` input box, it will access to `exportListAcademicYear()` function, then a `.csv` file will be exported and the application returns the current scene. Otherwise, the warning text will occur.<br> +Click on `View` button, if the input in the `inputStudnetID` is valid, the application will turn to `StudentScene` scene. Otherwise, the warning text will occur.<br> +Click on `Back` button, the application will turn to `StaffScene` scene.|

### **6. ListSchoolYearScene**
(Defined in ListSchoolYearScene.h and implemented in ListSchoolYearScene.cpp)
`ListSchoolYearScene` is a derived class inherited from `Scene` class used to create a list school year scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `ListSchoolYearScene()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `Add` button, if a start year is valid, the program will access to `addSchoolYear()` function, then a school year will be added and the function will return the current scene. Otherwise the warning text will occur. <br> + Click on `Remove` button, if a start year is valid, the program will access to `removeSchoolYear()` then a school year will be removed, the function will return the current scene. Otherwise the warning text will occur. <br> +Click on `View` button, the user had to choose the school year drop box, then the function will return `SchoolYearScene` scene. <br> +Click on `Back` button, the application will turn to `StaffScene` scene.|

### **7. SchoolYearScene**
(Defined in SchoolYearScene.h and implemented in SchoolYearScene.cpp)
`SchoolYearScene` is a derived class inherited from `Scene` class used to create a  school year scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `SchoolYearScene()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `Add` button, if a class name is valid, the program will access to `addSemester()` function, then a class will be added and the function will return the current scene. Otherwise the warning text will occur. <br> + Click on `Remove` button, if a class name is valid, the program will access to `removeSemester()`, then a class will be removed, the function will return the current scene. Otherwise the warning text will occur. <br> +Click on `View` button, the user had to choose the class drop box, then the function will return `SemesterScene` scene. <br> +Click on `Change` button, if the start year is valid, the program will access to `updateAcademicYearYear()`, then this schoolYear will be updated and the program will return this scene. Otherwise the warning text will occur. <br> +Click on `Export` button, if the exported file name is valid, the program will access to `exportListSemesterInAcademicYear()`, then a `.csv` file will be exported and the function returns current scene. Otherwise, the warning text will occur. <br> +Click on `Back` button, the application will turn to `ListAcademicYearScene` scene

### **8. ClassScene**
(Defined in ClassScene.h and implemented in ClassScene.cpp)
`ClassScene` is a derived class inherited from `Scene` class used to create a class scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `ClassScene()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `Add` button, if a student ID is valid, the program will access to `addStudentToClass()` function, then a student will be added and the function will return the current scene. Otherwise the warning text will occur. <br> + Click on `Remove` button, if a student ID is valid, the program will access to `removeStudentFromClass()`, then a student will be removed, the function will return the current scene. Otherwise the warning text will occur. <br> +Click on `View` button, the user had to choose the class drop box, then the function will return `ClassScene` scene. <br> +Click on `Change` button, if the class name is valid, the program will access to `updateClass()`, then this class will be updated and the program will return this scene. Otherwise the warning text will occur. <br> +Click on `Export` button, if the exported file name input is valid, the program will access to `exportListStudentInClass()`,  In addition, if user choose a semester in semester drop box, the program will access to `exportListScoreboardInSemesterOfClass()`, then a `.csv` file will be exported and the function returns current scene. Otherwise, the warning text will occur. <br> +Click on `Import` button, if the imported file name input is valid, the program will access to `importStudentListOfClassFromFile()`, then the function returns the current scene. Otherwise the warning will occur. <br> +Click on `Back` button, the application will turn to `ListSchoolYearScene` scene.|

### **9. ListAcademicYearScene**
(Defined in ListAcademicYearScene.h and implemented in ListAcademicYearScene.cpp)
`ListAcademicYearScene` is a derived class inherited from `Scene` class used to create list academic year scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `ListAcademicYearScene()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `Add` button, if a start year is valid, the program will access to `addAcademicYear()` function, then a school year will be added and the function will return the current scene. Otherwise the warning text will occur. <br> + Click on `Remove` button, if a start year is valid, the program will access to `removeAcademicYear()` then a school year will be removed, the function will return the current scene. Otherwise the warning text will occur. <br> +Click on `View` button, the user had to choose the school year drop box, then the function will return `AcademicYearScene` scene. <br> +Click on `Back` button, the application will turn to `StaffScene` scene.|

### **10. AcademicYearScene**
(Defined in AcademicYearScene.h and implemented in AcademicYearScene.cpp)
`AcademicYearScene` is a derived class inherited from `Scene` class used to create a academic year scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `AcademicYearScene()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `Add` button, if a semester ID input is valid, the program will access to `addClass()` function, then a semester will be added and the function will return the current scene. Otherwise the warning text will occur. <br> + Click on `Remove` button, if a semester ID input is valid, the program will access to `removeClass()`, then a semester will be removed, the function will return the current scene. Otherwise the warning text will occur. <br> +Click on `View` button, the user had to choose the semester drop box, then the function will return `ClassScene` scene. <br> +Click on `Change` button, if the start year is valid, the program will access to `updateAcademicYear()`, then this academicYear will be updated and the program will return this scene. Otherwise the warning text will occur. <br> +Click on `Export` button, if the exported file name is valid, the program will access to `exportListClassInAcademicYear()`, then a `.csv` file will be exported and the function returns current scene. Otherwise, the warning text will occur. <br> +Click on `Back` button, the application will turn to `ListAcademicYearScene` scene. |

### **11. SemesterScene**
(Defined in SemesterScene.h and implemented in SemesterScene.cpp)
`SemesterScene` is a derived class inherited from `Scene` class used to create a semester scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `SemesterScene()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `Add` button, if a course ID input is valid, the program will access to `addCourse()` function, then a course will be added and the function will return the current scene. Otherwise the warning text will occur. <br> + Click on `Remove` button, if a course ID input is valid, the program will access to `removeCourse()`, then a course will be removed, the function will return the current scene. Otherwise the warning text will occur. <br> +Click on `View` button, the user had to choose the course drop box, then the function will return `CourseScene` scene. <br> +Click on `Change` button, if the start date input, end date input or semesterID input are valid, the program will access to `updateSemester()`, `Semester::updateStartDate()` or `Semester::updateEndDate()`, then this semester will be updated and the program will return this scene. Otherwise the warning text will occur. <br> +Click on `Export` button, if the exported file name is valid, the program will access to `exportListCourseInSemester()`, then a `.csv` file will be exported and the function returns current scene. Otherwise, the warning text will occur. <br> +Click on `Back` button, the application will turn to `AcademicYearScene` scene. |

### **12. CourseScene**
(Defined in ClassScene.h and implemented in CourseScene.cpp)
`CourseScene` is a derived class inherited from `Scene` class used to create a course scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `CourseScene()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `Add` button, if a student ID is valid, the program will access to `addStudentToCourse()` function, then a student will be added and the function will return the current scene. Otherwise the warning text will occur. <br> + Click on `Remove` button, if a student ID is valid, the program will access to `removeStudentFromCourse()`, then a student will be removed, the function will return the current scene. Otherwise the warning text will occur. <br> +Click on `UpdateScoreboard` button, the function will return `EditCourseScene` scene. <br> +Click on `Change` button, if the course information inputs are valid, the program will access to `updateCourse()`, then this class will be updated and the program will return this scene. Otherwise the warning text will occur. <br> +Click on `Export` button, if the exported file name inputs are valid, the program will access to `exportListStudentInCourse()` or `exportListScoreboardOfCourse()`, then a `.csv` file will be exported and the function returns current scene. Otherwise, the warning text will occur. <br> +Click on `Import` button, if the imported file name inputs are valid, the program will access to `importStudentListOfCourseFromFile()` or ` importScoreBoardOfCourse()`, then the function returns the current scene. Otherwise the warning will occur. <br> +Click on `Back` button, the application will turn to `SemesterScene` scene.|

### **13. EditCourseScene**
(Defined in EditCourseScene.h and implemented in EditCourseScene.cpp)
`EditCourseScene` is a derived class inherited from `Scene` class used to create a edit course scene for the application. All the members in the private class are the variables for the objects for the scene.

| Attribute / Method | Description |
| -------- | --------|
| `EditCourseScene()` | The constructor initializes all private graphic objects above. |
| `void render()` | Renders all the objects implemented in the private class to the login scene. |
| `Scene* process()` | Updates the scene when user work on the scene and returns the scene to the application: <br> + Click on `Change` button, if score inputs are valid and student ID input is valid, the program will access to `updateScoreboard()` function, then a scoreboard of a student will be updated and the function will return the current scene. Otherwise the warning text will occur. <br> +Click on `View` button, the user had to enter student ID into input box, then the scoreboard of that student is shown on the screen and the function will return `SchoolYearScene` scene. <br> +Click on `Back` button, the application will turn to `CourseScene` scene.|

### **15. Registry**
(Defined in Registry.h and implemented in Registry.cpp)
`Registry` is a class used to store all the scenes have been implemented. All attributes in `Registry` class are the pointers of the `Scene` to all the scenes.