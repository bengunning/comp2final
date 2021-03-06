/* The control class for the entire game.
 * holds all graphics and Herd objects
 */

#ifndef SHEEP_HERDER
#define SHEEP_HERDER

#include <string>
#include "SDL/SDL.h"
#include "Herd.h"
#include "SheepGraphics.h"
#include "Stone.h"
#include "Fence.h"
using namespace std;

class SheepHerder {
public:
	SheepHerder(int=0,int=1280,int=900); // constructor
	~SheepHerder(); // destructor
	void playGame();
private:
	//helper functions
	void init(int); // initializes the graphics and herd(s)
	void drawAllSurfaces(); // draws all surcaces to screen

	//private data members
	int width, height; // the current size of the screen
	int fontSize; // font size for the caption in the bottom right corner
	string caption; // caption to be placed in the bottom right corner
	SDL_Color captionColor; // color of the caption

	int framerate, frame, startTime; // framerate control
	bool cap; // determines if framerate should be used or not

	bool paused; //false if the program is actively running
	bool quit; // determines if the program should stop
	SDL_Event e; // a generic sdl event picked off the event queue

	SDL_Surface* background; // the background image
	SDL_Surface* centerX;    // the X to go in the center of the herd
	SDL_Surface* title;	 // the caption layer
	SDL_Surface* cursor;     // image to follow cursor around
	
	//A stone obstacle
	Stone stone;
	
	Fence sheep_pen; // a fence to contain sheep.

	Herd herd; // the herd of sheep
	SheepGraphics system; // the main graphics layer
	
	int clickMode;	// various modes for different functionalities of mouse click
	int moveType;	// different types of movement based on key pressed
};

#endif
