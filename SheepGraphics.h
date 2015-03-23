#ifndef SHEEP_GRAPHICS_H
#define SHEEP_GRAPHICS_H

#include "Graphics.h"
#include "Herd.h"

class SheepGraphics : public Graphics {
public:
	SheepGraphics(int, int, int);
	void displayAll(Herd*);
private:
};

#endif
