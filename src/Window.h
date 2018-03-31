#pragma once
#include "includes.h"

class Window
{
public:
	Window();
	~Window();

private:
	bool init();

public:
	void clear();
	void display();
	void handleEvent();

public:
	SDL_Window *mWindow = nullptr;
	static SDL_Renderer *mRenderer;
	static SDL_Event *mEvent;
	bool isClosed;

};

