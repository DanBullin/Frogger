#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <SFML\Graphics.hpp>
#include ".\Sprites\UI\UI.h"

using namespace std;
using namespace sf;

/*
	This class creates a vector of UI (Buttons)
*/

class UIManager : public vector<UI*>
{
	private:
		int iWindowPosX;
		int iWindowPosY;
	public:
		UIManager();
		void loadWindowPos(int iWindowPosXParam, int iWindowPosYParam);
		void loadUI(); // Load all UI buttons
		/*
			Vector/List Functions
		*/
		int getListSize(); // Returns Size of vector
		int findElement(string sTypeParam); // Returns the element of a type of UI

		void setDrawToAll(bool bValue); // Sets the draw function of all UI
		int containsMouse(); // Use this for looping through each UI seeing if the mouse is inside it
};

#endif