//
// Created by User win 10 on 31.05.2022.
//

#include "Player.h"
#include "TextureManager.h"


Player::Player (const char *filename)
{
	setTex(filename);
	srcRect.x = transformObject.;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
}
void Player::setTex (const char *p_filename)
{
	texture = TextureManager::loadTexture(p_filename);
}

void Player::update ()
{

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 3;
	destRect.h = srcRect.h * 3;

}
void Player::draw ()
{
	TextureManager::draw(texture, srcRect, destRect);
}


void Player::init ()
{

}

