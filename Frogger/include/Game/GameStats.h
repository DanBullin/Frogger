#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include ".\Sprites\Entity\EntityManager.h"
#include ".\Sprites\Object\ObjectManager.h"
#include ".\Sprites\UI\UIManager.h"
#include ".\Text\GameTextManager.h"
#include ".\Sprites\Overlay\Overlay.h"
#include ".\Drawing\Scenes.h"
#include ".\Drawing\UpdateObjects.h"
#include ".\System\FileIO.h"
#include ".\System\StringManip.h"

using namespace std;
using namespace sf;

/*
	This class stores and handles all the Game variables (Life, Difficulty, etc)
*/

class GameStats
{
	private:
		int iGameScene;
		int iInitialLives;
		int iLives;
		int iScore;
		int iDifficulty;
		bool bFrogBaseChange;
		bool bGameEnd;
		bool bRidingEntity;

		vector<string> sLeaderboardName;
		vector<string> sLeaderboardScore;

		FileIO fileIO;
		StringManip stringManip;

		EntityManager * entityManager;
		ObjectManager * objectManager;
		UIManager * uiManager;
		GameTextManager * gameTextManager;
		Overlay * gameOverlay;
		Scenes * scenes;
		UpdateObjects * updateObjects;
	public:
		GameStats();

		void setProperties(EntityManager &entityManagerParam, ObjectManager &objectManagerParam, UIManager &uiManagerParam, GameTextManager &gameTextManagerParam, Overlay &gameOverlayParam, Scenes &scenesParam, UpdateObjects &updateObjectsParam);

		int getGameScene();
		int getInitialLives();
		int getLives(); // Returns the current amount of Lives of the Player
		int getDifficulty(); // Return the difficulty of the game (1 - Hard, 2 - Medium, 3 - Easy)
		bool getFrogBaseChange(); // Returns whether the frog base changes positions
		bool getGameEnd();
		int getScore();
		bool getRidingEntity();

		void setGameScene(int iValue); // Set the current Game Scene, updates objects automatically
		void setLives(int iValue); // Set the current Player's lives;
		void setDifficulty(int iValue); // Set the difficulty
		void setFrogBaseChange(bool bValue); // Set whether the frog base changes positions
		void setGameEnd(bool bValue);
		void setScore(int iValue);
		void setRidingEntity(bool bValue);

		void resetFrog(); // Sends Player back to original location
		void resetBase();
		void capturedBase(); // Player collides with Goal object

		void newScore();
};

#endif