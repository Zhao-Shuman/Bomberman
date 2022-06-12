#pragma once

#ifndef BOMBERMAN_GAMEOBJECT_H
#define BOMBERMAN_GAMEOBJECT_H

#include <string>


#include "SDL_image.h"
#include "SDL.h"

class GameObject
{
private:
public:
	virtual ~GameObject () {}
	virtual void update () {}
	virtual void draw () {}
	virtual void init () {}
	virtual bool checkCollision (const SDL_Rect & a, const SDL_Rect & b) {}
	SDL_Rect srcRect, destRect;//for displaying sprites
	SDL_Texture *texture;
	std::string tag_obj;


};

#endif //BOMBERMAN_GAMEOBJECT_H
