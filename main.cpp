#include "Engine/engine.h"


Engine::Engine() :
	window(SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)),
	renderer(SDL_CreateRenderer(window, -1, 0)),
	event(SDL_Event()),
	map(Map(renderer))
{
	// SDL_SetRelativeMouseMode(SDL_TRUE);
}
Engine::~Engine() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Engine::handleEvents() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			running = false;

	}
}

void Engine::draw() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	map.draw();

	SDL_RenderPresent(renderer);
}

void Engine::update() {

	controlFPS();
}

void Engine::controlFPS() {
	Uint64 delta = SDL_GetTicks64() - lastFrame;
	if (delta < DELTA_TIME) {
		SDL_Delay(DELTA_TIME - delta);
	}
	lastFrame = SDL_GetTicks64();
}

bool Engine::isRunning() { return running; }


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