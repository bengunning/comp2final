#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, int buffer) :
	x(x), y(y), buffer(buffer) 
{
}

int Obstacle::getX() {
	return x;
}

int Obstacle::getY() {
	return y;
}
