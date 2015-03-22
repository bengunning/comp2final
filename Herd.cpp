/* Implementation of functions in Herd.h
 * Add brings a new sheep into the herd
 * Remove removes a given sheep from the herd
 */

#include"Herd.h"
using namespace std;

// Constructor 
Herd::Herd()
{
   list<Sheep> group;
   numSheep = 0;
   vector<vector<int> > locations;
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
	 if(locations[i][0] == sheep.getX() && locations[i][1] == sheep.getY())
	    locations.erase(locations.begin() + i);
   }
}

// Calculate the return the horizontal average of all sheep in the group
int Herd::xCenter() {
	list<Sheep>::iterator it;
	int total = 0 , count = 0;
	for (it = group.begin() ; it != group.end() ; it++) {
		total += (*it).getX();
		count++;
	}
	return total / count;
}

// Calculate the return the vertical average of all sheep in the group
int Herd::yCenter() {
	list<Sheep>::iterator it;
	int total = 0 , count = 0;
	for (it = group.begin() ; it != group.end() ; it++) {
		total += (*it).getY();
		count++;
	}
	return total / count;
}

// Return locations of all sheep in the group list
vector<vector<int> > Herd::getAllLocations()
{
   return locations;
}

// Call updatePos() function for all sheep in the group list
void Herd::updateAll()
{
   for(list<Sheep>::iterator it = group.begin(); it != group.end(); it ++)
      it->updatePos();
}

