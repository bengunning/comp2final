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
	void updatePos(int,int,vector<vector<int> >,vector<vector<int> >); // update next position based on speed and direction.
	void updateDir(vector<vector<int> >,vector<vector<int> >); //turns towards a desired direction in radians
	void updateSpeed(double); // tend towards the new velocity,
	void face(int,int, int); //turns towards a given point; 3rd arg represents type of click 
private:
	//helper functions
	void makeAngleValid(double*); //makes sure a radian value falls between 0 and 2*pi. It adds or subtracts 2*pi if necessary to fit into the range

	//private variables
	int xPos, yPos; // A sheeps position within a window.
	double speed; // holds the speed of a sheep. Must be a positive value, 0 if not in motion
	double direction; // A cartesian direction in radians. 0 is to the right of the screen, pi/2 is the top of the screen, etc.
	double desiredDirection;
};

#endif
