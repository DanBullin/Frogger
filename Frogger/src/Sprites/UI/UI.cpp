#include ".\Sprites\UI\UI.h"

UI::UI(Vector2f fPosParam, string sTypeParam, int iClickActionParam)
{
	// Setting the properties of the UI
	// Generic Properties
	setPosition(fPosParam);
	spriteData.setType(sTypeParam);
	spriteData.setCurrentTextureFile(0);
	objectData.setDraw(false);
	spriteData.addTextureFile(2);
	spriteData.setAllowCollision(true);
	objectData.setCollisionAction(0);
	objectData.setClickAction(iClickActionParam);

	// UI specific properties
	// This function will create properities of UI of a type to be the same
	if(sTypeParam == "ButtonClose")
	{
		setProperties(Vector2f(16, 16), 2);
	}
	else if(sTypeParam == "ButtonReset")
	{
		setProperties(Vector2f(44, 18), 2);
	}
	else if(sTypeParam == "ButtonEasy")
	{
		setProperties(Vector2f(37, 21), 0);
		spriteData.setCurrentTextureFile(1);
	}
	else if(sTypeParam == "ButtonMedium")
	{
		setProperties(Vector2f(59, 18), 0);
	}
	else if(sTypeParam == "ButtonHard")
	{
		setProperties(Vector2f(38, 18), 0);
	}
	else if(sTypeParam == "ButtonYes")
	{
		setProperties(Vector2f(30, 18), 0);
	}
	else if(sTypeParam == "ButtonNo")
	{
		setProperties(Vector2f(25, 18), 0);
		spriteData.setCurrentTextureFile(1);
	}
	
	spriteData.setSpriteTexture(*this);
}

void UI::setProperties(Vector2f fSizeParam, int iHoverActionParam)
{
	setSize(fSizeParam);
	objectData.setHoverAction(iHoverActionParam);
}