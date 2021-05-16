#include ".\Sprites\Object\ObjectManager.h"

ObjectManager::ObjectManager()
{

}

void ObjectManager::loadObjects(int iLives)
{
	// Lives Positioning -- Used for automatically placing Lives
	// The amount of Life objects created is based on the Game's Lives
	int iX = 5;
	int iY = 384;

	this->clear(); // Always clear the vector

	// POSITION || TYPE (Parameter)
	push_back(new Object(Vector2f(0, 0), "Info"));
	push_back(new Object(Vector2f(0, 32), "Water"));
	push_back(new Object(Vector2f(0, 64), "Water"));
	push_back(new Object(Vector2f(0, 96), "Water"));
	push_back(new Object(Vector2f(0, 128), "Water"));
	push_back(new Object(Vector2f(0, 160), "Water"));
	push_back(new Object(Vector2f(0, 192), "Grass"));
	push_back(new Object(Vector2f(0, 224), "Road"));
	push_back(new Object(Vector2f(0, 256), "Road"));
	push_back(new Object(Vector2f(0, 288), "Road"));
	push_back(new Object(Vector2f(0, 320), "Road"));
	push_back(new Object(Vector2f(0, 352), "Grass"));
	push_back(new Object(Vector2f(0, 384), "Info"));
	push_back(new Object(Vector2f(64, 32), "Lilypad"));
	push_back(new Object(Vector2f(160, 32), "Lilypad"));
	push_back(new Object(Vector2f(288, 32), "Lilypad"));
	push_back(new Object(Vector2f(416, 32), "Lilypad"));
	push_back(new Object(Vector2f(512, 32), "Lilypad"));

	for(int i = 0; i < iLives; i++)
	{
		// Flexible amount of Lives support
		push_back(new Object(Vector2f(iX, iY), "Life"));
		iX = iX + 42;
	}

	push_back(new Object(Vector2f(420, 392), "Timer"));
	push_back(new Object(Vector2f(421, 393), "TimerTick"));
}

int ObjectManager::getListSize()
{
	int iSize = size();
	return iSize;
}

int ObjectManager::findElement(string sTypeParam)
{
	// Find the element id of an object based on its type
	// Returns the first instance of the type
	for(int i = 0; i < getListSize(); i++)
	{
		if(at(i)->spriteData.getType() == sTypeParam)
		{
			return i; // Found an object matching the passed type, return its element id
		}
	}
	return -1; // Cannot find item passed
}

void ObjectManager::setDrawToAll(bool bValue)
{
	for(int i = 0; i < getListSize(); i++)
	{
		at(i)->objectData.setDraw(bValue);
	}
}

void ObjectManager::setTextureToType(string sTypeParam, int iValue)
{
	// Sets the object with the type passed's current texture to the integer passed
	for(int i = 0; i < getListSize(); i++)
	{
		if(at(i)->spriteData.getType() == sTypeParam)
		{
			at(i)->spriteData.setCurrentTextureFile(iValue); // Found an object matching the passed type, return its element id
			at(i)->spriteData.setSpriteTexture(*at(i));
		}
	}
}

int ObjectManager::containsPlayer(Entity &entity)
{
	int iCollidedObject = -1;

	for(int i = 0; i < getListSize(); i++)
	{
		// Check if Object contains the Player, is being drawn and doesn't allow collision
		if(at(i)->objectData.containsPlayer(at(i)->getGlobalBounds(), entity.getGlobalBounds(), entity.getPosition(), entity.getSize()) && at(i)->objectData.getDraw() && !at(i)->spriteData.getAllowCollision())
		{
			// Add to the collided objects vector
			// Multi-collision -- Object drawn on top will be returned
			iCollidedObject = i;
		}
	}
	return iCollidedObject;
}

void ObjectManager::resetTimerSize()
{
	int iElement = findElement("TimerTick");
	at(iElement)->setSize(Vector2f(178, at(iElement)->getSize().y));
}