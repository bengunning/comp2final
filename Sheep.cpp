// Implementation of class Sheep

#include "Sheep.h"

Sheep::Sheep(int xPos, int yPos, double speed, double direction):
	xPos(xPos), yPos(yPos), speed(speed), direction(direction)
	{}

int Sheep::operator==(const Sheep& another) {
	if (xPos == another.xPos && yPos == another.yPos) {
		return 1;
	} else {
		return 0;
	}
}
// This definition of equality makes the assumption that different sheep cannot share the exact same horizontal and vertical coordinates
