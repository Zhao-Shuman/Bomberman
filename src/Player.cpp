//
// Created by User win 10 on 31.05.2022.
//
#include <cmath>

#include "Player.h"
#include "TextureManager.h"
#include "Map.h"

Player::Player (const char *filename)
{
//	init();
	keyboardController.transform.position.zero();
	transformObject = keyboardController.transform;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
	setTex(filename);
}
Player::Player (const char *filename, int x, int y)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
	keyboardController.transform.position.zero();
	transformObject = keyboardController.transform;
	destRect.x = x*2;
	destRect.y = y*2;
	position.x = x*2;
	position.y = y*2;
	keyboardController.transform.scale =2;
	setTex(filename);

}
void Player::setTex (const char *p_filename)
{
	texture = TextureManager::loadTexture(p_filename);
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

	if (keyboardController.direction == 0)
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
//			cout << " PosX: " << position.x << " PosY: " << position.y << " VelocityX: "
//			     << keyboardController.transform.velocity.y
//			     << " VelocityY:" << keyboardController.transform.velocity.y << endl;

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



//	if (checkCollision())
//	cout << " PosX: " << position.x << " PosY: " << position.y << " VelocityX: " << keyboardController.transform.velocity.y
//	     << " VelocityY:" << keyboardController.transform.velocity.y << endl;
	//===================================== calculating a position
	position.y += keyboardController.transform.velocity.y * keyboardController.transform.speed;
	position.x += keyboardController.transform.velocity.x * keyboardController.transform.speed;
	//===================================== calculating a position

	//===================================== turning position into rectangular
	destRect.x = static_cast<int>(position.x); //destRect and srcRect are defined in GameObject
	destRect.y = static_cast<int>(position.y);
	destRect.w = (keyboardController.transform.width) * keyboardController.transform.scale;
	destRect.h = (keyboardController.transform.height) * keyboardController.transform.scale;


}
void Player::draw ()
{
	TextureManager::draw(texture, srcRect, destRect);
}


void Player::init ()
{
//	keyboardController->transform->position.x = 0;
//	keyboardController->transform->position.y = 0;
//	transformObject->position.x = keyboardController->transform->position.x;
//	transformObject->position.y = keyboardController->transform->position.y;

}
bool Player::checkCollision (const SDL_Rect &a, const SDL_Rect & b)
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
	if( bottomA <= topB )
	{

		return false;
	}

	if( topA >= bottomB )
	{

		return false;
	}

	if( rightA <= leftB )
	{

		return false;
	}

	if( leftA >= rightB )
	{

		return false;
	}

	//If none of the sides from A are outside B
	return true;

//	int playerHalfW = destRect.w / 2;
//	int playerHalfH = destRect.h / 2;
//	int wallHalfW = gameObject.destRect.w / 2;
//	int wallHalfH = gameObject.destRect.h / 2;
//	int playerCenterX = (destRect.x + destRect.w) / 2;
//	int playerCenterY = (destRect.y + destRect.h) / 2;
//	int wallCenterX = (gameObject.destRect.x + gameObject.destRect.w) / 2;
//	int wallCenterY = (gameObject.destRect.y + gameObject.destRect.h) / 2;
//	int diffX = playerCenterX - wallCenterX;
//	int diffY = playerCenterY - wallCenterY;
//	int minXDist = playerHalfW + wallHalfW;
//	int minYDist = playerHalfH + wallHalfH;
//	int depthX = diffX > 0 ? minXDist - diffX : -minXDist - diffX;
//	int depthY = diffY > 0 ? minYDist - diffY : -minYDist - diffY;
//	if (depthX != 0 && depthY != 0)
//	{
//		if (abs(depthX) < abs(depthY))
//		{
//			if (depthX > 0)
//			{
//				cout << "left side" << endl;
//			}
//			else
//				cout << "right side" << endl;
//
//		}
//		else
//		{
//			if (depthY > 0)
//			{
//				cout << "top side" << endl;
//			}
//			else
//				cout << "bottom side" << endl;
//		}
//	}
//	return false;

}
