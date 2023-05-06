#include "CourseScene.h"

CourseScene :: CourseScene(){
    title = "Course";
    title.setSize(75);
    title.centerX();
    title.setY(75);

    courseID = "CourseID: " + defaultStr;
    courseID.setSize(40);
    courseID.setPos({50,75});
    courseID.setColor(MAROON);

    classID = "ClassID: " + defaultStr;
    classID.setSize(40);
    classID.setPos({50, 150});
    classID.setColor(MAROON);

    name = "Course Name: " + defaultStr;
    name.setSize(40);
    name.setPos({50, 225});
    name.setColor(MAROON);

    teacher = "Teacher: " + defaultStr;
    teacher.setSize(40);
    teacher.setPos({50, 300});
    teacher.setColor(MAROON);

    credit = "Credits: " + defaultStr;
    credit.setSize(40);
    credit.setPos({50, 375});
    credit.setColor(MAROON);    

    maxEnroll = "Max Enroll: " + defaultStr;
    maxEnroll.setSize(40);
    maxEnroll.setPos({50, 450});
    maxEnroll.setColor(MAROON);

    weekday = "Weekday: " + defaultStr;
    weekday.setSize(40);
    weekday.setPos({50, 525});
    weekday.setColor(MAROON);

    session = "Session: " + defaultStr;
    session.setSize(40);
    session.setPos({50, 600});
    session.setColor(MAROON);

    addText = "Add a student to course";
    addText.setSize(35);
    addText.setPos({500, 200});

    addBox.setSize({250,50});
    addBox.setPos({500, 250});
    addBox.defaultText = "Input studentID...";

    add.label = "Add";
    add.setSize({100,50});
    add.setPos({750,250});

    removeBox.setSize({250,50});
    removeBox.setPos({500, 375});
    removeBox.defaultText = "Input studentID...";

    remove.label = "Remove";
    remove.setSize({100,50});
    remove.setPos({750,375});

    remove.hover_color = RED;
    remove.press_color = MAROON;

    viewStudent.label = "View Students";
    viewStudent.setHeight(100);
    viewStudent.setWidth(250);
    viewStudent.setPos({950,75});

    viewScore.label = "View Scoreboards";
    viewScore.setSize({250, 100});
    viewScore.setPos({950, 225});

    updateBox.label = "Update Course";
    updateBox.setSize({250,100});
    updateBox.setPos({950, 375});

    fileButton.label = "Add by file";
    fileButton.setSize({250,100});
    fileButton.setPos({950,525});

    back.label = "Back";
    back.setSize({150,50});
    back.setY(600);
    back.centerX();

    back.hover_color = RED;
    back.press_color = MAROON;

    result = "";
	result.setColor(RED);
	result.setSize(24);
	result.centerX();
	result.setY(475);
}

void CourseScene :: render(){
    title.render();

    courseID.render();
    classID.render();
    name.render();
    teacher.render();
    credit.render();
    maxEnroll.render();
    weekday.render();
    session.render();

    addText.render(); 
    addBox.render(mousePoint);
    add.render(mousePoint);

    removeBox.render(mousePoint);
    remove.render(mousePoint);

    viewStudent.render(mousePoint);
    viewScore.render(mousePoint);
    updateBox.render(mousePoint);
    fileButton.render(mousePoint);
    back.render(mousePoint);

    result.render();
}

Scene* CourseScene::process(){
    std::string notif;
    this->mousePoint = GetMousePosition();
    addBox.process(mousePoint);
    removeBox.process(mousePoint);
    if (ptrCourse_Global){
        courseID = "CourseID: " + ptrCourse_Global->ID;
        classID = "ClassID: " + ptrCourse_Global->classID;
        name = "Course Name: " + ptrCourse_Global->name;
        teacher = "Teacher: " + ptrCourse_Global->teacher;
        credit = "Credits: " + std::to_string(ptrCourse_Global->credits);
        maxEnroll = "Max Enroll: " + std::to_string(ptrCourse_Global->maxEnroll);
        weekday = "Weekday: " + weekday_to_string(ptrCourse_Global->weekday);
        session = "Session: " + session_to_string(ptrCourse_Global->session);
    }

    if (add.clicked(mousePoint)||remove.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;
        }
        if (addBox.content.text.empty() && removeBox.content.text.empty()){
            result = "Invalid student ID, please retry!";
            result.centerX();
            return this;
        }
        else if (!addBox.content.text.empty()) addStudentToCourse(students, *ptrCourse_Global, addBox.content.text, notif);
        else removeStudFromCourse(*ptrCourse_Global, removeBox.content.text, notif);
        result = notif;
        result.centerX();
        addBox.content.text.clear();
        removeBox.content.text.clear();
        return this;
    }

    else if (fileButton.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;            
        }
        //importStudentListOfCourseFromFile(students, *ptrCourse_Global, notif);
        result = notif;
        result.centerX();
        return this;
    }
    
    else if (viewScore.clicked(mousePoint)) {
        addBox.clearContent();
        removeBox.clearContent();
        return registry.blank;
    }
    else if (viewStudent.clicked(mousePoint)) {
        addBox.clearContent();
        removeBox.clearContent();
        return registry.blank;
    }
    else if (updateBox.clicked(mousePoint)) {
        addBox.clearContent();
        removeBox.clearContent();
        return registry.editScene;
    }

    else if (back.clicked(mousePoint)) {
        addBox.clearContent();
        removeBox.clearContent();
        ptrCourse_Global = nullptr;
        return registry.blank;
    }
    return this;
}