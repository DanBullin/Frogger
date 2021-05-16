#include ".\Actions\HoverAction.h"

HoverAction::HoverAction()
{
	iTextSelectedItem = -1;
	iUISelectedItem = -1;
	iSizeIncrease = 2;
}

bool HoverAction::TextContainsMouse(GameTextManager &gameTextManager)
{
	// Loop through each Text
	int iElement = gameTextManager.containsMouse();

	if(iElement != -1 && iTextSelectedItem == -1)
	{
		// If there is some text being hovered over && there isn't currently a selected item, select it
		iTextSelectedItem = iElement;
		// Store the current settings so we can use them to reset it later when mouse leaves object
		iOriginalSize = gameTextManager[iElement]->getCharacterSize();
		iOriginalColour = gameTextManager[iElement]->getColour();
		TextPerformAction(*gameTextManager[iElement], false);
		return true;
	}
	else if(iElement == -1 && iTextSelectedItem != iElement)
	{
		// Else, if the item doesn't contain the mouse BUT an item is selected - meaning the mouse should be over an item but isn't - reset the selected item to its original settings
		TextPerformAction(*gameTextManager[iTextSelectedItem], true);
		iTextSelectedItem = -1;
		return true;
	}
	return false;
}

void HoverAction::UIContainsMouse(UIManager &uiManager)
{
	// Loop through each Text
	int iElement = uiManager.containsMouse();

	if(iElement != -1 && iUISelectedItem == -1)
	{
		// Set the selected item and perform its hover action
		iUISelectedItem = iElement;
		UIPerformAction(*uiManager[iElement], false);
	}
	else if(iElement == -1 && iUISelectedItem != iElement)
	{
		// Else, if the item doesn't contain the mouse BUT an item is selected - meaning the mouse should be over an item but isn't - reset the selected item
		UIPerformAction(*uiManager[iUISelectedItem], true);
		iUISelectedItem = -1;	
	}
}

void HoverAction::TextPerformAction(GameText &gameText, bool bReset)
{
	// If the object has a hover action of '1'
	if(gameText.objectData.getHoverAction() == 1 && iTextSelectedItem != -1)
	{
		// Grow & Change Colour
		gameText.setCharacterSize(gameText.getCharacterSize() + iSizeIncrease);
		gameText.setFillColor(sf::Color::White);
		gameText.setFillColor(gameText.TextColour[gameText.getColour()]);
	}

	// If the item needs to be reset
	if(bReset && gameText.objectData.getHoverAction() == 1)
	{
		// Revert back to state before the mouse entered the item
		gameText.setCharacterSize(iOriginalSize);
		gameText.setFillColor(sf::Color::White);
		gameText.setFillColor(gameText.TextColour[gameText.getColour()]);
	}
}

void HoverAction::UIPerformAction(UI &ui, bool bReset)
{
	// If the UI has an hover action of 2 and an item is selected
	if(ui.objectData.getHoverAction() == 2 && iUISelectedItem != -1)
	{
		ui.spriteData.setCurrentTextureFile(1);
		ui.spriteData.setSpriteTexture(ui);
	}

	if(bReset && ui.objectData.getHoverAction() == 2)
	{
		ui.spriteData.setCurrentTextureFile(0);
		ui.spriteData.setSpriteTexture(ui);
	}
}