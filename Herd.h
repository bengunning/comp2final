/* A herd of sheep which contains a vector of sheep.
 * Tracks the positions of each sheep in the surrounding environment.
 */

#ifndef HERD_H
#define HERD_H

#include"Sheep.h"
#include "SDL/SDL.h"
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

class Herd {
   public:
      Herd();	     		    // Constructor
      Herd(string);		    // Constructor with a filename
      void bear( Sheep& );	    // Add a sheep to the end of the group list
      void shear( Sheep& );	    // Remove a particular sheep from the group list
      int xCenter();		    // Calculate and return the horizontal average position of all sheep in the group
      int yCenter();		    // Calculate and return the vertical average position of all sheep in the group
      double speed(); 		    // calculate the average speed of the herd
      vector<vector<int> > getAllLocations();   // Return locations of all the sheep in the group list
      vector<double> getAllDirections();           // Return directions of all the sheep in the group list
      void updateAll(int,int);			     // Call updatePos() function for all sheep in the group list
      void handleAllEvents(SDL_Event*);
      void faceAll(int,int);           //Turn to face a coordinate
   private:
      list<Sheep> group;	       // list of sheep
      int numSheep;		       // number of sheep in the list
      vector<vector<int> > locations;  // an n*2(xPos in 1st col and yPos in 2nd col) 2-D vector storing locations of all the sheep in the group list
      vector<double> directions;       // a nx1 vector storing the directions of all the sheep
};
#endif
