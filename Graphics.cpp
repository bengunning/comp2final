//implementation of class Graphics

#include "Graphics.h"
#include "SDL/SDL.h"
#include <string>
#include <iostream>
using namespace std;

void Graphics::setup() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	screen = SDL_SetVideoMode(screenWidth,screenHeight,bpp,SDL_SWSURFACE | SDL_RESIZABLE);
	SDL_WM_SetCaption("Sheep Herder",NULL);
	SDL_WarpMouse(*xMousePos, *yMousePos); //Sets mouse to center of window
}

Graphics::Graphics(int width, int height, int bits) :
	screenWidth(width),
	screenHeight(height),
	bpp(bits),
	xMousePos(new int),
	yMousePos(new int)
{
	*xMousePos = getWidth()/2;
	*yMousePos = getHeight()/2;
	setup();
}

Graphics::~Graphics() {
	SDL_FreeSurface(screen);
	delete xMousePos;
	delete yMousePos;
	SDL_Quit();
}

int Graphics::getWidth() {
	return screenWidth;
}

int Graphics::getHeight() {
	return screenHeight;
}

SDL_Surface *Graphics::getScreen() {
	return screen;
}

int *Graphics::getXPos() {
	return xMousePos;
}

int *Graphics::getYPos() {
	return yMousePos;
}

void Graphics::resizeScreen(int width, int height) {
	screenWidth = width;
	screenHeight = height;
	screen = SDL_SetVideoMode(screenWidth,screenHeight,bpp,SDL_SWSURFACE | SDL_RESIZABLE);
}

void Graphics::fill_with_background(SDL_Surface* background, int width, int height) {
	for(int xPos=0; xPos < getWidth(); xPos += width) {
		for(int yPos=0; yPos < getHeight(); yPos += height) {
			apply_surface(xPos,yPos,background,screen);
		}
	}
}

SDL_Surface *Graphics::load_text(string filename, string text, SDL_Color color, int fontSize) {
	TTF_Font *font = NULL;
	font = TTF_OpenFont(filename.c_str(),fontSize);

	SDL_Surface *temp;
	return TTF_RenderText_Solid(font,text.c_str(),color);
}

SDL_Surface *Graphics::load_image(string filename) {
	SDL_Surface * loadedImage = NULL;
        SDL_Surface * optimizedImage = NULL;
        //loadedImage = SDL_LoadBMP( filename.c_str() );
        loadedImage = IMG_Load( filename.c_str() );
        if(loadedImage) {
                optimizedImage = SDL_DisplayFormat(loadedImage);
                SDL_FreeSurface(loadedImage);
		//Color Keying
		Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0x9C, 0x69, 0x9C );
		// changed this to a less common color
		SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
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
