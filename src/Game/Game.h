#pragma once
#include "../includes.h"


class Game
{
public:
	Game();
	~Game();
	void run();
	void init();
private:
	void handleEvent();

private:
	bool mRunning=false;
};

