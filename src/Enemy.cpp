//
// Created by User win 10 on 10.06.2022.
//

#include "Enemy.h"

Enemy::Enemy (const char *p_filename, int p_x, int p_y)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
	destRect.x = p_x*2;//2 is the scale of the tile
	destRect.y = p_y*2;//2 is the scale of the tile
	setTex(p_filename);
}

void Enemy::update ()
{

	position.x =1;
	position.y = 1;
	destRect.x+= static_cast<int>(position.x);
	destRect.y+=static_cast<int>(position.y);
	destRect.w = srcRect.w*transformObject.scale;
	destRect.h =srcRect.h*transformObject.scale;
}
void Enemy::draw ()
{
	TextureManager::draw(texture, srcRect, destRect);
//	cout<<"draw enemy"<<endl;

}
void Enemy::init ()
{
//	cout << "nice" << endl;
}
bool Enemy::checkCollision (const SDL_Rect &a,const SDL_Rect &b)
{
	return true;
}

void Enemy::setTex (const char *p_filename)
{
	texture = TextureManager::loadTexture(p_filename);
}
