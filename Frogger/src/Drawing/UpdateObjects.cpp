#include ".\Drawing\UpdateObjects.h"

UpdateObjects::UpdateObjects()
{

}

void UpdateObjects::resetObjects(EntityManager &entityManager, ObjectManager &objectManager, UIManager &uiManager, GameTextManager &gameTextManager, Overlay &overlay)
{
	// Loop through every object and set their draw variable to false
	entityManager.setDrawToAll(false);
	objectManager.setDrawToAll(false);
	uiManager.setDrawToAll(false);
	gameTextManager.setDrawToAll(false);
	overlay.setDraw(false);
}

void UpdateObjects::setDraw(vector<string> sGameScene, EntityManager &entityManager, ObjectManager &objectManager, UIManager &uiManager, GameTextManager &gameTextManager, Overlay &overlay)
{
	// Loop through every item in the GameScene passed as an arg and if it finds an object, set its draw variable to true

	int iSize = sGameScene.size();

	for(int i = 0; i < iSize; i++)
	{
		// If an item contains Overlay, set draw to true
		if(sGameScene[i].find("Overlay") != -1)
		{
			overlay.setDraw(true);
		}
		else
		{
			// Else, check if item contains.... - Overlay is different as it doesn't have a number/parameter in the item
			int iElement = stoi(stringManip.getParameter(sGameScene[i], 1));

			if(sGameScene[i].find("Entity") != -1)
			{
				entityManager[iElement]->objectData.setDraw(true);
			}
			else if(sGameScene[i].find("Text") != -1)
			{
				gameTextManager[iElement]->objectData.setDraw(true);
			}
			else if(sGameScene[i].find("UI") != -1)
			{
				uiManager[iElement]->objectData.setDraw(true);
			}
			else if(sGameScene[i].find("Object") != -1)
			{
				objectManager[iElement]->objectData.setDraw(true);
			}
		}
	}
}

void UpdateObjects::update(int iGameScene, Scenes scenes, EntityManager &entityManager, ObjectManager &objectManager, UIManager &uiManager, GameTextManager &gameTextManager, Overlay &overlay)
{
	// Reset the objects
	resetObjects(entityManager, objectManager, uiManager, gameTextManager, overlay);

	// Update the object's draw variables based on the current game scene
	if(iGameScene == 0)
	{
		setDraw(scenes.sGameScene0, entityManager, objectManager, uiManager, gameTextManager, overlay);
	}
	else if(iGameScene == 1)
	{
		setDraw(scenes.sGameScene1, entityManager, objectManager, uiManager, gameTextManager, overlay);
	}
	else if(iGameScene == 2)
	{
		setDraw(scenes.sGameScene2, entityManager, objectManager, uiManager, gameTextManager, overlay);
	}
	else if(iGameScene == 3)
	{
		setDraw(scenes.sGameScene3, entityManager, objectManager, uiManager, gameTextManager, overlay);
	}
	else if(iGameScene == 4)
	{
		setDraw(scenes.sGameScene4, entityManager, objectManager, uiManager, gameTextManager, overlay);
	}

	// Since Game Scene 5 means always draw, we need to do that manually as there isn't game-wise a Game Scene 5 event
	setDraw(scenes.sGameScene5, entityManager, objectManager, uiManager, gameTextManager, overlay);
}