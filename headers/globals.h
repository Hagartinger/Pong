#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	
	const int PLAYER_WIDTH = 10;
	const int PLAYER_HEIGHT = 80;
	const double PLAYER_SPEED = 8.0;
	const double PLAYER_GAP_PERCENT = 0.05;
	
	const int BALL_SIZE = 20;
	const double BALL_SPEED = 8.0;
	const double BALL_SPEED_CAP = 15;
	const double BALL_ACCELERATION = 1.05;
	
	const int SCORE_FONT_SIZE = 32;
	const int SCORE_POSY = SCREEN_HEIGHT * 0.1;
	const int SCORE_POSX_1 = SCREEN_WIDTH * 0.2;
	const int SCORE_POSX_2 = SCREEN_WIDTH * 0.8;

}

struct Vector2 
{
	double x, y;
	Vector2()
	{
		this->x = 0;
		this->y = 0;
	}
};

#endif
