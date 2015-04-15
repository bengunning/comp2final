#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, int buffer, int screenWidth, int screenHeight) :
	x(x), y(y), buffer(buffer),
	graphics(screenWidth,screenHeight,32) 
{
}

int Obstacle::getX() {
	return x;
}

int Obstacle::getY() {
	return y;
}
