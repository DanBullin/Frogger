#include ".\Game\Turtlebehaviour.h"

TurtleBehaviour::TurtleBehaviour()
{
	iTick = 3;
	iState = 0; // The state of the Turtle
}

void TurtleBehaviour::change(EntityManager &entityManager)
{
	elapsedTime = turtleClock.getElapsedTime();

	if(elapsedTime.asSeconds() >= iTick)
	{
		turtleClock.restart();
		for(int i = 0; i < entityManager.getListSize(); i++)
		{
			if(entityManager[i]->spriteData.getType() == "Turtle")
			{
				if(iState == 0)
				{
					entityManager[i]->spriteData.setCurrentTextureFile(1);
					entityManager[i]->spriteData.setSpriteTexture(*entityManager[i]);
				}
				else if(iState == 1)
				{
					entityManager[i]->objectData.setDraw(false);
				}
				else if(iState == 2)
				{
					entityManager[i]->objectData.setDraw(true);
				}
				else if(iState == 3)
				{
					entityManager[i]->spriteData.setCurrentTextureFile(0);
					entityManager[i]->spriteData.setSpriteTexture(*entityManager[i]);
				}
			}
		}

		if(iState == 3)
		{
			iState = 0;
		}
		else
		{
			iState++;
		}
	}
}