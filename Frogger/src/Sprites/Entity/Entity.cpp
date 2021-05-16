#include ".\Sprites\Entity\Entity.h"

Entity::Entity(Vector2f fPosParam, string sTypeParam)
{
	// Setting the properties of the Entity
	// Generic Properties
	setPosition(fPosParam);
	spriteData.setType(sTypeParam);
	spriteData.setCurrentTextureFile(0);
	objectData.setDraw(false);

	// Entity specific properties
	// This function will create properities of entities of a type to be the same
	if(sTypeParam == "Frog")
	{
		setProperties(Vector2f(32, 32), 0, 0, 4, true, 0, 0, 0);
	}
	else if(sTypeParam == "Car")
	{
		setProperties(Vector2f(32, 32), 1, 2, 1, false, 1, 0, 0);
	}
	else if(sTypeParam == "Lorry")
	{
		setProperties(Vector2f(64, 32), 3, 1, 1, false, 1, 0, 0);
	}
	else if(sTypeParam == "Turtle")
	{
		setProperties(Vector2f(32, 32), 1, 2, 2, false, 2, 0, 0);
	}
	else if(sTypeParam == "Log")
	{
		setProperties(Vector2f(96, 32), 3, 1, 1, false, 2, 0, 0);
	}
	
	spriteData.setSpriteTexture(*this);
}

void Entity::setProperties(Vector2f fSizeParam, int iDirectionParam, int iSpeedParam, int iTextureFilesParam, bool bAllowCollisionParam, int iCollisionActionParam, int iHoverActionParam, int iClickActionParam)
{
	setSize(fSizeParam);
	setDirection(iDirectionParam);
	setSpeed(iSpeedParam);
	spriteData.addTextureFile(iTextureFilesParam);
	spriteData.setAllowCollision(bAllowCollisionParam);
	objectData.setCollisionAction(iCollisionActionParam);
	objectData.setHoverAction(iHoverActionParam);
	objectData.setClickAction(iClickActionParam);
}

int Entity::getSpeed()
{
	return iSpeed;
}

int Entity::getDirection()
{
	return iDirection;
}

void Entity::setSpeed(int iValue)
{
	iSpeed = iValue;
}

void Entity::setDirection(int iValue)
{
	iDirection = iValue;
}