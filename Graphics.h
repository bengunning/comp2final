// Graphics class for creating an SDL Window

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL/SDL.h"

class Graphics {
public:
	Graphics();
	~Graphics();
	void setup();
	SDL_Surface* screen; //window
private:
	int screenWidth;  //width of window
	int screenHeight; //height of window
	int bpp; //bits per pixel
};

#endif
