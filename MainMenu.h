#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Graphics.h"

class MainMenu {
public:
	MainMenu(); // default constructor
	~MainMenu(); // destructor
	void drawToScreen(); // draws the main menu
	void start(); // Handles events and determines what to load next
private:
	SDL_Surface * background;
	SDL_Surface * playText;
	//Button playButton;
	Graphics graphics;

	bool quit;
	SDL_Event e;
};

#endif
