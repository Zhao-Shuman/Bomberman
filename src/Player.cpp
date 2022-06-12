//
// Created by User win 10 on 31.05.2022.
//
#include <cmath>
#include <algorithm>

#include "Player.h"
#include "TextureManager.h"
#include "Map.h"
#include "Bomb.h"

Player::Player (const char *filename)
{
//	init();
	keyboardController.transform.position.zero();
//	transformObject = keyboardController.transform;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
	setTex(filename);

}
Player::Player (const char *filename, int x, int y, string p_tag_obj)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
	keyboardController.transform.position.zero();
//	transformObject = keyboardController.transform;
	destRect.x = x * 2;
	destRect.y = y * 2;
	position.x = x * 2;
	position.y = y * 2;
	keyboardController.transform.scale = 1.5f;
	setTex(filename);
	tag_obj = p_tag_obj;

}
void Player::setTex (const char *p_filename)
{
	texture = TextureManager::loadTexture(p_filename);
}

void Player::placeBomb ()
{
	for (auto const &b: bombContainer)
	{
		if (b->index_map.first == destRect.x / 64 && b->index_map.second == destRect.y / 64)
		{
			return;
		}
	}
	bombContainer.emplace_back(make_unique<Bomb>(make_pair(destRect.x / 64, destRect.y / 64)));
}

bool Player::isValueOnTile (int y_coord, int x_coord, int id_tile)
{
	return Map::map_arr[y_coord][x_coord] == id_tile;
}
void Player::changeMapArrayAndMapObject (int y_coord, int x_coord, int y_resolution, SDL_Texture *p_texture,
                                         pair<int, int> prev_coord)
{
	if (Map::map_arr[prev_coord.first][prev_coord.second] != 2)
		return;

	auto it = Map::collidableMapObjects.begin();
	for (auto const &m_obj: Map::collidableMapObjects)
	{
		if (m_obj->destRect.x == x_coord * 64 && m_obj->destRect.y == y_coord * 64)
		{
			//finding that object in all map objects and changing its id and texture
			Map::collidableMapObjects.erase(it);
			Map::mapObjects.at(x_coord + y_resolution *(y_coord))->tileId = 2;
			Map::mapObjects.at(x_coord + y_resolution * (y_coord))->texture = p_texture;
			break;
		}
		++it;
	}
	Map::map_arr[y_coord][x_coord] = 2;
}
void Player::explodeBomb (unique_ptr<Bomb> &bomb)
{
	SDL_Texture *walk_tile = TextureManager::loadTexture("../src/assets/images/walk_tile.png");


	int y_resolution = 15;
	int x_coord = bomb->index_map.first;
	int y_coord = bomb->index_map.second;
	Map::mapObjects;
	for (int i = 2; i <= flameRange; i++)
	{
		if (isValueOnTile(y_coord - 1, x_coord, 3))//up
		{
			changeMapArrayAndMapObject(y_coord - 1, x_coord, y_resolution, walk_tile, {y_coord, x_coord});
		}
		else if (isValueOnTile(y_coord - i, x_coord, 3))//up
		{
			changeMapArrayAndMapObject(y_coord - i, x_coord, y_resolution, walk_tile, {y_coord-i+1, x_coord});
		}
		if (isValueOnTile(y_coord, x_coord + 1, 3))//right
		{
			changeMapArrayAndMapObject(y_coord, x_coord + 1, y_resolution, walk_tile, {y_coord, x_coord});
		}
		else if (isValueOnTile(y_coord, x_coord + i, 3))//right
		{
			changeMapArrayAndMapObject(y_coord, x_coord + i, y_resolution, walk_tile, {y_coord, x_coord+i-1});
		}
		if (isValueOnTile(y_coord + 1, x_coord, 3))//down
		{
			changeMapArrayAndMapObject(y_coord + 1, x_coord, y_resolution, walk_tile, {y_coord, x_coord});
		}
		else if (isValueOnTile(y_coord + i, x_coord, 3))//down
		{
			changeMapArrayAndMapObject(y_coord + i, x_coord, y_resolution, walk_tile, {y_coord+i-1, x_coord});
		}
		if (isValueOnTile(y_coord, x_coord - 1, 3))//left
		{
			changeMapArrayAndMapObject(y_coord, x_coord - 1, y_resolution, walk_tile, {y_coord, x_coord});
		}
		else if (isValueOnTile(y_coord, x_coord - i, 3))//left
		{
			changeMapArrayAndMapObject(y_coord, x_coord - i, y_resolution, walk_tile, {y_coord, x_coord-i+1});
		}
	}


//	if (Map::map_arr[y_coord - 1][x_coord] == 3)//up
//	{
//		auto it = Map::collidableMapObjects.begin();
//		for (auto const &m_obj: Map::collidableMapObjects)
//		{
//			if (m_obj->destRect.x == x_coord * 64 && m_obj->destRect.y == (y_coord - 1) * 64)
//			{
//				Map::collidableMapObjects.erase(it);
//				Map::mapObjects.at(x_coord+y_resolution*(y_coord - 1))->tileId = 2;//finding that object in all map objects and changing its id and texture
//				Map::mapObjects.at(x_coord+y_resolution*(y_coord - 1))->texture = walk_tile;
//				break;
//			}
//			++it;
//		}
//		Map::map_arr[y_coord - 1][x_coord] = 2;
//	}
//	if (Map::map_arr[y_coord ][x_coord+ 1] == 3)//right
//	{
//		auto it = Map::collidableMapObjects.begin();
//		for (auto const &m_obj: Map::collidableMapObjects)
//		{
//			if (m_obj->destRect.x == (x_coord+1) * 64 && m_obj->destRect.y == (y_coord) * 64)
//			{
//				Map::collidableMapObjects.erase(it);
//				Map::mapObjects.at(x_coord+1+y_resolution*(y_coord))->tileId = 2;
//				Map::mapObjects.at(x_coord+1+y_resolution*(y_coord))->texture = walk_tile;
//				break;
//			}
//			++it;
//		}
//		Map::map_arr[y_coord ][x_coord+ 1] = 2;
//	}
//	if (Map::map_arr[y_coord + 1][x_coord] == 3)//down
//	{
//		auto it = Map::collidableMapObjects.begin();
//		for (auto const &m_obj: Map::collidableMapObjects)
//		{
//			if (m_obj->destRect.x == x_coord * 64 && m_obj->destRect.y == (y_coord + 1) * 64)
//			{
//				Map::collidableMapObjects.erase(it);
//				Map::mapObjects.at(x_coord+y_resolution*(y_coord + 1))->tileId = 2;//finding that object in all map objects and changing its id and texture
//				Map::mapObjects.at(x_coord+y_resolution*(y_coord + 1))->texture = walk_tile;
//				break;
//			}
//			++it;
//		}
//		Map::map_arr[y_coord + 1][x_coord] = 2;//maybe move
//	}
//	if (Map::map_arr[y_coord][x_coord - 1] == 3)//left
//	{
//		auto it = Map::collidableMapObjects.begin();
//		for (auto const &m_obj: Map::collidableMapObjects)
//		{
//			if (m_obj->destRect.x == (x_coord-1) * 64 && m_obj->destRect.y == (y_coord) * 64)
//			{
//				Map::collidableMapObjects.erase(it);
//				Map::mapObjects.at(x_coord-1+y_resolution*(y_coord))->tileId = 2;
//				Map::mapObjects.at(x_coord-1+y_resolution*(y_coord))->texture = walk_tile;
//				break;
//			}
//			++it;
//		}
//		Map::map_arr[y_coord][x_coord - 1] = 2;
//	}


}

