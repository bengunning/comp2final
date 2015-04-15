#include "Stone.h"
#include <string>
#include "Graphics.h"

Stone::Stone(int x, int y, int buffer) :
	Obstacle::Obstacle(x,y,buffer),
	image(NULL)
{
	image = graphics.load_image("images/Stone.png");
}

SDL_Surface* Stone::getSurface() const {
	return image;
}

Stone::~Stone() {
	SDL_FreeSurface(image);
}
