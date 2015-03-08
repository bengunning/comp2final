// Driver program for sheepHerder

#include "Sheep.h"
#include "SDL/SDL.h"
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
	Sheep sheep(5,12,1.0,M_PI / 2.0);
	
	SDL_Surface* hello = NULL;
    	SDL_Surface* screen = NULL;          

	//Start SDL
	SDL_Init( SDL_INIT_EVERYTHING );
	
        //Set up screen
        screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
	
	//Load image
        if ( hello = SDL_LoadBMP( "sheep.bmp" ) ) {
		cout << "loaded successfully" << endl;
	} else {
		cout << "load failed" << endl;
		return 0;
	}
 
	//Apply image to screen
	SDL_BlitSurface( hello, NULL, screen, NULL );
	
	//Update Screen
	SDL_Flip( screen );
	
	//Pause
	SDL_Delay( 2000 );

	//Free the loaded image
	SDL_FreeSurface( hello );
	
	//Quit SDL
	SDL_Quit();
	
        return 0; 
}
