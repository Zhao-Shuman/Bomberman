#pragma once

#ifndef BOMBERMAN_FLAME_H
#define BOMBERMAN_FLAME_H

#include "string"

#include "GameObject.h"
#include "TextureManager.h"
class Flame : public GameObject
{
public:
	Flame (SDL_Texture *p_tex, int p_tileId, int p_x, int p_y, int p_w, int p_h, std::string p_tag_obj)
	{
		destRect.x = p_x * scale;
		destRect.y = p_y * scale;
		destRect.w = (p_w) * scale;
		destRect.h = (p_h) * scale;//destRect is from GameObject

		texture = p_tex;
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		tag_obj = p_tag_obj;
	}
	~Flame () override
	{

	}
	void update () override
	{
		if(screenTime<=0)
		{
			isAlive= false;
			return;
		}
		screenTime--;
	}
	void updateFlames ()
	{
		if(screenTime<=0)
		{
			isAlive= false;
			return;
		}
		screenTime--;
	}
	void draw () override
	{
		TextureManager::draw(texture,srcRect,destRect);
	}
	void init () override
	{
//		GameObject::init();
	}
//	bool checkCollision (const SDL_Rect &a, const SDL_Rect &b) override
//	{
//		return GameObject::checkCollision(a, b);
//	}

	int scale = 2;
	int screenTime = 60;
};

#endif //BOMBERMAN_FLAME_H
