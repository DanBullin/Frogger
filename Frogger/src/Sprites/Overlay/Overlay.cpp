#include ".\Sprites\Overlay\Overlay.h"

Overlay::Overlay()
{

}

void Overlay::setProperties(float fSizeX, float fSizeY, Color colour)
{
	setSize(Vector2f(fSizeX, fSizeY));
	setFillColor(colour);
	setDraw(false);
}

bool Overlay::getDraw()
{
	return bDraw;
}

void Overlay::setDraw(bool bValue)
{
	bDraw = bValue;
}