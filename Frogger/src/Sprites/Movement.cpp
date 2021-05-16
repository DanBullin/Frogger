#include ".\Sprites\Movement.h"

Movement::Movement()
{
	iMoveTick = 1;
	iPlayerDistance = 32;
}

void Movement::setProperties(int iWindowSizeXParam)
{
	iWindowSizeX = iWindowSizeXParam;
}

void Movement::move(Entity &entity, int iDirection, int iDistance)
{
	if(iDirection == 0)
	{
		entity.move(0.f, -iDistance);
	}
	else if(iDirection == 1)
	{
		entity.move(-iDistance, 0.f);
	}
	else if(iDirection == 2)
	{
		entity.move(0.f, iDistance);
	}
	else if(iDirection == 3)
	{
		entity.move(iDistance, 0.f);
	}
}

void Movement::movePlayer(GameStats &gameStats, int iDirection, EntityManager &entityManager, ObjectManager &objectManager)
{
	int iElement = entityManager.findElement("Frog");
	entityManager[iElement]->setDirection(iDirection);
	move(*entityManager[iElement], entityManager[iElement]->getDirection(), iPlayerDistance);
	goneOffEdge(gameStats, entityManager, iElement);
	collision(gameStats, entityManager, objectManager, iElement);
}

void Movement::moveNPC(GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager)
{
	int iSize = entityManager.getListSize();
	elapsedTime = movementClock.getElapsedTime();

	// Check if Player is riding an entity
	if(!gameStats.getRidingEntity())
	{
		iSize--;
	}

	if(elapsedTime.asMilliseconds() >= iMoveTick)
	{
		movementClock.restart();

		for(int i = 0; i < iSize; i++)
		{
			move(*entityManager[i], entityManager[i]->getDirection(), entityManager[i]->getSpeed());
			goneOffEdge(gameStats, entityManager, i);
			collision(gameStats, entityManager, objectManager, entityManager.findElement("Frog"));
		}
	}
}

void Movement::goneOffEdge(GameStats &gameStats, EntityManager &entityManager, int iElement)
{
	// If the entity is off-screen, set its position to the other side of the window
	int iResult = entityManager.offScreen(*entityManager[iElement], 608, 416);

	if(iResult == 1 || iResult == 2)
	{
		// Entity is off-screen, check what type of entity
		if(entityManager.at(iElement)->spriteData.getType() == "Frog")
		{
			gameStats.setLives(gameStats.getLives() - 1);
			gameStats.resetFrog();
		}
		else if(iResult == 1)
		{
			entityManager.at(iElement)->setPosition(Vector2f(-entityManager.at(iElement)->getSize().x, entityManager.at(iElement)->getPosition().y));
		}
		else if(iResult == 2)
		{
			entityManager.at(iElement)->setPosition(Vector2f(iWindowSizeX, entityManager.at(iElement)->getPosition().y));
		}
	}
}

void Movement::collision(GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager, int iElement)
{
	int iCollidedEntity = entityManager.containsPlayer(*entityManager[iElement]);
	
	if(iCollidedEntity == -1)
	{
		// Not collided with Entity -> check if collided with object
		// Loop through each Object and check for Collisions
		// Returns what object we're colliding with
		// Multile-collision is handled by returning the top-most(z-order) object we're colliding with
		gameStats.setRidingEntity(false); // Player cannot be riding an entity anymore
		int iCollidedObject = objectManager.containsPlayer(*entityManager[iElement]);
		if(iCollidedObject != -1)
		{
			collisionAction.performAction(gameStats, entityManager, objectManager, 0, iCollidedObject);		
		}
	}
	else
	{
		collisionAction.performAction(gameStats, entityManager, objectManager, 1, iCollidedEntity);		
	}
}