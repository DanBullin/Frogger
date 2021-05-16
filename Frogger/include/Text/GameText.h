#ifndef GAMETEXT_H
#define GAMETEXT_H

#include <SFML\Graphics.hpp>
#include <string>
#include ".\ObjectData.h"

using namespace std;
using namespace sf;

/*
	This class generates GameText
*/

class GameText : public Text
{
	private:
		Font font; // The font of the text
		int iCurrentColour; // The current colour of the text -- the Element of TextColour
	public:
		GameText(string sTextParam, Vector2f fPosParam, int iCharacterSizeParam, int iHoverActionParam, int iClickActionParam);
		ObjectData objectData;
		Color TextColour[2]; // The varying colours the text can be
		void setGameTextFont(string sFontName);

		int getColour();
		void setColour(int iValue);
};

#endif