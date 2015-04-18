#include "SheepHerder.h"
#include "Herd.h"
#include "SheepGraphics.h"

SheepHerder::SheepHerder(int numberOfSheep, int width, int height) :
	width(width),
	height(height),
	fontSize(120),
	caption("Sheep Herder"),
	framerate(20),
	frame(0),
	startTime(0),
	cap(true),
	quit(false),
	paused(false),
	background(NULL),
	centerX(NULL),
	title(NULL),
	cursor(NULL),
	stone(400,400,250,180,width,height), // added a radius to the stone
	system(width,height,32) 
	{
	captionColor.r = 255; captionColor.g = 255; captionColor.b = 255; //white
	init(numberOfSheep);
}

void SheepHerder::init(int numberOfSheep) {
	system.loadPics(); //loads the rotated pictures of sheep into a vector of SDL_Surfacesi

	//initialize surfaces
	background = system.load_image("images/GrayEdits/IMG_0458.png");
	centerX = system.load_image("images/centerX.png");
	title = system.load_text("fonts/fancy.ttf",caption,captionColor,fontSize);
	cursor = system.load_image("images/whistle.png");
	 
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
	system.fill_with_background(background,2000,1200); //display the background
	system.apply_surface(stone.getX()-45,stone.getY()-22,stone.getSurface(),system.getScreen());
	if (system.getWidth() > 600 && system.getHeight() > 400) system.apply_surface(system.getWidth()-fontSize*(caption.length()/3.5),system.getHeight()-fontSize-10,title,system.getScreen()); //display text in corner
	system.apply_surface(herd.getXCenter()-50,herd.getYCenter()-50,centerX,system.getScreen());  // display the x
	system.displayAll(&herd); //display the sheep
	system.apply_surface(*system.getXPos() - 25, *system.getYPos()- 15, cursor, system.getScreen()); //display the cursor
	SDL_Flip(system.getScreen()); //send images to screen
}

void SheepHerder::playGame() {
	// Create the obstacle location vector for the sheep to avoid
	vector<vector<int> > obstacles;
	vector<int> temp;
	temp.push_back(stone.getX());
	temp.push_back(stone.getY());
	temp.push_back(stone.getBuffer());
	obstacles.push_back(temp);

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
					} else if (e.key.keysym.sym == SDLK_p) {
						// toggle if paused is true or false
						paused = !paused;
					}
					break;
				case SDL_MOUSEMOTION:
					SDL_GetMouseState(system.getXPos(),system.getYPos());
					break;
				default:
					break;
			}
		}
		if(!paused) {
			herd.updateAll(system.getWidth(),system.getHeight(), obstacles);
			drawAllSurfaces();
		
			//framerate control
			frame++;
			if( ( cap == true ) && ( SDL_GetTicks() - startTime < 1000 / framerate ) ) {
				SDL_Delay( ( 1000 / framerate ) - SDL_GetTicks() + startTime ); 
			}
		} else {
			drawAllSurfaces();
		}
	}	
}

SheepHerder::~SheepHerder() {
	SDL_FreeSurface(background);
	SDL_FreeSurface(centerX);
	SDL_FreeSurface(title);
}
