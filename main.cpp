// Driver program for sheepHerder

#include "Sheep.h"
#include "SDL/SDL.h"
#include <cmath>
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
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_BPP = 32;
	
	//Images to load
	SDL_Surface* background = NULL;
	SDL_Surface* message = NULL;
    	SDL_Surface* screen = NULL;          

	// load SDL components
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
        	return 1; //ERROR 1: could not initialize SDL objects 
	}

	// setup screen, the window all other graphics will go into
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	if (!screen) {
		return 2; //ERROR 2: could not initialize screen
	}
	
	//Set window caption
	SDL_WM_SetCaption( "Sheep Herder", NULL );

	background = load_image("images/background.bmp");
	message = load_image( "images/hello.bmp" );

	apply_surface(0,0,background,screen);
	apply_surface(320, 0, background, screen);
	apply_surface(0, 240, background, screen);
	apply_surface(320, 240, background, screen);
	apply_surface(180, 140, message, screen);
	
	SDL_Flip(screen);
	SDL_Delay(5000);
	SDL_FreeSurface(background);
	SDL_FreeSurface(message);
	SDL_FreeSurface(screen);

	SDL_Quit();
	
        return 0; 
}
