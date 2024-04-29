#include "projector.h"


Projector::Projector(SDL_Renderer* rend, Player& player) :
	renderer(rend),
	player(player)
{
	rendereables.reserve(800 + 50);

	floor_rect.x = 0;
	floor_rect.y = WINDOW_HEIGHT / 2;
	floor_rect.w = WINDOW_WIDTH;
	floor_rect.h = WINDOW_HEIGHT / 2;

	SDL_Surface* surface = IMG_Load("assets/textures/sky.png");

	sky_src_rect.x = 0;
	sky_src_rect.y = 0;
	sky_src_rect.w = surface->w;
	sky_src_rect.h = surface->h;

	sky_dest_rect1.w = WINDOW_WIDTH;
	sky_dest_rect1.h = WINDOW_HEIGHT / 2;
	sky_dest_rect1.x = 0;
	sky_dest_rect1.y = 0;

	sky_dest_rect2.w = WINDOW_WIDTH;
	sky_dest_rect2.h = WINDOW_HEIGHT / 2;
	sky_dest_rect2.x = WINDOW_WIDTH;
	sky_dest_rect2.y = 0;

	sky_texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
}

Projector::~Projector() {}

void Projector::draw() {
	drawFloor();
	drawSky();

	// Sort array by distance
	std::sort(rendereables.begin(), rendereables.end(), [](Rendereable& a, Rendereable& b) { return a.distance > b.distance; });

	for (Rendereable& object : rendereables) {
		SDL_RenderCopy(renderer, object.texture, &object.srcrect, &object.dstrect);
	}

	rendereables.clear();
}

void Projector::drawSky() {
	sky_dest_rect1.x -= player.mouse_rel_x * 6;
	sky_dest_rect2.x -= player.mouse_rel_x * 6;

	if (sky_dest_rect1.x <= -WINDOW_WIDTH)
		sky_dest_rect1.x = sky_dest_rect2.x + WINDOW_WIDTH;
	else if (sky_dest_rect1.x >= WINDOW_WIDTH)
		sky_dest_rect1.x = sky_dest_rect2.x - WINDOW_WIDTH;

	if (sky_dest_rect2.x <= -WINDOW_WIDTH)
		sky_dest_rect2.x = sky_dest_rect1.x + WINDOW_WIDTH;
	else if (sky_dest_rect2.x >= WINDOW_WIDTH)
		sky_dest_rect2.x = sky_dest_rect1.x - WINDOW_WIDTH;

	SDL_RenderCopy(renderer, sky_texture, &sky_src_rect, &sky_dest_rect1);
	SDL_RenderCopy(renderer, sky_texture, &sky_src_rect, &sky_dest_rect2);
}

void Projector::drawFloor() {
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderFillRect(renderer, &floor_rect);
}