#ifndef OBJECTDATA_H
#define OBJECTDATA_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

/*
	This class creates data about all objects (sprites & text) in the game -- all objects must declare this class
*/

class ObjectData
{
	private:
		bool bDraw; // Do we draw this object
		int iCollisionAction; // What action is to taken when a player collides? (Refer to CollideAction.h for detailed info for each number)
		int iMouseClickAction; // What action is to be taken when the mouse clicks on the object (Refer to ClickAction.h for detailed info for each number)
		int iMouseHoverAction; // What action is to be taken when the mouse hover on the object (Refer to HoverAction.h for detailed info for each number)
	public:
		ObjectData();

		// Standard get/set functions
		bool getDraw();
		int getCollisionAction();
		int getHoverAction();
		int getClickAction();
		
		void setDraw(bool bValue);
		void setCollisionAction(int iValue);
		void setHoverAction(int iValue);
		void setClickAction(int iValue);
		
		bool containsMouse(FloatRect bounds, int iWindowPosX, int iWindowPosY); // Returns true if mouse is inside object, false if it isn't
		bool containsPlayer(FloatRect objectBounds, FloatRect playerBounds, Vector2f fPlayerPos, Vector2f fPlayerSize); // Returns true if player has collided, false if player hasn't
};

#endif