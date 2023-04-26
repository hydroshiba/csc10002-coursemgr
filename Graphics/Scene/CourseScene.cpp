#include "CourseScene.h"

CourseScene :: CourseScene(){
    ptrCourse = new Course();
    title = "Course";
    title.setSize(75);
    title.centerX();
    title.setY(75);

    courseID = ptrCourse->ID;
    courseID.setSize(40);
    courseID.setPos({100,200});
    courseID.setColor(MAROON);

    classID = ptrCourse->classID;
    classID.setSize(40);
    classID.setPos({100, 275});
    classID.setColor(MAROON);

    name = ptrCourse->name;
    name.setSize(40);
    name.setPos({100, 350});
    name.setColor(MAROON);

    teacher = ptrCourse->teacher;
    teacher.setSize(40);
    teacher.setPos({100, 425});
    teacher.setColor(MAROON);

    weekday = weekday_to_string(ptrCourse->weekday);
    weekday.setSize(40);
    weekday.setPos({100, 500});
    weekday.setColor(MAROON);

    session = session_to_string(ptrCourse->session);
    session.setSize(40);
    session.setPos({100, 575});
    session.setColor(MAROON);

    addBox.setSize({200,50});
    addBox.setPos({500, 275});
    addBox.defaultText = "Student ID";

    add.label = "Add";
    add.setSize({100,50});
    add.setPos({700,275});

    removeBox.setSize({200,50});
    removeBox.setPos({500, 375});
    removeBox.defaultText = "Student ID";

    remove.label = "Remove";
    remove.setSize({100,50});
    remove.setPos({700,375});

    remove.hover_color = RED;
    remove.press_color = MAROON;

    viewStudent.label = "View Students";
    viewStudent.setHeight(100);
    viewStudent.setWidth(250);
    viewStudent.setPos({950,100});

    viewScore.label = "View Scoreboards";
    viewScore.setSize({250, 100});
    viewScore.setPos({950, 250});

    updateBox.label = "Update Course";
    updateBox.setSize({250,100});
    updateBox.setPos({950, 400});

    back.label = "Back";
    back.setSize({150,50});
    back.setPos({1000, 600});

    back.hover_color = RED;
    back.press_color = MAROON;

    invalid = "";
	invalid.setColor(RED);
	invalid.setSize(24);
	invalid.centerX();
	invalid.setY(475);
}

void CourseScene :: render(){
    title.render();

    courseID.render();
    classID.render();
    name.render();
    teacher.render();
    weekday.render();
    session.render();

    addBox.render(mousePoint);
    add.render(mousePoint);

    removeBox.render(mousePoint);
    remove.render(mousePoint);

    viewStudent.render(mousePoint);
    viewScore.render(mousePoint);
    updateBox.render(mousePoint);
    back.render(mousePoint);

    invalid.render();
}

Scene* CourseScene::process(){
    this->mousePoint = GetMousePosition();
    addBox.process(mousePoint);
    removeBox.process(mousePoint);


    if (add.clicked(mousePoint)||remove.clicked(mousePoint)){
        if (addBox.content.text.empty() && removeBox.content.text.empty()){
            invalid = "Invalid student ID, please retry!";
            invalid.centerX();

            return this;
        }

        invalid = "";
        invalid.centerX();  
        return registry.blank;
    }
    
    if (viewScore.clicked(mousePoint)) return registry.blank;

    if (viewStudent.clicked(mousePoint)) return registry.blank;

    if (updateBox.clicked(mousePoint)) return registry.editScene;

    if (back.clicked(mousePoint)) return registry.blank;

    return this;
}