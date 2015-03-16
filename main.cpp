// Driver program for sheepHerder

#include "Sheep.h"
#include "Graphics.h"
#include "SDL/SDL.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
	int width = 1280;
	int height = 960;
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

	background = system.load_image("images/background.bmp");
	sheep = system.load_image("images/sheep.bmp");

	//Draw surfaces to screen
	system.fill_with_background(background,320,240);	
	system.apply_surface(180, 140, sheep, system.getScreen());
	SDL_Flip(system.getScreen());

	while(!quit) {
		while(SDL_PollEvent(&e)!=0) {
			if(e.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	SDL_FreeSurface(background);
	SDL_FreeSurface(sheep);
	
        return 0; 
}
