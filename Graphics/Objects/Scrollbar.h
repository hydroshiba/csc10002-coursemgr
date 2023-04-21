#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "raylib.h"
#include "Constants.h"

class Scrollbar {
private:
	Vector2 cur_pos, last_mouse;
	float len;
	bool pressing;

public:
	float pos_min, pos_max, thickness;
	float content_len, content_max_len;
	Vector2 pos;

	Color fill, press;
	bool horizontal;

	Scrollbar();
	Scrollbar(float pos_min, float pos_max, float content_len, float content_max_len, float thickness, bool horizontal = false, Color fill = box_const::border_color, Color press = button_const::press_color);
	
	Rectangle getRect();
	float content_height();

	bool clicked(const Vector2 &mouse);
	bool pressed(const Vector2 &mouse);

	void render(const Vector2 &mouse);
	void process(const Vector2 &mouse);
};

#endif