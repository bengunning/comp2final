#include "SheepHerder.h"
#include "Herd.h"
#include "SheepGraphics.h"
#include "Fence.h"
#include <list>
#include "FenceLink.h"

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
	paused(true),
	background(NULL),
	centerX(NULL),
	title(NULL),
	cursor(NULL),
	stone(400,400,80,width,height), 	
	sheep_pen(width, height),
	system(width,height,32), 
	clickMode(1),
	moveType(1)
	{
	captionColor.r = 255; captionColor.g = 255; captionColor.b = 255; //white
	init(numberOfSheep);
}

SheepHerder::~SheepHerder() {
	SDL_FreeSurface(background);
	SDL_FreeSurface(centerX);
	SDL_FreeSurface(title);
	SDL_FreeSurface(cursor);
}

void SheepHerder::init(int numberOfSheep) {
	system.loadPics(); //loads the rotated pictures of sheep into a vector of SDL_Surfacesi

	//initialize surfaces
	background = system.load_image("images/GrayEdits/IMG_0458.png");
	centerX = system.load_image("images/centerX.png");
	title = system.load_text("fonts/fancy.ttf",caption,captionColor,fontSize);
	cursor = system.load_image("images/whistle.png");
	sheep_pen.drawBox(75, 75, height - 125, width - 150); 
	sheep_pen.drawLine(1, 150, 2*height/5, width/2);// draw verticle line
	//initialize the herd
	if(numberOfSheep) {
		Herd temp(numberOfSheep, system.getWidth(), system.getHeight()); // initialize random herd
		herd = temp;
	} else {
		Herd temp("Herd.txt");
		herd = temp;
	}
}

void SheepHerder::drawAllSurfaces() { // destructor for Fence_Links called here somehow.
	system.fill_with_background(background,300,400); //display the background
	system.apply_surface(stone.getX()-55,stone.getY()-55,stone.getSurface(),system.getScreen());
	for (std::list<FenceLink *>::iterator lit = (sheep_pen.getLinks()).begin(); lit != (sheep_pen.getLinks()).end(); lit++) {
		system.apply_surface((*lit)->getX() - 100, (*lit)->getY() - 100, (*lit)->getSurface(), system.getScreen());
	//	std::cout << ((*lit)->getX()) << " , " << ((*lit)->getY()) << std::endl;
	}
	// need to draw all fence links in the pen
	if (system.getWidth() > 600 && system.getHeight() > 400) system.apply_surface(system.getWidth()-fontSize*(caption.length()/3.5),system.getHeight()-fontSize-10,title,system.getScreen()); //display text in corner
	//system.apply_surface(herd.getXCenter()-50,herd.getYCenter()-50,centerX,system.getScreen());  // display the x
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
	/*temp.push_back((*lit)->getX());
	temp.push_back((*lit)->getY());
	temp.push_back((*lit)->getBuffer());
	obstacles.push_back(temp);*/
	for (std::list<FenceLink *>::iterator lit = (sheep_pen.getLinks()).begin(); lit != (sheep_pen.getLinks()).end(); lit++) {
		temp[0] = (*lit)->getX();
		temp[1] = (*lit)->getY();
		temp[2] = (*lit)->getBuffer();
		obstacles.push_back(temp);
	}
	while(!quit) {
		startTime = SDL_GetTicks();

		herd.updateCenter(system.getWidth(),system.getHeight());
		if(frame % 6) {
			herd.faceAll(herd.getXCenter(),herd.getYCenter(), moveType);
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
					switch (clickMode){
						case 1:{	// deafult mode, click to change center of herd
							herd.handleAllEvents(&e);
							break;
						}
						case 2:{// mode 2, click to add a sheep at the clicking position
							// create a new sheep at the position of mouse click, with speed being the average speed of herd and direction 0
							int speed;
							if(herd.getNumSheep() == 0) speed = 10;
							else speed = herd.speed();
							Sheep newSheep(*(system.getXPos()), *(system.getYPos()), speed, 0);	
							herd.bear(newSheep);	// add newSheep to herd
							break;
						}
						case 3:{// mode 3, click to remove a sheep at the clicking position
							if(herd.getNumSheep() != 0)
								herd.shear(*(system.getXPos()), *(system.getYPos()));
							break;
						}
					}
					break;
				case SDL_KEYDOWN:
					// process different key presses
					switch (e.key.keysym.sym){
						case SDLK_q:	// 'q' is pressed to quit
							quit = true;
							break;
						case SDLK_p:	// 'p' is pressed to pause
							paused = !paused;	// revert state of paused
							break;
						case SDLK_c:    // 'c' is pressed to toggle speed cap
							cap = !cap;
							break;
						case SDLK_1:	// '1' is pressed to switch to moveType 1
							moveType = 1;	// move toward mouse click
							break;
						case SDLK_2:	// '2' is pressed to switch to moveType 2
							moveType = 2;	// move away from mouse click
							break;
						case SDLK_ESCAPE: // 'esc' is pressed to switch to clickMode 1
							clickMode = 1;	// click to move the herd
							SDL_FreeSurface(cursor);
							cursor = system.load_image("images/whistle.png");
							break;
						case SDLK_UP:	// arrow UP is pressed to switch to clickMode 2
							clickMode = 2;	// click to add (bear) a sheep
							SDL_FreeSurface(cursor);
							cursor = system.load_image("images/GrayEdits/gsheep_165.bmp");
							break;
						case SDLK_DOWN:	// arrow DOWN is pressed to switch to clickMode 3
							clickMode = 3;	// click to remove (shear) a sheep
							SDL_FreeSurface(cursor);
							cursor = system.load_image("images/wolf.jpeg");
							break;
						default:
							break;
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
