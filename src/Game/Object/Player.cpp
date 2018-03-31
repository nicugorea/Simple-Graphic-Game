#include "Player.h"
#include "../../TextureManager.h"


Player::Player(const char* path)
{
	mTexture = TextureManager::loadTexture(path);
	objectRect.x = WIN_W / 2;
	dx = 0; dy = 0; ax = 0; ay = 0;
	lastFrame = SDL_GetTicks();
}


Player::~Player()
{
}

//time from last check in miliseconds
int Player::deltaT() {
	int tmp = SDL_GetTicks() - lastFrame;
	lastFrame = SDL_GetTicks();
	return tmp;
}




	void Player::Update(Uint8 data[LEVEL_H][LEVEL_W]) {


		if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT])
			move(2, 0);
		if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT])
			move(-2, 0);
		if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_UP])
			move(0, -2);
		if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_DOWN])
			move(0, 2);


	}

