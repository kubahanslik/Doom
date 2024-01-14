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
	static const int WIDTH = 30;
	static const int HALF_WIDTH = WIDTH / 2;
	static const int SIZE = 3;
	static constexpr double SPEED = 0.005;
	static constexpr double ROT_SPEED = 0.03;
	static constexpr double MOUSE_SENSITIVITY = 0.0015;

	double pos_x, pos_y;
	double angle;
	int mouse_rel_x, mouse_rel_y;


public:
	Player(SDL_Renderer* rend, Map& map, Uint64& deltaTime);
	~Player();

	int getTileX();
	int getTileY();

	void update();
	void draw();
};

#endif // !PLAYER