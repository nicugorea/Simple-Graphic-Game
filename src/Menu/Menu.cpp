#include "Menu.h"
#include "../TextureManager.h"


Menu::Menu()
{
	

	clickTexture = TextureManager::loadTexture("res/img/selected_button.png");
	hoverTexture = TextureManager::loadTexture("res/img/hover_button.png");
}


Menu::~Menu()
{
}


bool Menu::hover(Option option) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= option.rect.x && y >= option.rect.y
		&& x <= option.rect.x + option.rect.w && y <= option.rect.y + option.rect.h) {
		return true;
	}
	return false;

}


bool Menu::clicked(Option option) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= option.rect.x && y >= option.rect.y
		&& x <= option.rect.x + option.rect.w && y <= option.rect.y + option.rect.h
		&& Window::mEvent->type == SDL_MOUSEBUTTONDOWN
		&& Window::mEvent->button.button == SDL_BUTTON_LEFT) {
		return true;
	}
	return false;

}


char Menu::choose() {
	int tmp = -1;
	//handle event
	while (1) {

		SDL_PollEvent(Window::mEvent);
		SDL_RenderClear(Window::mRenderer);


		for (int i = 0; i < optionsNr; i++)
		{
			TextureManager::draw(options[i].texture, NULL, &options[i].rect);
			if (hover(options[i])) {
				TextureManager::draw(hoverTexture, NULL, &options[i].rect);
			}

			if (clicked(options[i])) {
				TextureManager::draw(clickTexture, NULL, &options[i].rect);
				tmp = options[i].state;
			}
		}


		SDL_RenderPresent(Window::mRenderer);


		if (tmp != -1)
			break;
	}

	return tmp;
}