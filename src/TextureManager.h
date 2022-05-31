
#ifndef BOMBERMAN_TEXTUREMANAGER_H
#define BOMBERMAN_TEXTUREMANAGER_H

#include <iostream>

#include "ErrorHandler.h"
using namespace std;

#include "Game.h"

class TextureManager{
public:
	static SDL_Texture * loadTexture(const char * p_filename);
	static void draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dst );

};

#endif //BOMBERMAN_TEXTUREMANAGER_H

