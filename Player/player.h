#ifndef PLAYER
#define PLAYER

#include <SDL.h>
#include <cmath>
#include "../Engine/map.h"


class Player {
private:
	SDL_Renderer* renderer;
	Map& map;
	Uint64& deltaTime;

public:
	static const int SIZE = 30;
	static const int HALF_SIZE = SIZE / 2;
	static const int WIDTH = 3;
	static constexpr double SPEED = 0.005;
	static constexpr double ROT_SPEED = 0.06;
	static constexpr double MOUSE_SENSITIVITY = 0.0015;

	double pos_x, pos_y;
	double angle;
	int mouse_rel_x, mouse_rel_y;

private:
	int getTileX();
	int getTileY();

public:
	Player(SDL_Renderer* rend, Map& map, Uint64& deltaTime);
	~Player();

	void update();
	void draw();
};

#endif // !PLAYER