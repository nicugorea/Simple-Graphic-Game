#include "MainMenu.h"
#include "../TextureManager.h"


MainMenu::MainMenu()
{
	optionsNr = 2;
	options = new Option[optionsNr];
	//start
	options[0].state = 2;
	options[0].rect = { 100,100,200,100 };
	options[0].texture = TextureManager::loadTexture("res/img/start_button.png");

	//exit
	options[1].state = 0;
	options[1].rect = { 100,300,200,100 };
	options[1].texture = TextureManager::loadTexture("res/img/exit_button.png");
}


MainMenu::~MainMenu()
{
}








