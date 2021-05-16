#ifndef UPDATEOBJECTS_H
#define UPDATEOBJECTS_H

#include <SFML\Graphics.hpp>
#include ".\Sprites\Object\ObjectManager.h"
#include ".\Sprites\Entity\EntityManager.h"
#include ".\Sprites\UI\UIManager.h"
#include ".\Text\GameTextManager.h"
#include ".\Sprites\Overlay\Overlay.h"
#include ".\Drawing\Scenes.h"
#include ".\System\StringManip.h"

using namespace std;
using namespace sf;

/*
	This class updates the draw variable of all objects based on the game's current scene
*/

class UpdateObjects
{
	private:
		StringManip stringManip;
	public:
		UpdateObjects();
		void resetObjects(EntityManager &entityManager, ObjectManager &objectManager, UIManager &uiManager, GameTextManager &gameTextManager, Overlay &overlay);
		void setDraw(vector<string> sGameScene, EntityManager &entityManager, ObjectManager &objectManager, UIManager &uiManager, GameTextManager &gameTextManager, Overlay &overlay);
		void update(int iGameScene, Scenes scenes, EntityManager &entityManager, ObjectManager &objectManager, UIManager &uiManager, GameTextManager &gameTextManager, Overlay &overlay);
};

#endif