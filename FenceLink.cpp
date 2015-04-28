// FenceLink.cpp 
// 21 April 2015
#include "Obstacle.h"
#include <iostream> //for debugging
#include "FenceLink.h"
#include <vector>
#include "SDL/SDL.h"

FenceLink::FenceLink(int o, int x, int y, int screenWidth, int screenHeight) :
	Orient(o), Obstacle(x, y, 100, screenWidth, screenHeight) // might need to tweak the buffer of the actual obstacle
{
	switch(o) {
		case 0:
			if ((float)y/(float)screenHeight > 0.5)
				image = graphics.load_image("images/Fences/fence13.png"); // farther down the screen
			else
				image = graphics.load_image("images/Fences/fence7.png");
			break;
		case 1: 
			if ((float)x/(float)screenWidth > 2.0/3.0) // farther to the right
				image = graphics.load_image("images/Fences/fence11.png"); 
 			else if ((float)x/(float)screenWidth > 1.0/3.0) // middle-ish
				image = graphics.load_image("images/Fences/fence8.png");
			else
				image = graphics.load_image("images/Fences/fence6.png");
			break;
		case 2: // default to corners, predominantly just one point in the center, the other numbers in the encoding are important for pictures
			image = graphics.load_image("images/Fences/fence2.png"); // top right
			break;
		case 3:
			image = graphics.load_image("images/Fences/fence1.png"); // top left
			break;
		case 4:
			image = graphics.load_image("images/Fences/fence5.png"); // bottom left
			break;
		case 5:
			image = graphics.load_image("images/Fences/fence3.png"); // bottom right
			break;
		default:
			image = graphics.load_image("images/Fences/fence2.png"); // top right
	}
	if(image) {
		std::cout << "It is initialized" << std::endl;		
	} else {
		std::cout << "ya done goofed" << std::endl;
	}
}

FenceLink::~FenceLink() {
	SDL_FreeSurface(image);
}

int FenceLink::getOrient(void) const {
	return Orient;
}

long int FenceLink::getLengthX(void) const {

	//return hazards[1][0] - hazards[0][0] + 2*buffer; // distance between two points plus the outward reaches of the buffer
	return 2*buffer;

}

long int FenceLink::getLengthY(void) const {
	
	return 2*buffer;
	//return hazards[1][1] - hazards[0][1] + 2*buffer; 

}

SDL_Surface* FenceLink::getSurface(void) const {
	return image;
}
