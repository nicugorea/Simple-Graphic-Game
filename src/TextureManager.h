#pragma once

#include "includes.h"
#include "Window.h"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	static SDL_Texture* loadTexture(const char* path);
	static void draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);
	static void draw(int r, int g, int b);

private:


};

