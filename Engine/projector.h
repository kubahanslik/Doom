#ifndef PROJECTOR
#define PROJECTOR

#include <vector>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include "../Player/player.h"

extern const int WINDOW_HEIGHT;
extern const int WINDOW_WIDTH;

struct Rendereable {
	SDL_Texture* texture;
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	
	double distance;
};


class Projector {
private:
	Player& player;
	SDL_Renderer* renderer;
	SDL_Rect floor_rect;
	SDL_Texture* sky_texture;
	SDL_Rect sky_src_rect, sky_dest_rect1, sky_dest_rect2;
	int sky_offset;

public:
	std::vector<Rendereable> rendereables;
	
public:
	Projector(SDL_Renderer* rend, Player& player);
	~Projector();

	void draw();

private:
	void drawSky();
	void drawFloor();

};


#endif // !PROJECTOR
