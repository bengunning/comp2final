/* Implementation of functions in Herd.h
 * Add brings a new sheep into the herd
 * Remove removes a given sheep from the herd
 */

#include "Herd.h"
#include "Sheep.h"
#include <fstream>
#include <string>
#include <cmath>
#include "SDL/SDL.h"
using namespace std;

// Constructor 
Herd::Herd()
{
	list<Sheep> group;
	numSheep = 0;
	vector<vector<int> > locations;
	vector<double> directions;
	setCenter(300,300);
	centerSpeed = 5;
	centerDirection = 0;
}

Herd::Herd(string fileName) {
	list<Sheep> group;
	numSheep = 0;
	vector<vector<int> > locations;
	vector<double> directions;
	setCenter(300,300);
	centerSpeed = 5;
	centerDirection = 0;

	//Read in sheep information from a file
	int xPos, yPos; //temp variables 
	double speed, direction; //temp variables
	ifstream file(fileName.c_str());
	while (file >> xPos >> yPos >> speed >> direction) {
		Sheep temp(xPos,yPos,speed,direction);
		bear(temp);
	}
	file.close();
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

// Remove a particular sheep from the group list
void Herd::shear( Sheep& sheep ) {
   if(numSheep < 1) 
      return;

   list<Sheep>::iterator it = find( group.begin() , group.end() , sheep );
   if (it != group.end()) {
      group.erase(it);
      numSheep--;
      // remove the location of sheep from vector locations	 
      for(int i = 0; i < numSheep; i ++)
	 if(locations[i][0] == sheep.getX() && locations[i][1] == sheep.getY()) {
	    locations.erase(locations.begin() + i);
            directions.erase(directions.begin() + i);
         }
   }
}

// finds the average speed of herd
double Herd::speed() {
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
void Herd::updateAll(int screenWidth, int screenHeight)
{
   int i = 0;
   for(list<Sheep>::iterator it = group.begin(); it != group.end(); it ++) {
      it->updatePos(screenWidth, screenHeight, locations);
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
void Herd::faceAll(int x, int y) {
   for(list<Sheep>::iterator it = group.begin(); it != group.end(); it ++)
      it->face(x,y);
}

int Herd::getXCenter() {
	return xCenter;
}

int Herd::getYCenter() {
	return yCenter;
}
