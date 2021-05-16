#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>

#include ".\Sprites\SpriteData.h"
#include ".\ObjectData.h"

using namespace std;
using namespace sf;

/*
	This class creates an Object (Non-moving Sprite/RectangleShape)
*/

class Object : public RectangleShape
{
	private:

	public:
		Object(Vector2f fPosParam, string sTypeParam);
		SpriteData spriteData; // Data about the object
		ObjectData objectData;

		void setProperties(Vector2f fSizeParam, int iTextureFilesParam, bool bAllowCollisionParam, int iCollisionActionParam, int iHoverActionParam, int iClickActionParam);
};

#endif