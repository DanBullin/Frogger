#ifndef TURTLEBEHAVIOUR_H
#define TURTLEBEHAVIOUR_H

#include ".\Sprites\Entity\EntityManager.h"

using namespace std;

/*
	This class handles the Turtle's submerging behaviour
*/

class TurtleBehaviour
{
	private:
		Clock turtleClock;
		Time elapsedTime;
		int iTick;
		int iState;
	public:
		TurtleBehaviour();
		void change(EntityManager &entityManager);
};

#endif