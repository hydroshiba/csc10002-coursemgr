#include "EditScoreboardScene.h"

EditScoreboardScene::EditScoreboardScene(){
    title = "Edit scoreboard of " + defaultStr;
    title.setSize(75);
    title.centerX();
    title.setY(25);

    studentID = "Student ID";
    studentID.setSize(40);
    studentID.setPos({100,200});
    studentID.setColor(MAROON);

    IDBox.setSize({250,50});
    IDBox.setPos({400, 200});
    IDBox.defaultText = "Input studentID...";

    midTerm = "Mid Term Score";
    midTerm.setSize(40);
    midTerm.setPos({100,300});
    midTerm.setColor(MAROON);

    midTermBox.setSize({250,50});
    midTermBox.setPos({400, 300});
    midTermBox.defaultText = "Midterm score";

    final = "Final Score";
    final.setSize(40);
    final.setPos({100,375});
    final.setColor(MAROON);

    finalBox.setSize({250,50});
    finalBox.setPos({400, 375});
    finalBox.defaultText = "Final score";

    other = "Other Score";
    other.setSize(40);
    other.setPos({100,450});
    other.setColor(MAROON);

    otherBox.setSize({250,50});
    otherBox.setPos({400, 450});
    otherBox.defaultText = "Other score";

    total = "Total Score";
    total.setSize(40);
    total.setPos({100,525});
    total.setColor(MAROON);

    totalBox.setSize({250,50});
    totalBox.setPos({400, 525});
    totalBox.defaultText = "Total score";

    change.label = "Change";
    change.setSize({150,50});
    change.setPos({650, 200});
    change.setInsertColor();

    view.label = "View";
    view.setSize({150,50});
    view.setPos({800, 200});
    view.setViewColor();

    back.label = "Back";
    back.setSize({150,50});
    back.setPos({1100, 550});
    back.fill_color = RED;
    back.hover_color = RED;
    back.press_color = MAROON;

    result = "";
	result.setColor(RED);
	result.setSize(30);
	result.centerX();
	result.setY(600);
}

void EditScoreboardScene::render(){
    title.render();
    studentID.render();
    IDBox.render(mousePoint);

    midTerm.render();
    midTermBox.render(mousePoint);

    final.render();
    finalBox.render(mousePoint);

    other.render();
    otherBox.render(mousePoint);

    total.render();
    totalBox.render(mousePoint);

    change.render(mousePoint);
    view.render(mousePoint);
    back.render(mousePoint);
    result.render();
}

Scene* EditScoreboardScene::process(){
    string notif;
    this->mousePoint = GetMousePosition();
    IDBox.process(mousePoint);
    midTermBox.process(mousePoint);
    finalBox.process(mousePoint);
    otherBox.process(mousePoint);
    totalBox.process(mousePoint);
    
    if (ptrCourse_Global != nullptr) {
        title = "Edit scoreboard of " + ptrCourse_Global->ID;
        title.centerX();
    }
    if (change.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            return this;
        }
        string studentID = IDBox.getContent();
        string midterm = midTermBox.getContent();
        string final = finalBox.getContent();
        string other = otherBox.getContent();
        string total = totalBox.getContent();
        Scoreboard* ptrScoreboard = getScoreboard(*ptrCourse_Global, studentID);
        if (ptrScoreboard == nullptr) {
            notif = "Student with ID " + IDBox.getContent() + " is not existed in this course";
        }
        else if (updateScoreboard(*ptrCourse_Global, studentID, midterm , other, final , total, notif)){
            midTermBox.clearContent();
            finalBox.clearContent();
            otherBox.clearContent();
            totalBox.clearContent();

            IDBox.defaultText = "Input studentID...";
            midTermBox.defaultText = "Midterm score";
            finalBox.defaultText = "Final score";
            otherBox.defaultText = "Other score";
            totalBox.defaultText = "Total score";
        }
        result = notif;
        result.centerX();
        return this;
    }

    else if (view.clicked(mousePoint)){
        if (ptrCourse_Global == nullptr){
            result = "Access nullptr error!";
            result.centerX();
            IDBox.clearContent();
            midTermBox.clearContent();
            finalBox.clearContent();
            otherBox.clearContent();
            totalBox.clearContent();
            result.centerX();
            return this;
        }
        Scoreboard *ptrScoreboard;
        string studentID = IDBox.getContent();
        if (studentID.empty()){
            result = "Pls enter studentID!";
            result.centerX();
            IDBox.clearContent();
            midTermBox.clearContent();
            finalBox.clearContent();
            otherBox.clearContent();
            totalBox.clearContent();
            result.centerX();
            return this;
        }
        ptrScoreboard = getScoreboard(*ptrCourse_Global, studentID);
        if (ptrScoreboard == nullptr) {
            result = "Student with ID " + studentID + " is not existed in this course";
            result.centerX();
            IDBox.clearContent();
            midTermBox.clearContent();
            finalBox.clearContent();
            otherBox.clearContent();
            totalBox.clearContent();
            result.centerX();
        }
        else {
            IDBox.defaultText = IDBox.getContent();
            midTermBox.defaultText = to_string(ptrScoreboard->midterm);
            finalBox.defaultText = to_string(ptrScoreboard->final);
            otherBox.defaultText = to_string(ptrScoreboard->other);
            totalBox.defaultText = to_string(ptrScoreboard->total);
        }
        return this; 
    }

    else if (back.clicked(mousePoint)){
        IDBox.clearContent();
        midTermBox.clearContent();
        finalBox.clearContent();
        otherBox.clearContent();
        totalBox.clearContent();     
        result.clear();
        return registry.courseScene;
    }
    return this;
}