#include <iostream>
#include <SDL.h>
#include "Engine/map.h"


#define FPS 60

const int DELTA_TIME = 1000 / FPS;
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;


class Game {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	Map map;

	bool running = true;
	Uint64 lastFrame = SDL_GetTicks64();

private:
	void controlFPS() {
		Uint64 delta = SDL_GetTicks64() - lastFrame;
		if (delta < DELTA_TIME) {
			SDL_Delay(DELTA_TIME - delta);
		}
		lastFrame = SDL_GetTicks64();
	}


public:
	Game() :
		window(SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)),
		renderer(SDL_CreateRenderer(window, -1, 0)),
		event(SDL_Event()),
		map(Map(renderer))
	{
		// SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	~Game() {
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
	}

	void handleEvents() {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;

		}
	}

	void draw() {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

	void update() {

		controlFPS();
	}

	bool isRunning() { return running; }
	const int& getDeltaTime() { return DELTA_TIME; }
	const int& getWindowWidth() { return WINDOW_WIDTH; }
	const int& getWindowHeight() { return WINDOW_HEIGHT; }
};



int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "[!] Init failed\n";
	}
	else {
		std::cout << "[*] Init successful\n";
	}

	Game game;

	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.draw();
	}

	SDL_Quit();

	return 0;
}