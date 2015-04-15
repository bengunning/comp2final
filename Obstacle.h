// Class Obstacle
// An obstacle is an object that sheep will avoid if possible
// This is an abstract class, as specific obstacles will be created
// off of this class

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL/SDL.h"

class Obstacle {
public:
	Obstacle(int,int,int); //Constructor
	int getX();
	int getY();
	virtual SDL_Surface* getSurface() const = 0; //pure virtual function
protected:
	int x,y; //The coordinates of the obstacle
	int buffer; //The distance a sheep can get within this obstacle before it turns away.
		    //For example, a buffer with value 40 would make sheep turn away whenever
		    //they got within 40 pixels of this obstacle
};

#endif
