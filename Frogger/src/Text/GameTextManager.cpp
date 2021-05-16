#include ".\Text\GameTextManager.h"

GameTextManager::GameTextManager()
{

}

void GameTextManager::loadText()
{
	// TEXT || POSTION || CHARACTER SIZE || HOVER ACTION || CLICK ACTION (Parameters)

	push_back(new GameText("Frogger", Vector2f(215, 30), 48, 0, 0));
	push_back(new GameText("Play", Vector2f(281, 120), 24, 1, 2));
	push_back(new GameText("Leaderboard", Vector2f(235, 170), 24, 1, 3));
	push_back(new GameText("Settings", Vector2f(256, 220), 24, 1, 4));
	push_back(new GameText("Exit", Vector2f(280, 270), 24, 1, 6));
	push_back(new GameText("Daniel Bullin", Vector2f(2, 397), 16, 0, 0));
	push_back(new GameText("Version: 1.0", Vector2f(261, 397), 16, 0, 0));
	push_back(new GameText("P14132258", Vector2f(524, 397), 16, 0, 0));

	push_back(new GameText("Leaderboard", Vector2f(163, 30), 48, 0, 0));
	push_back(new GameText("Name", Vector2f(163, 100), 24, 0, 0));
	push_back(new GameText("Score", Vector2f(377, 100), 24, 0, 0));
	push_back(new GameText("1", Vector2f(130, 140), 16, 0, 0));
	push_back(new GameText("2", Vector2f(130, 190), 16, 0, 0));
	push_back(new GameText("3", Vector2f(130, 240), 16, 0, 0));
	push_back(new GameText("---", Vector2f(164, 140), 16, 0, 0));
	push_back(new GameText("---", Vector2f(164, 190), 16, 0, 0));
	push_back(new GameText("---", Vector2f(164, 240), 16, 0, 0));
	push_back(new GameText("---", Vector2f(378, 140), 16, 0, 0));
	push_back(new GameText("---", Vector2f(378, 190), 16, 0, 0));
	push_back(new GameText("---", Vector2f(378, 240), 16, 0, 0));

	push_back(new GameText("Difficulty", Vector2f(25, 35), 24, 0, 0));
	push_back(new GameText("Frog Base Change Position randomly", Vector2f(25, 110), 24, 0, 0));

	push_back(new GameText("Resume", Vector2f(263, 141), 24, 1, 2));
	push_back(new GameText("Quit", Vector2f(279, 241), 24, 1, 1));

	push_back(new GameText("Score: ", Vector2f(5, 6), 16, 0, 0));
}

void GameTextManager::loadWindowPos(int iWindowPosXParam, int iWindowPosYParam)
{
	iWindowPosX = iWindowPosXParam;
	iWindowPosY = iWindowPosYParam;
}

int GameTextManager::getListSize()
{
    int iSize = size();
	return iSize;
}

void GameTextManager::setDrawToAll(bool bValue)
{
	for(int i = 0; i < getListSize(); i++)
	{
		at(i)->objectData.setDraw(bValue);
	}
}

int GameTextManager::findElement(Vector2f fPosition)
{
	// Find the element id of an text based on its type & position
	// Returns the first instance of the type
	for(int i = 0; i < getListSize(); i++)
	{
		if(at(i)->getPosition() == fPosition)
		{
			return i; // Found game text matching the passed text and position, return its element id
		}
	}
	return -1; // Cannot find item passed
}

int GameTextManager::containsMouse()
{
	// Loop through each Text
	for(int i = 0; i < getListSize(); i++)
	{
		// If the mouse is inside one && there isn't an item currently hovered/selected
		if(at(i)->objectData.containsMouse(at(i)->getGlobalBounds(), iWindowPosX, iWindowPosY) && at(i)->objectData.getDraw())
		{
			return i;
		}
	}
	return -1;
}