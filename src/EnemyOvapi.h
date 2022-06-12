#pragma once

#ifndef BOMBERMAN_ENEMYOVAPI_H
#define BOMBERMAN_ENEMYOVAPI_H


#include <string>
#include <queue>

#include "TextureManager.h"
#include "GameObject.h"
#include "Game.h"
#include "Vector2D.h"
#include "Map"
#include "TransformObject.h"

class EnemyOvapi:public GameObject
{
public:
	EnemyOvapi (const char * p_filename, int p_x, int p_y, std::string tag_obj);
	void update () override;
	void draw () override;
	void init () override;
	bool checkCollision (const SDL_Rect &a, const SDL_Rect &b) override;
	void setTex (const char *p_filename);
	void transformPositionToTiles();
	void findShortestPath(const SDL_Rect & en_rect,const SDL_Rect & pl_rect);
	void printPath(vector<pair<int, int>>& path);
	bool isNotVisited(const pair<int,int>& to_find, const vector<pair<int,int>>&path);

	vector<pair<int, int>> path_to_player;
	vector<pair<int, int>> coordinates_path;//path to player in coordinates that he should do tp get to the target
	Vector2D position;
	TransformObject transformObject;

	SDL_Rect pl_src_rect, pl_dest_rect;
	SDL_Rect en_src_rect, en_dest_rect;

	bool flag = true;

};

#endif //BOMBERMAN_ENEMYOVAPI_H
