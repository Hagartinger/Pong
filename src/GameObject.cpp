#include "GameObject.h"

#include "Globals.h"

GameObject::GameObject()
{
}

GameObject::GameObject(int corX, int corY, int width, int height)
{
	x = corX;
	y = corY;
	bodyRect.x = corX;
	bodyRect.y = corY;
	bodyRect.w = width;
	bodyRect.h = height;
}


GameObject::~GameObject()
{
}


void GameObject::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &bodyRect);
}
void GameObject::setSpeed(double _dx, double _dy)
{
	dx = _dx;
	dy = _dy;
}
	
	
void GameObject::update()
{
	x += dx;
	y += dy;
	bodyRect.x = (int)x;
	bodyRect.y = (int)y;
}
