#include "InputBox.h"

void InputBox::refreshText() {
    textSize = 0;

    do {
        ++textSize;
		content.font_size = textSize + 1;
		defaultText.font_size = textSize + 1;
    } while(content.size().y * 3 < size.y * 2);
    
    textPos.x = fill_bound.x + text_const::padding;
    textPos.y = fill_bound.y + (fill_bound.height - (content.size().y)) / 2;

	if(textPos.x + content.size().x > fill_bound.x + fill_bound.width - text_const::padding)
		textPos.x = fill_bound.x + fill_bound.width - text_const::padding - content.size().x;
}

void InputBox::refresh() {
    border_bound = Rectangle{pos.x, pos.y, size.x, size.y};
    
    fill_bound.x = pos.x + box_const::thickness;
    fill_bound.y = pos.y + box_const::thickness;
    
    fill_bound.width = size.x - 2 * box_const::thickness;
    fill_bound.height = size.y - 2 * box_const::thickness;

    refreshText();
}

InputBox::InputBox() :
	pos({0, 0}),
    size({box_const::width, box_const::height}),
    defaultText("Input text here"),
	content(""),
    fill_color(box_const::fill_color),
    hover_color(button_const::hover_color),
    press_color(button_const::press_color),
    border_color(box_const::border_color) { refresh(); }

InputBox::InputBox(float x, float y, float width, float height, std::string text, Color fill, Color hover, Color press, Color border) :
    pos({x, y}),
    size({width, height}),
    defaultText(text),
	content(""),
    fill_color(fill),
    border_color(border),
    hover_color(hover),
    press_color(press) { refresh(); }

InputBox::InputBox(Vector2 pos, Vector2 size, std::string text, Color fill, Color hover, Color press, Color border) :
    pos(pos),
    size(size),
    defaultText(text),
	content(""),
    fill_color(fill),
    border_color(border),
    hover_color(hover),
    press_color(press) { refresh(); }

void InputBox::process(const Vector2 &mouse) {
	if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !clicked(mouse)) selected = false;
	if(clicked(mouse)) selected = true;

	if(selected) {
		int key = GetCharPressed();

		while((key >= 32) && (key <= 125)) {
			content.text.push_back(char(key));
			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE)) {
			if(!content.text.empty()) content.text.pop_back();
		}
	}

	refreshText();
	++frameCount;
}

void InputBox::render(const Vector2 &mouse) const {
	Color text_color;

	if(selected || pressed(mouse)) text_color = press_color;
	else if(hovering(mouse)) text_color = hover_color;
	else text_color = border_color;

	DrawRectangleRounded(border_bound, box_const::roundness, box_const::segments, fill_color);
    DrawRectangleRoundedLines(fill_bound, box_const::roundness, box_const::segments, box_const::thickness, text_color);

	std::string cursor;
	if((frameCount * 2 / app_const::fps) % 2 && selected) cursor = "|";
	else cursor = "";

	BeginScissorMode(fill_bound.x + text_const::padding, fill_bound.y, fill_bound.width - text_const::padding, fill_bound.height);
    
	if(!content.text.empty()) {
		if(!selected && !pressed(mouse) && !hovering(mouse)) text_color = text_const::color;
		DrawTextEx(content.font, (content.text + cursor).c_str(), textPos, content.font_size, content.space, text_color);
	}
	else
		DrawTextEx(defaultText.font, defaultText.text.c_str(), textPos, content.font_size, defaultText.space, text_color);

	EndScissorMode(); 
}

void InputBox::setX(float x) {
    pos.x = x;
    refresh();
}

void InputBox::setY(float y) {
    pos.y = y;
    refresh();
}

void InputBox::setWidth(float width) {
    size.x = width;
    refresh();
}

void InputBox::setHeight(float height) {
    size.y = height;
    refresh();
}

void InputBox::setPos(Vector2 pos) {
    this->pos = pos;
    refresh();
}

void InputBox::setSize(Vector2 size) {
    this->size = size;
    refresh();
}

Vector2 InputBox::getPos() {
    return pos;
}

Vector2 InputBox::getSize() {
    return size;
}

void InputBox::centerX() {
    pos.x = (GetScreenWidth() - size.x) / 2.0f;
    refresh();
}

void InputBox::centerY() {
    pos.y = (GetScreenHeight() - size.y) / 2.0f;
    refresh();
}

bool InputBox::clicked(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, border_bound)) return false;
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

bool InputBox::pressed(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, border_bound)) return false;
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

bool InputBox::hovering(const Vector2 &mouse) const {
    if(!CheckCollisionPointRec(mouse, border_bound)) return false;
    return IsMouseButtonUp(MOUSE_BUTTON_LEFT);
}