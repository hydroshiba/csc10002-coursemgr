#include "EditCourse.h"

EditCourse :: EditCourse(){
    title = "Edit Course";
    title.setSize(75);
    title.centerX();
    title.setY(50);

    courseID = (ptrCourse_Global) ? "CourseID: " + ptrCourse_Global->ID : "CourseID: " + defaultStr;
    courseID.setSize(40);
    courseID.setPos({50,175});
    courseID.setColor(MAROON);

    classID = (ptrCourse_Global) ? "ClassID: " + ptrCourse_Global->classID : "ClassID: " + defaultStr;
    classID.setSize(40);
    classID.setPos({50, 250});
    classID.setColor(MAROON);

    name = (ptrCourse_Global) ? "Course Name: " + ptrCourse_Global->name : "Course Name: " + defaultStr;
    name.setSize(40);
    name.setPos({50, 325});
    name.setColor(MAROON);

    teacher = (ptrCourse_Global) ? "Teacher: " + ptrCourse_Global->teacher : "Teacher: " + defaultStr;
    teacher.setSize(40);
    teacher.setPos({50, 400});
    teacher.setColor(MAROON);

    credit = (ptrCourse_Global) ? "Credits: " + ptrCourse_Global->credits : "Credits: " + defaultStr;
    credit.setSize(40);
    credit.setPos({50, 475});
    credit.setColor(MAROON);

    weekday = (ptrCourse_Global) ? "Weekday: " + weekday_to_string(ptrCourse_Global->weekday) : "Weekday: " + defaultStr;
    weekday.setSize(40);
    weekday.setPos({50, 550});
    weekday.setColor(MAROON);

    session = (ptrCourse_Global) ? "Session: " + session_to_string(ptrCourse_Global->session) : "Session: " + defaultStr;
    session.setSize(40);
    session.setPos({50, 625});
    session.setColor(MAROON);

    courseBox.setSize({300,50});
    courseBox.setPos({500,175});
    courseBox.defaultText = "Input Course ID";

    classBox.setSize({300,50});
    classBox.setPos({500,250});
    classBox.defaultText = "Input Class ID";

    nameBox.setSize({300,50});
    nameBox.setPos({500,325});
    nameBox.defaultText = "Input Course Name";

    teacherBox.setSize({300,50});
    teacherBox.setPos({500,400});
    teacherBox.defaultText = "Input Teacher";

    creditBox.setSize({300,50});
    creditBox.setPos({500,475});
    creditBox.defaultText = "Input Credits";    

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

    invalid = "";
	invalid.setColor(RED);
	invalid.setSize(24);
	invalid.centerX();
	invalid.setY(475);
}

void EditCourse::render(){
    title.render();
    courseID.render();
    classID.render();
    name.render();
    teacher.render();
    credit.render();
    weekday.render();
    session.render();

    courseBox.render(mousePoint);
    classBox.render(mousePoint);
    nameBox.render(mousePoint);
    teacherBox.render(mousePoint);
    creditBox.render(mousePoint);
    dayBox.render(mousePoint);
    sessionBox.render(mousePoint);

    change.render(mousePoint);
    back.render(mousePoint);

    invalid.render();
}

Scene* EditCourse::process(){
    std::string notif;
    mousePoint = GetMousePosition();

    courseBox.process(mousePoint);
    classBox.process(mousePoint);
    nameBox.process(mousePoint);
    teacherBox.process(mousePoint);
    creditBox.process(mousePoint);
    dayBox.process(mousePoint);
    sessionBox.process(mousePoint);

    if (change.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            invalid = "Access nullptr error!";
            invalid.setX(865);
            return this;
        }
        updateCourse(*ptrCourse_Global,courseBox.content.text, classBox.content.text, nameBox.content.text, teacherBox.content.text, creditBox.content.text, dayBox.content.text, sessionBox.content.text, notif);
        invalid = notif;
        invalid.setX(865);
        return registry.courseScene;
    }
    if (back.clicked(mousePoint)) return registry.courseScene;
    return this;
}