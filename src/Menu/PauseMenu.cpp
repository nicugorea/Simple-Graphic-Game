#include "PauseMenu.h"
#include "../TextureManager.h"

/*
0		exit
1		continue

*/


PauseMenu::PauseMenu()
{

	optionsNr = 2;
	options = new Option[optionsNr];
	//continue
	options[0].state = 1;
	options[0].rect = { 100,100,200,100 };
	options[0].texture = TextureManager::loadTexture("res/img/continue_button.png");

	//leave
	options[1].state = 0;
	options[1].rect = { 100,300,200,100 };
	options[1].texture = TextureManager::loadTexture("res/img/leave_button.png");
}


PauseMenu::~PauseMenu()
{
}
