#ifndef LILYPADBEHAVIOUR_H
#define LILYPADBEHAVIOUR_H

#include ".\Game\GameStats.h"
#include ".\Sprites\Object\ObjectManager.h"
#include <stdlib.h>
#include <time.h> 

using namespace std;

/*
	This class handles the Lilypad changing position behaviour (Not really, just change their draw bool)
*/

class LilypadBehaviour
{
	private:
		Clock LilypadClock;
		Time elapsedTime;
		int iTick;
		int iState;
	public:
		LilypadBehaviour();
		void change(GameStats &gameStats, ObjectManager &objectManager);
};

#endif