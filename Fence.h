// A sort of container class for FenceLinks. Draws a line or box
// 19 April 2015

#include "Obstacle.h"
#include <list>
#include "SDL/SDL.h"
#include "FenceLink"

class Fence { // 
public:
	void drawLine(int p1, int p2, int o); // places fences along a horizontal or vertical axis from p1 to p2
	void drawBox(int x, int y, int l, int w); // draws a rectangle of dimensions l w from points x y
private:
	long int getLength(void); // length spanned by two points in the fence, helper function
	std::list<FenceLink> links; // holds all the fencelinks added
}
