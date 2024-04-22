#ifndef SPRITE
#define SPRITE

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include "../Player/player.h"
#include "../Engine/raycaster.h"
#include "../Engine/projector.h"

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

class Sprite {
private:
	double pos_x, pos_y;
	double scale, shift;
	Rendereable rendereable;
	SDL_Renderer* renderer;
	Player& player;
	Projector& projector;

public:
	Sprite(SDL_Renderer* renderer, Player& player, Projector& proj, const char* texture_path, double pos_x, double pos_y, double scale, double shift);
	~Sprite();

	void update();
};

#endif // !SPRITE
