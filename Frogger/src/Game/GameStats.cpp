#include ".\Game\GameStats.h"

GameStats::GameStats()
{
	iInitialLives = 3;
	iLives = iInitialLives;
	iScore = 0;
	iDifficulty = 3;
	bFrogBaseChange = false;
	iGameScene = 0;
	bGameEnd = false;
	bRidingEntity = false;
}

void GameStats::setProperties(EntityManager &entityManagerParam, ObjectManager &objectManagerParam, UIManager &uiManagerParam, GameTextManager &gameTextManagerParam, Overlay &gameOverlayParam, Scenes &scenesParam, UpdateObjects &updateObjectsParam)
{
	entityManager = &entityManagerParam;
	objectManager = &objectManagerParam;
	uiManager = &uiManagerParam;
	gameTextManager = &gameTextManagerParam;
	gameOverlay = &gameOverlayParam;
	scenes = &scenesParam;
	updateObjects = &updateObjectsParam;
}

int GameStats::getGameScene()
{
	return iGameScene;
}

int GameStats::getInitialLives()
{
	return iInitialLives;
}

int GameStats::getLives()
{
	return iLives;
}

int GameStats::getDifficulty()
{
	return iDifficulty;
}

bool GameStats::getFrogBaseChange()
{
	return bFrogBaseChange;
}

bool GameStats::getGameEnd()
{
	return bGameEnd;
}

int GameStats::getScore()
{
	return iScore;
}

bool GameStats::getRidingEntity()
{
	return bRidingEntity;
}

void GameStats::setGameScene(int iValue)
{
	// The Game Scene has been changed, update all the object's draw variables
	iGameScene = iValue;
	updateObjects->update(iGameScene, *scenes, *entityManager, *objectManager, *uiManager, *gameTextManager, *gameOverlay);

	if(iGameScene == 1)
	{
		// Play/Resume has been clicked
		//setLives(getLives());
	}
}

void GameStats::setLives(int iValue)
{
	iLives = iValue;

	int iStartingElement = objectManager->findElement("Life"); // Get the first instance element id of a Life object
	objectManager->resetTimerSize();
	// Now lets update the texture of the Lives object

	// Set all Life objects to the texture of a heart with red cross
	objectManager->setTextureToType("Life", 1);
	// Loop through the Life's from the start by the amount of Lives, setting the texture of the Lives object to a heart
	for(int i = iStartingElement; i < iStartingElement + iLives; i++)
	{	
		objectManager->at(i)->spriteData.setCurrentTextureFile(0);
		objectManager->at(i)->spriteData.setSpriteTexture(*objectManager->at(i));
	}

	// END GAME - Player has used all their lives
	if(iLives == 0)
	{
		setGameScene(0); // Go to Main Menu
		newScore(); // Checks if its a top 3 score and set it if it is -- Player name is received through console input due to time restrictions
		setScore(0); // Reset Score to 0
	}
}

void GameStats::setDifficulty(int iValue)
{
	iDifficulty = iValue;

	// Set Lives
	setLives(iDifficulty);
}

void GameStats::setFrogBaseChange(bool bValue)
{
	bFrogBaseChange = bValue;
}

void GameStats::setGameEnd(bool bValue)
{
	bGameEnd = bValue; // Game Loop condition
}

void GameStats::setScore(int iValue)
{
	iScore = iValue;
	// Update Score text since the score has changed
	int iElement = gameTextManager->findElement(Vector2f(5, 6));
	gameTextManager->at(iElement)->setString("Score: " + to_string(iScore));
}

void GameStats::setRidingEntity(bool bValue)
{
	bRidingEntity = bValue;
}

void GameStats::resetFrog()
{
	int iElement = entityManager->findElement("Frog");
	entityManager->at(iElement)->setPosition(Vector2f(288, 352));
	entityManager->at(iElement)->spriteData.setCurrentTextureFile(0);
	entityManager->at(iElement)->spriteData.setSpriteTexture(*entityManager->at(iElement));
}

void GameStats::resetBase()
{
	for(int i = 0; i < objectManager->getListSize(); i++)
	{
		if(objectManager->at(i)->spriteData.getType() == "Lilypad")
		{
			objectManager->at(i)->spriteData.setCurrentTextureFile(0);
			objectManager->at(i)->spriteData.setSpriteTexture(*objectManager->at(i));
		}
	}
}

void GameStats::capturedBase()
{
	int iCounter = 0;
	resetFrog();
	objectManager->resetTimerSize();
	setScore(getScore() + 20);

	// Check if all Bases have been captured, if so, reset them to emulate more levels
	for(int i = 0; i < objectManager->getListSize(); i++)
	{
		if(objectManager->at(i)->spriteData.getCurrentTextureFile() == 0 && objectManager->at(i)->spriteData.getType() == "Lilypad")
		{
			iCounter++;
		}
	}

	if(iCounter == 0)
	{
		resetBase();
	}
}

void GameStats::newScore()
{
	// Check if it's within the top 3
	string sFileLine;
	fileIO.openFile(".\\leaderboard\\leaderboard.txt", 0);
	sLeaderboardName.clear();
	sLeaderboardScore.clear();
	// Get all current leaderboard scores
	while(fileIO.readLine(sFileLine))
	{
		sLeaderboardName.push_back(stringManip.getParameter(sFileLine, 1));
		sLeaderboardScore.push_back(stringManip.getParameter(sFileLine, 2));
	}

	int iSize = sLeaderboardScore.size();
	int iScorePlace = -1;
	bool bNewScore = false;
	int i = 0;
	// Check if current score is higher
	while(!bNewScore)
	{
		if(sLeaderboardScore[i] == "---")
		{
			iScorePlace = i;
			bNewScore = true;
		}
		else if(getScore() >= stoi(sLeaderboardScore[i]))
		{
			iScorePlace = i;
			bNewScore = true;
		}
		i++;
		if(i == 3)
		{
			bNewScore = true;
		}
	}

	if(iScorePlace != -1)
	{
		for(int i = 2; i > iScorePlace - 1; i--)
		{
			if(i == iScorePlace)
			{
				sLeaderboardScore[i] = to_string(getScore());
				string sName;
				cout << "========================================" << endl << "New Leaderboard Score!" << endl << endl << "Name: ";
				getline(cin, sName);
				sLeaderboardName[i] = sName;
			}
			else
			{
				sLeaderboardScore[i] = sLeaderboardScore[i - 1];
				sLeaderboardName[i] = sLeaderboardName[i - 1];
			}	
		}
		fileIO.openFile(".\\leaderboard\\leaderboard.txt", 1);
		fileIO.writeLine(sLeaderboardName, sLeaderboardScore);
	}
}