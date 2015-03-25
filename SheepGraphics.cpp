// implementation of class SheepGraphics

#include "SheepGraphics.h"
#include <iostream> //for debugging
#include <vector>
#include <iterator>
using namespace std;

SheepGraphics::SheepGraphics(int width, int height, int bpp) :
	Graphics(width,height,bpp)
	{}

void SheepGraphics::displayAll(Herd * herd) {
	vector<vector<int> > locs;
	locs = herd->getAllLocations();
	SDL_Surface* sheep = NULL;
	sheep = Graphics::load_image("images/sheep.bmp");
	for(int i=0; i < locs.size(); i++) {
		Graphics::apply_surface(locs[i][0],locs[i][1],sheep,Graphics::getScreen());
	}
}
