#ifndef SPRITEDATA_H
#define SPRITEDATA_H

#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

/*
	This class creates data about all sprites in the game -- all objects must declare this class
	ObjectData.h adds more data for sprites but also for text aswell which is why it's in a different file, go there for more data about the sprite
*/

class SpriteData
{
	private:
		string sType; // The type of object ("Grass", "Car", "Log", etc)
		bool bAllowCollision; // Does this object allow the player to collide with it?
		Texture texture;
		
		int iCurrentTextureFile; // Holds what the index of the file the texture is currently set at
	public:
		SpriteData();
		vector<string> sTextureFiles; // Holds the name of all texture files attatched to an object (Animated objects will have more than 1 file)
		string getType();
		bool getAllowCollision();
		int getCurrentTextureFile();

		void setType(string sValue);
		void setAllowCollision(bool bValue);
		void setSpriteTexture(RectangleShape &spriteObject);
		void addTextureFile(int iTextureFiles); // Pass how many texture files there are for this object
		void setCurrentTextureFile(int iValue);
};

#endif