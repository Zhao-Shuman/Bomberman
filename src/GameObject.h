#pragma once

#ifndef BOMBERMAN_GAMEOBJECT_H
#define BOMBERMAN_GAMEOBJECT_H

#include "SDL_image.h"
#include "SDL.h"

class GameObject{
private:
public:
	virtual ~GameObject(){}
	virtual void update(){}
	virtual void draw(){}
	virtual void init(){}

	SDL_Rect srcRect, destRect;
	SDL_Texture* texture;


};

#endif //BOMBERMAN_GAMEOBJECT_H
