#include "Player.h"
#include "Globals.h"

Player::Player()
{}

void Player::update()
{
	// Player on the upper edge of the screen
	if ((getY()+ dy) <= 0)
	{
		bodyRect.y = 0;
		setSpeed(0,0);
	}
	// Player on the bottom edge of the screen
	else 
	{
		if (getY() + getH() + dy >= globals::SCREEN_HEIGHT)
		{
			bodyRect.y = globals::SCREEN_HEIGHT - bodyRect.h;
			setSpeed(0,0);
		}
	//Player somewhere in between 
		else GameObject::update();
	}
}

