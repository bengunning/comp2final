// A stone is a basic obstacle

#ifndef STONE_H
#define STONE_H

#include "Obstacle.h"
#include "SDL/SDL.h"
#include "Graphics.h"

class Stone : public Obstacle {
public:
	Stone(int,int,int); //Constructor	
	~Stone();
	SDL_Surface* getSurface() const; //returns an sdl surface to be drawn
private:
	SDL_Surface* image;
	Graphics graphics;
};

#endif
