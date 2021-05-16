#ifndef COLLISIONACTION_H
#define COLLISIONACTION_H

#include <SFML\Graphics.hpp>
#include ".\Game\GameStats.h"
#include ".\Sprites\Entity\EntityManager.h"
#include ".\Sprites\Object\ObjectManager.h"

using namespace std;
using namespace sf;

/*
	This class performs all the actions for objects that don't allow collision
	Integer:
	0 - Nothing
	1 - Take 1 life off Player
	2 - Ride Entity (Log)
	3 - Goal (Lilypad)
	4 - Impassible Object, don't move entity
*/

class CollisionAction
{
	private:
	public:
		CollisionAction();
		void performAction(GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager, int iManager, int iElement);
};

#endif