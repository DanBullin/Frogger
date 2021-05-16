#include ".\Text\GameText.h"

GameText::GameText(string sTextParam, Vector2f fPosParam, int iCharacterSizeParam, int iHoverActionParam, int iClickActionParam)
{
	TextColour[0] = Color::White;
	TextColour[1] = Color::Yellow;

	setString(sTextParam);
	setPosition(fPosParam);
	setCharacterSize(iCharacterSizeParam);
	setFillColor(TextColour[0]);
	setGameTextFont("comic");
	objectData.setCollisionAction(0);
	objectData.setHoverAction(iHoverActionParam);
	objectData.setClickAction(iClickActionParam);
	setColour(0);
}

void GameText::setGameTextFont(string sFontFile)
{
	if (!font.loadFromFile(".\\font\\" + sFontFile + ".ttf"))
	{
		// Automatically prints error message to console
	}
	else
	{
		setFont(font);
	}
}

int GameText::getColour()
{
	return iCurrentColour;
}

void GameText::setColour(int iValue)
{
	iCurrentColour = iValue;
}