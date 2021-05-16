#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <SFML\Graphics.hpp>
#include ".\Sprites\Object\ObjectManager.h"
#include ".\Sprites\Entity\EntityManager.h"
#include ".\Game\GameStats.h"

using namespace std;
using namespace sf;

/*
	This class creates a game timer which when it hits 0 will do an action
*/

class GameTimer
{
	private:
		Clock gameTimer;
		Time elapsedTime;
		int iTimeTick; // In seconds
	public:
		GameTimer();
		void update(GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager);
};

#endif