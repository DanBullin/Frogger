#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include ".\Game\GameStats.h"
#include ".\Controls\Controls.h"

#include ".\Sprites\Entity\EntityManager.h"
#include ".\Sprites\Object\ObjectManager.h"
#include ".\Sprites\UI\UIManager.h"
#include ".\Text\GameTextManager.h"
#include ".\Sprites\Overlay\Overlay.h"
#include ".\Drawing\Scenes.h"
#include ".\Sprites\Movement.h"
#include ".\Game\Turtlebehaviour.h"
#include ".\Game\Lilypadbehaviour.h"

#include ".\Drawing\UpdateObjects.h"
#include ".\Actions\HoverAction.h"

#include ".\Debug\ConsoleMessages.h"
#include ".\GameTimer.h"

using namespace std;
using namespace sf;

/*
	This class generates the Frogger game and is the main element of the game
*/

class Game
{
	private:
		RenderWindow GameWindow; // The window
		string sWindowTitle; // The contents of the text in title of the window (Initialised in Constructor)
		float fWindowSizeX; // The horizontal size of the window (Initialised in Constructor)
		float fWindowSizeY; // The vertical size of the window (Initialised in Constructor)
		Color canvasBackground; // The default colour of the Window background (Initialised in Constructor)

		// Game loop is inside GameStats 'bGameEnd'

		ConsoleMessages consoleMessages;

		GameTimer gameTimer;
		GameStats gameStats;
		Controls controls;
		
		EntityManager entityManager;
		ObjectManager objectManager;
		UIManager uiManager;
		GameTextManager gameTextManager;
		Overlay gameOverlay;
		Scenes scenes;

		UpdateObjects updateObjects;
		HoverAction hoverAction;
		Movement movement;
		TurtleBehaviour turtleBehaviour;
		LilypadBehaviour lilypadBehaviour;

	public:
		Game(); // Constructor

		void setProperties();
		void updateGameSettings();
		void runGame(); // The main game function containing the game loop
		void pollEvent(); // Tracks events of the window
		void clearCanvas(); // Clears the canvas with the passed colour
		void drawObjects(); // Draws all objects which needs to be drawn
};

#endif