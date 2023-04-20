#include "EditCourse.h"

EditCourse :: EditCourse(){
    title = "Edit Course";
    title.setSize(75);
    title.centerX();
    title.setY(75);

    courseID = "Course ID";
    courseID.setSize(40);
    courseID.setPos({100,200});
    courseID.setColor(MAROON);

    classID = "Class ID";
    classID.setSize(40);
    classID.setPos({100, 275});
    classID.setColor(MAROON);

    name = "Course Name";
    name.setSize(40);
    name.setPos({100, 350});
    name.setColor(MAROON);

    teacher = "Teacher";
    teacher.setSize(40);
    teacher.setPos({100, 425});
    teacher.setColor(MAROON);

    weekday = "Day";
    weekday.setSize(40);
    weekday.setPos({100, 500});
    weekday.setColor(MAROON);

    session = "Session";
    session.setSize(40);
    session.setPos({100, 575});
    session.setColor(MAROON);

    courseBox.setSize({300,50});
    courseBox.setPos({350,200});
    courseBox.defaultText = "Course ID";

    classBox.setSize({300,50});
    classBox.setPos({350,275});
    classBox.defaultText = "Class ID";

    nameBox.setSize({300,50});
    nameBox.setPos({350,350});
    nameBox.defaultText = "Course Name";

    teacherBox.setSize({300,50});
    teacherBox.setPos({350,425});
    teacherBox.defaultText = "Teacher";

    dayBox.setSize({300,50});
    dayBox.setPos({350,500});
    dayBox.defaultText = "Weekday";

    sessionBox.setSize({300,50});
    sessionBox.setPos({350,575});
    sessionBox.defaultText = "Session";

    change.label = "Change";
    change.setSize({150,50});
    change.setPos({700,350});
    change.fill_color = ORANGE;

    back.label = "Back";
    back.setSize({150,50});
    back.setPos({1000, 600});
    back.fill_color = RED;
    back.hover_color = RED;
    back.press_color = MAROON;
}

void EditCourse::render(){
    title.render();
    courseID.render();
    classID.render();
    name.render();
    teacher.render();
    weekday.render();
    session.render();

    courseBox.render(mousePoint);
    classBox.render(mousePoint);
    nameBox.render(mousePoint);
    teacherBox.render(mousePoint);
    dayBox.render(mousePoint);
    sessionBox.render(mousePoint);

    change.render(mousePoint);
    back.render(mousePoint);
}

Scene* EditCourse::process(){
    mousePoint = GetMousePosition();

    courseBox.process(mousePoint);
    classBox.process(mousePoint);
    nameBox.process(mousePoint);
    teacherBox.process(mousePoint);
    dayBox.process(mousePoint);
    sessionBox.process(mousePoint);

    if (change.clicked(mousePoint)){
        // do sth
        return registry.courseScene;
    }
    if (back.clicked(mousePoint)) return registry.courseScene;
    return this;
}