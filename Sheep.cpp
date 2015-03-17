// Implementation of class Sheep

#include "Sheep.h"
#include "SDL/SDL.h"
#include <cmath> // for calculating direction radians from coordinates

Sheep::Sheep(int xPos, int yPos, double speed, double direction, SDL_Surface *pic):
	xPos(xPos), yPos(yPos), speed(speed), direction(direction), picture(pic)
	{}

Sheep::~Sheep() {
	if (picture) SDL_FreeSurface(picture); // free the sheep's individual surface pointer, don't quit
}
SDL_Surface *Sheep::getPicture() {
	return picture;
}
int Sheep::operator==(const Sheep& another) {
	return (xPos == another.xPos && yPos == another.yPos); 
}
// This definition of equality makes the assumption that different sheep cannot share the exact same horizontal and vertical coordinates

int Sheep::getX() {
	return xPos;
}

int Sheep::getY() {
	return yPos;
}

void Sheep::handleEvents(SDL_Event* e) {

	if (e->type == SDL_MOUSEBUTTONDOWN) { // user has clicked
		int xMouse, yMouse;
		SDL_GetMouseState(&xMouse, &yMouse); // set x y mouse positions
		direction = atan2(-(yPos - yMouse), (xPos - xMouse)); // negate y to accomodate for inverted coordinates. does pi/2 need to be
		// the top of the screen
		speed += 100/sqrt(pow(xPos - xMouse, 2) + pow(yPos - yMouse, 2)); // increase speed by arbitary value over the distance in pixels
	}
	
}
