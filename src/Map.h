#pragma once

#ifndef BOMBERMAN_MAP_H
#define BOMBERMAN_MAP_H

#include <string>

class Map
{
public:
	Map ();
	~Map ();
	static void addTile(int p_id, int p_x, int p_y, int p_w, int p_h);
	static void loadMap (const std::string & filename,int sizeX, int sizeY);
private:
};

#endif //BOMBERMAN_MAP_H
