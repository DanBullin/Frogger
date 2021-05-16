#include ".\GameTimer.h"

GameTimer::GameTimer()
{
	iTimeTick = 1;
}

void GameTimer::update(GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager)
{
	int iElement = objectManager.findElement("TimerTick");

	elapsedTime = gameTimer.getElapsedTime();
	if(elapsedTime.asSeconds() >= iTimeTick)
	{
		// Start a clock, if the clock's elapsed time is above the timer tick
		gameTimer.restart();

		// Reduce the timer tick size by a const
		objectManager[iElement]->setSize(Vector2f(objectManager[iElement]->getSize().x - 4, objectManager[iElement]->getSize().y));

		// If the size if less than 0, reduce life and reset
		if(objectManager[iElement]->getSize().x < 0)
		{
			gameStats.setLives(gameStats.getLives() - 1);
			gameStats.resetFrog();
			objectManager.resetTimerSize();
		}
	}
}