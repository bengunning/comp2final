// Implementation of class Sheep

#include <iostream> //for debugging
#include "Sheep.h"
#include "SDL/SDL.h"
#include <cmath> // for calculating direction radians from coordinates

Sheep::Sheep(int xPos, int yPos, double speed, double direction, SDL_Surface *pic):
	xPos(xPos), yPos(yPos), speed(speed), direction(direction), picture(pic)
	{
		while(direction < 0) direction += 2 * M_PI;
		while(direction > 2 * M_PI) direction -= 2 * M_PI;
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

double Sheep::getDirection() {
	return direction;
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

void Sheep::updatePos(int screenWidth, int screenHeight) {
	//Update the direction randomly
	double directionChange = (rand() % 49 - 25) * 2 * M_PI / 360.0; //random radian between -25 and 25 degrees
	direction += directionChange;
	while(direction < 0) direction += 2 * M_PI;
	while(direction > 2 * M_PI) direction -= 2 * M_PI;

	//Update the speed randomly
	int acceleration = rand() % 4 - 2; //random number between -2 and 1
	speed += acceleration / 2.0;
	if(speed < 0) speed = 0;

	//Update position
	xPos += speed*cos(direction);
	yPos += speed*sin(direction);

	//Make sure sheep stay within window bounds
	if(xPos < 0) xPos = 0;
	if(yPos < 0) yPos = 0;
	if(xPos > screenWidth) xPos = screenWidth;
	if(yPos > screenHeight) yPos = screenHeight;
}
