// A fence class that the sheep will avoid. Draws a line or box
// 19 April 2015

#include "Obstacle.h"
#include <vector>
#include "SDL/SDL.h"

class FenceLink: Obstacle { // 
public:
	FenceLink(int orient, int x, int y, int screenWidth, int screenHeight); // loads different pictures and point vectors depending on the orientation
	// 0 = Horizontal, 1 = Vertical, 2 = top right corner, 3 = top left corner, 4 = bottom left corner,
	// 5 = bottom right corner
	// pictures also depend on the portion of the screen
	~FenceLink();
	int getOrient() const; // return the orientation encoding
	long int getLengthX(void) const; // length spanned by the hazards in the fencelink horizontally or vertically, 
	long int getLengthY(void) const; //helps calculate lines. 
	SDL_Surface* getSurface() const;
private:
	int Orient;
	SDL_Surface* image;
}
