// Graphics class for creating an SDL Window

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL/SDL.h"
#include <string>

class Graphics {
public:
	Graphics(); //makes a 640 by 480 window
	Graphics(int,int,int); //takes in a width,height,and bpp
	~Graphics();
	void apply_surface(int,int,SDL_Surface*,SDL_Surface*);
	SDL_Surface *load_image(std::string);
	int getWidth(); //getter for screenWidth
	int getHeight(); //getter for screenHeight
	void fill_with_background(SDL_Surface*,int,int); //repeats a surface until it has filled a container vertically and horizontally
	SDL_Surface *getScreen(); //getter for screen
private:
	void setup();

	SDL_Surface* screen; //window to place other surfaces on
	int screenWidth;  //width of window
	int screenHeight; //height of window
	int bpp; //bits per pixel
};

#endif
