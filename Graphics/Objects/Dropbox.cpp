#include "DropBox.h"
#include "Dropbox.h"

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
    
    int optionNum = options.size();
    if(optionNum > 4) optionNum = 4;

    bound.x = pos.x;
    bound.y = pos.y + size.y;

    bound.width = size.x;
    bound.height = (size.y - box_const::thickness) * optionNum;
    
    bar.setPos({pos.x + size.x - 2 * box_const::thickness - bar.thickness, pos.y + size.y + box_const::thickness});
    bar.pos_max = bound.y + bound.height - 2 * box_const::thickness;

    bar.content_max_len = (size.y - box_const::thickness) * options.size();
    bar.content_len = bound.height;

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

void DropBox::add(const std::string &label) {
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
    
    refresh();
}

void DropBox::add(const Vector<std::string> &labels) {
    for(int i = 0; i < labels.size(); ++i) add(labels[i]);
}

string DropBox::getCurLabel() const {
    return current.label.text;
}

void DropBox::remove(const std::string label) {
    int pos = 0;

    for(int i = 0; i < options.size(); ++i) {
        if(options[i].label.text == label) {
            pos = i;
            break;
        }
    }

    options.remove(options.begin() + pos);
    refresh();
}

void DropBox::reset() {
    curIndex = -1;
    current.label = "Choose an option";
    current.label.color = border_color;
}

void DropBox::clear() {
    options.resize(0);
    reset();
    refresh();
}

int DropBox::getSelected() {
	return curIndex;
}

void DropBox::render(const Vector2 &mouse) {
    current.render(mouse);
    arrow.render();

    if(selected) {
        StartScissor(bound);

        for(int i = options.size() - 1; i > -1; --i) {
            if(!CheckCollisionRecs(bound, options[i].getRect())) continue;

            if(bar.currentlyPressed(mouse)) options[i].render({0, 0});
            else options[i].render(mouse);
        }
        
        EndScissor();

        Rectangle tempBound = bound;
        tempBound.y -= box_const::thickness;
        tempBound.height += box_const::thickness;

        DrawRectangleLinesEx(tempBound, box_const::thickness, border_color);
        bar.render(mouse);
    }
}

bool DropBox::process(const Vector2 &mouse) {
    bool areaClicked = false;

    if(selected) {
        if(arrow.angle != 90) arrow.angle += 900.0 / app_const::fps;
        float curY = current.getPos().y + size.y - box_const::thickness - bar.content_height();

        for(int i = 0; i < options.size(); ++i) {
            options[i].setY(curY);
            curY += size.y - box_const::thickness;

            if(bar.currentlyPressed(mouse)) continue;
            if(!CheckCollisionRecs(bound, options[i].getRect())) continue;

            if(options[i].clicked(mouse)){
                if(curIndex >= 0) options[curIndex].fill_color = fill_color;
                curIndex = i;

                selected = false;
                current.label = options[i].label;
                current.label.color = text_color;

                options[i].fill_color = hover_color;
                areaClicked = true;
            }
        }
    }
    else {
        if(arrow.angle) arrow.angle -= 900.0 / app_const::fps;
    }

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !current.clicked(mouse) && !bar.currentlyPressed(mouse)) selected = false;
	if(current.clicked(mouse) && !bar.currentlyPressed(mouse)) selected = !selected;
    bar.process(mouse);

    areaClicked = areaClicked || current.clicked(mouse);
    return areaClicked;
}