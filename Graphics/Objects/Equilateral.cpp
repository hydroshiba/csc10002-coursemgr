#include "Equilateral.h"

Equilateral::Equilateral(Vector2 center, float length, float angle, Color color) :
	center(center),
	length(length),
	angle(angle),
	color(color) {}

void Equilateral::render() {
	float dist = rootInv3 * length;
	
	float radA = DEG2RAD * angle;
	float radB = DEG2RAD * (angle + 120);
	float radC = DEG2RAD * (angle + 240);

	Vector2 A = {dist * cos(radA) + center.x, dist * sin(radA) + center.y};
	Vector2 B = {dist * cos(radB) + center.x, dist * sin(radB) + center.y};
	Vector2 C = {dist * cos(radC) + center.x, dist * sin(radC) + center.y};

	DrawTriangle(A, C, B, color);
}