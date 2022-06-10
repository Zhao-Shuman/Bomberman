#pragma once
#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

#include <vector>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
#include "Game.h"

class Game
{
public:
	Game () = default;
	~Game () noexcept = default;
	void initGame (const char *p_name, int p_xPos, int p_Ypos, int p_w, int p_h, bool fullscreen);
	void handleEvents ();
	void update ();
	void render ();
	void clean ();
	bool running () const {return isRunning;}
//	boo
	static SDL_Renderer *renderer;
	static SDL_Event event;
	static std::vector<std::unique_ptr<GameObject>> gameObjects;

private:
	SDL_Window *window{};
	bool isRunning = true;


};

#endif //BOMBERMAN_GAME_H
