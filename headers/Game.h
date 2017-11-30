#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <SDL.h>

#include "Player.h"
#include "Ball.h"
#include "Input.h"
#include "Score.h"

class Game{
	friend Ball;
public:
	Game();
	Game(std::string windowName, int width, int height);
	~Game();
	
	//main loop
	void gameLoop();
	
	//Renders everything on the screen
	void render();

	void update();
	
	// Handles events (input)
	void eventHandler(SDL_Event &e, Input &input);
	
	//Initialisation 
	void init();
	
	SDL_Renderer* getRen(){return renderer;}

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	bool gameRunning;
	Player player1, player2;
	Score score1, score2;
	Ball ball;
	
};
	
#endif