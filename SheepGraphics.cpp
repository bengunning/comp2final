// implementation of class SheepGraphics

#include "SheepGraphics.h"
#include <iostream> //for debugging
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

SheepGraphics::SheepGraphics(int width, int height, int bpp) :
	Graphics(width,height,bpp)
	{}

void SheepGraphics::displayAll(Herd * herd) {
	vector<vector<int> > locs;
	vector<double> dirs;
	locs = herd->getAllLocations();
	dirs = herd->getAllDirections();
	SDL_Surface* sheep_left = NULL;
	SDL_Surface* sheep_right = NULL;
	sheep_left = Graphics::load_image("images/sheep.bmp");
	sheep_right = Graphics::load_image("images/sheep_00.bmp");
	for(int i=0; i < locs.size(); i++) {
		if(cos(dirs[i]) > 0) {
			Graphics::apply_surface(locs[i][0]-25,locs[i][1]-27,sheep_right,Graphics::getScreen());
		} else {
			Graphics::apply_surface(locs[i][0]-25,locs[i][1]-27,sheep_left,Graphics::getScreen());
		}
	}
}
