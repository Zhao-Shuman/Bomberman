#pragma once
#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

#include <vector>
#include <memory>
#include <algorithm>

#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
#include "Game.h"

class Bomb;

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
//	bool firstMapDrawing;
	static SDL_Renderer *renderer;
	static SDL_Event event;
	void getUserInput();
	void congratulateWinner();
	bool isGameFinished();
	void declareATie();
	bool singlePlayer = false;
	bool multiPlayer = false;
	bool continueGame = true;
	bool isRunning = true;

#define USE_FANCYPANTS
#ifdef USE_FANCYPANTS
	static std::vector<std::unique_ptr<GameObject>> gameObjects;
	static std::vector<std::unique_ptr<GameObject>> bonuses;
	static std::vector<std::unique_ptr<GameObject>> players;

#endif
//	 unique_ptr<Player> player23;
//	 uniPlayer::GameObject player2;
private:
	SDL_Window *window{};


};

#endif //BOMBERMAN_GAME_H
