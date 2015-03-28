/* A class that represents a single sheep.
 * Sheep objects will move based on their
 * environment and previous movements.
 */

#ifndef SHEEP_H
#define SHEEP_H
#include "SDL/SDL.h"
#include <vector>
using namespace std;

class Sheep {
public:
	Sheep(int=0,int=0,double=0,double=0); // Creates a sheep with a given position.
						 // By default, a sheep is placed at the center of the screen facing right
	// probably a felt or hand-knit image, or an image file with 72 different rotations, it depends on how we want to rotate
	int operator==(const Sheep&); // Checks to see if two sheep share identical coordinates
	int getX(); // X and Y coordinates will give apply_surface the proper offset. 
	int getY();
	double getDirection();
	double getSpeed(); // needed to calculate average speeds
	void handleEvents(SDL_Event*); // handle mouse clicks, updating velocity
	void updatePos(int,int, vector<vector<int> >); // update next position based on speed and direction.
	void updateDir(vector<vector<int> >); //turns towards a direction in radians
	void updateSpeed(double s); // tend towards the new velocity,
private:
	int xPos, yPos; // A sheeps position within a window.
	double speed; // holds the speed of a sheep. Must be a positive value, 0 if not in motion
	double direction; // A cartesian direction in radians. 0 is to the right of the screen, pi/2 is the top of the screen, etc.
	double desiredDirection;
};

#endif
