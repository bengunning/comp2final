#include "SheepHerder.h"
#include "Herd.h"
#include "SheepGraphics.h"

SheepHerder::SheepHerder() :
	width(1280),
	height(900),
	fontSize(120),
	caption("Sheep Herder"),
	framerate(60),
	frame(0),
	startTime(0),
	cap(true),
	quit(false),
	background(NULL),
	centerX(NULL),
	title(NULL),
	herd("Herd.txt"),
	system(width,height,32) 
	{
	captionColor.r = 255; captionColor.g = 255; captionColor.b = 255; //white
	init();
}

void SheepHerder::init() {
	system.loadPics(); //loads the rotated pictures of sheep into a vector of SDL_Surfacesi

	 //initialize surfaces
	 background = system.load_image("images/plaid.png");
	 centerX = system.load_image("images/centerX.png");
	 title = system.load_text("fonts/fancy.ttf",caption,captionColor,fontSize);
}

void SheepHerder::drawAllSurfaces() {
	system.fill_with_background(background,300,225);
	system.displayAll(&herd);
	if (system.getWidth() > 600 && system.getHeight() > 400) system.apply_surface(system.getWidth()-fontSize*(caption.length()/3.5),system.getHeight()-fontSize-10,title,system.getScreen());
	system.apply_surface(herd.getXCenter()-50,herd.getYCenter()-50,centerX,system.getScreen()); 
	SDL_Flip(system.getScreen());
}

void SheepHerder::playGame() {
	while(!quit) {
		startTime = SDL_GetTicks();

		herd.updateCenter(system.getWidth(),system.getHeight());
		if(frame % 6) {
			herd.faceAll(herd.getXCenter(),herd.getYCenter());
		}

		while(SDL_PollEvent(&e)!=0) {
			switch(e.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_VIDEORESIZE:
					system.resizeScreen(e.resize.w,e.resize.h);
					drawAllSurfaces();
					break;
				case SDL_MOUSEBUTTONDOWN:
					herd.handleAllEvents(&e);
					break;
				case SDL_KEYDOWN:
					if(e.key.keysym.sym == SDLK_q) { //the 'q' key is pressed down
						quit = true;
					}
					break;
				default:
					break;
			}
		}
		herd.updateAll(system.getWidth(),system.getHeight());
		drawAllSurfaces();
		
		//framerate control
		frame++;
		if( ( cap == true ) && ( SDL_GetTicks() - startTime < 1000 / framerate ) ) {
			SDL_Delay( ( 1000 / framerate ) - SDL_GetTicks() + startTime ); 
		}
	}	
}

SheepHerder::~SheepHerder() {
	SDL_FreeSurface(background);
	SDL_FreeSurface(centerX);
	SDL_FreeSurface(title);
}
