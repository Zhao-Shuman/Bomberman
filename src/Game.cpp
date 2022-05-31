#include <memory>

#include "Game.h"
#include "ErrorHandler.h"
#include "Player.h"

using namespace std;

SDL_Renderer *Game::renderer = nullptr;//static variable
SDL_Event Game::event;//static variable
std::vector<std::unique_ptr<GameObject>> Game::gameObjects;//static variable


void Game::initGame (const char *p_name, int p_xPos, int p_Ypos, int p_w, int p_h, bool fullscreen)
{
	Uint32 flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		logSDLError(cout, "SDL_INIT");
		isRunning = false; //Game.h variable for detecting whether to continue main cycle or not
	}
	if (!IMG_Init(IMG_INIT_PNG))
	{
		logSDLError(cout, "IMG_Init");
		isRunning = false;
	}

	window = SDL_CreateWindow(p_name, p_xPos, p_Ypos, p_w, p_h, flags);
	if (window == nullptr)
	{
		logSDLError(cout, "SDL_CreateWindow");
		isRunning = false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		logSDLError(cout, "SDL_CreateRenderer");
		isRunning = false;
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);//setting color to white
	//==========================================================================
	isRunning = true;

	gameObjects.emplace_back(make_unique<Player>("../src/assets/README_assets/player.png"));

}
void Game::handleEvents ()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}
void Game::update ()
{
	for (const auto &obj: gameObjects)
	{
		obj->update();
	}
}
void Game::render ()
{
	SDL_RenderClear(renderer);
	for (const auto &obj: gameObjects)
	{
		obj->draw();
	}
	SDL_RenderPresent(renderer);

}
void Game::clean ()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_QUIT;
	cout << "Game cleaned" << endl;
}
