#include ".\Controls\Controls.h"

Controls::Controls()
{

}

void Controls::KeyReleased(Event KeyEvent, Movement &movement, GameStats &gameStats, EntityManager &entityManager, ObjectManager &objectManager)
{
	// This function is called if a Key is released
	int iElement = entityManager.findElement("Frog");
	if(KeyEvent.key.code == Keyboard::Up && gameStats.getGameScene() == 1)
	{
		// The Up arrow has been released
		entityManager[iElement]->spriteData.setCurrentTextureFile(0);
		entityManager[iElement]->spriteData.setSpriteTexture(*entityManager[iElement]);
		movement.movePlayer(gameStats, 0, entityManager, objectManager);
	}
	else if(KeyEvent.key.code == Keyboard::Left && gameStats.getGameScene() == 1)
	{
		// The Left arrow has been released
		entityManager[iElement]->spriteData.setCurrentTextureFile(3);
		entityManager[iElement]->spriteData.setSpriteTexture(*entityManager[iElement]);
		movement.movePlayer(gameStats, 1, entityManager, objectManager);
	}
	else if(KeyEvent.key.code == Keyboard::Right && gameStats.getGameScene() == 1)
	{
		// The Right arrow has been released
		entityManager[iElement]->spriteData.setCurrentTextureFile(1);
		entityManager[iElement]->spriteData.setSpriteTexture(*entityManager[iElement]);
		movement.movePlayer(gameStats, 3, entityManager, objectManager);
	}
	else if(KeyEvent.key.code == Keyboard::Down && gameStats.getGameScene() == 1)
	{
		// The Down arrow has been released
		entityManager[iElement]->spriteData.setCurrentTextureFile(2);
		entityManager[iElement]->spriteData.setSpriteTexture(*entityManager[iElement]);
		movement.movePlayer(gameStats, 2, entityManager, objectManager);
	}
	else if(KeyEvent.key.code == Keyboard::Escape && gameStats.getGameScene() == 1)
	{
		// The Esc key has been released
		gameStats.setGameScene(4);
	}
}

void Controls::MouseReleased(Event MouseEvent, GameStats &gameStats, GameTextManager &gameTextManager, UIManager &uiManager, ObjectManager &objectManager)
{
	// This function is called when a Mouse button is released

	if(MouseEvent.mouseButton.button == Mouse::Left)
	{
		// Left Mouse has been clicked
		if(!clickAction.TextContainsMouse(gameStats, gameTextManager, objectManager))
		{
			clickAction.UIContainsMouse(gameStats, uiManager);
		}
	}
	else if(MouseEvent.mouseButton.button == Mouse::Right)
	{
		// Right Mouse doesn't do anything but its setup incase it's needed
	}
}

void Controls::performAction(int iAction)
{
	// This functions performs the action passed to it - This function is called from the functions above ^^ to Move the Player, access the Debug mode, etc
}