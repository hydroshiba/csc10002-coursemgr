#include "Scissor.h"

Stack<Rectangle> scissorStack;

void StartScissor(Rectangle rect) {
	if(!scissorStack.empty()) EndScissorMode();
	BeginScissorMode(rect.x, rect.y, rect.width, rect.height);
	scissorStack.push(rect);
}

void StartScissor(Vector2 pos, Vector2 size) {
	Rectangle newRect;
	newRect.height = size.y;
	newRect.width = size.x;

	newRect.x = pos.x;
	newRect.y = pos.y;

	StartScissor(newRect);
}

void StartScissor(float x, float y, float width, float height) {
	StartScissor({x, y}, {width, height});
}

void EndScissor() {
	if(!scissorStack.empty()) scissorStack.pop();
	EndScissorMode();
	
	if(!scissorStack.empty()) {
		Rectangle rect = scissorStack.top();
		BeginScissorMode(rect.x, rect.y, rect.width, rect.height);
	}
}