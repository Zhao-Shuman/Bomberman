#pragma once

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include "GameObject.h"
#include "TextureManager.h"
#include "TransformObject.h"
#include "Vector2D.h"
#include "KeyboardController.h"
#include "Bomb.h"
#include "Flame.h"
#include "Map.h"
#include "CollisionManager.h"
#include "Bonus.h"
#include "RandomNumberGenerator.h"
//class Bomb;
//#include ""
class Player : public GameObject
{
public:
	Player () = default;
	Player (const char *filename);
	Player (const char *filename, int x, int y, string p_tag_obj);

	~Player () override
	{
		SDL_DestroyTexture(texture);
	}
	void update () override;
	void draw () override;
	void init () override;
	void setTex (const char *p_filename);
	void placeBomb ();
	void explodeBomb (unique_ptr<Bomb> &bomb);
	bool isValueOnTile (int x_coord, int y_coord, int id_tile);
	void changeMapArrayAndMapObject (int y_coord, int x_coord, int y_resolution, SDL_Texture *p_texture);
	void addEffect(string p_tag_bonus);
	bool bombIsPlaced = false;
	int flameRange = 1;
	int flameIncreaseCounter = 0;
	int bombCount;
//	static size_t currentScore;

	Vector2D position;
	KeyboardController keyboardController;
	vector<unique_ptr<Bomb>> bombContainer;
	static vector<unique_ptr<Flame>> flames;

};

#endif //BOMBERMAN_PLAYER_H
