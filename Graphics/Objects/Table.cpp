#include "Table.h"

Table::Table() :
	pos({10, 10}),
	row_height(50) {
		bar.setPos({pos.x + size.x - 2 * box_const::thickness - bar.thickness, pos.y + row_height + box_const::thickness});
	}

Vector2 Table::getSize() {
	Vector2 size;

	size.y = (row_height - box_const::thickness) * table[0].size();
	return { 0, 0 }; // Build error
}

void Table::process(const Vector2 &mouse) {
	bar.process(mouse);
}

Rectangle Table::getRect() {
	Rectangle rect;

	rect.width = size.x;
	rect.height = size.y;

	rect.x = pos.x;
	rect.y = pos.y;

	return rect;
}

Rectangle Table::getBound() {
	Rectangle rect = getRect();

	rect.y += row_height;
	rect.height -= row_height;

	return rect;
}

void Table::render(const Vector2 &mouse) {
	DrawRectangleLinesEx(getRect(), box_const::thickness, box_const::border_color);

	StartScissor(getRect());
	EndScissor();

	bar.render(mouse);
}