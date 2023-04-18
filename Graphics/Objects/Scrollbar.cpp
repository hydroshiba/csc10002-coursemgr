#include "Scrollbar.h"
#include <iostream>

Bar::Bar() :
	pos({0, 0}),
	size({50, 200}),
	fill(box_const::border_color),
	press(button_const::press_color),
	origin(pos) {}

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

	DrawRectangleRec(getRect(), color);
}

void Bar::process(const Vector2 &mouse) {
	if(!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) pressing = false;
	
	if(pressed(mouse)) {
		if(!pressing) {
			origin = pos;
			mouse_origin = mouse;
		}
		pressing = true;
	}

	if(pressing) pos.y = origin.y + mouse.y - mouse_origin.y;
}