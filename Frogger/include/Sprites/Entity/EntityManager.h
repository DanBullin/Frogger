#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <SFML\Graphics.hpp>
#include ".\Sprites\Entity\Entity.h"

using namespace std;
using namespace sf;

/* 
	This class creates a vector of Entities
*/

class EntityManager : public vector<Entity*>
{
	private:

	public:
		EntityManager();
		void loadEntities(); // Load all entities
		
		/*
			Vector/List Functions
		*/
		int getListSize(); // Returns Size of vector
		int findElement(string sTypeParam); // Returns the element of a type of Entity

		void setDrawToAll(bool bValue); // Sets the draw function of all entities
		/*
			Game Functions
		*/
		int offScreen(Entity entity, int iWindowSizeX, int iWindowSizeY); // Returns 0 the entity if onscreen, 1 if offscreen to the right, 2 if offscreen to the left
		int containsPlayer(Entity &entity); // Returns whether the Player is colliding with at least one entity
};

#endif