#include ".\Actions\ClickAction.h"

ClickAction::ClickAction()
{
	
}

bool ClickAction::TextContainsMouse(GameStats &gameStats, GameTextManager &gameTextManager, ObjectManager &objectManager)
{
	// Loop through each Text & if it contains the mouse, perform its click action
	int iElement = gameTextManager.containsMouse();

	if(iElement != -1)
	{
		TextPerformAction(gameStats, *gameTextManager[iElement], gameTextManager, objectManager);
		return true;
	}
	return false;
}

void ClickAction::UIContainsMouse(GameStats &gameStats, UIManager &uiManager)
{
	// Loop through each UI & if it contains the mouse, perform its click action
	int iElement = uiManager.containsMouse();

	if(iElement != -1)
	{
		UIPerformAction(gameStats, *uiManager[iElement], uiManager);
	}
}

void ClickAction::TextPerformAction(GameStats &gameStats, GameText &gameText, GameTextManager &gameTextManager, ObjectManager &objectManager)
{
	if(gameText.objectData.getClickAction() == 1)
	{
		gameStats.setGameScene(0);
	}
	else if(gameText.objectData.getClickAction() == 2)
	{
		gameStats.setGameScene(1);
		// Reset Timer size if the text being clicked on = "Play" as we dont want to reset timer if they click Resume
		if(gameText.getString() == "Play")
		{
			objectManager.resetTimerSize();
			gameStats.setLives(gameStats.getDifficulty());
			gameStats.resetFrog();
			gameStats.resetBase(); // Reset Bases
		}
	}
	else if(gameText.objectData.getClickAction() == 3)
	{
		gameStats.setGameScene(2);

		string sFileLine;
		int iElement = gameTextManager.findElement(Vector2f(164, 140));
		fileIO.openFile(".\\leaderboard\\leaderboard.txt", 0);
		while(fileIO.readLine(sFileLine))
		{
			gameTextManager[iElement]->setString(stringManip.getParameter(sFileLine, 1));
			gameTextManager[iElement + 3]->setString(stringManip.getParameter(sFileLine, 2));
			iElement++;
		}

	}
	else if(gameText.objectData.getClickAction() == 4)
	{
		gameStats.setGameScene(3);
	}
	else if(gameText.objectData.getClickAction() == 5)
	{
		gameStats.setGameScene(4);
	}
	else if(gameText.objectData.getClickAction() == 6)
	{
		gameStats.setGameEnd(true);
	}
}

void ClickAction::UIPerformAction(GameStats &gameStats, UI &ui, UIManager &uiManager)
{
	if(ui.objectData.getClickAction() == 1)
	{
		// Close Button
		gameStats.setGameScene(0);
	}
	else if(ui.objectData.getClickAction() == 7)
	{
		// Reset Leaderboard
		vector<string> sResetNames(3);
		vector<string> sResetScores(3);
		for(int i = 0; i < 3; i++)
		{
			sResetNames[i] = "---";
			sResetScores[i] = "---";
		}

		fileIO.openFile(".\\leaderboard\\leaderboard.txt", 1);
		fileIO.writeLine(sResetNames, sResetScores);
	}
	else if(ui.objectData.getClickAction() == 8)
	{
		// Easy Button
		gameStats.setDifficulty(3);
		setButtonsTexture(uiManager, 0);
		ui.spriteData.setCurrentTextureFile(1);
		ui.spriteData.setSpriteTexture(ui);
	}
	else if(ui.objectData.getClickAction() == 9)
	{
		// Medium Button
		gameStats.setDifficulty(2);
		setButtonsTexture(uiManager, 0);
		ui.spriteData.setCurrentTextureFile(1);
		ui.spriteData.setSpriteTexture(ui);
	}
	else if(ui.objectData.getClickAction() == 10)
	{
		// Hard Button
		gameStats.setDifficulty(1);
		setButtonsTexture(uiManager, 0);
		ui.spriteData.setCurrentTextureFile(1);
		ui.spriteData.setSpriteTexture(ui);
	}
	else if(ui.objectData.getClickAction() == 11)
	{
		// Yes Button
		gameStats.setFrogBaseChange(true);
		setButtonsTexture(uiManager, 1);
		ui.spriteData.setCurrentTextureFile(1);
		ui.spriteData.setSpriteTexture(ui);
	}
	else if(ui.objectData.getClickAction() == 12)
	{
		// No Button
		gameStats.setFrogBaseChange(false);
		setButtonsTexture(uiManager, 1);
		ui.spriteData.setCurrentTextureFile(1);
		ui.spriteData.setSpriteTexture(ui);
	}
}

void ClickAction::setButtonsTexture(UIManager &uiManager, int iSetting)
{
	// Sets all the buttons for one setting type to 0 (non-highlight)
	if(iSetting == 0)
	{
		// Changing Difficulty
		int iElement = uiManager.findElement("ButtonEasy");
		for(int i = iElement; i < iElement + 3; i++)
		{
			uiManager.at(i)->spriteData.setCurrentTextureFile(0);
			uiManager.at(i)->spriteData.setSpriteTexture(*uiManager[i]);
		} 
	}
	else if(iSetting == 1)
	{
		// Changing Frog Base change
		int iElement = uiManager.findElement("ButtonYes");
		for(int i = iElement; i < iElement + 2; i++)
		{
			uiManager.at(i)->spriteData.setCurrentTextureFile(0);
			uiManager.at(i)->spriteData.setSpriteTexture(*uiManager[i]);
		} 
	}
}