// FenceLink.cpp 
// 21 April 2015
#include "Obstacle.h"
#include "FenceLink.h"
#include <vector>
#include "SDL/SDL.h"

FenceLink::FenceLink(int o, int x, int y, int screenWidth, int screenHeight) :
	Orient(o), Obstacle(x, y, 100, screenWidth, screenHeight) // might need to tweak the buffer of the actual obstacle
{
	switch(o) {
		case 0:
			loadPoints("HorizFence.txt"); // load the text files with the specific layout of the fence hazards
			image = graphics.load_image("images/Objects/HorizFence.png");
		case 1: 
			loadPoints("VertiFence.txt");
			image = graphics.load_image("images/Objects/VertiFence.png"); // STILL NEED TO ADD THESE FILES
		default: // default to corners, predominantly just one point in the center, the other numbers in the encoding are important for pictures
			loadPoints("CornerFence.txt");
			image = graphics.load_image("images/Objects/CornerFence.png");
	}
}

FenceLink::~FenceLink() {
	SDL_FreeSurface(image);
}

FenceLink::getOrient(void) const {
	return Orient;
}

FenceLink::getLengthX(void) const {

	return hazards[1][0] - hazards[0][0] + 2*buffer; // distance between two points plus the outward reaches of the buffer

}

FenceLink::getLengthY(void) const {
	
	return hazards[1][1] - hazards[0][1] + 2*buffer; 

}

SDL_Surface* FenceLink::getSurface(void) const {
	return image;
}
