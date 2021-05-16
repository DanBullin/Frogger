#include ".\Drawing\Scenes.h"

Scenes::Scenes()
{
	
}

void Scenes::load(EntityManager &entityManager, ObjectManager &objectManager, int iLives)
{
	// Temporary to easily add all the ojects to their scenes
	string sTmpGameScene0[9] = {"Text 0", "Text 1", "Text 2", "Text 3", "Text 4", "Text 5", "Text 6", "Text 7", "Overlay"};
	string sTmpGameScene1[1] = {"Text 24"};
	string sTmpGameScene2[15] = {"Text 8", "Text 9", "Text 10", "Text 11", "Text 12", "Text 13", "Text 14", "Text 15", "Text 16", "Text 17", "Text 18", "Text 19", "Overlay", "UI 0", "UI 1"};
	string sTmpGameScene3[9] = {"Text 20", "Text 21", "Overlay", "UI 2", "UI 3", "UI 4", "UI 5", "UI 6", "UI 7"};
	string sTmpGameScene4[3] = {"Text 22", "Text 23", "Overlay"};

	// Loops through each Scene and adds their Tmp Scene/Managers
	for(int i = 0; i < 9; i++)
	{
		sGameScene0.push_back(sTmpGameScene0[i]);
	}

	for(int i = 0; i < 1; i++)
	{
		sGameScene1.push_back(sTmpGameScene1[i]);
	}

	for(int i = 0; i < 15; i++)
	{
		sGameScene2.push_back(sTmpGameScene2[i]);
	}

	for(int i = 0; i < 9; i++)
	{
		sGameScene3.push_back(sTmpGameScene3[i]);
	}

	for(int i = 0; i < 3; i++)
	{
		sGameScene4.push_back(sTmpGameScene4[i]);
	}

	for(int i = 18; i < objectManager.getListSize(); i++)
	{
		sGameScene1.push_back("Object " + to_string(i));
	}

	for(int i = 0; i < entityManager.getListSize(); i++)
	{
		sGameScene1.push_back("Entity " + to_string(i));
	}

	for(int i = 0; i < 18; i++)
	{
		sGameScene5.push_back("Object " + to_string(i));
	}
}