
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
	SDL_Texture *tempTex;

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);//stores data in tile
			switch (atoi(&tile))
			{
				case 0:
					tempTex = texture_background;
//				filename = "../src/assets/images/dirt.png";
					break;
				case 1:
					tempTex = texture_unbr_wall;
//				filename = "../src/assets/images/grass.png";
					break;
				case 2:
					tempTex = texture_walk_tile;
					break;
				case 3:
					tempTex = texture_wall;
					break;
//				filename = "../src/assets/images/water.png";
				default:
					break;
			}

			addTile(tempTex, atoi(&tile), x * 32, y * 32);
			mapFile.ignore();//skips coma

		}
	}
	mapFile.close();

}

void Map::addTile (SDL_Texture *p_tex, int p_tileId, int p_x, int p_y)
{
	mapObjects.emplace_back(
			std::make_unique<MapObject>(p_tex, p_tileId, static_cast<int> (p_x), static_cast<int> (p_y), 32, 32));
//	for(auto const & o:mapObjects)
//		if(o->tileId==1||o->tileId==3)
//			collidableMapObjects.push_back(&o);
	if (p_tileId == 1 || p_tileId == 3)
		collidableMapObjects.emplace_back(
				make_unique<MapObject>(p_tex, p_tileId, static_cast<int> (p_x), static_cast<int> (p_y), 32, 32));
}
