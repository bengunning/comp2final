// Implementation of class Sheep

#include "Sheep.h"
#include "SDL/SDL.h"
#include <cmath> // for calculating direction radians from coordinates

Sheep::Sheep(int xPos, int yPos, double speed, double direction, SDL_Surface *pic):
	xPos(xPos), yPos(yPos), speed(speed), direction(direction), picture(pic)
	{}

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
		direction = atan2((yPos - yMouse), (xPos - xMouse)); // capture direction based on diference in coordinates
		// atan2 takes account of signs and returns proper radians among 2pi
		speed = 10 + 55/sqrt(pow(xPos - xMouse, 2) + pow(yPos - yMouse, 2)); // increase speed by arbitary value over the distance in pixels
		//closer the click, the more the speed increases, 50 minimum change
	}
	
}

void Sheep::updatePos() {
	// way to access size of screen?
	xPos += speed*cos(direction);
	yPos += speed*sin(direction);
	
	// velocity gradually changing
	if (speed > 0) speed -= 1.25;
	else speed = 0;
	//else if (speed < 0) speed += 2;	
}
