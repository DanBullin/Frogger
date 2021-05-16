#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <SFML\Graphics.hpp>
#include ".\Sprites\Object\Object.h"
#include ".\Sprites\Entity\Entity.h"

using namespace std;
using namespace sf;

/*
	This class creates a vector of Objects
*/

class ObjectManager : public vector<Object*>
{
	private:

	public:
		ObjectManager();
		void loadObjects(int iLives); // Load all objects
		/*
			Vector/List Functions
		*/
		int getListSize(); // Returns Size of vector
		int findElement(string sTypeParam); // Returns the element of a type of Object

		void setDrawToAll(bool bValue); // Sets the draw function of all objects
		void setTextureToType(string sTypeParam, int iValue); // Sets the texture to all objects of a particular type

		int containsPlayer(Entity &entity); // Returns whether the Player is colliding with at least one object

		void resetTimerSize();
};

#endif