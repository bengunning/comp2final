#include "Stone.h"
#include <string>
#include <fstream>
#include "Graphics.h"

Stone::Stone(int x, int y, int buffer, int screenWidth, int screenHeight) :
	Obstacle::Obstacle(x,y,buffer,screenWidth,screenHeight),
	image(NULL)
{
	image = graphics.load_image("images/Objects/clay.png");
	//string pFile = "images/Objects/Stone.txt";
	//loadPoints(pFile);
}

SDL_Surface* Stone::getSurface() const {
	return image;
}

Stone::~Stone() {
	SDL_FreeSurface(image);
}
