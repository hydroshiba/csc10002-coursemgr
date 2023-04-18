#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "raylib.h"
#include "Constants.h"

class Bar {
private:
	Vector2 origin, last_mouse;
	bool pressing;

public:
	Vector2 pos, size;
	Color fill, press;
	bool horizontal;
	float limit;

	Bar();
	Bar(Vector2 pos, Vector2 size, float limit, bool horizontal = false, Color fill = box_const::border_color, Color press = button_const::press_color);
	Rectangle getRect();

	bool clicked(const Vector2 &mouse);
	bool pressed(const Vector2 &mouse);

	void render(const Vector2 &mouse);
	void process(const Vector2 &mouse);
};

class Scrollbar {
private:
	Rectangle bound;
public:

};

#endif