#include "Window.h"

SDL_Renderer* Window::mRenderer = nullptr;
SDL_Event* Window::mEvent = nullptr;

Window::Window()
{
	isClosed = !init();
	SDL_SetRenderDrawColor(mRenderer, 27, 3, 99, 255);

}


Window::~Window()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	IMG_Quit();
	SDL_Quit();
}


bool Window::init() {

	if (SDL_Init(SDL_INIT_EVERYTHING)) {					
		std::cout << "Error initialising everything sdl_system" << std::endl;
		return false;
	}

	//window pointer
	mWindow = SDL_CreateWindow(	WIN_N,						//window name
								SDL_WINDOWPOS_CENTERED,		//window pos X
								SDL_WINDOWPOS_CENTERED,		//window pos Y
								WIN_W, WIN_H,				//window w and h
								NULL);						//flags

	if (mWindow == nullptr) {								
		std::cout << "Error creating window" << std::endl;
		return false;
	}

	//renderer pointer
	mRenderer = SDL_CreateRenderer(	mWindow,					//window pointer
									-1,							//rendering driver (-1 for first supporting flags)
									SDL_RENDERER_PRESENTVSYNC);	//flags
	if (Window::mRenderer == nullptr) {
		std::cout << "Error creating renderer" << std::endl;
		return false;
	}

	//event pointer
	mEvent = new SDL_Event;
	if (mEvent == nullptr) {
		std::cout << "Error creating event pointer" << std::endl;
		return false;
	}


	return true;
}


void Window::clear() {
	SDL_RenderClear(mRenderer);

}


void Window::display() {

	SDL_RenderPresent(mRenderer);

}


void Window::handleEvent() {
	if (SDL_PollEvent(mEvent)) {

		if (mEvent->type == SDL_QUIT) {
			isClosed = true;
		}
	
	}

}