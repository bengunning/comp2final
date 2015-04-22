// Fence.cpp
// 4/23/15
//
#include "Fence.h"
#include "FenceLink.h"

Fence::Fence(int w, int h) { // fence constructor

	screenWidth = w;
	screenHeight = h;
}

void Fence::drawLine(int o, int p1, int p2, int c) { // o = 0, horizontal, else vertical

	if (!o) { // horizontal
		links.push(FenceLink temp(0, p1, c, screenWidth, screenHeight));
		int needed_links = ceil((double)(p2 - p1)/(double)(links.first().getLengthX())); // find the needed links for the this gap
		int gap = needed_links/(p2 - p1);
		for (int lc = 1; lc <= needed_links; lc++) links.push(FenceLink temp(0, p1 + lc*gap, c, screenWidth, screenHeight));
	} else {
		links.push(FenceLink temp(1, p1, c, screenWidth, screenHeight));
		int needed_links = ceil((double)(p2 - p1)/(double)(links.first().getLengthY())); // find the needed links for the this gap
		int gap = needed_links/(p2 - p1);
		for (int lc = 1; lc <= needed_links; lc++) links.push(FenceLink temp(0, c, p1 + lc*gap, screenWidth, screenHeight)); // minor changes to draw a vertical line
	}
	
}
