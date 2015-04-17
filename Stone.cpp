#include "Stone.h"
#include <string>
#include <fstream>
#include "Graphics.h"

Stone::Stone(int x, int y, int r, int buffer, int screenWidth, int screenHeight) :
	Obstacle::Obstacle(x,y,r,buffer,screenWidth,screenHeight),
	image(NULL)
{
	image = graphics.load_image("images/Objects/Stone.png");
	//loadPoints("images/Objects/Stone.txt");
}

SDL_Surface* Stone::getSurface() const {
	return image;
}

Stone::~Stone() {
	SDL_FreeSurface(image);
}
