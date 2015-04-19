/* Implementation of functions in Herd.h
 * Add brings a new sheep into the herd
 * Remove removes a given sheep from the herd
 */

#include "Herd.h"
#include "Sheep.h"
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "SDL/SDL.h"
using namespace std;

// Constructor 
Herd::Herd() {
	init();
}
//randomized constructor
Herd::Herd(int x, int w, int h)
{
	srand(time(NULL));
	init();
	if (w > 0 && h > 0) {
	for (int i = 0; i < x; i++) { //count number of 
		Sheep temp(rand()%(w - w/4) + w/8, (rand()%(h - h/4)) + h/8, 0, 0);//*(8/9) + w*(17/18)), rand()%(h*(8/9) + h*(17/18)), 0, 0); // speed defaults at 0
		// sheep only fill in 8/9 of the screen
		bear(temp);
	}
	} 
}

Herd::Herd(string fileName) {
	init();
	
	//Read in sheep information from a file
	int xPos, yPos; //temp variables 
	double speed, direction; //temp variables
	ifstream file(fileName.c_str());
	bool endOfFileReached = false;
	while(!endOfFileReached) {
		if (file >> xPos >> yPos >> speed >> direction) {
			Sheep temp(xPos,yPos,speed,direction);
			bear(temp);
		} else if (file.eof()) {
			endOfFileReached = true;
		} else {
			// the file just read a line that could not be properly parsed
			// We will assume all such lines are comments and not create
			// any sheep for them.
			file.clear(); // ignore the error
			file.ignore(10000, '\n'); //skip to the next line
		}
	}
	file.close();
}

void Herd::init() {
	numSheep = 0;
	setCenter(300,300);
	centerSpeed = 0;
	centerDirection = 0;
}

void Herd::setCenter(int x, int y) {
	xCenter = x;
	yCenter = y;
}

void Herd::updateCenter(int width, int height) {
	xCenter += centerSpeed * cos(centerDirection);
	yCenter += centerSpeed * sin(centerDirection);
	if(xCenter < 0) xCenter = 0;
	if(xCenter > width) xCenter = width;
	if(yCenter < 0) yCenter = 0;
	if(yCenter > height) yCenter = height;
}

// Add a sheep to the end of the group list
void Herd::bear( Sheep& sheep )
{
   group.push_back(sheep);
   numSheep++;
   // store the location of sheep into vector locations   
   vector<int> temp; // temp vector to store location of sheep
   temp.push_back(sheep.getX());
   temp.push_back(sheep.getY());
   locations.push_back(temp);
   directions.push_back(0);
}

// Remove sheep at a particular position from the group list
void Herd::shear(int xPos, int yPos) {
	if(numSheep < 1)	// quit if there's no sheep in the list 
		return;

	for(list<Sheep>::iterator it = group.begin(); it != group.end(); ++ it){
		// if the sheep is close enough (within 10 pixels) to the specified position, remove it
		if(abs(xPos - it->getX()) < 10 && abs(yPos - it->getY()) < 10){
			for(int i = 0; i < numSheep; i ++)
				if(locations[i][0] == it->getX() && locations[i][1] == it->getY()) {
					// remove corresponding location and direction of the removed sheep
					locations.erase(locations.begin() + i);
					directions.erase(directions.begin() + i);
					-- i;
			}
			group.erase(it);
			-- it;
			numSheep --;
		}
	}
}

// finds the average speed of herd
double Herd::speed() {
	if(group.size() == 0)
		return 0;
	list<Sheep>::iterator it;
	double sum = 0;
	for (it = group.begin(); it != group.end(); it++) {
		sum += it->getSpeed();
	}
	return sum / group.size();
}

// Return locations of all sheep in the group list
vector<vector<int> > Herd::getAllLocations()
{
   return locations;
}

vector<double> Herd::getAllDirections() {
   return directions;
}

// Call updatePos() function for all sheep in the group list
void Herd::updateAll(int screenWidth, int screenHeight, vector<vector<int> > obstacles)
{
	int i = 0;
	for(list<Sheep>::iterator it = group.begin(); it != group.end(); it ++) {
		it->updatePos(screenWidth, screenHeight, locations, obstacles);
		it->updateSpeed(speed());
		locations[i][0] = it->getX();
		locations[i][1] = it->getY();
		// update locations vector along with each sheep. using random access
		directions[i] = it->getDirection();
		i++;
	}
}

// Handles a mouse click
void Herd::handleAllEvents(SDL_Event* e) {
   SDL_GetMouseState(&xCenter,&yCenter); //make the click's spot the new center
   // Have each sheep handle the mouse click
   for(list<Sheep>::iterator it = group.begin(); it != group.end(); it ++)
      it->handleEvents(e);
}

// Make all sheep face a certain point
void Herd::faceAll(int x, int y, int moveType)
{
   for(list<Sheep>::iterator it = group.begin(); it != group.end(); it ++)
      it->face(x,y, moveType);
}

int Herd::getXCenter() {
	return xCenter;
}

int Herd::getYCenter() {
	return yCenter;
}

int Herd::getNumSheep()
{
	return numSheep;
}
