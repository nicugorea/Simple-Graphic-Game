#pragma once

#include "../../includes.h"

class GameObject
{
public:
	GameObject();
	GameObject(const char* path);
	~GameObject();
	void draw();
	void move(int x, int y);
	void setPos(int x, int y);
	void setTextureRect(int x, int y, int w, int h);
	void setObjectRect(int x, int y, int w, int h);
protected:
	SDL_Rect objectRect = { 0,0,32,32 };	//rectangle of object in game (dest)
	SDL_Rect textureRect = { 0,0,32,32 };	//rectangle of texture for object (source)
	SDL_Texture *mTexture;					//texture for object
};

