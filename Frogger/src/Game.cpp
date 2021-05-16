#include ".\Game.h"

Game::Game()
{
	sWindowTitle = "Frogger - Daniel Bullin";
	fWindowSizeX = 608;
	fWindowSizeY = 416;
	canvasBackground = Color::White;
}

void Game::setProperties()
{
	// Create the window
	GameWindow.create(VideoMode(fWindowSizeX, fWindowSizeY), sWindowTitle, Style::Titlebar | Style::Close);
	// Load Entities
	entityManager.loadEntities();
	consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sLoadedEntities);
	// Load Objects
	objectManager.loadObjects(gameStats.getInitialLives());
	consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sLoadedObjects);
	// Load UI
	uiManager.loadUI();
	consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sLoadedUI);
	// Load GameText
	gameTextManager.loadText();
	consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sLoadedText);
	// Load the overlay
	gameOverlay.setProperties(fWindowSizeX, fWindowSizeY, Color(48, 48, 48, 200));
	// Load the scenes
	scenes.load(entityManager, objectManager, gameStats.getLives());
	consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sLoadedScenes);
	// Update Objects based on starting scene
	updateObjects.update(gameStats.getGameScene(), scenes, entityManager, objectManager, uiManager, gameTextManager, gameOverlay);
	// Load Properties of Files
	gameStats.setProperties(entityManager, objectManager, uiManager, gameTextManager, gameOverlay, scenes, updateObjects);
	// Set Movement's window size
	movement.setProperties(GameWindow.getSize().x);
	// Set initial Score
	gameStats.setScore(gameStats.getScore());
}

void Game::runGame()
{
	consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sStartingGame);
	setProperties(); // Set those initial properties
	consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sControls);

	while (!gameStats.getGameEnd())
    {
		gameTextManager.loadWindowPos(GameWindow.getPosition().x, GameWindow.getPosition().y); // Pass the Window position so we can use it for Mouse detection for hovering
		uiManager.loadWindowPos(GameWindow.getPosition().x, GameWindow.getPosition().y); // ^^^^^^^
		
		
		if(gameStats.getGameScene() == 1)
		{
			// Update Game Timer
			gameTimer.update(gameStats, entityManager, objectManager);
			// Move Entities
			movement.moveNPC(gameStats, entityManager, objectManager);
			turtleBehaviour.change(entityManager);
			lilypadBehaviour.change(gameStats, objectManager);
		}

		pollEvent(); // Keep checking keyboard/mouse/window events

        clearCanvas();
        drawObjects();
        GameWindow.display();
    }

	consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sGameAbruptlyClosed);
	GameWindow.close(); // Close Window if Game has ended
}

void Game::pollEvent()
{
	Event event;

	while (GameWindow.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			gameStats.setGameEnd(true);
			consoleMessages.printMessage(consoleMessages.sInfoTag, consoleMessages.sGameAbruptlyClosed);
			GameWindow.close();
		} 
		if(event.type == Event::MouseButtonReleased)
		{
			// Mouse has been pressed & released
			controls.MouseReleased(event, gameStats, gameTextManager, uiManager, objectManager);
		}
		if(event.type == Event::MouseMoved)
		{
			// Mouse has moved - Check if mouse is hovering over an object
			if(!hoverAction.TextContainsMouse(gameTextManager))
			{
				// No text has the mouse so lets check buttons
				hoverAction.UIContainsMouse(uiManager);
			} 
		}
		if (event.type == Event::KeyReleased)
		{
			// Key has been pressed & released
			controls.KeyReleased(event, movement, gameStats, entityManager, objectManager);
		}
	}
}

void Game::clearCanvas()
{
	GameWindow.clear(canvasBackground);
}

void Game::drawObjects()
{
	// Loop through each object and if their draw variable is set to true, draw them :D

	for(int i = 0; i < objectManager.getListSize(); i++)
	{
		if(objectManager[i]->objectData.getDraw() == true)
		{
			GameWindow.draw(*objectManager[i]);
		}	
	}

	for(int i = 0; i < entityManager.getListSize(); i++)
	{
		if(entityManager[i]->objectData.getDraw() == true)
		{
			GameWindow.draw(*entityManager[i]);
		}	
	}

	if(gameOverlay.getDraw() == true)
	{
		GameWindow.draw(gameOverlay);
	}

	for(int i = 0; i < uiManager.getListSize(); i++)
	{
		if(uiManager[i]->objectData.getDraw() == true)
		{
			GameWindow.draw(*uiManager[i]);
		}	
	}

	for(int i = 0; i < gameTextManager.getListSize(); i++)
	{
		if(gameTextManager[i]->objectData.getDraw() == true)
		{
			GameWindow.draw(*gameTextManager[i]);
		}	
	}
}