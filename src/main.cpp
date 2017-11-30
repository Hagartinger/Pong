#include "Game.h"
#include "globals.h"

int main(int argc, char* argv[])
{
	Game pong = Game("Pong", globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT);
	
	pong.gameLoop();
	
	
	return 0;
}