// Class Obstacle
// An obstacle is an object that sheep will avoid if possible
// This is an abstract class, as specific obstacles will be created
// off of this class

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL/SDL.h"
#include "Graphics.h"
#include <vector>
#include <string>
using namespace std;

class Obstacle {
public:
	Obstacle(int,int,int,int,int); //Constructor
	int getX();
	int getY();
//	vector< vector<int> > getHazards();
	int getBuffer();
	virtual SDL_Surface* getSurface() const = 0; //pure virtual function
protected:
//	void loadPoints(string f); // helper function to load in the corresponding points
//	vector < vector<int> > hazards; //The coordinate vectors of hazardous points, sheep avoid these
	int x, y; // the center coordinates
	int buffer; //The distance a sheep can get within this obstacle before it turns away.
		    //For example, a buffer with value 40 would make sheep turn away whenever
		    //they got within 40 pixels of this obstacle
	Graphics graphics; //Graphics object to create sdl surfaces from
};

#endif
