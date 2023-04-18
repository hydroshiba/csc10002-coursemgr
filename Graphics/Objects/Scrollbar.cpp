#include "Scrollbar.h"
#include <iostream>

Bar::Bar() :
	pos({0, 0}),
	size({50, 200}),
	limit(500),
	horizontal(false),
	fill(box_const::border_color),
	press(button_const::press_color),
	origin({0, 0}),
	last_mouse({0, 0}) {}

Bar::Bar(Vector2 pos, Vector2 size, float limit, bool horizontal, Color fill, Color press) :
	pos(pos),
	size(size),
	limit(limit),
	horizontal(horizontal),
	fill(fill),
	press(press),
	origin(pos),
	last_mouse(pos) {}

Rectangle Bar::getRect() {
	return Rectangle{pos.x, pos.y, size.x, size.y};
}

bool Bar::clicked(const Vector2 &mouse) {
	if(!CheckCollisionPointRec(mouse, getRect())) return false;
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

bool Bar::pressed(const Vector2 &mouse) {
	if(!CheckCollisionPointRec(mouse, getRect())) return false;
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

void Bar::render(const Vector2 &mouse) {
	Color color;
	
	if(pressing || pressed(mouse)) color = press;
	else color = fill;
	
	DrawRectangleRounded(getRect(), box_const::roundness, box_const::segments, color);
}

void Bar::process(const Vector2 &mouse) {
	if(!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) pressing = false;
	
	if(pressed(mouse)) {
		if(!pressing) last_mouse = mouse;
		pressing = true;
	}

	if(pressing) {
		float diff = (mouse.x - last_mouse.x) * horizontal + (mouse.y - last_mouse.y) * (!horizontal);
		float &cur = (horizontal ? pos.x : pos.y);

		float org = (horizontal ? origin.x : origin.y);
		float len = (horizontal ? size.x : size.y);

		if(cur + diff + len <= limit && cur + diff >= org) cur += diff;
		last_mouse = mouse;
	}
}