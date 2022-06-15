#pragma once

#ifndef BOMBERMAN_BONUS_H
#define BOMBERMAN_BONUS_H

#include <string>

#include "GameObject.h"
#include "TextureManager.h"


enum BonusType
{
	addBomb,
	addFlameRange,
	addSpeed
};

class Bonus : public GameObject
{
public:
	Bonus (int x_coord, int y_coord, int bonus_id, SDL_Texture *p_texture, string p_tag_obj)
	{
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;

		destRect.x = x_coord * 64;
		destRect.y = y_coord * 64;
		destRect.w = srcRect.w*scale;
		destRect.h = srcRect.h*scale;

		texture = p_texture;

		tag_obj = p_tag_obj;
	}
	~Bonus () override{}
	void update () override {};
	void draw () override
	{
		TextureManager::draw(texture,srcRect,destRect);
	}
	void init () override {}
	int scale = 2;
};

#endif //BOMBERMAN_BONUS_H
