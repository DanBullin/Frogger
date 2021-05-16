#include ".\Sprites\UI\UIManager.h"

UIManager::UIManager()
{

}

void UIManager::loadUI()
{
	// POSITION || TYPE || CLICK ACTION (Parameter)
	push_back(new UI(Vector2f(580, 8), "ButtonClose", 1));
	push_back(new UI(Vector2f(550, 390), "ButtonReset", 7));
	push_back(new UI(Vector2f(25, 72), "ButtonEasy", 8));
	push_back(new UI(Vector2f(67, 73), "ButtonMedium", 9));
	push_back(new UI(Vector2f(131, 73), "ButtonHard", 10));
	push_back(new UI(Vector2f(25, 147), "ButtonYes", 11));
	push_back(new UI(Vector2f(60, 147), "ButtonNo", 12));
	push_back(new UI(Vector2f(580, 8), "ButtonClose", 1));
}

void UIManager::loadWindowPos(int iWindowPosXParam, int iWindowPosYParam)
{
	iWindowPosX = iWindowPosXParam;
	iWindowPosY = iWindowPosYParam;
}

int UIManager::getListSize()
{
	int iSize = size();
	return iSize;
}

void UIManager::setDrawToAll(bool bValue)
{
	for(int i = 0; i < getListSize(); i++)
	{
		at(i)->objectData.setDraw(bValue);
	}
}

int UIManager::findElement(string sTypeParam)
{
	// Find the element id of an UI based on its type
	// Returns the first instance of the type
	for(int i = 0; i < getListSize(); i++)
	{
		if(at(i)->spriteData.getType() == sTypeParam)
		{
			return i; // Found an UI matching the passed type, return its element id
		}
	}
	return -1; // Cannot find item passed
}

int UIManager::containsMouse()
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