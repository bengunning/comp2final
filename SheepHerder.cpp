#include "SheepHerder.h"
#include "Herd.h"
#include "SheepGraphics.h"

SheepHerder::SheepHerder(int numberOfSheep, int width, int height) :
	width(width),
	height(height),
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
	stoneSurface(NULL),
	stone(400,400,80),
	system(width,height,32) 
	{
	captionColor.r = 255; captionColor.g = 255; captionColor.b = 255; //white
	init(numberOfSheep);
}

void SheepHerder::init(int numberOfSheep) {
	system.loadPics(); //loads the rotated pictures of sheep into a vector of SDL_Surfacesi

	 //initialize surfaces
	 background = system.load_image("images/plaid.png");
	 centerX = system.load_image("images/centerX.png");
	 title = system.load_text("fonts/fancy.ttf",caption,captionColor,fontSize);
	 stoneSurface = stone.getSurface(); 
	 
	//initialize the herd
	if(numberOfSheep) {
		Herd temp(numberOfSheep, system.getWidth(), system.getHeight()); // initialize random herd
		herd = temp;
	} else {
		Herd temp("Herd.txt");
		herd = temp;
	}
}

void SheepHerder::drawAllSurfaces() {
	system.fill_with_background(background,300,225); //display the background
	system.apply_surface(stone.getX()-45,stone.getY()-22,stoneSurface,system.getScreen());
	if (system.getWidth() > 600 && system.getHeight() > 400) system.apply_surface(system.getWidth()-fontSize*(caption.length()/3.5),system.getHeight()-fontSize-10,title,system.getScreen()); //display text in corner
	system.apply_surface(herd.getXCenter()-50,herd.getYCenter()-50,centerX,system.getScreen());  // display the x
	system.displayAll(&herd); //display the sheep
	SDL_Flip(system.getScreen()); //send images to screen
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
