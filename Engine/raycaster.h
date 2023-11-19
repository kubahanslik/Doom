#ifndef RAYCASTER
#define RAYCASTER

#include <iostream>
#include <SDL.h>
#include <cmath>
#include "engine.h"
#include "map.h"
#include "../Player/player.h"
#include "projector.h"

struct Ray {
	double angle;
	double depth_vert, depth_hor;
	double x_vert, y_vert, x_hor, y_hor;

	double dx, dy, delta_depth;
	double cos_a, sin_a;

	double depth;
	double offset;
};


class Raycaster {
private:
	SDL_Renderer* renderer;
	Player& player;
	Map& map;
	Projector projector;

public:
	static constexpr double FOV = 1.4;
	static constexpr double HALF_FOV = FOV / 2;
	static const int NUM_RAYS = 800;
	static constexpr double DELTA_ANGLE = FOV / NUM_RAYS;
	static const int MAX_DEPTH = 20;
	static const int RAY_WIDTH = Engine::WINDOW_WIDTH / NUM_RAYS;
	static const double SCREEN_DEPTH;

public:
	Raycaster(SDL_Renderer* rend, Player& p, Map& m);
	~Raycaster();

	void update();

};


#endif // !RAYCASTER
