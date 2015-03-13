//implementation of class Graphics

#include "Graphics.h"
#include "SDL/SDL.h"
#include <string>
#include <iostream>
using namespace std;

void Graphics::setup() {
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(screenWidth,screenHeight,bpp,SDL_SWSURFACE);
	SDL_WM_SetCaption("Sheep Herder",NULL);
}

Graphics::Graphics() {
	screenWidth = 640;
	screenHeight = 480;
	bpp = 32;
	setup();
}

Graphics::~Graphics() {
	SDL_FreeSurface(screen);
	SDL_Quit();
}

SDL_Surface *Graphics::load_image(string filename) {
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

void Graphics::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination) {
        SDL_Rect offset;
        offset.x = x;
        offset.y = y;

        SDL_BlitSurface(source, NULL, destination, &offset);
}
