#include ".\Sprites\Object\Object.h"

Object::Object(Vector2f fPosParam, string sTypeParam)
{
	// Setting the properties of the Object
	// Generic Properties
	setPosition(fPosParam);
	spriteData.setType(sTypeParam);
	spriteData.setCurrentTextureFile(0);
	objectData.setDraw(false);

	// Object specific properties
	// This function will create properities of objects of a type to be the same
	if(sTypeParam == "Info")
	{
		setProperties(Vector2f(640, 32), 1, false, 4, 0, 0);
	}
	else if(sTypeParam == "Water")
	{
		setProperties(Vector2f(640, 32), 1, false, 1, 0, 0);
	}
	else if(sTypeParam == "Grass")
	{
		setProperties(Vector2f(640, 32), 1, true, 0, 0, 0);
	}
	else if(sTypeParam == "Road")
	{
		setProperties(Vector2f(640, 32), 1, true, 0, 0, 0);
	}
	else if(sTypeParam == "Lilypad")
	{
		setProperties(Vector2f(32, 32), 2, false, 3, 0, 0);
	}
	else if(sTypeParam == "Life")
	{
		setProperties(Vector2f(32, 32), 2, false, 4, 0, 0);
		spriteData.setCurrentTextureFile(1);
	}
	else if(sTypeParam == "Timer")
	{
		setProperties(Vector2f(180, 16), 1, false, 4, 0, 0);
	}
	else if(sTypeParam == "TimerTick")
	{
		setProperties(Vector2f(178, 14), 1, false, 4, 0, 0);
	}
	
	spriteData.setSpriteTexture(*this);
}

void Object::setProperties(Vector2f fSizeParam, int iTextureFilesParam, bool bAllowCollisionParam, int iCollisionActionParam, int iHoverActionParam, int iClickActionParam)
{
	setSize(fSizeParam);
	spriteData.addTextureFile(iTextureFilesParam);
	spriteData.setAllowCollision(bAllowCollisionParam);
	objectData.setCollisionAction(iCollisionActionParam);
	objectData.setHoverAction(iHoverActionParam);
	objectData.setClickAction(iClickActionParam);
}