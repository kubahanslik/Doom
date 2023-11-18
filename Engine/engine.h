#ifndef ENGINE
#define ENGINE

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "map.h"


#define FPS 60


class Engine {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	Map map;

	bool running = true;
	Uint64 lastFrame = SDL_GetTicks64();

public:
	static const int DELTA_TIME = 1000 / FPS;
	static const int WINDOW_WIDTH = 1600;
	static const int WINDOW_HEIGHT = 900;

private:
	void controlFPS();

public:
	Engine();
	~Engine();

	void handleEvents();
	void draw();
	void update();

	bool isRunning();
};

#endif // !ENGINE