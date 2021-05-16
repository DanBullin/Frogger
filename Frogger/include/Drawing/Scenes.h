#ifndef SCENES_H
#define SCENES_H

#include <vector>
#include <string>
#include ".\Sprites\Entity\EntityManager.h"
#include ".\Sprites\Object\ObjectManager.h"

using namespace std;

/*
	This class contains vectors which describe which objects should be drawn on which scene
	0 - Main Menu
	1 - Game Level
	2 - Leaderboard
	3 - Settings
	4 - Pause
	5 - All

	All object strings are stored in the vectors in the Scenes constructor
	The objects draw variable is set inside the UpdateObjects file which uses these vectors
*/

class Scenes
{
	private:
	public:
		Scenes();

		vector<string> sGameScene0;
		vector<string> sGameScene1;
		vector<string> sGameScene2;
		vector<string> sGameScene3;
		vector<string> sGameScene4;
		vector<string> sGameScene5;

		void load(EntityManager &entityManager, ObjectManager &objectManager, int iLives);
};

#endif