void Player::update ()
{
	keyboardController.handleUserInput(); //handling user input

	//vector2D for storing previous value of our position to make proper collision
	Vector2D temp_pos;
	SDL_Rect temp_rect;
	temp_pos.x = position.x;
	temp_pos.y = position.y;
	temp_rect.x = static_cast<int>( position.x);
	temp_rect.y = static_cast<int>( position.y);
	temp_rect.w = keyboardController.transform.width * keyboardController.transform.scale;
	temp_rect.h = keyboardController.transform.height * keyboardController.transform.scale;

	if (keyboardController.direction == 4)
	{
		keyboardController.transform.velocity.x = 0;
		keyboardController.transform.velocity.y = 0;

	}
	if (keyboardController.tag == "bomb_placed")
	{
		placeBomb();
		bombIsPlaced = true;
	}

	else if (keyboardController.direction == 0)
	{
		temp_rect.y -= 3;
		for (const auto &map_obj: Map::collidableMapObjects)
		{
			if (checkCollision(temp_rect, map_obj->destRect))
			{
				cout << "UP" << endl;
				keyboardController.transform.velocity.y = 0;
			}
		}
	}
	else if (keyboardController.direction == 1)
	{
		temp_rect.x -= 3;
		for (const auto &map_obj: Map::collidableMapObjects)
		{
			if (checkCollision(temp_rect, map_obj->destRect))
			{
				cout << "LEFT" << endl;
				keyboardController.transform.velocity.x = 0;
			}
		}
	}
	else if (keyboardController.direction == 2)
	{
		temp_rect.y += 3;
		for (const auto &map_obj: Map::collidableMapObjects)
		{
			if (checkCollision(temp_rect, map_obj->destRect))
			{
				cout << "DOWN" << endl;
				keyboardController.transform.velocity.y = 0;
			}

		}
	}
	else
	{
		temp_rect.x += 3;
		for (const auto &map_obj: Map::collidableMapObjects)
		{
			if (checkCollision(temp_rect, map_obj->destRect))
			{
				cout << "RIGHT" << endl;
				keyboardController.transform.velocity.x = 0;
			}
		}
	}
	//===================================== calculating a position
	position.y += keyboardController.transform.velocity.y * keyboardController.transform.speed;
	position.x += keyboardController.transform.velocity.x * keyboardController.transform.speed;
	//===================================== calculating a position

	//===================================== turning position into rectangular
	destRect.x = static_cast<int>(position.x); //destRect and srcRect are defined in GameObject
	destRect.y = static_cast<int>(position.y);
	destRect.w = (keyboardController.transform.width) * keyboardController.transform.scale;
	destRect.h = (keyboardController.transform.height) * keyboardController.transform.scale;

//====================================================== managing bomb explosions
	auto it = bombContainer.begin();
	for (auto &b: bombContainer)
	{
		if (!b->isAlive)
		{
			explodeBomb(b); //explode the bomb
			bombContainer.erase(it); //erase it from the vector after exploding
			it = bombContainer.begin();
			break;
		}
		else
		{
			b->update();
			++it;
		}
	}
//====================================================== managing bomb explosions


}
void Player::draw ()
{
	for (auto const &b: bombContainer)
		TextureManager::draw(b->texture, b->srcRect, b->destRect);
	TextureManager::draw(texture, srcRect, destRect);
}
void Player::init ()
{

}
bool Player::checkCollision (const SDL_Rect &a, const SDL_Rect &b)
{
	// Rectangular border
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	// Calculate rectangle A The length of
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	// Calculate rectangle B The length of
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
		return false;
	if (topA >= bottomB)
		return false;
	if (rightA <= leftB)
		return false;
	if (leftA >= rightB)
		return false;
	//If none of the sides from A are outside B
	return true;
}
