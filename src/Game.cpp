#include <memory>

#include "Game.h"
#include "ErrorHandler.h"
#include "Player.h"
#include "KeyboardController.h"
#include "Map.h"
#include "MapObject.h"
#include "CircleCollision.h"
#include "Enemy.h"
#include "EnemyOvapi.h"
#include "EnemyGhost.h"

using namespace std;

SDL_Renderer *Game::renderer = nullptr;//static variable
SDL_Event Game::event;//static variable


int Map::map_arr[15][15];//static variable
std::vector<std::unique_ptr<GameObject>> Game::gameObjects;//static variable
std::vector<std::unique_ptr<MapObject>> Map::mapObjects;//static variable
std::vector<std::unique_ptr<MapObject>> Map::collidableMapObjects;//static variable
std::vector<std::unique_ptr<Flame>> Player::flames;
std::vector<std::unique_ptr<GameObject>> Game::bonuses;//static variable
std::vector<std::unique_ptr<GameObject>> Game::players;


unique_ptr<Map> map1;

static unique_ptr<Player> player;//static variable

void Game::getUserInput ()
{
	size_t gameMode;
	cout << "-------------------------------------------------------------" << endl;
	std::cout << "Choose your game mode " << endl;
	std::cout << "0:  Single-Player " << endl;
	std::cout << "1:  Multi-Player " << endl;
	std::cout << "2:  Exit The Game " << endl;
	cout << "-------------------------------------------------------------" << endl;

	while (true)
	{
		cin >> gameMode;
		if (cin.eof())
		{
//			this->clean();
			throw std::invalid_argument("EOF");;
		}
		if (cin.good() && (gameMode == 0 || gameMode == 1 || gameMode == 2))
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "Invalid input of gameMode, try typing 0 for single-player, or 1 for multi-player." << endl;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	switch (gameMode)
	{
		case 0:
			singlePlayer = true;
			multiPlayer = false;
			break;
		case 1:
			multiPlayer = true;
			singlePlayer = false;
			break;
		case 2:
			continueGame = false;
			isRunning = false;
			cout << "!!!!!!!!!!!!----------------         ----------------!!!!!!!!!!!!" << endl;
			cout << endl;
			cout << "Thank You For Playing The Game" << endl;
			cout << endl;
			cout << "!!!!!!!!!!!!----------------         ----------------!!!!!!!!!!!!" << endl;
			isRunning = false;
			break;
		default:
			break;
	}

}
void Game::initGame (const char *p_name, int p_xPos, int p_Ypos, int p_w, int p_h, bool fullscreen)
{
	//===================================================== when restarting the game, we should clear all containers
	while (!gameObjects.empty())//detecting if game has restarted
	{
		gameObjects.erase(gameObjects.begin());
	}
	while (!Map::mapObjects.empty())
	{
		Map::mapObjects.erase(Map::mapObjects.begin());
	}
	while (!Map::collidableMapObjects.empty())
	{
		Map::collidableMapObjects.erase(Map::collidableMapObjects.begin());
	}
	while (!bonuses.empty())
	{
		bonuses.erase(bonuses.begin());
	}
	while (!Player::flames.empty())
	{
		Player::flames.erase(Player::flames.begin());
	}
	//=====================================================

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
	//================================always happens
	map1 = make_unique<Map>();
	map1->initialize();
	map1->loadMap("../src/assets/dev/15x15_test.map", 15, 15);

	player = make_unique<Player>("../src/assets/images/bomberman.png", 32 * 2, 32 * 3, "player1");
//	gameObjects.emplace_back(move(player));
	//================================always happens

	if (singlePlayer)
	{
		gameObjects.emplace_back(
				make_unique<EnemyOvapi>("../src/assets/images/enemy_ovapi.png", 32 * 12, 32 * 3,
				                        "enemy_ovapi"));//32*12, 32*3
		gameObjects.emplace_back(
				make_unique<Enemy>("../src/assets/images/enemy_common.png", 32 * 12, 32 * 11,
				                   "enemy"));//
		gameObjects.emplace_back(
				make_unique<EnemyGhost>("../src/assets/images/enemy_ghost.png", 32 * 12, 32 * 11,
				                        "enemy_ghost"));//

	}
	else if (multiPlayer)
	{
		unique_ptr<Player> player2 = make_unique<Player>("../src/assets/images/bomberman2.png", 32 * 12, 32 * 3,
		                                                 "player2");
		gameObjects.emplace_back(move(player2));

	}

	gameObjects.emplace_back(move(player));

	isRunning = true;

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
void Game::congratulateWinner ()
{
	cout << "!!!!!!!!!!!!----------------GAME OVER----------------!!!!!!!!!!!!" << endl;
	cout << endl;
	if (multiPlayer) {}
	cout << gameObjects[0]->tag_obj << " won, " << "score is: " << gameObjects[0]->currentScore << endl;
	if (singlePlayer)
		cout << gameObjects[0]->tag_obj << " won " << endl;
	cout << endl;
	cout << "!!!!!!!!!!!!----------------         ----------------!!!!!!!!!!!!" << endl;
	isRunning = false;
	SDL_Delay(500);//wait a lil bit
}
void Game::declareATie ()
{
	if (singlePlayer)
	{
		cout << "!!!!!!!!!!!!----------------GAME OVER----------------!!!!!!!!!!!!" << endl;

		cout << endl;
		cout << "No one has won, both you and an enemy died at the same time" << endl;
		cout << endl;
		cout << "!!!!!!!!!!!!----------------         ----------------!!!!!!!!!!!!" << endl;
		isRunning = false;
	}
	if (multiPlayer)
	{
		cout << "!!!!!!!!!!!!----------------GAME OVER----------------!!!!!!!!!!!!" << endl;
		cout << endl;
		cout << "No one has won, both players died at the same time" << endl;
		cout << endl;
		cout << "!!!!!!!!!!!!----------------         ----------------!!!!!!!!!!!!" << endl;
	}
	isRunning = false;

}
bool Game::isGameFinished ()
{
	if (multiPlayer)
	{
		if (gameObjects.size() == 1)
		{
			congratulateWinner();//player1 or player2
			return true;
		}
		else if (gameObjects.size() == 0)//players were simultaneously exploded by the bomb
		{
			declareATie();
			return true;
		}
	}
	if (singlePlayer)
	{
		if (gameObjects.size() == 1)
		{
			congratulateWinner();//player or enemy
			return true;
		}
		else if (gameObjects.size() == 0)//player and the enemy were simultaneously exploded by the bomb
		{
			declareATie();
			return true;
		}
	}
	return false;
}
void Game::update ()
{
	Player::flames.erase(remove_if(begin(Player::flames), end(Player::flames),
	                               [] (const unique_ptr<Flame> &mFlame) {
		                               return !mFlame->isAlive;
	                               }), end(Player::flames));

//	cout<<Game::gameObjects.size()<<endl;
	Game::gameObjects.erase(remove_if(begin(Game::gameObjects), end(Game::gameObjects),
	                                  [] (const unique_ptr<GameObject> &mObj) {
		                                  return !mObj->isAlive;
	                                  }), end(Game::gameObjects));

	if (isGameFinished())//check whether game has finished or not
		return;

	for (const auto &obj: Game::gameObjects)
	{
		obj->update();
	}
	for (const auto &flame: Player::flames)//collision between flames and gameObjects(players and ghosts)
	{
		for (const auto &obj: Game::gameObjects)
		{
			if (CollisionManager::checkCollision(flame->destRect, obj->destRect))
			{
				if (obj->tag_obj == "enemy" || obj->tag_obj == "enemy_ovapi" || obj->tag_obj == "enemy_ghost")
				{
					//======================== adding  points to the player when he kills an enemy
					for (const auto &obj1: Game::gameObjects)
					{
						if (obj1->tag_obj == "player1")
						{
							obj1->currentScore += 600;
						}
					}
					//======================== adding  points to the player when he kills an enemy

				}
				obj->isAlive = false;// if there is a collision between an enemy and the
			}
		}
	}

}
void Game::render ()
{
	SDL_RenderClear(renderer);
	for (const auto &obj: Map::mapObjects)
	{
		obj->draw();
	}

	for (const auto &obj: Map::collidableMapObjects)
	{
		obj->draw();
	}

	for (const auto &obj: Game::gameObjects)
	{
		obj->draw();
	}
	for (const auto &obj: Game::bonuses)
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
//	cout << "Thanks for playing the game" << endl;
}
