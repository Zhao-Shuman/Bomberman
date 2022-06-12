#include "TextureManager.h"



SDL_Texture *TextureManager::loadTexture (const char *p_filename)
{
	SDL_Surface *tmpSurface = IMG_Load(p_filename);
	if (tmpSurface == nullptr)
		logSDLError(cout, "IMG_Load");
	SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;


}
void TextureManager::draw (SDL_Texture *tex, SDL_Rect src, SDL_Rect dst)
{
	if(SDL_RenderCopy(Game::renderer, tex, &src, &dst)!=0)
		logSDLError(cout,"SDL_RenderCopy ");


}
