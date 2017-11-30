#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Globals.h"
#include <SDL.h>

class Player;
class Game;
class Score;
class  Ball: public GameObject 
{
public:
	Ball();
	Ball(int corX, int corY, int width, int height, Game *game);
	~Ball();
	
	void update();
	void collisionCheck();

	void placeBall();
	
private:
	void collision(Player *player);
	double ballSpeed;
	Player *player1, *player2;
	Score *score1, *score2;


};

#endif