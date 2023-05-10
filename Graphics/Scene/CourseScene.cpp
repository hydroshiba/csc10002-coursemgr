#include "CourseScene.h"

const float textSize = 30;

CourseScene :: CourseScene(){
    title = defaultStr;
    title.setSize(75);
    title.centerX();
    title.setY(5);

// Course Infor
    courseID = "CourseID";
    courseID.setSize(textSize);
    courseID.setPos({50,100});
    courseID.setColor(MAROON);

    classID = "ClassID";
    classID.setSize(textSize);
    classID.setPos({50, 175});
    classID.setColor(MAROON);

    name = "Course Name";
    name.setSize(textSize);
    name.setPos({50, 250});
    name.setColor(MAROON);

    teacher = "Teacher";
    teacher.setSize(textSize);
    teacher.setPos({50, 325});
    teacher.setColor(MAROON);

    credit = "Credits";
    credit.setSize(textSize);
    credit.setPos({50, 400});
    credit.setColor(MAROON);    

    maxEnroll = "Max Enroll";
    maxEnroll.setSize(textSize);
    maxEnroll.setPos({50, 475});
    maxEnroll.setColor(MAROON);

    weekday = "Weekday";
    weekday.setSize(textSize);
    weekday.setPos({50, 550});
    weekday.setColor(MAROON);

    session = "Session";
    session.setSize(textSize);
    session.setPos({50, 625});
    session.setColor(MAROON);

    courseBox.setSize({300,50});
    courseBox.setPos({250,100});
    courseBox.defaultText = defaultStr;

    classBox.setSize({300,50});
    classBox.setPos({250,175});
    classBox.defaultText = defaultStr;

    nameBox.setSize({300,50});
    nameBox.setPos({250,250});
    nameBox.defaultText = defaultStr;

    teacherBox.setSize({300,50});
    teacherBox.setPos({250,325});
    teacherBox.defaultText = defaultStr;

    creditBox.setSize({300,50});
    creditBox.setPos({250,400});
    creditBox.defaultText = defaultStr;    

    enrollBox.setSize({300,50});
    enrollBox.setPos({250,475});
    enrollBox.defaultText = defaultStr;   

    dayBox.setSize({300,50});
    dayBox.setPos({250,550});
    dayBox.defaultText = defaultStr;

    sessionBox.setSize({300,50});
    sessionBox.setPos({250,625});
    sessionBox.defaultText = defaultStr;

// ------------------------------------------------------
// Add student
    addText = "Add Student";
    addText.setSize(textSize);
    addText.setPos({620,100});

    addBox.setSize({250,50});
    addBox.setPos({900, 100});
    addBox.defaultText = "Input studentID...";

    add.label = "Add";
    add.setSize({100,50});
    add.setPos({1150,100});
    add.setInsertColor();
// -------------------------------------------------------
// Remove student
    removeText = "Remove Student";
    removeText.setSize(textSize);
    removeText.setPos({620,175});

    removeBox.setSize({250,50});
    removeBox.setPos({900, 175});
    removeBox.defaultText = "Input studentID...";

    remove.label = "Remove";
    remove.setSize({100,50});
    remove.setPos({1150,175});
    remove.setRemoveColor();
// -------------------------------------------------------
// Export students
    fileText = "Export students";
    fileText.setSize(textSize);
    fileText.setPos({620,250});

    fileBox.setSize({250,50});
    fileBox.setPos({900, 250});
    fileBox.defaultText = "Input file name...";    

    viewStudent.label = "Export";
    viewStudent.setSize({100,50});
    viewStudent.setPos({1150,250});
    viewStudent.setViewColor();
// -------------------------------------------------------
// Export scoreboards
    expText = "Export scoreboards";
    expText.setSize(textSize);
    expText.setPos({620,325});

    expBox.setSize({250,50});
    expBox.setPos({900, 325});
    expBox.defaultText = "Input file name...";

    expButton.label = "Export";
    expButton.setSize({100,50});
    expButton.setPos({1150,325});
    expButton.setViewColor();
// --------------------------------------------------------
// Update Scoreboard Scene
    viewScore.label = "Update Scoreboards";
    viewScore.setSize({300, 50});
    viewScore.setPos({850, 625});
    viewScore.setViewColor();
// --------------------------------------------------------

// Import students
    impText = "Import students";
    impText.setSize(textSize);
    impText.setPos({620,400});

    impBox.setSize({250,50});
    impBox.setPos({900, 400});
    impBox.defaultText = "Input file name...";

    fileButton.label = "Import";
    fileButton.setSize({100,50});
    fileButton.setPos({1150,400});
    fileButton.setViewColor();
// ------------------------------------------------------
// Import scoreboard
    impScoreText = "Import scoreboards";
    impScoreText.setSize(textSize);
    impScoreText.setPos({620,475});

    impScoreBox.setSize({250,50});
    impScoreBox.setPos({900, 475});
    impScoreBox.defaultText = "Input file name...";

    impScoreButton.label = "Import";
    impScoreButton.setSize({100,50});
    impScoreButton.setPos({1150,475});
    impScoreButton.setViewColor();
// -------------------------------------------------------
    change.label = "Change";
    change.setSize({150, 50});
    change.setPos({550,625});
    change.setViewColor();

    back.label = "Back";
    back.setSize({100,50});
    back.setPos({1150, 625});
    back.setRemoveColor();

    result = "";
	result.setColor(RED);
	result.setSize(textSize);
	result.centerX();
	result.setY(675);

    test = "";
    test.setSize(textSize);
    test.setPos({ 620, 550 });
}

