#include "DropBox.h"

DropBox::DropBox() {
    curIndex = -1;
    selected = false;

    current.label = "Choose an option";
    current.label.color = border_color;
    current.roundness = 0;

    pos = {0, 0};
    size = {box_const::width, box_const::height};

    arrow.center = {300, 300};
    arrow.length = 5;
    arrow.angle = 0;
    arrow.color = border_color;

    refresh();
}

void DropBox::refresh() {
    current.setPos(pos);
    current.setSize(size);

    for(int i = 0; i < options.size(); ++i) {
        options[i].setSize(size);

        Vector2 curPos;
        if(i) curPos = options[i - 1].getPos();
        else curPos = pos;

        options[i].setPos({curPos.x, curPos.y + size.y - box_const::thickness});
    }

    arrow.length = current.getRightPad() / 3;
    arrow.center = {pos.x + size.x - current.getRightPad() / 2, pos.y + size.y / 2};
}

void DropBox::setLabel(std::string label) {
    current.label = label;
}

void DropBox::setX(float x) {
    pos.x = x;
    refresh();
}

void DropBox::setY(float y) {
    pos.y = y;
    refresh();
}

void DropBox::setWidth(float width) {
    size.x = width;
    refresh();
}

void DropBox::setHeight(float height) {
    size.y = height;
    refresh();
}

void DropBox::setPos(Vector2 pos) {
    this->pos = pos;
    refresh();
}

void DropBox::setSize(Vector2 size) {
    this->size = size;
    refresh();
}

void DropBox::add(std::string label) {
    Option* last = nullptr;
    Option option;

    if(options.size() == 0) last = &current;
    else {
        last = (options.end() - 1);
        last->roundness = 0;
    }
    
    option.setPos({pos.x, last->getPos().y + size.y - box_const::thickness});
    option.setSize(size);
    option.label = label;
    option.roundness = 0;

    option.fill_color = fill_color;
    option.border_color = border_color;
    option.hover_color = hover_color;
    option.press_color = press_color;

    options.append(option);
}

int DropBox::getSelected() {
    return curIndex;
}

void DropBox::render(const Vector2 &mouse) {
    // DrawRectangleRoundedLines(bound, 0.05, box_const::segments, box_const::thickness, border_color);
    
    current.render(mouse);
    bar.render(mouse);
    arrow.render();

    // BeginScissorMode(0, 0, 10, 100);

    if(selected) {
        for(int i = options.size() - 1; i > -1; --i)
            options[i].render(mouse);
        // BeginScissorMode(0, 0, 10, 100);
    }

    // EndScissorMode();
}

bool DropBox::process(const Vector2 &mouse) {
    bool areaClicked = false;

    if(selected) {
        if(arrow.angle != 90) arrow.angle += 900.0 / app_const::fps;

        for(int i = 0; i < options.size(); ++i) if(options[i].clicked(mouse)){
            if(curIndex >= 0) options[curIndex].fill_color = fill_color;
            curIndex = i;

            selected = false;
            current.label = options[i].label;
            current.label.color = text_color;

            options[i].fill_color = hover_color;
            areaClicked = true;
        }
    }
    else {
        if(arrow.angle) arrow.angle -= 900.0 / app_const::fps;
    }

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !current.clicked(mouse)) selected = false;
	if(current.clicked(mouse)) selected = !selected;

    bound = Rectangle{size.x, size.y, pos.x, pos.y};

    bar.process(mouse);
    areaClicked = areaClicked || current.clicked(mouse);
    return areaClicked;
}