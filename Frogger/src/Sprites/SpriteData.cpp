#include ".\Sprites\SpriteData.h"

SpriteData::SpriteData()
{

}

#pragma region Get Functions

string SpriteData::getType()
{
	return sType;
}

bool SpriteData::getAllowCollision()
{
	return bAllowCollision;
}

int SpriteData::getCurrentTextureFile()
{
	return iCurrentTextureFile;
}

#pragma endregion

#pragma region Set Functions

void SpriteData::setType(string sValue)
{
	sType = sValue;
}

void SpriteData::setAllowCollision(bool bValue)
{
	bAllowCollision = bValue;
}

void SpriteData::setSpriteTexture(RectangleShape &spriteObject)
{
	if(!texture.loadFromFile(".\\texture\\" + sTextureFiles[getCurrentTextureFile()]))
	{
		// Can't load the texture - file is probably in the wrong location or wrong name
		// Automatically prints error to console
	}
	else
	{
		// Texture loaded - now lets set it
		spriteObject.setTexture(&texture);
	}
}

void SpriteData::addTextureFile(int iTextureFiles)
{
	for(int i = 0; i < iTextureFiles; i++)
	{
		sTextureFiles.push_back(getType() + to_string(i) + ".png");
	}
	
}

void SpriteData::setCurrentTextureFile(int iValue)
{
	iCurrentTextureFile = iValue;
}

#pragma endregion
