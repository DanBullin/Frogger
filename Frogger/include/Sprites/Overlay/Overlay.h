#ifndef OVERLAY_H
#define OVERLAY_H

#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

/*
	This class creates an Overlay
*/

class Overlay : public RectangleShape
{
	private:
		bool bDraw; // Do we draw the overlay?
	public:
		Overlay();
		void setProperties(float fSizeX, float fSizeY, Color colour);

		bool getDraw();
		void setDraw(bool bValue);
};

#endif