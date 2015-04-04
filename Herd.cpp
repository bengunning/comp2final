/* Implementation of functions in Herd.h
 * Add brings a new sheep into the herd
 * Remove removes a given sheep from the herd
 */

#include "Herd.h"
#include "Sheep.h"
#include <fstream>
#include <string>
#include "SDL/SDL.h"
using namespace std;

// Constructor 
Herd::Herd()
{
   list<Sheep> group;
   numSheep = 0;
   vector<vector<int> > locations;
   vector<double> directions;
}

Herd::Herd(string fileName) {
	list<Sheep> group;
	numSheep = 0;
	vector<vector<int> > locations;
	vector<double> directions;

	int xPos, yPos;
	double speed, direction;
	ifstream file(fileName.c_str());
	while (file >> xPos >> yPos >> speed >> direction) {
		Sheep temp(xPos,yPos,speed,direction);
		bear(temp);
	}
	file.close();
}

// Add a sheep to the end of the group list
void Herd::bear( Sheep& sheep )
{
   group.push_back(sheep);
   numSheep ++;
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
      numSheep --;
      // remove the location of sheep from vector locations	 
      for(int i = 0; i < numSheep; i ++)
	 if(locations[i][0] == sheep.getX() && locations[i][1] == sheep.getY()) {
	    locations.erase(locations.begin() + i);
            directions.erase(directions.begin() + i);
         }
   }
}

// Calculate the return the horizontal average of all sheep in the group
int Herd::xCenter() {
	vector<vector<int> >::iterator it;
	int total = 0 , count = 0;
	for (it = locations.begin() ; it != locations.end() ; it++) {
		total += (*it)[0];
		count++;
	}
	return total / count;
}

// Calculate the return the vertical average of all sheep in the group
int Herd::yCenter() {
	vector<vector<int> >::iterator it;
	int total = 0 , count = 0;
	for (it = locations.begin() ; it != locations.end() ; it++) {
		total += (*it)[1];
		count++;
	}
	return total / count;
}

double Herd::speed() {
	list<Sheep>::iterator it;
	double sum = 0;
	int count = 0;
	for (it = group.begin(); it != group.end(); it++) {
		sum += it->getSpeed();
		count++;
	}
	return sum/count;
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

void Herd::handleAllEvents(SDL_Event* e) {
   for(list<Sheep>::iterator it = group.begin(); it != group.end(); it ++)
      it->handleEvents(e);
}

void Herd::faceAll(int x, int y) {
   for(list<Sheep>::iterator it = group.begin(); it != group.end(); it ++)
      it->face(x,y);
}
