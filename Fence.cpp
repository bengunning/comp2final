// Fence.cpp
// 4/23/15
//
#include <cmath> // for ceil()
#include "Fence.h"
#include "FenceLink.h"
#include <list>
#include <iostream>

Fence::Fence(int w, int h)
//:links(0, FenceLink(0,0,0,w,h))  { // fence constructor
{

	screenWidth = w;
	screenHeight = h;
}

Fence::~Fence() {
	for (std::list<FenceLink *>::iterator lit = links.begin(); lit != links.end(); lit++) {
		delete *lit;
	}
}

void Fence::drawLine(int o, int p1, int p2, int c) { // o = 0, horizontal, else vertical // from p1 to p2, c is center point, on axis perpindicular to the fence

	if (!o) { // horizontal	
		std::cout << "Pushing first link." << std::endl;
		links.push_front(new FenceLink(0, p1, c, screenWidth, screenHeight));	
		std::cout << "Pushed first link." << std::endl;
		int needed_links = ceil((double)(p2 - p1)/(double)(links.front()->getLengthX())); // find the needed links for the this gap
		int gap = (p2 - p1)/needed_links; // distance over the fence links we will place
		//FenceLink* hpoint;
		for (int lc = 1; lc <= needed_links; lc++) {
			//hpoint = new FenceLink(0, p1 + lc*gap, c, screenWidth, screenHeight);
			std::cout << "Pushing new link." << std::endl;
			links.push_front(new FenceLink(0, p1 + lc*gap, c, screenWidth, screenHeight));
		}
	} else {
		links.push_front(new FenceLink(1, c, p1, screenWidth, screenHeight));
		int needed_links = ceil((double)(p2 - p1)/(double)(links.front()->getLengthY())); // find the needed links for the this gap
		int gap = (p2 - p1)/needed_links;
		
	//	FenceLink* vpoint;
		for (int lc = 1; lc <= needed_links; lc++) {
			//vpoint = new FenceLink(0, c, p1 + lc*gap, screenWidth, screenHeight); // i am certain that all this is a problem
			std::cout << "Pushing new link." << std::endl;
			links.push_front(new FenceLink(1, c, p1 + lc*gap, screenWidth, screenHeight)); // minor changes to draw a vertical line
		}
		
	}
	
}

void Fence::drawBox(int x, int y, int l, int w) {
	links.push_front(new FenceLink(3, x, y, screenWidth, screenHeight)); // top left corner
	drawLine(1, y + links.front()->getBuffer(), y + l - links.front()->getBuffer(), x - links.front()->getBuffer()/2); // left line
	links.push_front(new FenceLink(4, x, y + l, screenWidth, screenHeight)); // bottom left corner
	drawLine(0, x + links.front()->getBuffer(), x + w - links.front()->getBuffer(), y + l); //- links.front()->getBuffer()/2); // bottom line
	links.push_front(new FenceLink(5, x + w, y + l, screenWidth, screenHeight)); // bottom right corner
	drawLine(1, y + links.front()->getBuffer(), y + l - links.front()->getBuffer(), x + w + links.front()->getBuffer()/2); // right line
	links.push_front(new FenceLink(2, x + w, y, screenWidth, screenHeight)); // top right corner
	drawLine(0, x + links.front()->getBuffer(), x + w - links.front()->getBuffer(), y - links.front()->getBuffer()/2); // top line
}

std::list<FenceLink *> &Fence::getLinks(void) {
	return links;
}
