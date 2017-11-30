#include "Game.h"


#include <iostream>
#include "globals.h"


Game::Game(){
}

Game::Game(std::string windowName, int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window != nullptr)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer != nullptr)
		{
			
		
			gameRunning = true;
		}
	}
}

Game::~Game(){
}

void Game::gameLoop()
{
	init();
	SDL_Event e;
	Input input;
	Uint32 previousTime = SDL_GetTicks();
	Uint32 elapsedTime;
	while(gameRunning)
	{
		eventHandler(e,input);
		update();
		render();
		
		elapsedTime = SDL_GetTicks() - previousTime;
		if(elapsedTime < globals::SCREEN_TICKS_PER_FRAME)
			SDL_Delay(globals::SCREEN_TICKS_PER_FRAME - elapsedTime);
		previousTime = SDL_GetTicks();
	}
}

void Game::init()
{
	int player1X = globals::SCREEN_WIDTH * globals::PLAYER_GAP_PERCENT;
	int player2X = globals::SCREEN_WIDTH * (1 - globals::PLAYER_GAP_PERCENT) - globals::PLAYER_WIDTH;
	
	int playersY = (globals::SCREEN_HEIGHT - globals::PLAYER_HEIGHT) / 2;
	
	player1 = Player(player1X, playersY, globals::PLAYER_WIDTH, globals::PLAYER_HEIGHT);
	player2 = Player(player2X, playersY, globals::PLAYER_WIDTH, globals::PLAYER_HEIGHT);
	ball = Ball(globals::SCREEN_WIDTH / 2,globals::SCREEN_HEIGHT /2 ,globals::BALL_SIZE,globals::BALL_SIZE, this);
	score1 = Score(globals::SCORE_POSX_1, globals::SCORE_POSY);
	score2 = Score(globals::SCORE_POSX_2, globals::SCORE_POSY);
	ball.placeBall();
	
	
}
	
void Game::update()
{
	player1.update();
	player2.update();
	ball.update();
}

void Game::eventHandler(SDL_Event &e, Input &input)
{
	while (SDL_PollEvent(&e) != 0 )
	{
		switch (e.type)
		{
			case SDL_QUIT :
				gameRunning = false;
				break;
			case SDL_KEYDOWN :
				input.ButtonPressed(e.key.keysym.sym);
				break;
			case SDL_KEYUP :
				input.ButtonReleased(e.key.keysym.sym);
				break;
			default:
				break;
		}
	}	
	
		// Controls
	if (input.IsKeyHeld(SDLK_UP))
		player2.setSpeed(0, - globals::PLAYER_SPEED);
	else 
	{
		if (input.IsKeyHeld(SDLK_DOWN))
		{
			player2.setSpeed(0, globals::PLAYER_SPEED);
		}
		else 
			player2.setSpeed(0,0);
	}
	
	if (input.IsKeyHeld(SDLK_w))
		player1.setSpeed(0, -globals::PLAYER_SPEED);
	else if (input.IsKeyHeld(SDLK_s))
		player1.setSpeed(0, globals::PLAYER_SPEED);
		else 
			player1.setSpeed(0,0);
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Draw every object on backsurface:

	// Draw central line
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(renderer, globals::SCREEN_WIDTH / 2, 0, globals::SCREEN_WIDTH / 2, globals::SCREEN_HEIGHT);

	// Draw Players
	player1.draw(renderer);
	player2.draw(renderer);
	ball.draw(renderer);
	score1.draw(renderer);
	score2.draw(renderer);

	//Switch renderer with backsurface
	SDL_RenderPresent(renderer);
}