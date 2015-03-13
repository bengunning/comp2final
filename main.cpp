// Driver program for sheepHerder

#include "Sheep.h"
#include "Graphics.h"
#include "SDL/SDL.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
	Graphics system;
	bool quit = false;
	SDL_Event e;	

	//Images to load
	SDL_Surface* background = NULL;
	SDL_Surface* message = NULL;

	background = system.load_image("images/background.bmp");
	message = system.load_image("images/hello.bmp");

	system.apply_surface(0,0,background, system.screen);
	system.apply_surface(320, 0, background, system.screen);
	system.apply_surface(0, 240, background, system.screen);
	system.apply_surface(320, 240, background, system.screen);
	system.apply_surface(180, 140, message, system.screen);
	
	SDL_Flip(system.screen);
	
	while(!quit) {
		while(SDL_PollEvent(&e)!=0) {
			if(e.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	SDL_FreeSurface(background);
	SDL_FreeSurface(message);
	
        return 0; 
}
