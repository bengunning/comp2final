// Driver program for sheepHerder

#include "MainMenu.h"
#include "SheepHerder.h"
#include <cstdlib> //for atoi
using namespace std;

int main(int argc, char* args[]) {
	// Arguments control the number of sheep spawned and the 
	// One additional argument will be the number of sheep desired
	// Two additional arguments will be the width and height of the window desired
	// Three arguments will be the number of sheep wanted followed
	// by the width and height
	int width = 1280, height = 900; //default width and height of window
	int numberOfSheep = 80; //default number of sheep. Leaving this as 0 will read in sheep from Herd.txt by default
	int numberOfArgs = argc - 1;
	switch(numberOfArgs) {
		case 1:
			numberOfSheep = atoi(args[1]);
			break;
		case 2:
			width = atoi(args[1]);
			height = atoi(args[2]);
			break;
		case 3:
			numberOfSheep = atoi(args[1]);
			width = atoi(args[2]);
			height = atoi(args[3]);
			break;
		default:
			break;
	}

	MainMenu menu;
	menu.drawToScreen();
	menu.start();
	SheepHerder shepherd(numberOfSheep,width,height);
	shepherd.playGame();
	
        return 0; 
}
