#ifndef HOVERACTION_H
#define HOVERACTION_H

#include <SFML\Graphics.hpp>
#include ".\Sprites\UI\UIManager.h"
#include ".\Text\GameTextManager.h"
#include <iostream>

using namespace std;
using namespace sf;

/*
	This class performs all the actions for items that have a hover action
	Integer:
	0 - Nothing
	1 - Grow in Character Size by 2 & Change text to Yellow
	2 - Highlight object by switching to next texture in their texture vector
*/

class HoverAction
{
	private:
		int iTextSelectedItem; // This variable tells us whether text is currently selected (-1 is there isn't)
		int iUISelectedItem; // This variable tells us whether UI is currently selected (-1 is there isn't)
		int iSizeIncrease; // Action 1 grows the text, this variable dictates by how much
		int iOriginalColour; // Used to revert item back to original colour when the mouse leaves
		int iOriginalSize; // Used to revert item back to original size when mouse leaves
	public:
		HoverAction();
		bool TextContainsMouse(GameTextManager &gameTextManager);
		void UIContainsMouse(UIManager &uiManager);
		void TextPerformAction(GameText &gameText, bool bReset);
		void UIPerformAction(UI &ui, bool bReset);
};

#endif