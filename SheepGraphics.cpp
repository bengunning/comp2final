// implementation of class SheepGraphics

#include "SheepGraphics.h"
#include <vector>
#include <iterator>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

SheepGraphics::SheepGraphics(int width, int height, int bpp) :
	Graphics(width,height,bpp)
	{
		vector<SDL_Surface*> sheepPics;
	}

void SheepGraphics::displayAll(Herd * herd) {
	vector<vector<int> > locs;
	vector<double> dirs;
	int count;        // These two are used to determine
	double direction; // which picture to use
	int dimension = 100; // width and height of the sheep
	locs = herd->getAllLocations();
	dirs = herd->getAllDirections();
	for(int i=0; i < locs.size(); i++) {
		//Here we will determine the sheep image to use based on the value of that sheeps direction
		//There are multiple pictures of the sheep, each one rotated 15 degrees from another
		//count will hold the number of 15degree increments away from 0degrees that the angle is
		count = 0;
		direction = dirs[i] * 360 / 2 / M_PI; //sheep direction in degrees
		while (! (direction > -7.5 && direction <= 7.5) ) {
			count++;
			direction -= 15;
		}

		if(count >= sheepPics.size()) count = 0; //Fix possible error when angle very close to 360

		Graphics::apply_surface(locs[i][0]-dimension/2,locs[i][1]-dimension/2,sheepPics[count],Graphics::getScreen());
		// ofset the sheep pictures by half the height and half the width
		
	}
}

void SheepGraphics::loadPics() {
	string imageName;
	ifstream file("imageNames.txt");	
	while(file >> imageName) {
		sheepPics.push_back(Graphics::load_image(imageName));
	}
	file.close();
}
