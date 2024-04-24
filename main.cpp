#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Engine/map.h"
#include "Player/player.h"
#include "Engine/raycaster.h"
#include "Engine/projector.h"
#include "Sprites/spritehandler.h"

#define FPS 60

const int TARGET_DELTA_TIME = 1000 / FPS;
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;


class Engine {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	Map map;
	Player player;
	Projector projector;
	Raycaster raycaster;
	SpriteHandler sprite_handler;

	bool running = true;
	Uint64 lastFrame = SDL_GetTicks64();
	Uint64 deltaTime = TARGET_DELTA_TIME;

public:
	Engine() :
		window(SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)),
		renderer(SDL_CreateRenderer(window, -1, 0)),
		event(),
		map(renderer),
		player(renderer, map, deltaTime),
		projector(renderer, player),
		raycaster(renderer, player, map, projector),
		sprite_handler(renderer, player, projector)
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

		sprite_handler.draw();
		projector.draw();

		SDL_RenderPresent(renderer);
	}

	void update() {
		player.update();
		sprite_handler.update();
		raycaster.update();

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
	if (SDL_Init(SDL_INIT_VIDEO) && IMG_Init(IMG_INIT_PNG)) {
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