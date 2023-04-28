#include "SchoolYearScene.h"

SchoolYearScene::SchoolYearScene() {
    nameScene = "School Year";
    nameScene.setSize(50);
    nameScene.centerX();
    nameScene.setY(100);
    //--------------------------------------
    viewClass = "View Classes";
    viewClass.setSize(30);
    viewClass.setPos({100, 250});

    listClass.setLabel("List of Classes:");
    listClass.setPos({400, 240});
    listClass.setSize({300, 50});

    view.label = "View";
    view.setPos({800, 240});
    view.setSize({150, 50});
    
    warningViewClass = "A class must be selected";
    warningViewClass.setColor(RED); 
    warningViewClass.setSize(30);
    warningViewClass.setPos({400, 290});

    isAnyClassChosen = true;
    //--------------------------------------
    addClass = "Add Class";
    addClass.setSize(30);
    addClass.setPos({100, 350});

    inputClassNameAdded.defaultText = "Enter Class Name";
    inputClassNameAdded.setPos({400, 340});
    inputClassNameAdded.setSize({300, 50});

    add.label = "Add";
    add.setPos({800, 340});
    add.setSize({150, 50});

    warningClassNameAdded = "Class name must not be empty";
    warningClassNameAdded.setColor(RED);
    warningClassNameAdded.setSize(30);
    warningClassNameAdded.setPos({400, 390});

    isClassNameNotEmpty = true;
    //--------------------------------------
    removeClass = "Remove Class";
    removeClass.setSize(30);
    removeClass.setPos({100, 450});

    inputClassNameRemoved.defaultText = "Enter Class Name";
    inputClassNameRemoved.setPos({400, 440});
    inputClassNameRemoved.setSize({300, 50});

    remove.label = "Remove";
    remove.setPos({800, 440});
    remove.setSize({150, 50});
    //--------------------------------------
    editYear = "Edit Year";
    editYear.setSize(30);
    editYear.setPos({100, 550});

    inputYearEditted.defaultText = "Enter Year";
    inputYearEditted.setPos({400, 540});
    inputYearEditted.setSize({300, 50});

    change.label = "Change";
    change.setPos({800, 540});
    change.setSize({150, 50});
    //--------------------------------------
    back.label = "Back";
    back.setPos({1000, 600});
    back.setSize({200, 50});
}

void SchoolYearScene::render() {
    nameScene.render();
    //--------------------------------------
    viewClass.render();
    listClass.render(mousePoint);
    view.render(mousePoint);
    if (!isAnyClassChosen) warningViewClass.render();
    //--------------------------------------
    addClass.render();
    inputClassNameAdded.render(mousePoint);
    add.render(mousePoint);
    if (!isClassNameNotEmpty) warningClassNameAdded.render();
    //--------------------------------------
    removeClass.render();
    inputClassNameRemoved.render(mousePoint);
    remove.render(mousePoint);
    //--------------------------------------
    editYear.render();
    inputYearEditted.render(mousePoint);
    change.render(mousePoint);
    //--------------------------------------
    back.render(mousePoint);
}

Scene* SchoolYearScene::process() {
    this->mousePoint = GetMousePosition();
    //--------------------------------------
    listClass.process(mousePoint);
    if (view.clicked(mousePoint)) {
        if (listClass.getSelected() == -1)
            isAnyClassChosen = false;
        else 
            isAnyClassChosen = true;
            //switch to the class scene of the class selected
    }
    //--------------------------------------
    inputClassNameAdded.process(mousePoint);
    if (add.clicked(mousePoint)) {
        if(inputClassNameAdded.getContent() == "")
            isClassNameNotEmpty = false;
        else 
            isClassNameNotEmpty = true;
            //add class
    }
    //--------------------------------------
    inputClassNameRemoved.process(mousePoint);
    if (remove.clicked(mousePoint)) {
        if(inputClassNameRemoved.getContent() == "") {
            std::cout << "Class Name must not be empty\n";
        }
        else 
            std::cout << "Class removed\n";
            //remove class
    }
    //--------------------------------------
    inputYearEditted.process(mousePoint);
    if (change.clicked(mousePoint)) {
        if (inputYearEditted.getContent() == "")
            std::cout << "Start year must not be empty\n";
        else 
            std::cout << "Start year changed\n";
            //change start year
    }
    if (back.clicked(mousePoint)) {
        std::cout << "Back to previous scene clicked\n";
    }
    return this;
} 