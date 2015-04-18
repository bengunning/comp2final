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
	Herd(); // default constructor
	Herd(int, int, int);	     		    // Randomized Constructor
	Herd(string);		    // Constructor with a filename
	void bear( Sheep& );	    // Add a sheep to the end of the group list
	void shear( Sheep& );	    // Remove a particular sheep from the group list
	double speed(); 		    // calculate the average speed of the herd
	vector<vector<int> > getAllLocations();   // Return locations of all the sheep in the group list
	vector<double> getAllDirections();           // Return directions of all the sheep in the group list
	int getXCenter();
	int getYCenter();
	void updateAll(int,int,vector<vector<int> >);	// Call updatePos() function for all sheep in the group list
	void handleAllEvents(SDL_Event*);
	void faceAll(int,int, int);           //Turn to face a coordinate, 3rd arg represents type of click
	void setCenter(int,int);         //adjusts the center of the herd to a new point
	void updateCenter(int,int);             //updates the center location
	int getClickType();	// return clickType
private:
	void init();		    // common code between constructors

	list<Sheep> group;	       // list of sheep
	int numSheep;		       // number of sheep in the list
	vector<vector<int> > locations;  // an n*2(xPos in 1st col and yPos in 2nd col) 2-D vector storing locations of all the sheep in the group list
	vector<double> directions;       // a nx1 vector storing the directions of all the sheep
	int xCenter, yCenter;    	       // The center of the herd all sheep are circled around
	double centerSpeed, centerDirection;   // The speed and direction the center of the herd is moving
	int clickType;	// differentiate different types of mouse click to have different reactions to a click
};
#endif
