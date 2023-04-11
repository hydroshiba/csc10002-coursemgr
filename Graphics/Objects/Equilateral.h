#ifndef EQUILATERAL_H
#define EQUILATERAL_H

#include <cmath>
#include "raylib.h"

class Equilateral {
private:
	const float rootInv3 = 0.577350269189;

public:
	Vector2 center;
	float length, angle;
	Color color;

	Equilateral(Vector2 center = {0, 0}, float length = 1, float angle = 0, Color color = BLACK);
	void render();
};

#endif