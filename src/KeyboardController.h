#pragma once
#ifndef BOMBERMAN_KEYBOARDCONTROLLER_H
#define BOMBERMAN_KEYBOARDCONTROLLER_H

#include "TransformObject.h"
//#include "GameObject.h"
#include "Game.h"
#include "Player.h"

class KeyboardController
{

public:
	TransformObject transform;
	int direction;
//	array<int,4> direction{0,0,0,0};


	KeyboardController ()
	{
		transform.position.x = 0.0f;
		transform.position.y = 0.0f;

	}


	void handleUserInput ()
	{

		if (Game::event.type == SDL_KEYDOWN)
		{
			direction = 4;
			switch (Game::event.key.keysym.sym)
			{
				case SDLK_w:
					direction = 0;
//					cout << "Pressed w" << endl;
					transform.velocity.y = -1;//it will move the player up because of pos.y = velocity.y * speed
					break;
				case SDLK_a:
					direction = 1;
//					cout << "Pressed a" << endl;
					transform.velocity.x = -1;
					break;
				case SDLK_s:
					direction = 2;
//					cout << "Pressed s" << endl;
					transform.velocity.y = 1;
					break;
				case SDLK_d:
					direction = 3;
//					cout << "Pressed d" << endl;
					transform.velocity.x = 1;
					break;
				default:
					break;
			}
		}
		if (Game::event.type == SDL_KEYUP)//when we release the key, we set our velocity to 0
		{
			switch (Game::event.key.keysym.sym)
			{
				case SDLK_w:
					direction = 4; //default
					transform.velocity.y = 0;
					break;
				case SDLK_a:
					direction = 4; //default
					transform.velocity.x = 0;
					break;
				case SDLK_s:
					direction = 4; //default
					transform.velocity.y = 0;
					break;
				case SDLK_d:
					direction = 4; //default
					transform.velocity.x = 0;
					break;

				default:
					break;
			}
		}
	}

};

#endif //BOMBERMAN_KEYBOARDCONTROLLER_H
