#pragma once

#ifndef BOMBERMAN_MAP_H
#define BOMBERMAN_MAP_H

#include <vector>
#include <string>
#include <memory>

#include "MapObject.h"

class Map
{
public:
	Map ();
	~Map ();
	static void addTile (SDL_Texture *p_tex, int p_tileId, int p_x, int p_y);
	void loadMap (const std::string &filename, int sizeX, int sizeY);
	void initialize ()
	{
		texture_unbr_wall = TextureManager::loadTexture("../src/assets/images/unbreakable_wall.png");
		texture_wall = TextureManager::loadTexture("../src/assets/images/breakable_wall.png");
		texture_background = TextureManager::loadTexture("../src/assets/images/background.png");
		texture_walk_tile = TextureManager::loadTexture("../src/assets/images/walk_tile.png");

		texture_bonus_bomb = TextureManager::loadTexture("../src/assets/images/bonus_bomb.png");
		texture_bonus_speed = TextureManager::loadTexture("../src/assets/images/bonus_speed.png");
		texture_bonus_flame = TextureManager::loadTexture("../src/assets/images/bonus_flame.png");


	}
	SDL_Texture *texture_unbr_wall;
	SDL_Texture *texture_wall;
	SDL_Texture *texture_background;
	SDL_Texture *texture_walk_tile;
	static SDL_Texture  * texture_bonus_bomb;
	static SDL_Texture  * texture_bonus_speed;
	static SDL_Texture  * texture_bonus_flame;
	static std::vector<std::unique_ptr<MapObject>> mapObjects;
	static std::vector<std::unique_ptr<MapObject>> collidableMapObjects;
	static int map_arr[15][15];

};

#endif //BOMBERMAN_MAP_H
