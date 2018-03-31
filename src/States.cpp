#include "States.h"
#include "Menu/MainMenu.h"
#include "Window.h"
#include "Game/Game.h"

/*
====================
id		->	state
---			--------
0			exit game
1			main menu
2			game start

*/


States::States()
{
	active = true;
	active_state = 1;

}


States::~States()
{

}


void States::check(bool &isClosed) {

	while (active) {
		
		//Handle state
		if (active_state == 0) {
			active = false;
			isClosed = !active;
			return;
		}
		else if (active_state == 1) {
			MainMenu menu;
			active_state = menu.choose();
		}
		else if (active_state == 2) {
			Game game;
			game.run();
			active_state = 1;
		}

	}
}