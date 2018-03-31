#include "TextureManager.h"



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}



SDL_Texture* TextureManager::loadTexture(const char* path) {
	SDL_Surface *tmpSurface = IMG_Load(path);
	SDL_Texture *tmpTexture = SDL_CreateTextureFromSurface(Window::mRenderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tmpTexture;
}


void TextureManager::draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest) {
	SDL_RenderCopy(Window::mRenderer, texture, src, dest);
}


void TextureManager::draw(int r, int g, int b) {
	SDL_RenderDrawRect(Window::mRenderer, NULL);
}