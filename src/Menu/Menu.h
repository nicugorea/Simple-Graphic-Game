#pragma once

#include "../includes.h"

typedef struct {
	char state;
	SDL_Rect rect;
	SDL_Texture *texture;
}Option;

class Menu
{
public:
	Menu();
	~Menu();

public:
	char choose();

protected:
	bool clicked(Option option);
	bool hover(Option option);

protected:
	Uint8 optionsNr;
	Option *options;
	SDL_Texture *clickTexture;
	SDL_Texture *hoverTexture;

};

