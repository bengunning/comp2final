// Driver program for sheepHerder

#include "Sheep.h"
#include "Herd.h"
#include "SheepGraphics.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
	int width = 1280; //default screen width
	int height = 900; //default screen height
	const int FONT_SIZE = 120;                // Font and Text to be placed in
	const string CAPTION = "Sheep Herder";    // the bottom right corner of the screen
	const SDL_Color WHITE = {255,255,255}; //rgb value

	//Framerate control
	const int FRAMERATE = 60; //frames per second
	int frame = 0; //holds the current frame
	bool cap = true; //determines if the frame rate should be used
	int startTime = 0;

	if (argc == 3) { //if two arguments given
		width = atoi(args[1]);
		height = atoi(args[2]);
	}

	SheepGraphics system(width,height,32); //Creates a 1280 by 960 window with 32 bits per pixel
	bool quit = false;
	SDL_Event e;	

	//Images to load
	SDL_Surface* background = NULL;
	SDL_Surface* title = NULL;
	system.loadPics(); //loads the rotated pictures of sheep into a vector of SDL_Surfaces

	//initialize surfaces
	background = system.load_image("images/plaid.png");
	title = system.load_text("fonts/fancy.ttf",CAPTION,WHITE,FONT_SIZE);

	//Create herd of sheep
	Herd herd("Herd.txt"); //reads in Sheep objects from a text file

	//Draw surfaces to screen
	system.fill_with_background(background,300,225);	
	system.displayAll(&herd);
	system.apply_surface(system.getWidth()-FONT_SIZE*(CAPTION.length()/3.5),system.getHeight()-FONT_SIZE-10,title,system.getScreen());
	SDL_Flip(system.getScreen());

	while(!quit) {
		startTime = SDL_GetTicks();
		while(SDL_PollEvent(&e)!=0) {
			switch(e.type) { 
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_VIDEORESIZE:
					system.resizeScreen(e.resize.w,e.resize.h);
					//redrawing the surfaces
					system.fill_with_background(background,300,225);	
					system.displayAll(&herd);
					system.apply_surface(system.getWidth()-FONT_SIZE*(CAPTION.length()/3.5),system.getHeight()-FONT_SIZE-10,title,system.getScreen());
					SDL_Flip(system.getScreen());
					break;
				case SDL_MOUSEBUTTONDOWN:		
					herd.handleAllEvents(&e);
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
		
		herd.updateAll(system.getWidth(),system.getHeight());
		system.fill_with_background(background,300,225);
		system.displayAll(&herd);
		system.apply_surface(system.getWidth()-FONT_SIZE*(CAPTION.length()/3.5),system.getHeight()-FONT_SIZE-10,title,system.getScreen());
		SDL_Flip(system.getScreen());
		//SDL_Delay(30);
		frame++;
		if( ( cap == true ) && ( SDL_GetTicks() - startTime < 1000 / FRAMERATE ) ) {
            		//Sleep the remaining frame time
                        SDL_Delay( ( 1000 / FRAMERATE ) - SDL_GetTicks() + startTime );
                }
	}

	SDL_FreeSurface(background);
	
        return 0; 
}
