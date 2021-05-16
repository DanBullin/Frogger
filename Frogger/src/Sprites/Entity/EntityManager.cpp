#include ".\Sprites\Entity\EntityManager.h"

EntityManager::EntityManager()
{

}

void EntityManager::loadEntities()
{
	// POSITION || TYPE (Parameters)

	// Bottom Lane
	push_back(new Entity(Vector2f(32, 320), "Car"));
	push_back(new Entity(Vector2f(224, 320), "Car"));
	push_back(new Entity(Vector2f(448, 320), "Car"));
	push_back(new Entity(Vector2f(544, 320), "Car"));
	push_back(new Entity(Vector2f(608, 320), "Car"));
	// Second from Bottom Lane
	push_back(new Entity(Vector2f(64, 288), "Lorry"));
	push_back(new Entity(Vector2f(288, 288), "Lorry"));
	push_back(new Entity(Vector2f(416, 288), "Lorry"));
	push_back(new Entity(Vector2f(576, 288), "Lorry"));
	push_back(new Entity(Vector2f(160, 288), "Lorry"));
	// Third from Bottom Lane
	push_back(new Entity(Vector2f(128, 256), "Car"));
	push_back(new Entity(Vector2f(256, 256), "Car"));
	push_back(new Entity(Vector2f(480, 256), "Car"));
	push_back(new Entity(Vector2f(320, 256), "Car"));
	push_back(new Entity(Vector2f(544, 256), "Car"));
	// Fourth from Bottom Lane
	push_back(new Entity(Vector2f(96, 224), "Lorry"));
	push_back(new Entity(Vector2f(352, 224), "Lorry"));
	push_back(new Entity(Vector2f(224, 224), "Lorry"));
	push_back(new Entity(Vector2f(448, 224), "Lorry"));
	push_back(new Entity(Vector2f(576, 224), "Lorry"));
	// Fifth from Bottom Lane
	push_back(new Entity(Vector2f(128, 160), "Log"));
	push_back(new Entity(Vector2f(320, 160), "Log"));
	// Sixth from Bottom Lane
	push_back(new Entity(Vector2f(64, 128), "Turtle"));
	push_back(new Entity(Vector2f(160, 128), "Turtle"));
	push_back(new Entity(Vector2f(320, 128), "Turtle"));
	push_back(new Entity(Vector2f(512, 128), "Turtle"));
	// Seventh from Bottom Lane
	push_back(new Entity(Vector2f(224, 96), "Log"));
	push_back(new Entity(Vector2f(480, 96), "Log"));
	// Eigth from Bottom Lane
	push_back(new Entity(Vector2f(128, 64), "Turtle"));
	push_back(new Entity(Vector2f(224, 64), "Turtle"));
	push_back(new Entity(Vector2f(288, 64), "Turtle"));
	push_back(new Entity(Vector2f(480, 64), "Turtle"));

	push_back(new Entity(Vector2f(288, 352), "Frog"));
}

int EntityManager::getListSize()
{
	int iSize = size();
	return iSize;
}

void EntityManager::setDrawToAll(bool bValue)
{
	for(int i = 0; i < getListSize(); i++)
	{
		at(i)->objectData.setDraw(bValue);
	}
}

int EntityManager::findElement(string sTypeParam)
{
	// Find the element id of an entity based on its type
	// Returns the first instance of the type
	for(int i = 0; i < getListSize(); i++)
	{
		if(at(i)->spriteData.getType() == sTypeParam)
		{
			return i; // Found an entity matching the passed type, return its element id
		}
	}
	return -1; // Cannot find item passed
}

int EntityManager::offScreen(Entity entity, int iWindowSizeX, int iWindowSizeY)
{
	// If the entity is off-screen, set its position to the other side of the window
	if(entity.getPosition().x >= iWindowSizeX && entity.getDirection() == 3)
	{
		return 1; // Off to the right
	}
	else if(entity.getPosition().x <= -(entity.getSize().x) && entity.getDirection() == 1)
	{
		return 2; // Off to the left
	}
	else if(entity.spriteData.getType() == "Frog" && entity.getPosition().x < -16)
	{
		return 2;
	}
	return 0;
}

int EntityManager::containsPlayer(Entity &entity)
{
	int iCollidedEntity = -1;

	// Check all entities except the player itself
	for(int i = 0; i < getListSize() - 1; i++)
	{
		// Check if Object contains the Player, is being drawn and doesn't allow collision
		if(at(i)->objectData.containsPlayer(at(i)->getGlobalBounds(), entity.getGlobalBounds(), entity.getPosition(), entity.getSize()) && at(i)->objectData.getDraw() && !at(i)->spriteData.getAllowCollision())
		{
			// Add to the collided objects vector
			// Multi-collision -- Object drawn on top will be returned
			iCollidedEntity = i;
		}
	}
	return iCollidedEntity;
}