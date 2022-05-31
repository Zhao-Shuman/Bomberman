
#include "Map.h"
#include "Game.h"
#include <fstream>

Map::Map ()
{
}
Map::~Map ()
{


}
void Map::loadMap (const std::string &filename, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(filename);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);//stores data in tile
//			Game::addTile(atoi(&tile), x * 32, y * 32);
			mapFile.ignore();//skips coma
		}
	}

	mapFile.close();


}