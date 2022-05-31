#pragma once

#ifndef BOMBERMAN_MAPOBJECT_H
#define BOMBERMAN_MAPOBJECT_H

#include "SDL.h"
#include "SDL_image.h"

class MapObject
{
public:
	MapObject (int p_id, int p_x, int p_y, int p_w, int p_h)
	{
		tileRect.x = p_x;
		tileRect.y = p_y;
		tileRect.w = p_w;
		tileRect.h = p_h;
		tileId = p_id;
		switch (tileId)
		{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;

		}
	}

	SDL_Texture *texture;
	SDL_Rect tileRect;
	int tileId;
};

#endif //BOMBERMAN_MAPOBJECT_H
