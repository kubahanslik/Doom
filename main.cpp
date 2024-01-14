#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Engine/map.h"
#include "Player/player.h"

#define FPS 60

extern const int TARGET_DELTA_TIME = 1000 / FPS;
extern const int WINDOW_WIDTH = 1600;
extern const int WINDOW_HEIGHT = 900;


class Engine {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	Map map;
	Player player;

	bool running = true;
	Uint64 lastFrame = SDL_GetTicks64();
	Uint64 deltaTime = TARGET_DELTA_TIME;

public:
	Engine() :
		window(SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)),
		renderer(SDL_CreateRenderer(window, -1, 0)),
		event(),
		map(renderer),
		player(renderer, map, deltaTime)
	{
		// SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	~Engine() {
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

		map.draw();
		//player.draw();

		SDL_RenderPresent(renderer);
	}

	void update() {
		//player.update();

		controlFPS();
	}

	bool isRunning() { return running; }

private:
	void controlFPS() {
		deltaTime = SDL_GetTicks64() - lastFrame;
		if (deltaTime < TARGET_DELTA_TIME) {
			SDL_Delay(TARGET_DELTA_TIME - deltaTime);
			deltaTime = TARGET_DELTA_TIME;
		}
		lastFrame = SDL_GetTicks64();
	}
};


int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) && IMG_Init(IMG_INIT_JPG & IMG_INIT_PNG)) {
		std::cout << "[!] Init failed\n";
	}
	else {
		std::cout << "[*] Init successful\n";
	}

	Engine engine;

	while (engine.isRunning()) {
		engine.handleEvents();
		engine.update();
		engine.draw();
	}

	SDL_Quit();

	return 0;
}