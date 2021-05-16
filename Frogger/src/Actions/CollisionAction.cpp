#include ".\Actions\CollisionAction.h"

CollisionAction::CollisionAction()
{
}

void CollisionAction::performAction(GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager, int iManager, int iElement)
{
	if(iManager == 0)
	{
		// Collided with Object
		if(objectManager[iElement]->objectData.getCollisionAction() == 1)
		{
			gameStats.setLives(gameStats.getLives() - 1);
			gameStats.resetFrog();
		}
		else if(objectManager[iElement]->objectData.getCollisionAction() == 3)
		{
			// GOALLLL
			// Check if goal isn't object already captured
			if(objectManager[iElement]->spriteData.getCurrentTextureFile() == 0)
			{
				objectManager[iElement]->spriteData.setCurrentTextureFile(1);
				objectManager[iElement]->spriteData.setSpriteTexture(*objectManager[iElement]);
				gameStats.capturedBase();
			}
			
		}
		else if(objectManager[iElement]->objectData.getCollisionAction() == 4)
		{
			// Move Player back to position before it had moved (Since incollided objects are only above/below the player (Info))
			int iPlayerElement = entityManager.findElement("Frog");
			if(entityManager[iPlayerElement]->getDirection() == 0)
			{
				entityManager[iPlayerElement]->setPosition(Vector2f(entityManager[iPlayerElement]->getPosition().x, entityManager[iPlayerElement]->getPosition().y + 32));
			}
			else if(entityManager[iPlayerElement]->getDirection() == 2)
			{
				entityManager[iPlayerElement]->setPosition(Vector2f(entityManager[iPlayerElement]->getPosition().x, entityManager[iPlayerElement]->getPosition().y - 32));
			}
		}
	}
	else if(iManager == 1)
	{
		// Collided with Entity
		if(entityManager[iElement]->objectData.getCollisionAction() == 1)
		{
			gameStats.setLives(gameStats.getLives() - 1);
			gameStats.resetFrog();
		}
		else if(entityManager[iElement]->objectData.getCollisionAction() == 2)
		{
			// Ride the Entity
			int iPlayerElement = entityManager.findElement("Frog");
			gameStats.setRidingEntity(true);
			entityManager[iPlayerElement]->setDirection(entityManager[iElement]->getDirection());
			entityManager[iPlayerElement]->setSpeed(entityManager[iElement]->getSpeed());
		}
	}
}