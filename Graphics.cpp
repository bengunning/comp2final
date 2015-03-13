//implementation of class Graphics

#include "Graphics.h"

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
