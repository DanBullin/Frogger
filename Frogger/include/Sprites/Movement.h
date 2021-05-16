#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SFML\Graphics.hpp>
#include <string>
#include ".\Sprites\Entity\EntityManager.h"
#include ".\Sprites\Object\ObjectManager.h"
#include ".\Game\GameStats.h"
#include ".\Actions\CollisionAction.h"

using namespace std;
using namespace sf;

/*
	This class handles movement of Entities
*/

class Movement
{
	private:
		int iWindowSizeX;
		int iPlayerDistance;

		Clock movementClock;
		Time elapsedTime;

		int iMoveTick;

		CollisionAction collisionAction;
	public:
		Movement();
		void setProperties(int iWindowSizeXParam);
		void move(Entity &entity, int iDirection, int iDistance);

		void movePlayer(GameStats &gameStats, int iDirection, EntityManager &entityManager, ObjectManager &objectManager);
		void moveNPC(GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager);

		void goneOffEdge(GameStats &gameStats, EntityManager &entityManager, int iElement);

		void collision(GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager, int iElement);
};

#endif