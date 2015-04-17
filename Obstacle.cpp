#include "Obstacle.h"
#include <fstream>
#include <vector>

Obstacle::Obstacle(int x, int y, int r, int buffer, int screenWidth, int screenHeight) :
	x(x), y(y), buffer(buffer), radius(r), total_points(0),
	graphics(screenWidth,screenHeight,32)
{
}

int Obstacle::getX() {
	return x; // position where this object is plotted
}

std::vector<int> Obstacle::getXV() { // x coordinates of point vector
	return x_v;
}

int Obstacle::getY() {
	return y;
}

std::vector<int> Obstacle::getYV() {
	return y_v;
}

int Obstacle::getR() {
	return radius;
}

int Obstacle::getBuffer() {
	return buffer;
}

void Obstacle::loadPoints(char *file) {
	// text file adds points relative to the center point
	std::ifstream coord; // file to input the coordinates
	coord.open(file);
	int p = 0; // hold number of points inserted
	while (coord >> x_v[p] >> y_v[p]) p++; // count points inserted to file
	total_points = p;
	coord.close();

}
