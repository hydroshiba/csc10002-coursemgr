#ifndef OPTION_H
#define OPTION_H

#include "raylib.h"
#include "Button.h"
#include "Scissor.h"

class Option : public Button {
protected:
	float right_padding, left_padding = text_const::padding;
	
	void refreshText();
	void refresh();

public:
	float getLeftPad();
    float getRightPad();

	void render(const Vector2 &mouse) const;
};

#endif //OPTION_H