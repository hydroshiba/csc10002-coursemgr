#include "Scrollbar.h"
#include <iostream>

Scrollbar::Scrollbar() :
	pos_min(0),
	pos_max(500),
	content_len(100),
	content_max_len(500),
	thickness(10),
	horizontal(false),
	fill(box_const::border_color),
	press(button_const::press_color),
	pos({0, 0}),
	last_mouse({0, 0}) {
		cur_pos = pos;
	}

Scrollbar::Scrollbar(Vector2 pos, float pos_min, float pos_max, float content_len, float content_max_len, float thickness, bool horizontal, Color fill, Color press) :
	pos_min(pos_min),
	pos_max(pos_max),
	content_len(content_len),
	content_max_len(content_max_len),
	thickness(thickness),
	horizontal(horizontal),
	fill(fill),
	press(press),
	pos(pos),
	last_mouse(cur_pos) {
		cur_pos = pos;
	}

Rectangle Scrollbar::getRect() {
	if(horizontal) return Rectangle{cur_pos.x, cur_pos.y, len, thickness};
	return Rectangle{cur_pos.x, cur_pos.y, thickness, len};
}

void Scrollbar::setPos(Vector2 newPos) {
	pos = newPos;
	cur_pos = pos;

	pos_min = (horizontal ? pos.x : pos.y);
}

float Scrollbar::content_height() {
	float h = (horizontal ? cur_pos.x - pos.x : cur_pos.y - pos.y);
	return content_len * h / len;
}

bool Scrollbar::clicked(const Vector2 &mouse) {
	if(!CheckCollisionPointRec(mouse, getRect())) return false;
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

bool Scrollbar::pressed(const Vector2 &mouse) {
	if(!CheckCollisionPointRec(mouse, getRect())) return false;
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

bool Scrollbar::currentlyPressed(const Vector2 &mouse) {
	return pressing;
}

void Scrollbar::render(const Vector2 &mouse) {
	Color color;
	
	if(pressing || pressed(mouse)) color = press;
	else color = fill;

	DrawRectangleRounded(getRect(), 1.0, box_const::segments, color);
}

void Scrollbar::process(const Vector2 &mouse) {
	len = (content_len / content_max_len) * (pos_max - pos_min);

	if(!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) pressing = false;
	
	if(pressed(mouse)) {
		if(!pressing) last_mouse = mouse;
		pressing = true;
	}

	if(pressing) {
		float diff = (mouse.x - last_mouse.x) * horizontal + (mouse.y - last_mouse.y) * (!horizontal);
		float &cur = (horizontal ? cur_pos.x : cur_pos.y);

		cur += diff;
		if(cur + len > pos_max) cur = pos_max - len;
		if(cur < pos_min) cur = pos_min;

		last_mouse = mouse;
	}
	else {
		float diff = GetMouseWheelMove() * -4;
		float &cur = (horizontal ? cur_pos.x : cur_pos.y);

		cur += diff;
		if(cur + len > pos_max) cur = pos_max - len;
		if(cur < pos_min) cur = pos_min;

		last_mouse = mouse;
	}
}