#pragma once

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include "GameObject.h"
#include "TextureManager.h"
#include "TransformObject.h"
#include "Vector2D.h"
#include "KeyboardController.h"
#include "CircleCollision.h"

class Player : public GameObject
{
public:
	Player () = default;
	Player (const char *filename);
	Player (const char *filename, int x, int y);

	~Player () override
	{
		SDL_DestroyTexture(texture);
	}
	void update () override;
	void draw () override;
	void init () override;
	void setTex (const char *p_filename);
	bool checkCollision(const SDL_Rect & a, const SDL_Rect & b)override;
	TransformObject transformObject;
	Vector2D position;
	KeyboardController keyboardController;
//	static Circle circlePos;

};

#endif //BOMBERMAN_PLAYER_H
