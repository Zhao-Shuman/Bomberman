#include <memory>

#include "Game.h"
#include "ErrorHandler.h"
#include "Player.h"
#include "KeyboardController.h"
#include "Map.h"
#include "MapObject.h"
#include "CircleCollision.h"
#include "Enemy.h"

using namespace std;

SDL_Renderer *Game::renderer = nullptr;//static variable
SDL_Event Game::event;//static variable

std::vector<std::unique_ptr<GameObject>> Game::gameObjects;//static variable
std::vector<std::unique_ptr<MapObject>> Map::mapObjects;//static variable
std::vector<std::unique_ptr<MapObject>> Map::collidableMapObjects;//static variable

unique_ptr<Map> map;



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

	map = make_unique<Map>();
	map->initialize();
	map->loadMap("../src/assets/dev/15x15.map", 15, 15);
//	player = make_unique<Player>("../src/assets/images/bomberman.png");
	gameObjects.emplace_back(make_unique<Enemy>("../src/assets/images/enemy_ovapi.png",32*2+2,32*3+2));
	gameObjects.emplace_back(make_unique<Player>("../src/assets/images/bomberman.png", 32*2,32*3));
//	gameObjects.emplace_back(player);


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
	for (const auto &obj: Game::gameObjects)
	{
		obj->update();
	}
//	for (const auto &obj: Game::gameObjects)
//	{
//
//		for(const auto &obj2:Map::collidableMapObjects)
//		{
//			obj->checkCollision(*obj2);
//		}
//	}

}
void Game::render ()
{
	SDL_RenderClear(renderer);

	for (const auto &obj: Map::mapObjects)
	{
		obj->draw();
	}
	for (const auto &obj: Game::gameObjects)
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
