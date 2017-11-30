#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
class GameObject
{
public:
	GameObject();
	~GameObject();
	GameObject(int corX, int corY, int width, int height);

	int getX() { return bodyRect.x; };
	int getY() { return bodyRect.y; };
	int getH() { return bodyRect.h; };
	int getW() { return bodyRect.w; };
	int getCenterX(){ return 0.5 * (getW() - getX());}
	int getCenterY(){ return 0.5 * (getH() - getY());}

	// Fills rect of current object on the renderer.
	void draw(SDL_Renderer* renderer);
	
	void update();

	void setSpeed(double _dx, double _dy);

protected:
	double dx, dy;
	double x,y;

	SDL_Rect bodyRect;
};

#endif

