/* A class that represents a single sheep.
 * Sheep objects will move based on their
 * environment and previous movements.
 */

#ifndef SHEEP_H
#define SHEEP_H

class Sheep {
public:
	Sheep(int=0,int=0,double=0,double=0); // Creates a sheep with a given position.
						 // By default, a sheep is placed at the center of the screen facing right
	int operator==(const Sheep&); // Checks to see if two sheep share identical coordinates
	int getX();
	int getY();
private:
	int xPos, yPos; // A sheeps position within a window.
	double speed; // holds the speed of a sheep. Must be a positive value, 0 if not in motion
	double direction; // A cartesian direction in radians. 0 is to the right of the screen, pi/2 is the top of the screen, etc.
};

#endif