void CourseScene::render(){
    title.render();
    courseID.render();
    classID.render();
    name.render();
    teacher.render();
    credit.render();
    maxEnroll.render();
    weekday.render();
    session.render();

    courseBox.render(mousePoint);
    classBox.render(mousePoint);
    nameBox.render(mousePoint);
    teacherBox.render(mousePoint);
    creditBox.render(mousePoint);
    enrollBox.render(mousePoint);
    dayBox.render(mousePoint);
    sessionBox.render(mousePoint);

    addText.render();
    addBox.render(mousePoint);
    add.render(mousePoint);

    removeText.render();
    removeBox.render(mousePoint);
    remove.render(mousePoint);

    fileText.render();
    fileBox.render(mousePoint);
    viewStudent.render(mousePoint);

    expText.render();
    expBox.render(mousePoint);
    expButton.render(mousePoint);

    viewScore.render(mousePoint);

    impText.render();
    impBox.render(mousePoint);
    fileButton.render(mousePoint);

    impScoreText.render();
    impScoreBox.render(mousePoint);
    impScoreButton.render(mousePoint);

    change.render(mousePoint);
    back.render(mousePoint);

    result.render();
    test.render();
}

Scene* CourseScene::process(){
    std::string notif;
    mousePoint = GetMousePosition();

    courseBox.process(mousePoint);
    classBox.process(mousePoint);
    nameBox.process(mousePoint);
    teacherBox.process(mousePoint);
    creditBox.process(mousePoint);
    enrollBox.process(mousePoint);
    dayBox.process(mousePoint);
    sessionBox.process(mousePoint);
    addBox.process(mousePoint);
    removeBox.process(mousePoint);
    fileBox.process(mousePoint);
    expBox.process(mousePoint);
    impBox.process(mousePoint);
    impScoreBox.process(mousePoint);

    if (ptrCourse_Global != nullptr){
        title = ptrCourse_Global->ID;
        if (ptrCourse_Global->ptrSemester != nullptr) {
            title = ptrCourse_Global->ID + " ( " + ptrCourse_Global->ptrSemester->semesterID + " )";
            title.centerX();
            test = "Number of students: " + to_string(ptrCourse_Global->scoreboards.size());
        }
        courseBox.defaultText = ptrCourse_Global->ID;
        classBox.defaultText = ptrCourse_Global->classID;
        nameBox.defaultText = ptrCourse_Global->name;
        teacherBox.defaultText = ptrCourse_Global->teacher;
        creditBox.defaultText = to_string(ptrCourse_Global->credits);
        enrollBox.defaultText = to_string(ptrCourse_Global->maxEnroll);
        dayBox.defaultText = weekday_to_string(ptrCourse_Global->weekday);
        sessionBox.defaultText = session_to_string(ptrCourse_Global->session);
    }    

    if (change.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;
        }
        addBox.content.text.clear();
        removeBox.content.text.clear();
        fileBox.content.text.clear();    
        impBox.clearContent();
        expBox.clearContent();  
        impScoreBox.clearContent();     
        if(updateCourse(*ptrCourse_Global,courseBox.content.text, classBox.content.text, nameBox.content.text, teacherBox.content.text, creditBox.content.text, enrollBox.content.text, dayBox.content.text, sessionBox.content.text, notif)){
            courseBox.content.text.clear();
            classBox.content.text.clear();
            nameBox.content.text.clear();
            teacherBox.content.text.clear();
            creditBox.content.text.clear();
            enrollBox.content.text.clear();
            dayBox.content.text.clear();
            sessionBox.content.text.clear();
        }
        result = notif;
        result.centerX();
        return this;
    }

    if (add.clicked(mousePoint)||remove.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;
        }
        courseBox.content.text.clear();
        classBox.content.text.clear();
        nameBox.content.text.clear();
        teacherBox.content.text.clear();
        creditBox.content.text.clear();
        enrollBox.content.text.clear();
        dayBox.content.text.clear();
        sessionBox.content.text.clear();
        fileBox.content.text.clear(); 
        impBox.clearContent();
        expBox.clearContent();  
        impScoreBox.clearContent();
        if (addBox.content.text.empty() && removeBox.content.text.empty()){
            result = "Invalid student ID, please retry!";
            result.centerX();
            return this;
        }
        else if (!addBox.content.text.empty()) addStudentToCourse(*ptrCourse_Global, addBox.content.text, notif);
        else removeStudFromCourse(*ptrCourse_Global, removeBox.content.text, notif);
        result = notif;
        result.centerX();
        addBox.content.text.clear();
        removeBox.content.text.clear();
        return this;
    }

    if (fileButton.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;            
        }
        courseBox.content.text.clear();
        classBox.content.text.clear();
        nameBox.content.text.clear();
        teacherBox.content.text.clear();
        creditBox.content.text.clear();
        enrollBox.content.text.clear();
        dayBox.content.text.clear();
        sessionBox.content.text.clear();
        addBox.content.text.clear();
        removeBox.content.text.clear();
        fileBox.content.text.clear(); 
        expBox.clearContent();  
        impScoreBox.clearContent();
        if (importStudentListOfCourseFromFile(impBox.content.text, *ptrCourse_Global, notif)) impBox.clearContent();
        result = notif;
        result.centerX();
        return this;
    }

    if (impScoreButton.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;            
        }
        courseBox.content.text.clear();
        classBox.content.text.clear();
        nameBox.content.text.clear();
        teacherBox.content.text.clear();
        creditBox.content.text.clear();
        enrollBox.content.text.clear();
        dayBox.content.text.clear();
        sessionBox.content.text.clear();
        addBox.content.text.clear();
        removeBox.content.text.clear();
        fileBox.content.text.clear(); 
        expBox.clearContent();  
        impBox.clearContent();
        if (importScoreBoardOfCourse(impScoreBox.content.text, *ptrCourse_Global, notif)) impScoreBox.clearContent();
        result = notif;
        result.centerX();
        return this;
    }

    if (viewScore.clicked(mousePoint)) {
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;            
        }
        courseBox.content.text.clear();
        classBox.content.text.clear();
        nameBox.content.text.clear();
        teacherBox.content.text.clear();
        creditBox.content.text.clear();
        enrollBox.content.text.clear();
        dayBox.content.text.clear();
        sessionBox.content.text.clear();        
        addBox.content.text.clear();
        removeBox.content.text.clear();
        fileBox.content.text.clear(); 
        impBox.clearContent();
        expBox.clearContent();  
        impScoreBox.clearContent();
        result.clear();
        result.centerX();
        return registry.editScoreboardCourse;
    }

    if (viewStudent.clicked(mousePoint)) {
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;            
        }
        courseBox.content.text.clear();
        classBox.content.text.clear();
        nameBox.content.text.clear();
        teacherBox.content.text.clear();
        creditBox.content.text.clear();
        enrollBox.content.text.clear();
        dayBox.content.text.clear();
        sessionBox.content.text.clear();        
        addBox.content.text.clear();
        removeBox.content.text.clear();
        impBox.clearContent();
        expBox.clearContent();  
        impScoreBox.clearContent();
        if (exportListOfStudentInCourse(fileBox.content.text, *ptrCourse_Global, notif)){
            fileBox.content.text.clear();
        }    
        result = notif;
        result.centerX();
        return this;
    }

    if (expButton.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;            
        }
        courseBox.content.text.clear();
        classBox.content.text.clear();
        nameBox.content.text.clear();
        teacherBox.content.text.clear();
        creditBox.content.text.clear();
        enrollBox.content.text.clear();
        dayBox.content.text.clear();
        sessionBox.content.text.clear();        
        addBox.content.text.clear();
        removeBox.content.text.clear();
        impBox.clearContent();
        impScoreBox.clearContent();
        if (exportListScoreboardOfCourse(expBox.getContent(), *ptrCourse_Global, notif)) expBox.clearContent();
        result = notif;
        result.centerX();
        return this;
    }

    if (back.clicked(mousePoint)) {
        courseBox.content.text.clear();
        classBox.content.text.clear();
        nameBox.content.text.clear();
        teacherBox.content.text.clear();
        creditBox.content.text.clear();
        enrollBox.content.text.clear();
        dayBox.content.text.clear();
        sessionBox.content.text.clear();
        addBox.content.text.clear();
        removeBox.content.text.clear();
        impBox.clearContent();
        expBox.clearContent();
        fileBox.content.text.clear();
        impScoreBox.clearContent();
        ptrCourse_Global = nullptr;
        result.clear();
        ptrCourse_Global = nullptr;
        return registry.semesterScene;
    }
    return this;
}