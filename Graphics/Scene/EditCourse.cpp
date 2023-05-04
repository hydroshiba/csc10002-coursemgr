#include "EditCourse.h"

EditCourse :: EditCourse(){
    title = "Edit Course";
    title.setSize(75);
    title.centerX();
    title.setY(25);

    courseID = "CourseID: " + defaultStr;
    courseID.setSize(40);
    courseID.setPos({50,100});
    courseID.setColor(MAROON);

    classID = "ClassID: " + defaultStr;
    classID.setSize(40);
    classID.setPos({50, 175});
    classID.setColor(MAROON);

    name = "Course Name: " + defaultStr;
    name.setSize(40);
    name.setPos({50, 250});
    name.setColor(MAROON);

    teacher = "Teacher: " + defaultStr;
    teacher.setSize(40);
    teacher.setPos({50, 325});
    teacher.setColor(MAROON);

    credit = "Credits: " + defaultStr;
    credit.setSize(40);
    credit.setPos({50, 400});
    credit.setColor(MAROON);    

    maxEnroll = "Max Enroll: " + defaultStr;
    maxEnroll.setSize(40);
    maxEnroll.setPos({50, 475});
    maxEnroll.setColor(MAROON);

    weekday = "Weekday: " + defaultStr;
    weekday.setSize(40);
    weekday.setPos({50, 550});
    weekday.setColor(MAROON);

    session = "Session: " + defaultStr;
    session.setSize(40);
    session.setPos({50, 625});
    session.setColor(MAROON);

    courseBox.setSize({300,50});
    courseBox.setPos({500,100});
    courseBox.defaultText = "Input Course ID";

    classBox.setSize({300,50});
    classBox.setPos({500,175});
    classBox.defaultText = "Input Class ID";

    nameBox.setSize({300,50});
    nameBox.setPos({500,250});
    nameBox.defaultText = "Input Course Name";

    teacherBox.setSize({300,50});
    teacherBox.setPos({500,325});
    teacherBox.defaultText = "Input Teacher";

    creditBox.setSize({300,50});
    creditBox.setPos({500,400});
    creditBox.defaultText = "Input Credits";    

    enrollBox.setSize({300,50});
    enrollBox.setPos({500,475});
    enrollBox.defaultText = "Input Number Enrolled";   

    dayBox.setSize({300,50});
    dayBox.setPos({500,550});
    dayBox.defaultText = "Input Weekday";

    sessionBox.setSize({300,50});
    sessionBox.setPos({500,625});
    sessionBox.defaultText = "Input Session";

    change.label = "Change";
    change.setSize({200, 75});
    change.setPos({850,350});
    change.fill_color = ORANGE;

    back.label = "Back";
    back.setSize({150,50});
    back.setPos({1000, 600});
    back.fill_color = RED;
    back.hover_color = RED;
    back.press_color = MAROON;

    result = "";
	result.setColor(RED);
	result.setSize(24);
	result.centerX();
	result.setY(475);
}

void EditCourse::render(){
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

    change.render(mousePoint);
    back.render(mousePoint);

    result.render();
}

Scene* EditCourse::process(){
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

    if (change.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.setX(865);
            return this;
        }
        if(updateCourse(*ptrCourse_Global,courseBox.content.text, classBox.content.text, nameBox.content.text, teacherBox.content.text, creditBox.content.text, enrollBox.content.text, dayBox.content.text, sessionBox.content.text, notif)){
            courseBox.content.text.clear();
            classBox.content.text.clear();
            nameBox.content.text.clear();
            teacherBox.content.text.clear();
            creditBox.content.text.clear();
            enrollBox.content.text.clear();
            dayBox.content.text.clear();
            sessionBox.content.text.clear();
            return registry.courseScene;
        }
        else{
            result = notif;
            result.setX(865);
            return this;
        }
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
        return registry.courseScene;
    }
    return this;
}