#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "raylib.h"

#include "TextBox.h"
#include "Scrollbar.h"
#include "Option.h"
#include "Vector.h"

class Table {
private:
	Vector2 pos;
	Scrollbar bar;

	Vector<Vector<std::string>> table;
	float row_height;

public:
	Table();

	Vector2 getSize();

	Rectangle getRect();
	Rectangle getBound();

	void process(const Vector2 &mouse);
	void render(const Vector2 &mouse);
};

#endif