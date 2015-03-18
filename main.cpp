// Driver program for sheepHerder

#include "Sheep.h"
#include "Graphics.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
	int width = 1280;
	int height = 900;
	const int FONT_SIZE = 120;
	const string CAPTION = "Sheep Herder";
	if (argc == 3) { //if two arguments given
		width = atoi(args[1]);
		height = atoi(args[2]);
	}

	Graphics system(width,height,32); //Creates a 1280 by 960 window with 32 bits per pixel
	bool quit = false;
	SDL_Event e;	

	//Images to load
	SDL_Surface* background = NULL;
	SDL_Surface* sheep = NULL;
	SDL_Surface* title = NULL;

	//initialize surfaces
	background = system.load_image("images/grass.png");
	sheep = system.load_image("images/sheep.bmp");
	title = system.load_text("fonts/fancy.ttf",CAPTION,(SDL_Color){255,255,255},FONT_SIZE);

	//Draw surfaces to screen
	system.fill_with_background(background,256,256);	
	system.apply_surface(180, 140, sheep, system.getScreen());
	system.apply_surface(system.getWidth()-FONT_SIZE*(CAPTION.length()/3.5),system.getHeight()-FONT_SIZE-10,title,system.getScreen());
	SDL_Flip(system.getScreen());

	while(!quit) {
		while(SDL_PollEvent(&e)!=0) {
			switch(e.type) { //e.type is the type of event on the top of the event queue
				case SDL_QUIT: //red/X button pressed on window
					quit = true;
					break;
				case SDL_VIDEORESIZE: //User drags the screen to a new size
					system.resizeScreen(e.resize.w,e.resize.h);
					//redrawing the surfaces
					system.fill_with_background(background,256,256);	
					system.apply_surface(180, 140, sheep, system.getScreen());
					system.apply_surface(system.getWidth()-FONT_SIZE*(CAPTION.length()/3.5),system.getHeight()-FONT_SIZE-10,title,system.getScreen());
					SDL_Flip(system.getScreen());
					break;
				case SDL_MOUSEMOTION: //the mouse moves
					system.fill_with_background(background,256,256);	
					SDL_GetMouseState(system.getXPos(),system.getYPos());
					system.apply_surface(*system.getXPos(), *system.getYPos(), sheep, system.getScreen());
					system.apply_surface(system.getWidth()-FONT_SIZE*(CAPTION.length()/3.5),system.getHeight()-FONT_SIZE-10,title,system.getScreen());
					SDL_Flip(system.getScreen());
					break;
				case SDL_KEYDOWN: //a key is pressed
					if(e.key.keysym.sym == SDLK_q) { //the 'q' key is pressed down
						quit = true;
						break;
					}
					break;
				default: 
					break;
			}
		}
	}

	SDL_FreeSurface(background);
	SDL_FreeSurface(sheep);
	
        return 0; 
}
