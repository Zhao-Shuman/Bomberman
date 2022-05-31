#pragma once

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include "GameObject.h"
#include "TextureManager.h"
#include "TransformObject.h"

class Player : public GameObject
{
public:
	Player () = default;
	Player (const char *filename);
	~Player ()
	{
		SDL_DestroyTexture(texture);
	}
	void update () override;
	void draw () override;
	void init () override;
	void setTex (const char *p_filename);
	int xpos = 0, ypos = 0;
	TransformObject *transformObject;
};

#endif //BOMBERMAN_PLAYER_H
