#pragma once

#ifndef BOMBERMAN_ENEMY_H
#define BOMBERMAN_ENEMY_H

#include "GameObject.h"
#include "TransformObject.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "Player.h"
#include "Game.h"

class Enemy : public GameObject
{
public:
	Enemy () = default;
	Enemy (const char *p_filename, int p_x, int p_y, string p_tag_obj);
	~Enemy () override {}//SDL_DestroyTexture(texture);
	void update () override;
	void draw () override;
	void init () override;
//	bool checkCollision (const SDL_Rect &a,const SDL_Rect &b) override;
	void setTex (const char *p_filename);
	void transformPositionToTiles ();
	void findDummyPath (pair<int, int> enemy_coords);
	bool moveThroughFoundDummyPath();
	SDL_Rect pl_src_rect, pl_dest_rect;
	SDL_Rect en_src_rect, en_dest_rect;
	pair<int, int> dummyMovementCoords;
	TransformObject transformObject;
	Vector2D position;
//	KeyboardController keyboardController;
};

#endif //BOMBERMAN_ENEMY_H
