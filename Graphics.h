// Graphics class for creating an SDL Window

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL/SDL.h"
#include <string>

class Graphics {
public:
	Graphics();
	~Graphics();
	void setup();
	void apply_surface(int,int,SDL_Surface*,SDL_Surface*);
	SDL_Surface *load_image(std::string);

	SDL_Surface* screen; //window
private:
	int screenWidth;  //width of window
	int screenHeight; //height of window
	int bpp; //bits per pixel
};

#endif
