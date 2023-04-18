#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "raylib.h"
#include "Constants.h"

class Bar {
private:
	Vector2 origin, mouse_origin;
	bool pressing;

public:
	Vector2 pos, size;
	Color fill, press;

	Bar();
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