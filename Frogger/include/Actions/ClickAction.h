#ifndef CLICKACTION_H
#define CLICKACTION_H

#include <SFML\Graphics.hpp>
#include ".\Text\GameTextManager.h"
#include ".\Sprites\Object\ObjectManager.h"
#include ".\Sprites\UI\UIManager.h"
#include ".\System\FileIO.h"
#include ".\System\StringManip.h"
#include ".\Game\GameStats.h"
#include <iostream>

using namespace std;
using namespace sf;

/*
	This class performs all the actions for items that have a click action
	Integer:
	0 - Nothing
	1 - Load Main Menu
	2 - Load Game Level
	3 - Load Leaderboard
	4 - Load Settings
	5 - Load Pause
	6 - Close Window
	7 - Reset Leaderboard
	8 - Load Easy
	9 - Load Medium
	10 - Load Hard
	11 - Load Yes
	12 - Load No
*/

class ClickAction
{
	private:
		FileIO fileIO;
		StringManip stringManip;

	public:
		ClickAction();

		bool TextContainsMouse(GameStats &gameStats, GameTextManager &gameTextManager, ObjectManager &objectManager);
		void UIContainsMouse(GameStats &gameStats, UIManager &uiManager);
		void TextPerformAction(GameStats &gameStats, GameText &gameText, GameTextManager &gameTextManager, ObjectManager &objectManager);
		void UIPerformAction(GameStats &gameStats, UI &ui, UIManager &uiManager);
		void setButtonsTexture(UIManager &uiManager, int iSetting);

};

#endif