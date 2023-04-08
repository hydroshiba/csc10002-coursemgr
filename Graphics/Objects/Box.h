#ifndef BOX_H
#define BOX_H

#include "raylib.h"
#include "Button.h"

class Box : public Button {
protected:
	float right_padding, left_padding = text_const::padding;
	
	void refreshText();
	void refresh();

public:
	void render(const Vector2 &mouse) const;
};

#endif