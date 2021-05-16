#ifndef GAMETEXTMANAGER_H
#define GAMETEXTMANAGER_H

#include <SFML\Graphics.hpp>
#include ".\Text\GameText.h"

using namespace std;
using namespace sf;

/*
	This class generates a vector contain GameText objects
*/

class GameTextManager : public vector<GameText*>
{
	private:
		int iWindowPosX;
		int iWindowPosY;
	public:
		GameTextManager();
		void loadWindowPos(int iWindowPosXParam, int iWindowPosYParam);
		void loadText(); // Load all text
		/*
			Vector/List Functions
		*/
		int getListSize(); // Returns Size of vector
		int findElement(Vector2f fPosition); // Returns the element of GameText based on its Position

		void setDrawToAll(bool bValue); // Sets the draw function of all game text
		int containsMouse(); // Use this for looping through each Text seeing if the mouse is inside it
};

#endif