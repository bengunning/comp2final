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

class Obstacle {
public:
	Obstacle(int,int,int,int,int,int); //Constructor
	int getX();
	std::vector <int> getXV();
	int getY();
	std::vector <int> getYV();
	int getR();
	int getBuffer();
	virtual SDL_Surface* getSurface() const = 0; //pure virtual function
protected:
	void loadPoints(char *f); // helper function to load in the corresponding points
	std::vector <int> x_v, y_v; //The coordinate vectors of hazardous points, sheep avoid these
	int x, y; // the center coordinates
	int radius; // radius in pixels of the obstacle points
	int total_points; // number of points
	int buffer; //The distance a sheep can get within this obstacle before it turns away.
		    //For example, a buffer with value 40 would make sheep turn away whenever
		    //they got within 40 pixels of this obstacle
	Graphics graphics; //Graphics object to create sdl surfaces from
};

#endif
