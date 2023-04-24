#include "Option.h"

void Option::refreshText() {
	label.font_size = 0;

    while(label.size().y * 3 < size.y * 2) {
        ++label.font_size;
    }

    --label.font_size;
    textPos.x = fill_bound.x + left_padding;
    textPos.y = fill_bound.y + (fill_bound.height - (label.size().y)) / 2;
}

void Option::refresh() {
    border_bound = Rectangle{pos.x, pos.y, size.x, size.y};
    
    fill_bound.x = pos.x + box_const::thickness;
    fill_bound.y = pos.y + box_const::thickness;
    
    fill_bound.width = size.x - 2 * box_const::thickness;
    fill_bound.height = size.y - 2 * box_const::thickness;

	right_padding = size.y;

    refreshText();
}

float Option::getLeftPad() {
	return left_padding;
}

float Option::getRightPad() {
	return right_padding;
}

void Option::render(const Vector2 &mouse) const {
	Color color;

    if(hovering(mouse)) color = hover_color;
    else if(pressed(mouse)) color = press_color;
    else color = fill_color;

    DrawRectangleRounded(border_bound, roundness, box_const::segments, color);
    DrawRectangleRoundedLines(fill_bound, roundness, box_const::segments, box_const::thickness, border_color);

	StartScissor(fill_bound.x + left_padding, fill_bound.y, fill_bound.width - right_padding, fill_bound.height);
    DrawTextEx(label.font, label.text.c_str(), textPos, label.font_size, label.space, label.color);
    EndScissor();
}