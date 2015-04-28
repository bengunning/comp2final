// Fence.cpp
// 4/23/15
//
#include <cmath> // for ceil()
#include "Fence.h"
#include "FenceLink.h"

Fence::Fence(int w, int h) { // fence constructor

	screenWidth = w;
	screenHeight = h;
}

void Fence::drawLine(int o, int p1, int p2, int c) { // o = 0, horizontal, else vertical

	if (!o) { // horizontal
		FenceLink temph(0, p1, c, screenWidth, screenHeight);
		links.push_front(temph);
		int needed_links = ceil((double)(p2 - p1)/(double)(links.front().getLengthX())); // find the needed links for the this gap
		int gap = needed_links/(p2 - p1);
		FenceLink* hpoint;
		for (int lc = 1; lc <= needed_links; lc++) {
			hpoint = new FenceLink(0, p1 + lc*gap, c, screenWidth, screenHeight);
			links.push_front(*hpoint);
		}
	} else {
		FenceLink tempv(1, c, p1, screenWidth, screenHeight);
		links.push_front(tempv);
		int needed_links = ceil((double)(p2 - p1)/(double)(links.front().getLengthY())); // find the needed links for the this gap
		int gap = needed_links/(p2 - p1);
		
		FenceLink* vpoint;
		for (int lc = 1; lc <= needed_links; lc++) {
			vpoint = new FenceLink(0, c, p1 + lc*gap, screenWidth, screenHeight);
			links.push_front(*vpoint); // minor changes to draw a vertical line
		}
	}
	
}

void Fence::drawBox(int x, int y, int l, int w) {
	FenceLink temp0(3, x, y, screenWidth, screenHeight);
	links.push_front(temp0); // top left corner
	drawLine(1, y, y + l, x); // left line
	FenceLink temp1(4, x, y + l, screenWidth, screenHeight);
	links.push_front(temp1); // bottom left corner
	drawLine(0, x, x + w, y + l); // bottom line
	FenceLink temp2(5, x + w, y + l, screenWidth, screenHeight);
	links.push_front(temp2); // bottom right corner
	drawLine(1, y + l, y, x + w); // right line
	FenceLink temp3(2, x + w, y, screenWidth, screenHeight);
	links.push_front(temp3); // top right corner
	drawLine(0, x + w, x, y); // top line
}
