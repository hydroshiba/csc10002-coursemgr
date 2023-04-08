#include "Dropbox.h"
#include "math.h"
#include <iostream>

Dropbox::Dropbox() {}

void Dropbox::setLabel(std::string label) {
    select.label = label;
}

void Dropbox::setX(float x) {
    position.x = x;
    select.setX(x);
}

void Dropbox::setY(float y) {
    position.y = y;
    select.setY(y);
}

void Dropbox::setWidth(float width) {
    size.x = width;
    select.setWidth(width);
}

void Dropbox::setHeight(float height) {
    size.y = height;
    select.setHeight(height);
    total_height = height;
}

void Dropbox::setPos(Vector2 pos) {
    position = pos;
    select.setPos(pos);
}

void Dropbox::setSize(Vector2 sz) {
    size = sz;
    select.setSize(sz);
    total_height = sz.y;
}

void Dropbox::addNewButton(std::string label) {
    Button temp;
    temp.label = label;
    temp.setSize(size);
    temp.setPos({position.x, position.y + total_height});
    options.append(temp);
    total_height += size.y;
    chosen.append(false);
    if (options.size() != 1) return;
    select.label.text = label;
    select.setPos(position);
    select.setSize(size);
    chosen[0] = true;
}

void Dropbox::renderAllOptions(const Vector2 &mouse) {
    int number_of_options = options.size();
    for (int i = 0; i < number_of_options; ++i) {
        //rendering
        if (chosen[i]) {
            options[i].render(options[i].getPos());
        }
        else {
            options[i].render(mouse);
        }
        //check if a button is chosen
        if (options[i].clicked(mouse)) {
            if (!chosen[i]) {
                //unhighlight option chosen before
                chosen[option_chosen_before] = false;
                //highlight option chosen now
                select.label.text = options[i].label.text;
                select.setPos(position);
                select.setSize(size);
                chosen[i] = true;
                option_chosen_before = i;
            }
            clicked = false;
            return;
        }
    }
}

int Dropbox::returnChosenButton() {
    return option_chosen_before;
}

void Dropbox::render(const Vector2 &mouse) {
    select.render(mouse);
    if (select.clicked(mouse)) {
        if (clicked == false) clicked = true;
        else clicked = false;
    }
    if (clicked) {
        renderAllOptions(mouse);
        std::cout << returnChosenButton() << '\n';
    }
}
