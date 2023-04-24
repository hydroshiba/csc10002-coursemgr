#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "raylib.h"
#include "Constants.h"

class Scrollbar {
private:
	Vector2 pos, cur_pos, last_mouse;
	float len;
	bool pressing;

public:
	float pos_min, pos_max, thickness;
	float content_len, content_max_len;

	Color fill, press;
	bool horizontal;

	Scrollbar();
	Scrollbar(Vector2 pos, float pos_min, float pos_max, float content_len, float content_max_len, float thickness, bool horizontal = false, Color fill = box_const::border_color, Color press = button_const::press_color);
	
	Rectangle getRect();
	void setPos(Vector2 newPos);
	float content_height();

	bool clicked(const Vector2 &mouse);
	bool pressed(const Vector2 &mouse);
	bool currentlyPressed(const Vector2 &mouse);

	void render(const Vector2 &mouse);
	void process(const Vector2 &mouse);
};

#endif