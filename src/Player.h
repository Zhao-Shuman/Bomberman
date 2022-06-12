#pragma once

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H


#include "GameObject.h"
#include "TextureManager.h"
#include "TransformObject.h"
#include "Vector2D.h"
#include "KeyboardController.h"
#include "Bomb.h"

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
	bool checkCollision(const SDL_Rect & a, const SDL_Rect & b)override;
	void placeBomb();
	void explodeBomb(unique_ptr<Bomb>& bomb);
	bool isValueOnTile(int x_coord, int y_coord, int id_tile);
	void changeMapArrayAndMapObject(int y_coord, int x_coord, int y_resolution, SDL_Texture * p_texture, pair<int,int>prev_coord);
//	void drawBombs();
	bool bombIsPlaced = false;
	int flameRange = 2;
	Vector2D position;
	KeyboardController keyboardController;
	vector<unique_ptr<Bomb>> bombContainer;

};
#endif //BOMBERMAN_PLAYER_H
