#include ".\Game\Lilypadbehaviour.h"

LilypadBehaviour::LilypadBehaviour()
{
	iTick = 10;
}

void LilypadBehaviour::change(GameStats &gameStats, ObjectManager &objectManager)
{
	elapsedTime = LilypadClock.getElapsedTime();
	bool bValidLilypad = false;
	int iFirstLilypad = objectManager.findElement("Lilypad");
	int iIndex;

	if(elapsedTime.asSeconds() >= iTick && gameStats.getFrogBaseChange())
	{
		LilypadClock.restart();
		srand (time(NULL));

		for(int i = 0; i < objectManager.getListSize(); i++)
		{
			if(objectManager[i]->spriteData.getType() == "Lilypad" && objectManager[i]->spriteData.getCurrentTextureFile() == 0)
			{
				objectManager[i]->objectData.setDraw(false);
			}
		}

		// Randomly pick a lilypad that hasn't been captured
		while(!bValidLilypad)
		{
			iIndex = rand() % 5;
			if(objectManager[iFirstLilypad + iIndex]->spriteData.getCurrentTextureFile() == 0)
			{
				bValidLilypad = true;
			}
		}

		objectManager[iFirstLilypad + iIndex]->objectData.setDraw(true);
	}
}