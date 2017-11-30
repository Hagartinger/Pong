#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

#include "GameObject.h"

class Player: public GameObject
{
public:
	Player();
	Player(int corX, int corY, int width, int height):GameObject(corX,corY,width,height){};
	
	void update();
	
	
};



#endif