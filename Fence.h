// A sort of container class for FenceLinks. Draws a line or box
// 19 April 2015

#include "Obstacle.h"
#include <list>
#include "SDL/SDL.h"
#include "FenceLink.h"
#ifndef FENCE_H
#define FENCE_H
class Fence { // 
public:
	Fence(int screenWidth, int screenHeight); // Fence constructor
	// should not need destructor since all the surfaces are in Fence Links
	void drawLine(int o, int p1, int p2, int c); // places fences along a horizontal or vertical axis from p1 to p2, all on second coordinate c
	void drawBox(int x, int y, int l, int w); // draws a rectangle of dimensions l w from points x y
private:
	std::list<FenceLink> links; // holds all the fencelinks added
	int screenWidth;
	int screenHeight;
};
#endif
