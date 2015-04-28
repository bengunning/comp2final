#include "Obstacle.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

Obstacle::Obstacle(int x, int y, int buffer, int screenWidth, int screenHeight) :
	x(x), y(y), buffer(buffer), graphics(screenWidth,screenHeight,32)
{
}

int Obstacle::getX() {
	return x; // position where this object is plotted
}

int Obstacle::getY() {
	return y;
}

/*vector< vector<int> > Obstacle::getHazards() {
	vector< vector<int> > temp(hazards); // copy hazards vector
	for (int i = 0; i < temp.size(); i++) {
		temp[i][0] += getX(); // add the x and y position to this vector
		temp[i][1] += getY(); 
	}
	return temp;	
}*/


int Obstacle::getBuffer() {
	return buffer;
}

/*void Obstacle::loadPoints(string file) {
	// text file adds points relative to the center point
	std::ifstream coord; // file to input the coordinates
	coord.open(file.c_str());
	int p = 0; // hold number of points inserted
	int p1, p2; // holds the numbers in the file
	while (coord >> p1 >> p2) {
		hazards.push_back(vector<int>(2));
		hazards[p].push_back(p1);
		hazards[p].push_back(p2);
		p++; // count points inserted to file
	}
	coord.close();
}*/
