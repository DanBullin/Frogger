#ifndef CONTROLS_H
#define CONTROLS_H

#include <SFML\Graphics.hpp>
#include ".\Sprites\Entity\EntityManager.h"
#include ".\Sprites\Object\ObjectManager.h"
#include ".\Sprites\UI\UIManager.h"
#include ".\Text\GameTextManager.h"
#include ".\Actions\ClickAction.h"
#include ".\Game\GameStats.h"
#include ".\Sprites\Movement.h"
#include <iostream>

using namespace std;
using namespace sf;

/*
	This class handles the controls/input of the game (Mouse & Keyboard)
	Arrow Keys controls the Frog
	/ activates the Debug commands
	Esc pauses the game
*/

class Controls
{
	private:
		ClickAction clickAction;
	public:
		Controls(); // Constructor
		void KeyReleased(Event KeyEvent, Movement &movement, GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager);
		void MouseReleased(Event MouseEvent, GameStats &gameStats, GameTextManager &gameTextManager, UIManager &uiManager, ObjectManager &objectManager);
		void performAction(int iAction);
};

#endif