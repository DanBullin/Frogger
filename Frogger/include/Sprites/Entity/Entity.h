#ifndef ENTITY_H
#define ENTITY_H

#include <SFML\Graphics.hpp>

#include ".\Sprites\SpriteData.h"
#include ".\ObjectData.h"

using namespace std;
using namespace sf;

/*
	This class creates an Entity (Moving object)
*/

class Entity : public RectangleShape
{
	private:
		int iSpeed; // The speed of the entity
		int iDirection; // The direction of the entity
	public:
		Entity(Vector2f fPosParam, string sTypeParam);
		SpriteData spriteData;
		ObjectData objectData;

		int getSpeed();
		int getDirection();

		void setSpeed(int iValue);
		void setDirection(int iValue);

		// Call this function to set properties
		void setProperties(Vector2f fSizeParam, int iDirectionParam, int iSpeedParam, int iTextureFilesParam, bool bAllowCollisionParam, int iCollisionActionParam, int iHoverActionParam, int iClickActionParam);
};

#endif