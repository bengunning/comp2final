#include "MainMenu.h"

MainMenu::MainMenu() :
	background(NULL),
	graphics(900,675,32),
	playText(NULL),
	quit(false)
{
	//Create color to use for text
	SDL_Color playButtonColor;
	playButtonColor.r = 255;
	playButtonColor.g = 0;
	playButtonColor.b = 0;

	background = graphics.load_image("images/MainMenuBackground.png");
	playText = graphics.load_text("fonts/fancy.ttf","Play",playButtonColor,300);
	graphics.toggleCursorVisibility();
	
	//Create the button background
	SDL_Rect playButton;
	playButton.x = 150;
	playButton.y = 400;
	playButton.w = 600;
	playButton.h = 200;
	SDL_FillRect(background,&playButton,SDL_MapRGB(background->format,255,255,255));
}

MainMenu::~MainMenu() {
	SDL_FreeSurface(playText);
	SDL_FreeSurface(background);
}

void MainMenu::drawToScreen() {
	graphics.apply_surface(0,0,background,graphics.getScreen());
	graphics.apply_surface(280,340,playText,graphics.getScreen());
	SDL_Flip(graphics.getScreen());
}

void MainMenu::start() {
	int xClickPos, yClickPos;
	
	while(!quit) {
		while(SDL_PollEvent(&e)!=0) {	
			switch(e.type) {
				case SDL_MOUSEBUTTONDOWN:
					SDL_GetMouseState(&xClickPos,&yClickPos);
					if (xClickPos > 150 && xClickPos < 750 && yClickPos > 400 && yClickPos < 600) {
						quit = true;
					}
					break;
				case SDL_KEYDOWN:
					break;
				default:
					break;
			}
		}
		drawToScreen();
	}
}
