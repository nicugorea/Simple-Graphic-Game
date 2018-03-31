#include "Game.h"
#include "Object/Player.h"
#include "../TextureManager.h"
#include "../Menu/PauseMenu.h"
#include "Level/Level.h"

Player *player;
Level *level;

Game::Game()
{
	init();
}


Game::~Game()
{
}


void Game::init() {
	player = new Player("res/img/player.png");
	player->setTextureRect(0, 0, 512, 1024);
	player->setObjectRect(0, 0, 64, 128);
	mRunning = true;

}


void Game::handleEvent() {
	if (SDL_PollEvent(Window::mEvent)) {
		if (Window::mEvent->type == SDL_QUIT)
			mRunning = false;
	}

	//escape key - pause menu
	if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_ESCAPE]) {
		PauseMenu menu;
		int tmp = menu.choose();
		if (tmp == 0)
			mRunning = false;
	}
	
	player->Update(level->data);


}


void Game::run() {

	level = new Level;
	level->load("level/first.nicu");

	int *x = new int;int *y = new int;
	level->getPlayerPos(x, y);
	player->setPos(0, *y);
	free(x); free(y);
	Uint32 lastFrame = SDL_GetTicks();
	int delay;
	while (mRunning) {
		delay = SDL_GetTicks() - lastFrame;
		SDL_RenderClear(Window::mRenderer);
		level->draw();
		player->draw();
		
		SDL_RenderPresent(Window::mRenderer);
		
		
		handleEvent();
		if (delay < FPS) {
			SDL_Delay(FPS - delay);
			lastFrame = SDL_GetTicks();
		}
	}
}