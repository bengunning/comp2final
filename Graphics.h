// Graphics class for creating an SDL Window

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

class Graphics {
public:
	Graphics(int = 640,int = 480,int = 32); // construct a window with default values
	~Graphics();
	void apply_surface(int,int,SDL_Surface*,SDL_Surface*);
	SDL_Surface *load_image(std::string);
	int getWidth(); //getter for screenWidth
	int getHeight(); //getter for screenHeight
	int *getXPos(); //getter for xMousePos
	int *getYPos(); //getter for yMousePos
	void resizeScreen(int,int);
	void toggleCursorVisibility(); //changes if the cursor is visible or not
	void fill_with_background(SDL_Surface*,int,int); //repeats a surface until it has filled a container vertically and horizontally
	SDL_Surface *getScreen(); //getter for screen
	SDL_Surface *load_text(std::string,std::string,SDL_Color,int);
private:
	SDL_Surface* screen; //window to place other surfaces on
	int screenWidth;  //width of window
	int screenHeight; //height of window
	int * xMousePos; //x position of mouse
	int * yMousePos; //y position of mouse
	int bpp; //bits per pixel
	bool showCursor; //cursor is shown iff shownCursor == true
};

#endif
