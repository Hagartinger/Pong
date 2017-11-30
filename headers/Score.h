#ifndef SCORE_H
#define SCORE_H

#include <SDL.h>
#include <SDL_ttf.h>
class Score
{
public:
	Score();
	Score(int x, int y);
	~Score();
	
	void reset();
	
	void increment() { score++; }
	

	int getScore() { score; }

	void draw(SDL_Renderer* renderer);

private:
	SDL_Texture* texture;
	TTF_Font* font;

	int score;
	int x, y;


};

#endif
