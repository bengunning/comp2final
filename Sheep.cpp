// Implementation of class Sheep

#include <iostream> //for debugging
#include <climits>
#include "Sheep.h"
#include "SDL/SDL.h"
#include <cmath> // for calculating direction radians from coordinates
using namespace std;

Sheep::Sheep(int xPos, int yPos, double speed, double direction):
	xPos(xPos), 
	yPos(yPos), 
	speed(speed), 
	direction(direction) 
	{
		makeAngleValid(&direction);
		desiredDirection = direction;
	}

void Sheep::makeAngleValid(double * theta) {
	while(*theta < 0) *theta += 2 * M_PI;
	while(*theta > 2 * M_PI) *theta -= 2 * M_PI;
}

// This definition of equality makes the assumption that different sheep cannot share the exact same horizontal and vertical coordinates
int Sheep::operator==(const Sheep& another) {
	return (xPos == another.xPos && yPos == another.yPos); 
}

int Sheep::getX() {
	return xPos;
}

int Sheep::getY() {
	return yPos;
}

double Sheep::getDirection() {
	return direction;
}

double Sheep::getSpeed() {
	return speed;
}

// handle a mouse click
void Sheep::handleEvents(SDL_Event* e) {

	if (e->type == SDL_MOUSEBUTTONDOWN) { // user has clicked
		int xMouse, yMouse;
		SDL_GetMouseState(&xMouse, &yMouse); // set x y mouse positions
		face(xMouse,yMouse);
		speed = 10 + 55/sqrt(pow(xPos - xMouse, 2) + pow(yPos - yMouse, 2)); // increase speed by arbitary value over the distance in pixels
		//closer the click, the more the speed increases, 50 minimum change
	}
	
}

void Sheep::face(int x, int y) {
	desiredDirection =  M_PI + atan2((yPos - y), (xPos - x));
}

void Sheep::updatePos(int screenWidth, int screenHeight, vector<vector<int> > locations, vector<vector<int> > obstacles) {
	// Make sure speed is not negative 
	if(speed < 0) speed = 0;

	//Update the direction but only if the sheep is moving
	if(speed>0) {
		updateDir(locations,obstacles);
	}

	//Update position
	xPos += speed*cos(direction);
	yPos += speed*sin(direction);

	//Make sure sheep stay within window bounds
	if(xPos < 0) xPos = 0;
	if(yPos < 0) yPos = 0;
	if(xPos > screenWidth) xPos = screenWidth;
	if(yPos > screenHeight) yPos = screenHeight;
}

void Sheep::updateDir(vector<vector<int> > locations, vector<vector<int> > obstacles) {
	//Check if desiredDirection needs to be updated because of other sheep's close proximity
	int closestSheep = -1; //index of the closest sheep. stays -1 if no sheep is within 60 pixels
	int minDistance = INT_MAX; // holds the smallest distance found between this sheep and another up to this point
	double currentDistance;  //holds the distance to the sheep currently being looked at
	for(int i=0; i < locations.size(); i++) {
		if(xPos == locations[i][0] && yPos == locations[i][1]) continue; //Skip, as this is the same sheep as is being looked at in locations
		currentDistance = sqrt(pow(xPos-locations[i][0],2) + pow(yPos-locations[i][1],2));
		if(currentDistance < 60) { //if the distance between this sheep and another sheep is less than 60 pixels
			if(currentDistance < minDistance) {
				minDistance = currentDistance;
				closestSheep = i;
			}
		}
	}
	if(closestSheep != -1) {
		//Make desired direction away from this nearby sheep
		desiredDirection =  atan2((yPos - locations[closestSheep][1]), (xPos - locations[closestSheep][0]));
	}

	//Check if within the radius of any obstacles
	double distance;
	for(int i = 0; i < obstacles.size(); i++) {
		distance = sqrt(pow(xPos-obstacles[i][0],2) + pow(yPos-obstacles[i][1],2));
		if(distance < obstacles[i][2]) {
			//Within the stated distance of an obstacle, turn away from it
			desiredDirection = atan2(yPos - obstacles[i][1], xPos - obstacles[i][0]);
		}
	}

	//make sure desired Direction is between 0 and 2pi
	makeAngleValid(&desiredDirection);

	//Determine if turning is necessary
	double difference = desiredDirection - direction;
	if(difference < M_PI / 8.0 && difference > -1 * M_PI / 8.0) {
		//No need to turn
		direction = desiredDirection;
	} else if((difference < 0 && difference > -1 * M_PI) || difference > M_PI) {
		//turn left
		direction -= M_PI / 8.0;
		makeAngleValid(&direction);
	} else{
		//turn right
		direction += M_PI / 8.0;
		makeAngleValid(&direction);
	}	
}

void Sheep::updateSpeed(double s) {
	
	double weight = 3/4; //weight given to interpolation, changes more quickly if closer to one.
	
	speed += (s - speed)*weight;

}
