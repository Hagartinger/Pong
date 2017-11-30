#include "Ball.h"

#include "Game.h"
#include "Player.h"
#include "Score.h"
#include "Globals.h"

#include <iostream>
#include <math.h>
#include <random>
#include <ctime>

const double PI = 3.14;

Ball::Ball(){
}
Ball::Ball(int corX, int corY, int width, int height, Game *game): GameObject(corX,corY,width,height)
{
	player1 = &game->player1;
	player2 = &game->player2;
	score1 = &game->score1;
	score2 = &game->score2;
}

Ball::~Ball(){
}

void Ball::placeBall()
{
	x = globals::SCREEN_WIDTH / 2 - bodyRect.w;
	y = globals::SCREEN_HEIGHT / 2 - bodyRect.h;
	ballSpeed = globals::BALL_SPEED;

	// find degree for ball
	std::srand(std::time(0));
	int randDegree = rand() % 60 ;

	
	// (-1)^n - gives random sign
	dx = std::pow(-1, rand()) * ballSpeed * std::cos(randDegree * PI/ 180.0);
	dy = std::pow(-1, rand()) * ballSpeed * std::sin(randDegree * PI/ 180.0);

}


void Ball::update()
{
	//GameObject::update();
	collisionCheck();
}

void Ball::collisionCheck()
{
	
	if ( getX() + getW() + dx >= player1->getX() && getX() + dx <= player1->getX() + player1->getW() )
	{
		if (getY() + getH() + dy >= player1->getY() && getY() + dy <= player1->getY() + player1->getH())
		{// collision will happen with first player
			
			collision(player1);
			
		}
	}
	
	// Check collision with second player
	if (getX() + getW() + dx >= player2->getX() && getX() + dx <= player2->getX() + player2->getW())
	{
		if (getY() + getH() + dy >= player2->getY() && getY() + dy <= player2->getY() + player2->getH())
		{
			collision(player2);
		}
	}
	
	// Check collision with screen
	if (getY() < 0 || getY() + getH() > globals::SCREEN_HEIGHT)
	{
		dy = -dy;
	}
	
	if (getX() + getW() <= 0)
	{
		score1->increment();
		placeBall();
	}
	if (getX() >= globals::SCREEN_WIDTH)
	{
		score2->increment();
		placeBall();
	}
	
	GameObject::update();
	
}

void Ball::collision(Player *player)
{
			
	if (ballSpeed * globals::BALL_ACCELERATION <= globals::BALL_SPEED_CAP)
	ballSpeed *= globals::BALL_ACCELERATION;
	// relativePos = [0..1]
	double relativePos = (double)( player->getY() + player->getH() - getY() ) / (player->getH() + getH());
	if (relativePos <= 0.3)
		relativePos = 0.3;
	if (relativePos >= 0.7)
		relativePos = 0.7;
	double angle = relativePos * (PI);
	
	dy =  ballSpeed * cos(angle);
	std::cout<<dy<<'\n';
	if (std::signbit(dx))
	{
		// dx < 0
		dx =  ballSpeed * sin(angle);
	}
	else
	{
		dx = - ballSpeed * sin(angle);
	}

}