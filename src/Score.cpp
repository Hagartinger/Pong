#include "Score.h"
#include <string>
#include "Globals.h"
Score::Score()
{
	
}

Score::Score(int x, int y):x(x),y(y)
{
	TTF_Init();
	font = TTF_OpenFont("../resources/unifont.ttf", globals::SCORE_FONT_SIZE);
	reset();
}

void Score::reset()
{
	score = 0;
}


void Score::draw(SDL_Renderer* renderer)
{
	std::string text = std::to_string(score);
	SDL_Color colour = { 255,255,255,255 };
	SDL_Surface* textSurface = NULL;
	textSurface = TTF_RenderText_Solid(font, text.c_str(), colour);
	if (textSurface != NULL)
	{
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_Rect destRect = { x, y, textSurface->w, textSurface->h };
		SDL_RenderCopy(renderer, texture, NULL, &destRect);
	}
	SDL_FreeSurface(textSurface);
	textSurface = NULL;
	SDL_DestroyTexture(texture);
}

Score::~Score()
{
}
