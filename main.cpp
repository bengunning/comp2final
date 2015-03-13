// Driver program for sheepHerder

#include "Sheep.h"
#include "Graphics.h"
#include "SDL/SDL.h"
#include <iostream>
#include <string>
using namespace std;

SDL_Surface *load_image(string filename) {
	SDL_Surface * loadedImage = NULL;	
	SDL_Surface * optimizedImage = NULL;
	loadedImage = SDL_LoadBMP( filename.c_str() );
	if(loadedImage) {
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
	} else {
		cout << "Could not load " << filename << endl;
	}
	return optimizedImage; //NULL if no image loaded
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	
	SDL_BlitSurface(source, NULL, destination, &offset);
}

int main(int argc, char* args[]) {
	Graphics system;
	bool quit = false;
	SDL_Event e;	

	//Images to load
	SDL_Surface* background = NULL;
	SDL_Surface* message = NULL;

	background = load_image("images/background.bmp");
	message = load_image( "images/hello.bmp" );

	apply_surface(0,0,background, system.screen);
	apply_surface(320, 0, background, system.screen);
	apply_surface(0, 240, background, system.screen);
	apply_surface(320, 240, background, system.screen);
	apply_surface(180, 140, message, system.screen);
	
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
