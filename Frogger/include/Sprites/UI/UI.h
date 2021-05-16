#ifndef UI_H
#define UI_H

#include <SFML\Graphics.hpp>

#include ".\Sprites\SpriteData.h"
#include ".\ObjectData.h"

using namespace std;
using namespace sf;

/*
	This class creates UI Buttons
*/

class UI : public RectangleShape
{
	private:

	public:
		UI(Vector2f fPosParam, string sTypeParam, int iClickActionParam);
		SpriteData spriteData; // The occupying data of the sprite
		ObjectData objectData;

		void setProperties(Vector2f fSizeParam, int iHoverActionParam);
};

#endif