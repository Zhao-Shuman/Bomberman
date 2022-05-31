#include <iostream>
#include <memory>

#include "Game.h"
#include "Player.h"

using namespace std;

unique_ptr<Game> game = make_unique<Game>();


int main (int argc, char *args[])
{

	//================================================== FPS MANAGEMENT
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	//==================================================



	game->initGame("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks(); //ticks since we first initialized sdl
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;//how long it took to go through 1 cycle of main loop

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	std::cout << "Hello, World!" << std::endl;
	return 0;

}

