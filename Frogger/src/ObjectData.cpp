#include ".\ObjectData.h"

ObjectData::ObjectData()
{

}

#pragma region Get Functions

bool ObjectData::getDraw()
{
	return bDraw;
}

int ObjectData::getCollisionAction()
{
	return iCollisionAction;
}

int ObjectData::getHoverAction()
{
	return iMouseHoverAction;
}

int ObjectData::getClickAction()
{
	return iMouseClickAction;
}

#pragma endregion

#pragma region Set Functions

void ObjectData::setDraw(bool bValue)
{
	bDraw = bValue;
}

void ObjectData::setCollisionAction(int iValue)
{
	iCollisionAction = iValue;
}

void ObjectData::setHoverAction(int iValue)
{
	iMouseHoverAction = iValue;
}

void ObjectData::setClickAction(int iValue)
{
	iMouseClickAction = iValue;
}

#pragma endregion

bool ObjectData::containsMouse(FloatRect bounds, int iWindowPosX, int iWindowPosY)
{
	int iTranslatedWindowPosX = iWindowPosX + 8; // Need to add 9 to get canvas position
	int iTranslatedWindowPosY = iWindowPosY + 30; // Need to add 31 to get canvas position

	if(bounds.contains((Mouse::getPosition().x - iTranslatedWindowPosX), (Mouse::getPosition().y - iTranslatedWindowPosY)) && this->getDraw() == true)
	{
		return true; // Mouse is inside object
	}
	return false; // Mouse isn't inside object
}

bool ObjectData::containsPlayer(FloatRect objectBounds, FloatRect playerBounds, Vector2f fPlayerPos, Vector2f fPlayerSize)
{
	// Check if player has interested an entity/object
	if(playerBounds.intersects(objectBounds))
	{
		// Check if the majority of the player is inside the object -> more accurate collision detection
		if(objectBounds.contains(fPlayerPos.x + (fPlayerSize.x / 2), fPlayerPos.y + (fPlayerSize.y / 2)))
		{
			return true;
		}
		return false; // Player has collided with object
	}
	return false; // Player hasn't collided with object
}